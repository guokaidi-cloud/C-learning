#include <vector> 
#include <iostream> 

class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << std::endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << std::endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << std::endl;
    }
    ~testDemo(){
        std::cout << "调用析构函数" << std::endl;
    };
private:
    int num;
};

int main()
{
    std::cout << "emplace_back:" << std::endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);  
    std::cout << "push_back:" << std::endl; 
    std::vector<testDemo> demo2;
    demo2.push_back(2);
    std::cout << "before end of main" << std::endl;
}