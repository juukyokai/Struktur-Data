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

int main() {
	string cari;
	string del;
	string up;
	SingleLL sll;
	bool loop=true;
	char input;
	
	
	Node *simpul1= new Node("Atika",NULL);
	Node *simpul2= new Node("Ben",NULL);
	Node *simpul3= new Node("Chika",NULL);
	
	simpul1->next = simpul2;
	simpul2->next = simpul3;
	sll.head=simpul1;
	sll.tail=simpul3;
	
	
	while(loop==true){
		system("cls");
		cout << "1. Check Simple Data\n";
		cout << "2. Append New Data\n";
		cout << "3. Prepend New Data\n";
		cout << "4. Insert New Data\n";
		cout << "5. Delete Data\n";
		cout << "6. Update Data\n";
		cout << "7. Extract First Data\n";
		cout << "8. Extract Data\n";
		cout << "press q to quit!!\n";
		cout << "Masukkan menu : ";
		cin >> input;
		
		if(input=='1'){
			//checking simple data
			sll.printList();
			cout << "Last Node : " << sll.last() << endl;
			getch();	
		}else if(input=='2'){
			//Input last data
			sll.append("Delta");
			sll.printList();
			cout << "Last Node : " << sll.last() << endl;
			getch();
		}else if(input=='3'){
			//input first data
			sll.prepend("Alpha");
			sll.printList();
			cout << "First Node : " << sll.first() <<endl;
			getch();
		}else if(input=='4'){
			//input mid data
			sll.printList();
			cout << "Masukkan data setelah Nama : ";
			cin >> cari;
			sll.insertMid("Gamma",cari);	
			sll.printList();
			getch();
		}else if(input=='5'){
			//Delete data
			sll.printList();
			cout << "Masukkan data yang ingin dihapus : ";
			cin >> del;
			sll.deleteData(del);
			sll.printList();
			getch();
		}else if(input=='6'){
			//update data
			sll.printList();
			cout << "Masukkan data yang ingin diganti : ";
			cin >> up;
			sll.updateData(up);
			sll.printList();
		}else if(input=='7'){
			sll.printList();
			sll.first();
			cout << "Node yang terekstrak adalah : " << sll.extractFirst();
			sll.printList();
		}else if(input=='8'){
			cout << "Masukkan data yang ingin diekstrak : ";
			cin >> del;
			cout << "data yang di ekstrak adalah : " << sll.extract(del);
			sll.printList();
		}else if(input=='q'){
			loop=false;
		}
	}
	system("cls");
	cout<<"Terima Kasih!!";
	
	return 0;
}
