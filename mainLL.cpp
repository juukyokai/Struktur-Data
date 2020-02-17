#include <iostream>
#include <string.h>
#include <conio.h>
#include "Node.h"
using namespace std;

class SingleLL{
	public:
		Node *head;
		Node *tail;
		

		SingleLL(){
			head=NULL;
			tail=NULL;
		}

		void printList(){
			Node *n=head;
			while(n != NULL){
				cout << n->data << " ";
				n=n->next;
			}
			cout << "\n";
		}
		
		bool isEmpty(){
			//check if linked lsit is empty or not
			if(this->head==NULL){
				return true;	//true=1
			}else{
				return false;	//false=0
			}
		}
		
		string first(){
			if(isEmpty() != true){
				return head->data;
			}else{
				return NULL;
			}
		}
		
		string last(){
			if(tail != NULL){
				return tail->data;
			}else{
				return NULL;
			}
		}
		
		void append(string s){
			Node *temp = new Node(s,NULL);
			if(head==NULL){
				head=temp;
			}else{
				tail->next=temp;
			}
			tail=temp;
		}
		
		void prepend(string s){
			Node *temp = new Node(s,NULL);
			if(head!=NULL){
				temp->next=head;	
			}
			head=temp;
		}
		
		void delNode(Node *pPre, Node *pCur){
			if(pPre == NULL){
				head= pCur->next;
			}
			else{
				pPre->next = pCur->next;
			}
		}
		
		void insertMid(string s, string cari){
			//Alokasi Node
			Node *temp = new Node(s,NULL);
			
			Node *pPre = NULL;
			Node *pCur = head;
				
			while(pCur != NULL && pCur->data.compare(cari) != 0){
				pPre = pCur;
				pCur = pCur->next;
			}
			
			if(pCur==NULL){
				cout << "Maaf data tidak ditemukan!";
			}else if(pPre==NULL){
				temp->next=head;
				head=temp;
			}else{
				temp->next = pCur->next;
				pCur->next = temp;
			}
		}
		
		void updateData(string cari){
			
			Node *pCur=head;
			string tmp;
			
			while(pCur != NULL && pCur->data.compare(cari) != 0){
				pCur = pCur->next;
			}
			if(pCur==NULL){
				cout << "Maaf data tidak ditemukan\n";
			}else{
				cout << "Masukkan data pengganti : ";
				cin >> tmp;
				
				pCur->data=tmp;
			}
			
			
		}
		
		void deleteData(string cari){
			Node *pPre = NULL;
			Node *pCur = head;
			
			while(pCur != NULL && pCur->data.compare(cari) != 0){
				pPre = pCur;
				pCur = pCur->next;
			}
			
			if(pCur==NULL){
				cout << "Maaf data tidak ditemukan!";
			}else{
				delNode(pPre,pCur);
			}
		}
		
		~SingleLL(){
			delete[] head;
			delete[] tail;
		}
		
};

int main() {
	string cari;
	string del;
	string up;
	
	
	
	SingleLL sll;
	Node *simpul1= new Node("Atika",NULL);
	Node *simpul2= new Node("Ben",NULL);
	Node *simpul3= new Node("Chika",NULL);
	
	simpul1->next = simpul2;
	simpul2->next = simpul3;
	sll.head=simpul1;
	sll.tail=simpul3;
	
	sll.printList();
	cout << "Last Node : " << sll.last() << endl;
	getch();
	system("cls");
	sll.append("Delta");
	sll.printList();
	cout << "Last Node : " << sll.last() << endl;
	getch();
	system("cls");
	sll.prepend("Alpha");
	sll.printList();
	cout << "First Node : " << sll.first() <<endl;
	getch();
	system("cls");
	sll.printList();
	cout << "Masukkan data setelah Nama : ";
	cin >> cari;
	sll.insertMid("Gamma",cari);	
	sll.printList();
	getch();
	system("cls");
	sll.printList();
	cout << "Masukkan data yang ingin dihapus : ";
	cin >> del;
	sll.deleteData(del);
	sll.printList();
	getch();
	system("cls");
	sll.printList();
	cout << "Masukkan data yang ingin diganti : ";
	cin >> up;
	sll.updateData(up);
	sll.printList();
	return 0;
}
