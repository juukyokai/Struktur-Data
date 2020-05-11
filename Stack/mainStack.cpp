#include <iostream>
#include <vector>
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
		void push(String data){
			if(top==max){
				cout << "Maaf stack penuh!!"<<endl;
			}else{
				cout << "Pushing...." << data << endl;
				list.prepend(data);
				top+=1;
			}
		}
		String pop(){
			if(top!=0){
				cout << "Maaf Stack kosong. Tidak ada data yang dapat diekstrak!!"<< endl;
				return NULL;
			}else{
				cout << "Popping..."<<endl;
				String result = list.extractFirst()->data;
				return result;
			}
		}
		void view(){
			cout << "Stack Berisi : "<< endl;
			list.printList();
		}
};

class MyFirstStack{
	private:
		int size;
		std::vector<int> stack;
		int top;
		
	public:
		MyFirstStack(int size) : stack(size){
			this->size=size;
			top=-1;
		}
		void push(int data){
			if(top==(size-1)){
				cout << "Maaf data penuh. tidak bisa tambah lagi!"<< endl;
			}else{
				cout << "Pushing...." << data << endl;
				stack[++top]=data;
			}
		}
		int pop(){
			if(top==-1){
				cout << "Maaf Data kosong. tidak bisa menghapus!" << endl;
				return -1;
			}else{
				cout << "Popping..." << endl;
				int result = stack[top--];
				return result;
			}
		}
		void view(char ket){
			int i;
			if(ket =='1'){
				cout << "bawah ke atas" <<endl;
				for(i=0;i<=this->top;i++){
					cout << stack[i] << endl;
				}
			}else if(ket == '2'){
				cout << "atas ke bawah"<< endl;
				for(i=this->top;i>=0;i--){
					cout << stack[i] << endl;
				}
			}else{
				cout << "Maaf input salah!!" << endl;
			}
			cout << "stack selesai!!"<<endl;
		}
		
};

int main(int argc, char** argv) {
	int inp_int;
	String inp_str;
	char temp;
	char inp_ch;
	bool loop=true;
	//MyFirstStack mfs(3);
	MyLLStack mlls(3);
	
	while(loop == true){
		cout << "Pilih Menu : " << endl;
		cout << "1. Push Data." << endl;
		cout << "2. Pop Data." << endl;
		cout << "3. View Data." << endl;
		cout << "press 'q' to quit" << endl;
		cin >> temp;
		
		if(temp=='1'){
			/*
			cout << "Masukkan data bernilai : " ;
			cin >> inp_int; 
			mfs.push(inp_int);
			*/
			
			
			
		}else if(temp=='2'){
			cout << "Data yang dikeluarkan : " << mfs.pop() << endl;	
		}else if(temp=='3'){
			cout<<"Mau ascending atau descending? (1/2)"<<endl;
			cin >> inp_ch;
			mfs.view(inp_ch);
		}else if(temp=='q'){
			loop=false;
		}else{
			cout<<"Input salah!!";
		}	
	}
	
	return 0;
}
