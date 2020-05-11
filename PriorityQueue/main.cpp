#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class PriorityQueue {
	private:
		int root;
		vector<int> pqArray;
	public:
		PriorityQueue(){
			root=0;
			pqArray.push_back(0);
		}
		bool isEmpty(){
			if(pqArray.size()==1){
				return true;
			}
			else return false;
		}
		
		vector<int> addElement(int key){
			if(isEmpty()){
				root=key;
				pqArray.push_back(key);
				cout << "root : " << key << "\n";
			}
			else {
				pqArray.push_back(key);
				/* Proses Upheap */
				//cari index dari key
				vector<int> vkey;
				vkey.push_back(key);
				vector<int>::iterator it=std::find_end(pqArray.begin(), pqArray.end(), vkey.begin(), vkey.end());
				int keyIndex=std::distance(pqArray.begin(), it);
				
				//simpan nilai parent dari key yang dimasukkan 
				int parentIndex=(int)floor(keyIndex/2);
				int temp=0;
				
				//selama key lebih besar dari nilai parentnya 
				while(parentIndex>0 & key>pqArray[parentIndex]){
					//update root apabila lebih kecil
					if(parentIndex==1){
						root = key;
					}
					cout << "Exchanging key " << key << " with its parent " << pqArray[parentIndex];
					//tukar key <-> parent
					temp=pqArray[parentIndex];
					pqArray[parentIndex]=key;
					pqArray[keyIndex]=temp;
					
					//cari index baru dari key
					it=std::find_end(pqArray.begin(), pqArray.end(), vkey.begin(), vkey.end());
					keyIndex=std::distance(pqArray.begin(), it);
					
					//update parent
					parentIndex=(int)floor(keyIndex/2);
					cout << "\n-------------------finished-----------------\n";
				}
			}
			return pqArray;
		}
		
		int view(){
			cout << "\n-----------------Showing Tree---------------\n";
			/*
			//cetak
			int y=0;
			int x=pow(2,y);
			for(int i=0;i<al.size();i++){
				if(i==x+1){
					cout << "\n";
					for(int j=0;j<x;j++){
						cout << " /   |	";
					}
					y++;
					x=pow(2,y);
					cout <<"\n";
				}
				cout << " " << al.at(i) << " ";
			}
			*/
			
			
			for(int i=0; i<pqArray.size(); i++){
				cout << " " << pqArray.at(i) << " ";
			}
			cout << "\n-------------------finished-----------------\n";
			return 0;
		}
		
		int DequeueMax(){
			cout << "\n-------------------Popping------------------\n";
			fflush(stdin);
			if(isEmpty()){
				cout << "Maaf Queue Kosong \n";
			}
			else {
				//save root to temp
				vector<int>::iterator tempPtr= pqArray.end()-1;
				//cout << *ptr << "";
				int tempPop = root;
				int parentIndex = 1;
				
				//set root to end element
				root = *tempPtr;
				pqArray[parentIndex] = *tempPtr;
				pqArray.pop_back();
				/* Proses Downheap */
				//cari index dari child root
				int temp=0;
				int childL = parentIndex*2;
				int childR = (parentIndex*2)+1;	
				
				//selama masih ada anaknya maka lanjut
				while(childR <= pqArray.size() && childL <= pqArray.size()){
					if(pqArray[parentIndex]<pqArray[childR]){
						//cout << "\n-------------------if-----------------\n";
						//tukar key <-> parent
						temp=pqArray[parentIndex];
						pqArray[parentIndex]=pqArray[childR];
						pqArray[childR]=temp;
						
						//update parent
						parentIndex=childR;
					}
					else if(pqArray[parentIndex]<pqArray[childL]){
						//cout << "\n-------------------elsif-----------------\n";
						//tukar key <-> parent
						temp=pqArray[parentIndex];
						pqArray[parentIndex]=pqArray[childL];
						pqArray[childL]=temp;
						
						//update parent
						parentIndex=childL;
					}
					childL = parentIndex*2;
					childR = (parentIndex*2)+1;
					//cout << "\nchildL : " << pqArray[childL] <<"[" <<  childL << "]" <<endl;
					//cout <<  "\nchildR : " << pqArray[childR] <<"[" <<  childR << "]" <<endl;
				}
				cout << "\n-------------------finished-----------------\n";
				return tempPop;
			}
		}

};

int main(int argc, char** argv) {
	
	PriorityQueue myPQ;
	vector<int> al = myPQ.addElement(2);
	al = myPQ.addElement(5);
	al = myPQ.addElement(8);
	al = myPQ.addElement(12);
	al = myPQ.addElement(10);
	al = myPQ.addElement(7);
	al = myPQ.addElement(6);
	al = myPQ.addElement(5);
	al = myPQ.addElement(5);
	al = myPQ.addElement(13);
	myPQ.view();
	cout << "\nHasil extract : " << myPQ.DequeueMax() << endl;
	myPQ.view();
	al = myPQ.addElement(15);
	myPQ.view();
	cout << "\nHasil extract : " << myPQ.DequeueMax() << endl;
	myPQ.view();
	return 0;
}
