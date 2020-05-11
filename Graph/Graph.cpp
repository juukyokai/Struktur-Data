#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "nodeVertex.h"


using namespace std;

/* 
	@Algorithm Original By : Intan Yuniar Purbasari, S.Kom.,M.Sc.
	@Source Code Original By : Mohammad Faisal Riftiarrasyid (18081010001)
	@Uploaded at Github : https://github.com/JuukyoKai/Struktur-Data/tree/master/Graph
*/

class Graph{
	private:
		nodeVertex *root;
		vector<nodeVertex*> vertexPtrArr;
		vector<int> vertexArr;
	
	public:
		/*             constructor                */
		Graph(){
			root->setName(-1);
			vertexPtrArr.push_back(root);
			vertexArr.push_back(-1);
		}
		
		/*            Basic Function              */
		//ensure that graph is Empty
		bool isEmpty(){
			if(vertexArr.size()==1){
				return true;
			}
			else return false;
		}
		//ensure that graph has a minimum of 2 vertices
		bool isValid(){
			if(vertexArr.size()>=3){
				return true;
			}
			else return false;
		}
		vector<int>::iterator cariIndex(int key){
			//Searching for designated key in recorded data of vertices (vertexArr)
			vector<int> vkey;
			vkey.push_back(key);
			vector<int>::iterator it=std::search(vertexArr.begin(), vertexArr.end(), vkey.begin(), vkey.end());
			return it;
		}
		
		/*           Mandatory function              */
		void addVertex(int key){
			//make temporary object
			nodeVertex *tempVert = new nodeVertex(key);
			if(isEmpty()){
				//exchange default root
				root=tempVert;
				cout << "Adding root : " << key << endl;
			}else {
				cout << "Adding Vertex : " << key << endl;
			}
			//push temp to Vertex Array
			vertexArr.push_back(key);
			vertexPtrArr.push_back(tempVert);
		}
		
		void addEdge(int fromVert, int toVert){
			//make temporary object
			nodeEdge *tempEdge = new nodeEdge();
			//search and save index vertex
			int indexFrom = std::distance(vertexArr.begin(), cariIndex(fromVert));
			int indexTo = std::distance(vertexArr.begin(), cariIndex(toVert));
			//connecting between vertices
			vertexPtrArr[indexFrom]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexFrom]->setConnectedVertex(vertexPtrArr[indexTo]);
			vertexPtrArr[indexTo]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexTo]->setConnectedVertex(vertexPtrArr[indexFrom]);
		}
		void addEdge(int fromVert, int toVert, int weight){
			//make temporary object
			nodeEdge *tempEdge = new nodeEdge(weight);
			//search and save index vertex
			int indexFrom = std::distance(vertexArr.begin(), cariIndex(fromVert));
			int indexTo = std::distance(vertexArr.begin(), cariIndex(toVert));
			//connecting between vertices
			vertexPtrArr[indexFrom]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexFrom]->setConnectedVertex(vertexPtrArr[indexTo]);
			vertexPtrArr[indexTo]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexTo]->setConnectedVertex(vertexPtrArr[indexFrom]);
		}
		nodeVertex* getVertex(int vertKey){
			cout << "Getting Vertex ...." << endl;
			if(cariIndex(vertKey) != vertexArr.end()){
				cout << " Status : Ditemukan" << endl;
				return vertexPtrArr[std::distance(vertexArr.begin(), cariIndex(vertKey))];
			} else {
				cout << " Status : Tidak Ditemukan" << endl;	
			}
		}
		
		void getVertices(){
			vector<int>::iterator it;
			for (it = vertexArr.begin(); it != vertexArr.end(); it++) { 
           		cout << *it << ' '; 
        	} 
        	cout << "\n" << endl;
		}
		void inGraph(int vertKey){
			if(cariIndex(vertKey) != vertexArr.end()){
				cout << "vertex yang anda cari adalah : " << vertKey << " Status : Ditemukan" << endl;
			} else {
				cout << "vertex yang anda cari adalah : " << vertKey << " Status : Tidak Ditemukan" << endl;	
			}
		}
		/* --------------- NPM Modules 1 ---------------*/ 
		//Adjacency List
		void adjList(nodeVertex* node){
			vector<nodeVertex*>::iterator j;
			vector<nodeVertex*> tempVert = node->getConnectedVertex();
			vector<nodeEdge*> tempEdge = node->getConnectedEdge();
			for (j=tempVert.begin()+1; j != tempVert.end(); j++) { 
				cout << "-> " << "(" << tempEdge[(j-tempVert.begin())]->getWeight() << ")" << (*j)->getName(); 
        	}
		}
		void printAdjList(){
			vector<nodeVertex*>::iterator i;
			for (i = vertexPtrArr.begin()+1; i != vertexPtrArr.end(); i++) { 
				cout << "\n Adjacency list of vertex " << (*i)->getName() << "\n head "; 
				adjList(*i);
        	} 
        	cout << "\n" << endl;
		}
		void test(int t){
			int indexTest = std::distance(vertexArr.begin(), cariIndex(t));
			nodeVertex *tempVert = new nodeVertex(t);
			cout << "Node : " << t << " Index : " << "-" << " Ptr : "<< tempVert << endl;
			cout << "Node : " << t << " Index : " << indexTest << " Ptr : "<< vertexPtrArr[indexTest] << endl;
		}
};



int main(int argc, char** argv) {
	Graph myGraph;
	cout << "Add Vertex : " << endl;
	myGraph.addVertex(0);
	myGraph.addVertex(1);
	myGraph.addVertex(2);
	myGraph.addVertex(3);
	myGraph.addVertex(4);
	cout << "\n\n Add Edge : " << endl;
	myGraph.addEdge(0,1,3);
	myGraph.addEdge(1,2);
	myGraph.addEdge(2,3,2);
	myGraph.addEdge(1,3,4);
	myGraph.addEdge(0,3,7);
	myGraph.addEdge(3,4,3);
	myGraph.addEdge(0,4,8);
	cout << "\n\n Get Vertex : " << endl;
	cout << "Vertex : " << myGraph.getVertex(3)->getName() << " Alamat : " << myGraph.getVertex(3) << endl;
	cout << "\n\n Get Vertices : " << endl;
	myGraph.getVertices();
	cout << "\n\n inGraph : " << endl;
	myGraph.inGraph(4);
	cout << "\n\n Adjacency List : " << endl;
	myGraph.printAdjList();
	
	return 0;
}
