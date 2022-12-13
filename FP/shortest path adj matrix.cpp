#include <bits/stdc++.h>

using namespace std;

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
	
	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}
	
	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " => " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }
    
    void shortestDistance(int src, int dest){
		int pred[V], dist[V];
		shortest_path(src, dest, pred, dist);
		vector<int> path;
		int c = dest;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		cout<<endl;
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " = " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("gor", 1, 2);
	graph.addVertex("masjid_syuhada", 1, 14);
	graph.addVertex("red_mm", 2, 3);
	graph.addVertex("pln", 2, 10);
	graph.addVertex("tugu_s3", 14, 15);
	graph.addVertex("tugu_s3", 17, 15);
	graph.addVertex("pasar", 3, 4);
	graph.addVertex("damkar", 3, 9);
	graph.addVertex("polres", 10, 11);
	graph.addVertex("pertamina", 15, 20);
	graph.addVertex("bri", 4, 5);
	graph.addVertex("rsud", 6, 8);
	graph.addVertex("smp_3", 11, 12);
	graph.addVertex("masjid_agung", 11, 13);
	graph.addVertex("masjid_agung", 8, 13);
	graph.addVertex("satlantas", 11, 16);
	graph.addVertex("bank nagari", 5, 6);
	graph.addVertex("kodim", 16, 17);
	graph.addVertex("kodim", 13, 17);
	graph.addVertex("bupati", 13, 19);
	graph.addVertex("bakso_solo", 6, 7);
	graph.addVertex("pln", 9, 10);
	graph.addVertex("pertamina", 19, 20);
	graph.addVertex("dprd", 19, 18);
	
	int src, dest;
	cout << "Input asal : ";
	cin >> src ;
	cout << "Input tujuan : ";
	cin >> dest;
    graph.shortestDistance(src,dest);
}