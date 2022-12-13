#include <bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	bool visited_dfs[21] = {false};
	bool visited_dfs_no_dest[21] = {false};
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string place[21];
	
public:
	Graph(int v){
		V = v+1;
	}	
	
	void addVertex(string str, int v1, int v2){
		adjM[v1][v2] = 1;
		place[v2] = str;
	}
	
	int flag = 0;
	void dfs(int source, string destination){
		visited_dfs[source] = true;
		const char *d = destination.c_str();
		const char *c = place[source].c_str();
		cout << c << " -> ";
		if(strcmp(c, d) == 0) {
			flag = 1;
			return;
		}
		for(int i = 1;i<=V;i++){
		    if(flag == 1) return;
			else if ((!visited_dfs[i]) && adjM[source][i] == 1) dfs(i, destination);
		}
	}
	void dfs_no_destination(int source){
		visited_dfs_no_dest[source] = true;
		const char *c = place[source].c_str();
		cout << c << " -> ";
		for(int i = 1;i<=V;i++){
			if ((!visited_dfs_no_dest[i]) && adjM[source][i] == 1) dfs_no_destination(i);
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
	graph.addVertex("bank_nagari", 5, 6);
	graph.addVertex("kodim", 16, 17);
	graph.addVertex("kodim", 13, 17);
	graph.addVertex("bupati", 13, 19);
	graph.addVertex("bakso_solo", 6, 7);
	graph.addVertex("pln", 9, 10);
	graph.addVertex("pertamina", 19, 20);
	graph.addVertex("dprd", 19, 18);
	
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