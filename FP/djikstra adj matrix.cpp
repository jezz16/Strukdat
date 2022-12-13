#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v, int w){
	    adjM[u][v] = w;
	    places[v] = str;
	}

	
	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 100;
		}
		dist[src] = 1;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
	}
	
};
int main(){
	Graph graph(20);
	
	graph.addVertex("rumah", 1, 1, 0);
	graph.addVertex("gor", 1, 2, 3);
	graph.addVertex("gor", 2, 2, 0);
	graph.addVertex("red_mm", 3, 3, 0);
	graph.addVertex("masjid_syuhada", 1, 14, 4);
	graph.addVertex("masjid_syuhada", 14, 14, 0);
	graph.addVertex("red_mm", 2, 3, 4);
	graph.addVertex("pln", 2, 10, 3);
	graph.addVertex("pln", 10, 10, 0);
	graph.addVertex("tugu_s3", 14, 15, 6);
	graph.addVertex("tugu_s3", 17, 15, 5);
	graph.addVertex("pasar", 3, 4, 4);
	graph.addVertex("pasar", 4, 4, 0);
	graph.addVertex("damkar", 3, 9, 5);
	graph.addVertex("damkar", 9, 9, 0);
	graph.addVertex("polres", 10, 11, 4);
	graph.addVertex("polres", 11, 11, 0);
	graph.addVertex("pertamina", 15, 20, 6);
	graph.addVertex("bri", 4, 5, 6);
	graph.addVertex("bri", 5, 5, 0);
	graph.addVertex("rsud", 6, 8, 3);
	graph.addVertex("smp_3", 11, 12, 2);
	graph.addVertex("smp_3", 12, 12, 0);
	graph.addVertex("masjid_agung", 11, 13, 8);
	graph.addVertex("masjid_agung", 8, 13, 3);
	graph.addVertex("satlantas", 11, 16, 6);
	graph.addVertex("satlantas", 16, 16, 0);
	graph.addVertex("bank_nagari", 5, 6, 8);
	graph.addVertex("bank_nagari", 6, 6, 0);
	graph.addVertex("kodim", 16, 17, 4);
	graph.addVertex("kodim", 13, 17, 4);
	graph.addVertex("kodim", 17, 17, 0);
	graph.addVertex("bupati", 13, 19, 5);
	graph.addVertex("bupati", 19, 19, 0);
	graph.addVertex("bakso_solo", 6, 7, 5);
	graph.addVertex("bakso_solo", 7, 7, 0);
	graph.addVertex("pln", 9, 10, 4);
	graph.addVertex("pertamina", 19, 20, 5);
	graph.addVertex("pertamina", 20, 20, 0);
	graph.addVertex("dprd", 19, 18, 5);
	graph.addVertex("dprd", 18, 18, 0);
	
	int src;
	cin >> src;
    graph.djikstra(src);
}