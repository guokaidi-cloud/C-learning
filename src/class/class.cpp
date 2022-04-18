#include<iostream>
using namespace std;
//普通构造、拷贝构造、拷贝赋值、移动构造、移动赋值运算符

class TestString {
public:
	// 普通构造
	TestString(){
		cout << "普通构造" << endl;
	}
	TestString(int x):n(x) {
		cout << "普通构造" << endl;
	}
	// 拷贝构造
	TestString(const TestString& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "拷贝构造" << endl;
	}
	// 移动构造
	TestString(TestString&& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "移动构造" << endl;
	}
	// 拷贝赋值构造
	TestString& operator= (const TestString& str){
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "拷贝赋值构造" << endl;
		return *this;
	}
	// 移动赋值构造
	TestString& operator= (TestString&& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "移动赋值构造" << endl;
		return *this;
	}
	~TestString(){
		cout << "析构函数" << endl;
	}
public:
	int n = 0;
	char ch[];
};


template<typename T>
class TestVector {
public:
	// 普通构造
	TestVector() {
		cout << "普通构造构造函数" << endl;
	}
	TestVector(int size,int capacity):theSize_(size),theCapacity_(capacity){
		cout << "普通构造构造函数重载" << endl;
	}
	// 拷贝构造函数
	TestVector(const TestVector& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "拷贝构造函数" << endl;
	}
	// 移动构造函数
	TestVector(TestVector&& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "移动构造函数" << endl;
	}
	// 拷贝赋值函数
	TestVector& operator = (const TestVector& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "拷贝赋值函数" << endl;
		return *this;
	}
	// 移动赋值函数
	TestVector& operator = (TestVector&& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "移动赋值函数" << endl;
		return *this;
	}

	~TestVector() {
		cout << "析构函数" << endl;
	}
public:
	int theSize_;
	int theCapacity_ ;
	T objects[];
};

#if 0
int main() {
	TestString str1(4);
	TestString str2 = str1;
	TestString str3(str1);
	TestString str4;
	str4 = str1;
	str4 = TestString();
	str4 = move(str2);

	cout << "--------------------" << endl;
	return 0;
}
#endif



int main() {

	TestVector<int> vec1(1,2);
	cout << vec1.theSize_ << " " << vec1.theCapacity_ << endl;
	TestVector<int> vec2(vec1);
	cout << vec2.theSize_ << " " << vec2.theCapacity_ << endl;
	TestVector<int> vec3;
	vec3 = vec1;
	cout << vec3.theSize_ << " " << vec3.theCapacity_ << endl;
	TestVector<int> vec4;
	vec4 = move(vec1);
	cout << "-------------------" << endl;
	return 0;
}