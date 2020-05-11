#include <iostream>
using namespace std;

class Node {
	public:
		string data;
		Node *next;
		
		Node (string s, Node *n){
			this->data=s;
			this->next=n;
		}
};
