#include <iostream>


using namespace std;

class nodeEdge{
	private:
		int weight;
		
	public:
		//constructor
		nodeEdge(){
			weight = 1;
			
		}
		nodeEdge(int w){
			weight = w;
			
		}
		//setter
		void setWeight(int w){
			weight = w;
		}
		
		//getter
		int getWeight(){
			return weight;
		}
		
};


