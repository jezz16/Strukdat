#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
	vector<bool> visited_dfs;
	vector<bool> visited;
public:
Graph(int v){
	V = v+1;
	visited_dfs.resize(V,false);
	visited.resize(V,false);
}

void addVertex(string str, int v1, int v2){
	adj[v1].push_back(make_pair(v2, str));
	
}

int flag = 0;
void dfs(int source, string destination){
	
	visited[source] = true;
	const char *c = adj[source].front().second.c_str();
	const char *d = destination.c_str();
	cout << c << " -> ";
	if(strcmp(c, d) == 0) {
		flag = 1;
		return;
	}
	else {
		for(auto const &i: adj[source]){	
			if(flag == 1) return;
			else if(!visited[i.first]) dfs(i.first, destination);
		}
	}
}


void dfs_no_destination(int source){
	visited_dfs[source] = true;
	const char *c = adj[source].front().second.c_str();
	cout << c << " -> ";
	for(auto const &i: adj[source]){	
		if(!visited_dfs[i.first]) dfs_no_destination(i.first);
	}
}

};
int main(){
	Graph graph(20);
	
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("gor", 1, 2);
	graph.addVertex("gor", 2, 2);
	graph.addVertex("red_mm", 3, 3);
	graph.addVertex("masjid_syuhada", 1, 14);
	graph.addVertex("masjid_syuhada", 14, 14);
	graph.addVertex("red_mm", 2, 3);
	graph.addVertex("pln", 2, 10);
	graph.addVertex("pln", 10, 10);
	graph.addVertex("tugu_s3", 14, 15);
	graph.addVertex("tugu_s3", 17, 15);
	graph.addVertex("pasar", 3, 4);
	graph.addVertex("pasar", 4, 4);
	graph.addVertex("damkar", 3, 9);
	graph.addVertex("damkar", 9, 9);
	graph.addVertex("polres", 10, 11);
	graph.addVertex("polres", 11, 11);
	graph.addVertex("pertamina", 15, 20);
	graph.addVertex("bri", 4, 5);
	graph.addVertex("bri", 5, 5);
	graph.addVertex("rsud", 6, 8);
	graph.addVertex("smp_3", 11, 12);
	graph.addVertex("smp_3", 12, 12);
	graph.addVertex("masjid_agung", 11, 13);
	graph.addVertex("masjid_agung", 8, 13);
	graph.addVertex("satlantas", 11, 16);
	graph.addVertex("satlantas", 16, 16);
	graph.addVertex("bank_nagari", 5, 6);
	graph.addVertex("bank_nagari", 6, 6);
	graph.addVertex("kodim", 16, 17);
	graph.addVertex("kodim", 13, 17);
	graph.addVertex("kodim", 17, 17);
	graph.addVertex("bupati", 13, 19);
	graph.addVertex("bupati", 19, 19);
	graph.addVertex("bakso_solo", 6, 7);
	graph.addVertex("bakso_solo", 7, 7);
	graph.addVertex("pln", 9, 10);
	graph.addVertex("pertamina", 19, 20);
	graph.addVertex("pertamina", 20, 20);
	graph.addVertex("dprd", 19, 18);
	graph.addVertex("dprd", 18, 18);
	
 	cout << "DFS no destination" << endl;
 	graph.dfs_no_destination(1);
 	cout << "\n\nDFS" << endl;
 	
	int src;
 	string dest;
 	cout << "Input asal : ";
 	cin >> src;
 	cout << "Input tujuan : ";
 	cin >> dest;
 	graph.dfs(src, dest);
}