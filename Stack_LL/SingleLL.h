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
				delete(pCur);
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
			}else if(pCur->next==NULL){
				tail=temp;
				temp->next = pCur->next;
				pCur->next = temp;
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
		
		Node* extractFirst(){
			if(!isEmpty()){
				Node *hasil=head;
				head=head->next;	
				return hasil;
			}
		}
		
		Node* extract(string cari){
			Node *hasil=head;
			Node *pPre=NULL;
			Node *pCur=head;
			
			while(pCur != NULL && pCur->data.compare(cari) != 0){
				pPre=pCur;
				pCur=pCur->next;
			}
			hasil=pCur;
			
			if(pCur==NULL){
				cout << "Maaf Data tidak ditemukan";
			}else if(pCur->next==NULL){
				tail=pPre;
				delNode(pPre,pCur);
			}else{
				delNode(pPre,pCur);
				return hasil;
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
			}else if(pCur->next==NULL){
				tail=pPre;
				delNode(pPre,pCur);
			}else{
				delNode(pPre,pCur);
			}
		}
		
		~SingleLL(){
			delete[] head;
			delete[] tail;
		}
		
};

