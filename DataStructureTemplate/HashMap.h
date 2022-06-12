#pragma once
#include<string>
#include<stdexcept>
using namespace std;

template<class T1,class T2>
class HashMap {
	struct hasharray {
		T1* key;
		T2* value;
		hasharray* next;
		hasharray() :key(nullptr),value(nullptr), next(nullptr) {}
		hasharray(const T1& t,const T2& v) :next(nullptr) {
			key = new T1;
			value = new T2;
			*key = t;
			*value = v;
		};
		~hasharray() {
			delete key;
			delete value;
		}
	};
private:
	hasharray* arr_;
	int size_;
	int hashcode(const string& t);
	int hashcode(const int& t);
	int hashcode(const char& t);
	int hashcode(const double& t);
	int hashcode(const float& t);

public:
	HashMap();
	HashMap(int size);
	T2 get(const T1& key);
	void put(const T1& key, const T2& value);
	bool search(const T1& key);
	void remove(const T1& key);
	~HashMap();
};

template<class T1, class T2>
inline int HashMap<T1,T2>::hashcode(const string& t)
{	
	int n = 0;
	for (int i = 0; i < t.length(); i++) {
		n += t[i];
	}
	return n % size_;
}

template<class T1, class T2>
inline int HashMap<T1, T2>::hashcode(const int& t)
{
	return t % size_;
}

template<class T1, class T2>
inline int HashMap<T1, T2>::hashcode(const char& t)
{
	return t % size_;
}

template<class T1, class T2>
inline int HashMap<T1, T2>::hashcode(const double& t)
{
	return (int)t % size_;
}

template<class T1, class T2>
inline int HashMap<T1, T2>::hashcode(const float& t)
{
	return (int)t % size_;
}

template<class T1, class T2>
inline HashMap<T1, T2>::HashMap()
{
	size_ = 100;
	arr_ = new hasharray[100];
}

template<class T1, class T2>
inline HashMap<T1, T2>::HashMap(int size):size_(size)
{
	arr_ = new hasharray[size_];
}

template<class T1, class T2>
inline T2 HashMap<T1, T2>::get(const T1& key)
{
	int n = hashcode(key);
	if (arr_[n].key!=nullptr && *(arr_[n].key) == key) return *(arr_[n].value);
	hasharray* p = &arr_[n];
	while (p->next != nullptr) {
		p = p->next;
		if (*(p->key) == key) return *(p->value);
	}
	throw invalid_argument("There is no such value according to this key");
}

template<class T1, class T2>
inline void HashMap<T1, T2>::put(const T1& key, const T2& value)
{
	int n = hashcode(key) % size_;
	if (arr_[n].key == nullptr) {
		arr_[n].key = new T1;
		arr_[n].value = new T2;
		*(arr_[n].key) = key;
		*(arr_[n].value) = value;
		return;
	}
	else if (*(arr_[n].key) == key) {
		*(arr_[n].value) = value;
		return;
	}
	hasharray* p = &arr_[n];
	while (p->next != nullptr) {
		p = p->next;
		if (*(p->key) == key) {
			*(p->value) = value;
			return;
		}
	}
	hasharray* node = new hasharray(key,value);
	p->next = node;
}

template<class T1, class T2>
inline bool HashMap<T1, T2>::search(const T1& key)
{
	int n = hashcode(key) % size_;
	if (*(arr_[n].key) == key) return true;
	hasharray* p = &arr_[n];
	while (p->next != nullptr) {
		p = p->next;
		if (*(p->key) == key) return true;
	}
	return false;
}

template<class T1, class T2>
inline void HashMap<T1, T2>::remove(const T1& key)
{
	int n = hashcode(key) % size_;
	if (*(arr_[n].key) == key) {
		delete arr_[n].key;
		delete arr_[n].value;
		arr_[n].key = nullptr;
		arr_[n].value = nullptr;
		return;
	}
	hasharray* p = &arr_[n];
	while (p->next != nullptr) {
		if (*(p->next->key) == key) {
			hasharray* temp = p->next;
			p->next = p->next->next;
			delete p->key;
			delete p->value;
			delete temp;
			return;
		}
		p = p->next;
	}
	return;
}

template<class T1, class T2>
inline HashMap<T1, T2>::~HashMap()
{
	for (int i = 0; i < size_; i++) {
		hasharray* p = arr_[i].next;
		while (p!= nullptr) {
			hasharray* q = p->next;
			delete p;
			p = q;
		}
	}
	delete[] arr_;
}
