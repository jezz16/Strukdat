#include <bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string place[21];
	
public:
	Graph(int v){
		V = v;
	}

	void addVertex(string str, int v1, int v2){
		adjM[v1][v2] = 1;
		place[v2] = str;
	}
	
	
	void bfs(string startVertex, string destination){
		bool visited[21] = {false};
		queue<int> q;
		q.push(1);
		visited[1] = true;
		while(!q.empty()){
			int flag = 0;
			for(int i = 1; i<= 20; i++){
				if(!visited[i]){
					visited[i] = true;
					q.push(i);
				}
			}
			const char *d = destination.c_str();
			const char *c = place[q.front()].c_str();
			cout << place[q.front()] << " -> ";
			q.pop();
			if(strcmp(d, c)==0) break;
		}
	}
	
	void bfs_no_destination(string startVertex){
		bool visited[21] = {false};
		queue<int> q;
		q.push(1);
		visited[1] = true;
		while(!q.empty()){
			int flag = 0;
			for(int i = 1; i<= 20; i++){
				if(!visited[i]){
					visited[i] = true;
					q.push(i);
				}
			}
			cout << place[q.front()] << " -> ";
			q.pop();
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
	
	cout << "BFS no destination" << endl;
 	graph.bfs_no_destination("rumah");
	cout << "\n\nBFS" << endl;
 	graph.bfs("rumah", "red mm");

}