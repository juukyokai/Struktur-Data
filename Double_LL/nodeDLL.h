#include <iostream>
using namespace std;

class nodeDLL{
	private :
		string data;
		nodeDLL *next;
		nodeDLL *prev;
		
	public :
		//constructor
		nodeDLL(string s){
			data=s;
			next=NULL;
			prev=NULL;
		}
		nodeDLL(string s, nodeDLL *n, nodeDLL *p){
			data=s;
			next=n;
			prev=p;
		}
		//setter
		void setData(string s){
			data=s;
		}
		void setNext(nodeDLL *n){
			next=n;
		}
		void setPrev(nodeDLL *p){
			prev=p;
		}
		//getter
		string getData(){
			return data;
		}
		nodeDLL* getNext(){
			return next;
		}
		nodeDLL* getPrev(){
			return prev;
		}
};
