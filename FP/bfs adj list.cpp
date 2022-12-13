#include <bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
	vector<bool> visited;
	
	public:
	Graph(int v){
		V = v;
		visited.resize(V,false);
	}
	
	addVertex(string str, int v1, int v2){
		adj[v1].push_back(make_pair(v2, str));
	}
	
			
	void bfs_no_dest(string startVertex){
		vector<bool> visited;
		visited.resize(V,false);
		queue<pair<int, string>> q;
		q.push(make_pair(1, startVertex));
		visited[1] = true;
		while(!q.empty()){
			for(auto const &i: adj[q.front().first]){
				if(!visited[i.first]){
					visited[i.first] = true;
					q.push(make_pair(i.first, i.second));
				}
			}
			cout << q.front().second << " -> ";
			q.pop();
		}
	}
	void bfs(string startVertex, string destination){
		vector<bool> visited;
		visited.resize(V,false);
		queue<pair<int, string>> q;
		q.push(make_pair(1, startVertex));
		visited[1] = true;
		while(!q.empty()){
			for(auto const &i: adj[q.front().first]){
				if(!visited[i.first]){
					visited[i.first] = true;
					q.push(make_pair(i.first, i.second));
				}
			}
			cout << q.front().second << " -> ";
			const char *c = q.front().second.c_str();
			const char *d = destination.c_str();
			q.pop();
			if(strcmp(c, d) == 0) break;
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
	
	cout << "BFS no destination" << endl;
 	graph.bfs_no_dest("rumah");
	cout << "\n\nBFS" << endl;
	graph.bfs("rumah", "pertamina");
	
}