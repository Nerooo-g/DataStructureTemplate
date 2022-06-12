#pragma once
#include<stdexcept>

template<class T>
class MyStack {
private:
	T* arr_;
	int maxsize_;
	int top;
public:
	MyStack();
	MyStack(const int& maxsize);
	void push(const T& element);
	T pop();
	T get_top();
	bool is_empty();
	int get_size();
	~MyStack();
};

template<class T>
inline MyStack<T>::MyStack()
{
	arr_ = new T[100];
	maxsize_ = 100;
	top = -1;
}

template<class T>
inline MyStack<T>::MyStack(const int& maxsize)
{
	maxsize_ = maxsize;
	arr_ = new T[maxsize];
	top = -1;
}

template<class T>
inline void MyStack<T>::push(const T& element)
{
	if (top == maxsize_ - 1) throw std::overflow_error("The stack is full!");
	arr_[++top] = element;
}

template<class T>
inline T MyStack<T>::pop()
{
	if (is_empty()) throw std::underflow_error("The stack is empty!");
	return arr_[top--];
}

template<class T>
inline T MyStack<T>::get_top()
{
	if (is_empty()) throw std::underflow_error("The stack is empty!");
	return arr_[top];
}

template<class T>
inline bool MyStack<T>::is_empty()
{
	return top == -1;
}

template<class T>
inline int MyStack<T>::get_size()
{
	return top+1;
}

template<class T>
inline MyStack<T>::~MyStack()
{
	delete[] arr_;
}
