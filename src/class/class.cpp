#include<iostream>
using namespace std;
//��ͨ���졢�������졢������ֵ���ƶ����졢�ƶ���ֵ�����

class TestString {
public:
	// ��ͨ����
	TestString(){
		cout << "��ͨ����" << endl;
	}
	TestString(int x):n(x) {
		cout << "��ͨ����" << endl;
	}
	// ��������
	TestString(const TestString& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "��������" << endl;
	}
	// �ƶ�����
	TestString(TestString&& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "�ƶ�����" << endl;
	}
	// ������ֵ����
	TestString& operator= (const TestString& str){
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "������ֵ����" << endl;
		return *this;
	}
	// �ƶ���ֵ����
	TestString& operator= (TestString&& str) {
		this->n = str.n;
		for (int i = 0; i < n; i++) {
			this->ch[i] = str.ch[i];
		}
		cout << "�ƶ���ֵ����" << endl;
		return *this;
	}
	~TestString(){
		cout << "��������" << endl;
	}
public:
	int n = 0;
	char ch[];
};


template<typename T>
class TestVector {
public:
	// ��ͨ����
	TestVector() {
		cout << "��ͨ���칹�캯��" << endl;
	}
	TestVector(int size,int capacity):theSize_(size),theCapacity_(capacity){
		cout << "��ͨ���칹�캯������" << endl;
	}
	// �������캯��
	TestVector(const TestVector& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "�������캯��" << endl;
	}
	// �ƶ����캯��
	TestVector(TestVector&& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "�ƶ����캯��" << endl;
	}
	// ������ֵ����
	TestVector& operator = (const TestVector& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "������ֵ����" << endl;
		return *this;
	}
	// �ƶ���ֵ����
	TestVector& operator = (TestVector&& rhs) {
		this->theSize_ = rhs.theSize_;
		this->theCapacity_ = rhs.theCapacity_;
		for (int i = 0; i < theSize_; i++) {
			this->objects[i] = rhs.objects[i];
		}
		cout << "�ƶ���ֵ����" << endl;
		return *this;
	}

	~TestVector() {
		cout << "��������" << endl;
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