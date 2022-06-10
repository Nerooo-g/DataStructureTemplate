#pragma once
#include<stdexcept>

template<class T>
class MyQueue {
private:
	int maxsize_;
	int front_;
	int rear_;
	T* arr_;
public:
	MyQueue();
	MyQueue(int maxsize);
	void push(const T& element);
	T pop();
	bool is_empty();
	int get_size();
	~MyQueue();
};

template<class T>
inline MyQueue<T>::MyQueue()
{
	arr_ = new T[100];
	front_ = rear_ = 0;
	maxsize_ = 100;
}

template<class T>
inline MyQueue<T>::MyQueue(int maxsize)
{
	maxsize_ = ++maxsize;
	arr_ = new T[maxsize_];
	front_ = rear_ = 0;
}

template<class T>
inline void MyQueue<T>::push(const T& element)
{
	if (get_size() == maxsize_-1) throw std::overflow_error("The queue is full!");
	arr_[rear_] = element;
	rear_ = (rear_ + 1) % maxsize_;
}

template<class T>
inline T MyQueue<T>::pop()
{
	if (is_empty()) throw std::underflow_error("The queue is empty!");
	T temp = arr_[front_];
	front_ = (front_ + 1) % maxsize_;
	return temp;
}

template<class T>
inline bool MyQueue<T>::is_empty()
{
	return front_ == rear_;
}

template<class T>
inline int MyQueue<T>::get_size()
{
	if (rear_ == front_) return 0;
	if (front_ < rear_) return rear_ - front_;
	else return maxsize_ - (front_ - rear_);
}

template<class T>
inline MyQueue<T>::~MyQueue()
{
	delete[] arr_;
}
