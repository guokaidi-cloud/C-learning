#pragma once 
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>


template <typename T>
class SafeQueue{
 public:
  SafeQueue() = default;
  ~SafeQueue() = default;

  void enqueue(T&& t){
      std::lock_guard<std::mutex> lock(mutex_);
      if(queue_.size() >= max_queue_size_){
          queue_.pop();
          queue_size_--;
      }
      queue_.push(t);
      cv_.notify_one();
  }

  T dequeue(){
      std::unique_lock<std::mutex> lock(mutex_);
      while(queue_.empty()){
          cv_.wait(lock);
      }
      T val = queue_.front();
      queue_.pop();
      return val;
  }

  T getElement(){
      std::unique_lock<std::mutex> lock(mutex_);
      if(queue_.empty()){
          cv_.wait(lock);
      }
      T val = queue_.front();
      queue_.pop();
      return val;
  }
  T size(){
      std::unique_lock<std::mutex> lock(mutex_);
      return queue_.size();
  }

 private:
  std::queue<T> queue_{};
  std::mutex mutex_{};
  std::condition_variable cv_{};
  std::atomic<int> queue_size_{0};
  std::atomic<int> max_queue_size_{};
};