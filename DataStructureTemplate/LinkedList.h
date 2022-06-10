#pragma once
#include<stdexcept>
#include<iostream>


template<class T>
class LinkedList {

private:
	struct Node {
		T data;
		Node* next;
	};
	Node* head_;
	int size_;
	Node* find(int n) const;
public:
	LinkedList();
	LinkedList(const int *arr,int n);
	void add(const T& element);
	T remove(int n);
	void insert(int n, const T& element);
	int get_size() const{ return size_; }
	const T& get_data(int n) const;
	void display() const;
	T& operator[](int n);
	const T& operator[] (int n) const;
	~LinkedList();
};


template<class T>
inline LinkedList<T>::Node* LinkedList<T>::find(int n) const
{
	Node* p = head_;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	return p;
}

template<class T>
inline LinkedList<T>::LinkedList()
{
	head_ = nullptr;
	size_ = 0;
}

template<class T>
inline LinkedList<T>::LinkedList(const int* arr,int n)
{
	head_ = nullptr;
	size_ = 0;
	for (int i = 0; i < n; i++) {
		add(arr[i]);
	}
}

template<class T>
inline void LinkedList<T>::add(const T& element)
{
	if (!head_) {
		head_ = new Node;
		head_->data = element;
		head_->next = nullptr;
	}
	else {
		Node* temp = new Node;
		Node* p = head_;
		temp->data = element;
		temp->next = nullptr;
		while (p->next) {
			p = p->next;
		}
		p->next = temp;
	}
	++size_;
}

template<class T>
inline T LinkedList<T>::remove(int n)
{	
	if (n<0 || n>get_size() - 1) throw std::invalid_argument("The argument types wrong.");
	--size_;
	T temp;
	Node* p = head_;
	if (n == 0) {
		temp = head_->data;
		head_ = head_->next;
		delete p;
		return temp;
	}
	p = find(n - 1);
	Node* q = p->next;
	temp = q->data;
	p->next = p->next->next;
	delete q;
	return temp;
}

template<class T>
inline void LinkedList<T>::insert(int n, const T& element)
{
	if (n<0 || n>get_size()) throw std::invalid_argument("The argument types wrong.");
	Node* node = new Node;
	Node* p = find(n - 1);
	node->data = element;
	node->next = p->next;
	p->next = node;
	++size_;
}

template<class T>
inline const T& LinkedList<T>::get_data(int n) const
{
	if (n<0 || n>get_size() - 1) throw std::invalid_argument("The argument types wrong.");
	return find(n)->data;
}

template<class T>
inline void LinkedList<T>::display() const
{
	Node* p = head_;
	while (p) {
		std::cout << p->data << std::endl;
		p = p->next;
	}
}

template<class T>
inline T& LinkedList<T>::operator[](int n)
{
	if (n<0 || n>get_size() - 1) throw std::invalid_argument("The argument types wrong.");
	return find(n)->data;
	// // O: insert return statement here
}

template<class T>
inline const T& LinkedList<T>::operator[](int n) const
{
	if (n<0 || n>get_size() - 1) throw std::invalid_argument("The argument types wrong.");
	return find(n)->data;
	// // O: insert return statement here
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	Node* p = head_;
	while (get_size()!=0) {
		Node* q = p->next;
		delete p;
		--size_;
		p = q;
	}
}
