#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	struct Node {
		 T data;
		Node* next;
	};

	private:
		Node* head;
		Node* findMid(Node* start) {
			Node* slow = start;
			Node* fast = start->next;
			while (fast != nullptr && fast->next != nullptr) {
				slow = slow->next;
				fast = fast->next->next;
			}
		};
		void sortNode(Node** root) {
			if (*root == nullptr || (*root)->next == nullptr) {
				return;	
			}
			Node* start = *root;
			Node* mid = findMid(start);
			sortNode(start):
			sortNode(mid);
			*root = merge(a,b);
		};

	public:
		LinkedList(initializer_list<T> list): head{nullptr} {
			Node* tail = nullptr;
			for (auto& it : list) {
				Node* curr = new Node();
				curr->data = it;
				curr->next = tail;
				if (head == nullptr) {
					head = curr;
				} else {
					tail->next = curr
				}
				tail = curr;
			}
		};
		~LinkedList() {
			Node* curr = head;
			while(curr!= nullptr) {
				temp = curr;
				curr = curr->next;
				delete temp;
			}
		};
		void sort() {
			sortNode(&head);
		};
		Node* merge(Node* start, Node* end) {
			if (start == nullptr) {
				return end;
			} else if (end == nullptr) {
				return start; 
			}
			Node* result = nullptr;
			if (start->data < end->data) {
				result = start;
				result ->next = merge(start->next, end);
			} else {
				result = end;
				result->next = merge(start, end->next);
			}
			return result;
		};
		void print() {
			Node* curr = head;
			while(curr != nullptr) {
				cout << curr->data << endl;
				curr = curr->next;
			}
		};
}

int main ( int argc, char* argv[]) {
	LinkedList* list = new LinkedList({1,3,5,7,8});
	list->sort();
	list->print();
	return 0;
}
