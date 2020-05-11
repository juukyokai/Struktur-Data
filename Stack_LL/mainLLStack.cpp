#include <iostream>
#include <string.h>
#include <conio.h>
#include "SingleLL.h"
using namespace std;


class MyLLStack{
	private:
		int top;
		int max;
		SingleLL list;
	public:
		MyLLStack(int maxSize){
			top=0;
			max=maxSize;
		}
		void push(string data){
			if(top==max){
				cout << "Maaf stack penuh!!"<<endl;
			}else{
				cout << "Pushing...." << data << endl;
				list.prepend(data);
				top++;
			}
		}
		string pop(){
			if(top==0){
				cout << "Maaf Stack kosong. Tidak ada data yang dapat diekstrak!!"<< endl;
				return "Tidak Ada!";
			}else{
				cout << "Popping..." << endl;
				Node* result = list.extractFirst();
				top--;
				return result->data;
			}
		}
		void view(){
			cout << "Stack Berisi : "<< endl;
			list.printList();
		}
};


int main(int argc, char** argv) {
	string inp_str;
	char temp;
	bool loop=true;
	MyLLStack mlls(3);
	
	while(loop == true){
		system("cls");
		cout << "Pilih Menu : " << endl;
		cout << "1. Push Data." << endl;
		cout << "2. Pop Data." << endl;
		cout << "3. View Data." << endl;
		cout << "press 'q' to quit" << endl;
		cin >> temp;
		
		if(temp=='1'){
			cout << "Masukkan isi data : ";
			cin >> inp_str;
			mlls.push(inp_str);
		}else if(temp=='2'){
			cout << "Data yang dikeluarkan : " << mlls.pop() << endl;	
		}else if(temp=='3'){
			mlls.view();
		}else if(temp=='q'){
			loop=false;
		}else{
			cout<<"Input salah!!";
		}
		getch();
	}
	return 0;
}
