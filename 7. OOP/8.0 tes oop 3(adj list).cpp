#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
	protected:
		int v;
		list<int> adj[100];
		
	public:	
		Graph (int len){
			v=len;
		}
		void addEdge(int s, int d) {
 			adj[s].push_back(d);
  			adj[d].push_back(s);
		}

		// Print the graph
		void printGraph(int v) {
		  for (int d = 0; d < v; ++d) {
		    cout << "\n Vertex "
		       << d << ":";
		    for (auto x : adj[d])
		      cout << "-> " << x ;
			  cout <<endl;
		  }
		}
		
};
			
int main() {
	
  // Create a graph
  Graph graph1(4);
//  vector<int> adj[];

  // Add edges
  graph1.addEdge(0, 1);
  graph1.addEdge(0, 2);
  graph1.addEdge(1, 2);
  graph1.addEdge(0, 3);
          
  graph1.printGraph(4);
	
}                   