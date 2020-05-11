#include <iostream>
#include <vector>
#include <cmath>
#include "Node.h"
using namespace std;

class NodeStatus {
	private :
		Node* node;
		int status;
	public :
		NodeStatus(){
			node = NULL;
			status=0;
		}
		void setNodeStatus(Node* root, int val){
			node = root;
			status = val;
		}
		Node* getNode(){
			return node;
		}
		int getStatus(){
			return status;
		}
};

class BinarySearch {
	private:
		std::vector<int> array;
	public:
		BinarySearch(vector<int> data){
			array = data;
		}
		void printArray(){
			for (int i=0;i<array.size();i++){
				cout << i << ". " <<array[i] << " \n";
			}
			cout << "\n";
		}
		
		
		
		int binarySearch(int key){
			int l=0;
			int r=array.size()-1;
			while (l<=r){
				int m=(int)(floor(l+r)/2);
				if (key==array[m]){
					return m;
				}
				else if( key< array[m]){
					r=m-1;
				}
				else {
					l=m+1;
				}
			}
			return -1;
		}
};

class BinarySearchTree{
	private:
		int nodeCount;
		Node* root;
	public:
		BinarySearchTree(){
			nodeCount=0;
			root=NULL;
		}
		NodeStatus find(Node* start, int value){
			NodeStatus ns;
			if(start!=NULL){
				if(value < start->getElement()){
					if(start->getLeft()!=NULL){
						return find(start->getLeft(),value);	
					}
					else{
						ns.setNodeStatus(start,0);
						return ns;
					}
					
				}
				else if(value == start->getElement()){
					ns.setNodeStatus(start,1);
					return ns;
				}
				else if(value > start->getElement()){
					if(start->getRight()!=NULL){
						return find(start->getRight(),value);
					}
					else {
						ns.setNodeStatus(start,0);
						return ns;
					}
				}
			}
			return ns;
		}
		void insertNode(int newValue){
			cout << "inserting node " << newValue << "\n";
			Node *newNode = new Node;
			nodeCount+=1;
			newNode->setID(nodeCount);
			newNode->setElement(newValue);
			newNode->setLeft(NULL);
			newNode->setRight(NULL);
			if(root!=NULL){
				Node* curr;
				curr=root;
				NodeStatus ns = find(curr,newValue);
				Node* parNode=ns.getNode();
				int nodeExist=ns.getStatus();
				if(parNode!=NULL & nodeExist==0){
					if(newValue < parNode->getElement()){
						parNode->setLeft(newNode);
					}
					else if(newValue > parNode->getElement()){
						parNode->setRight(newNode);
					}
				}
				else if(parNode!=NULL && nodeExist==1){
					cout << "Node " << newValue << " exist. Cannot insert node with the same value\n";
				}
				else if(parNode!=NULL && root->getElement()==newValue && nodeExist==1){
					cout << "Node " << newValue << "exist. Cannot insert node with the same value\n";
				}
			}
			else{
				if(newValue < parNode->getElement()){
						parNode->setLeft(newNode);
					}
					else if(newValue > parNode->getElement()){
						parNode->setRight(newNode);
					}
				}
		}
		void printBinaryTree(Node* ptr){
			if(ptr!=NULL){
			        
			        printf("test");
		            if(ptr->getElement()!=NULL){
			            cout << ptr->getID() << " " << ptr->getElement();
			            
			        }
			        	printBinaryTree(ptr->getLeft());
			        	printBinaryTree(ptr->getRight());
			        
			}
			/*
			else{
				printBinaryTree(root);
			}*/
		}
		Node* getRoot(){
			return root;
		}
		/*
		void displayBinaryTree(){

		}
		void deleteTree(int value){
			//find dulu baru delete
		}
		*/
	
};
int main(int argc, char** argv) {
	BinarySearchTree bst = BinarySearchTree();
	bst.insertNode(2);
	bst.insertNode(1);
	bst.insertNode(5);
	bst.insertNode(7);
	bst.printBinaryTree(bst.getRoot());
	
	
	
	/*
	vector<int> vect;
	vect.push_back(2);
	vect.push_back(5);
	vect.push_back(7);
	vect.push_back(13);
	vect.push_back(15);
	vect.push_back(32);
	vect.push_back(21);
	
	BinarySearch bs = BinarySearch(vect);
	vect.push_back(21);
	bs.printArray();
	int hasil = bs.binarySearch(21);
	if (hasil == -1){
		cout << "Data Tidak Ditemukan";
	}
	else {
		cout << "Data ada di posisi " << hasil;
	}
	*/
	return 0;
	
}
