#include<iostream>
using namespace std;

#define MAX_EDGES 100
#define MAX_NODES 100

struct Edge{
	int u,v, weight;
};

void sortEdge(Edge edges[], int E){
	for(int i = 0; i < E-1; i++){
		for(int j = 0; j < E - i - 1;j++){
			if(edges[j].weight >edges[j + 1].weight){
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j+1] = temp;
			
			}
		}
	}
}

int find(int parent[], int x){
	if(parent[x] != x){
		parent[x] = find(parent, parent[x]);
	}
	return parent[x];
}

void unionSets(int parent[], int x, int y){
	int rootX = find(parent, x);
	int rootY = find(parent, y);
	parent[rootX] = rootY;
}

void kruskalMST(Edge edges[], int V, int E){
	sortEdge(edges, E);
	
	int parent[MAX_NODES];
	for(int i = 0; i < V; i++){
		parent[i] = i;
	}
	
	int mstWeight = 0; 
	cout<<"Edges in MST: \n";
	
	for(int i = 0; i < E; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int weight = edges[i].weight;
		
		if(find(parent,u) != find(parent, v)){
			cout<<u<<" - "<<v<<" : "<<weight<< "\n";
			mstWeight += weight;
			unionSets(parent, u, v);
		}
	}
	
	cout<<"total weight of MST: "<< mstWeight <<endl;
}

int main(){
	int V,E;
	Edge edges[MAX_EDGES];
	
	cout<<"Enter number of vertices and edges: ";
	cin>>V>>E;
	
	cout<<"Enter edges(u,v,weight): \n";
	for(int i = 0; i < E; i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].weight;
	}
	
	kruskalMST(edges, V,E);
	
	return 0;
}
