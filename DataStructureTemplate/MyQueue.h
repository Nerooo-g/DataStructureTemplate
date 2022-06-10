#pragma once
#include<stdexcept>

template<class T>
class MyQueue {
private:
	int maxsize_;
	int front_;
	int rear_;
	T* arr;
public:
	MyQueue();
	MyQueue(int maxsize);
	void push(const T& element);
	T pop();
	int get_size();
};

template<class T>
inline MyQueue<T>::MyQueue()
{
	arr = new T[100];
	front_ = rear_ = 0;
	maxsize_ = 100;
}

template<class T>
inline MyQueue<T>::MyQueue(int maxsize)
{
	maxsize_ = maxsize;
	arr = new T[maxsize];
	front_ = rear_ = 0;
}

template<class T>
inline void MyQueue<T>::push(const T& element)
{
	if (get_size() == maxsize_-1) throw std::overflow_error("The queue is full!");
	arr[rear_] = element;
	rear_ = (rear_ + 1) % maxsize_;
}

template<class T>
inline T MyQueue<T>::pop()
{
	if (get_size() == 0) throw std::underflow_error("The queue is empty!");
	T temp = arr[front_];
	front_ = (front_ + 1) % maxsize_;
	return front_;
}

template<class T>
inline int MyQueue<T>::get_size()
{
	if (rear_ == front_) return 0;
	if (front_ < rear_) return rear_ - front_;
	else return maxsize_ - (front_ - rear_);
}
