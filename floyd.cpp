#include <iostream>
using namespace std;

const int INF = 10001;
const int V = 4;

void floydWarshall(int dist[V][V]){
	for(int k = 0; k < V; k++){
		for(int i = 0;i < V;i++){
			for(int j =0; j < V; j++){
				if(dist[i][k] != INF && dist[k][j] != INF){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}

void printSolution(int dist[V][V]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(dist[i][j] == INF){
				cout<<"INF";
			} else{
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}


