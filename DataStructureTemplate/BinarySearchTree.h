#pragma once
#include<iostream>

template<class T>
class BST {
	struct Node {
		T data;
		Node* parent;
		Node* left;
		Node* right;
		Node(T data) :parent(nullptr),left(nullptr), right(nullptr),data(data) {}
	};
private:
	Node* root_;
	Node* find_successor(Node* node);
	void transplant(Node* ori, Node* suc);
	Node* s_delete(Node* p);
public:
	BST(const T& data);
	Node* search(const T& data);
	void insert(const T& data);
	void preorder(bool flag,Node* node = nullptr);
	void remove(const T& data);
	~BST();
};

template<class T>
inline BST<T>::Node* BST<T>::find_successor(Node* node)
{
	if (!node||!node->right) return nullptr;
	Node* p = node->right;
	while (p->left) {
		p = p->left;
	}
	return p;
}

template<class T>
inline void BST<T>::transplant(Node* ori,Node* suc)
{

	if (!ori->parent) root_ = suc;
	else if (ori == ori->parent->left) ori->parent->left = suc;
	else ori->parent->right = suc;
	if (suc) suc->parent = ori->parent;
}

template<class T>
inline BST<T>::Node* BST<T>::s_delete(Node *p)
{
	if (p->left) p->left=s_delete(p->left);
	if (p->right) p->right=s_delete(p->right);
	delete p;
	return nullptr;

}




template<class T>
inline BST<T>::BST(const T& data)
{
	root_ = new Node(data);
}

template<class T>
inline BST<T>::Node* BST<T>::search(const T& data)
{
	Node* p = root_;
	while (p) {
		if (data == p->data) return p;
		if (data > p->data) p = p->right;
		else p = p->left;
	}
	return nullptr;
}

template<class T>
inline void BST<T>::insert(const T& data)
{
	Node* p = root_;
	while (true) {
		if (data >= p->data) {
			if (!p->right) {
				Node* node = new Node(data);
				p->right = node;
				node->parent = p;
				break;
			}
			else p = p->right;
		}
		else {
			if (!p->left) {
				Node* node = new Node(data);
				p->left = node;
				node->parent = p;
				break;
			}
			else p = p->left;
		}
	}
}

template<class T>
inline void BST<T>::preorder(bool flag, Node* node)
{
	if (flag) node = root_;
	if (!node) return;
	std::cout << node->data << std::endl;
	preorder(false, node->left);
	preorder(false, node->right);
}

template<class T>
inline void BST<T>::remove(const T& data)
{
	Node* temp = search(data);
	if (!temp) return;
	if (!temp->left) transplant(temp, temp->right);
	else if (!temp->right) transplant(temp, temp->left);
	else {
		Node* p = find_successor(temp);
		if (p->parent != temp) {
			transplant(p, p->right);
			p->right = temp->right;
			p->right->parent = p;
		}
		transplant(temp, p);
		p->left = temp->left;
		p->left->parent = p;
	}
	delete temp;
}

template<class T>
inline BST<T>::~BST()
{
	s_delete(root_);
}
