#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

class Graph {
    protected:
        int V;
        int arr[100][100];
    
    public:
        Graph(int v){
            V = v;
            for (int i = 0; i <= v; i++)
            {
                for (int j = 0; j <= v; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        
        
        addVertex(int v1, int v2){
            arr[v1][v2] = 1;
            }

        showGraph(){
            cout << "===Show Graph===" << endl;
            cout << "    ";
            for (int k = 1; k <= V; k++)
            {
                cout << k << " ";
                if(k<10) cout << " ";
            }

            cout << endl;
            
            for (int i = 1; i <= V; i++){
                cout << i << "  ";
                if(i<10) cout << " ";
                for (int j = 1; j <= V; j++)
                {
                    cout << arr[i][j] << "  ";
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
  
    graph.showGraph();

}