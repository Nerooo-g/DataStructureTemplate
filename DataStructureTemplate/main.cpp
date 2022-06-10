#include<iostream>
#include<stdexcept>

#include "LinkedList.h"
using namespace std;


struct Node {
	int data;
	Node* next;
};

Node* add(Node* head_,int element) {
	if (!head_) {
		head_ = new Node;
		head_->data = element;
		head_->next = nullptr;
	}
	else {
		Node* temp = new Node;
		temp->data = element;
		temp->next = head_;
		head_ = temp;
	}
	return head_;
}

void test(int n) {
	if (n == 0) throw invalid_argument("haha");
}

int main() {
	int arr[] = {1,2,3,4,5};
	const LinkedList<int>* t=new LinkedList<int>(arr,5);
	t->display();
	t->get_data(3);
	cout << t->get_size() << endl;
	delete t;
}