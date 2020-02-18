#include <iostream>
#include <string.h>
#include "nodeDLL.h"
using namespace std;

class doubleLL{
	public:
		nodeDLL *head;
		nodeDLL *tail;
		
		doubleLL(){
			head=NULL;
			tail=NULL;
		}
		
		void printList(){
			nodeDLL *n=head;
			while(n != NULL){
				cout << n->getData() <<" ";
				n=n->getNext();
			}
			cout << "\n";
		}
		
		bool isEmpty(){
			if(head==NULL){
				return true;
			}else{
				return false;
			}
		}
		
		string first(){
			if(!isEmpty()){
				return head->getData();
			}else{
				return NULL;
			}
		}
		
		string last(){
			if(tail != NULL){
				return tail->getData();
			}else{
				return NULL;
			}
		}
		
		void append(string s){
			nodeDLL *temp = new nodeDLL(s);
			if(head==NULL){
				head=temp;
			}else{
				tail->setNext(temp);
			}
			tail=temp;
		}
		
		void prepend(string s){
			nodeDLL *temp = new nodeDLL(s);
			if(head!=NULL){
				temp->setNext(head);
			}
			head=temp;
		}
};


int main(int argc, char** argv) {
	doubleLL dll;
	
	nodeDLL *simpul1 = new nodeDLL("Atika");
	nodeDLL *simpul2 = new nodeDLL("Ben");
	nodeDLL *simpul3 = new nodeDLL("Chika");
	
	simpul1->setNext(simpul2);
	simpul2->setNext(simpul3);
	dll.head=simpul1;
	dll.tail=simpul3;
	
	
	//input first data
	dll.prepend("Alpha");
	dll.printList();
	cout << "First Node : " << dll.first() << endl;
	
	return 0;
}
