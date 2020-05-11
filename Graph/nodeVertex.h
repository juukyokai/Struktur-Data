#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "nodeEdge.h"

using namespace std;

class nodeVertex{
	private:
		int vertexName;
		vector<nodeEdge*> connectedEdge;
		vector<nodeVertex*> connectedVertex;
		
	public :
		//constructor
		nodeVertex(int name){
			vertexName = name;
			connectedEdge.push_back(0);
			connectedVertex.push_back(0);
		}
		nodeVertex(int name, nodeEdge* ne, nodeVertex* nv){
			vertexName = name;
			connectedEdge.push_back(ne);
			connectedVertex.push_back(nv);
		}
		//setter
		void setName(int name){
			vertexName = name;
		}
		void setConnectedEdge(nodeEdge* ne){
			cout << "Connecting Edge..." << endl;
			connectedEdge.push_back(ne);
		}
		void setConnectedVertex(nodeVertex* nv){
			cout << "Connecting Vertex to " << nv->getName() << "..." << endl;
			connectedVertex.push_back(nv);
		}
		//getter
		int getName(){
			return vertexName;
		}
		vector<nodeEdge*> getConnectedEdge(){
			return connectedEdge;
		}
		vector<nodeVertex*> getConnectedVertex(){
			return connectedVertex;
		}
};
