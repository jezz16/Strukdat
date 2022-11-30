#include <iostream>
#include <list>
#include <queue>
#include <iterator>

using namespace std;

class Graph {
	protected:
		int vertex;
		list <int> adj[100];
		
		public:
			Graph(int v){
				vertex = v;
			}
			addVertex (int v1, int v2){
				adj[v1].push_back(v2);
			}
			showVertex() {
				for (int i=1; i<=vertex; i++){
					cout << i <<" => ";	
					list <int>::iterator it;
					for (it = adj[i].begin(); it != adj[i].end(); it++){
						cout << *it << " ";
					}
					cout << endl;
				}
			}
};

int main() {
	Graph graph(20);
	graph.addVertex(1, 1);
	graph.addVertex(1, 2);
	graph.addVertex(1, 14);
	graph.addVertex(2, 3);
	graph.addVertex(2, 10);
	graph.addVertex(14, 15);
	graph.addVertex(17, 15);
	graph.addVertex(3, 4);
	graph.addVertex(3, 9);
	graph.addVertex(10, 11);
	graph.addVertex(15, 20);
	graph.addVertex(4, 5);
	graph.addVertex(6, 8);
	graph.addVertex(11, 12);
	graph.addVertex(11, 13);
	graph.addVertex(8, 13);
	graph.addVertex(11, 16);
	graph.addVertex(5, 6);
	graph.addVertex(16, 17);
	graph.addVertex(13, 17);
	graph.addVertex(13, 19);
	graph.addVertex(6, 7);
	graph.addVertex(9, 10);
	graph.addVertex(19, 20);
	graph.addVertex(19, 18);
	
	graph.showVertex();
}