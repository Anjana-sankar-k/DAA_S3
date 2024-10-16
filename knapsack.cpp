#include<iostream>
using namespace std;

int knapsack(int W, int w[], int v[], int n){
	int K[100][100];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(i == 0 || j == 0){
				K[i][j] = 0;
				}
			else if(w[i - 1] <= j){
				K[i][j] = max(K[i - 1][j], v[i - 1] + K[i - 1][j - w[i - 1]]);
			}
			else{
				K[i][j] = K[i - 1][j];
			}
		}
	}
	return K[n][W];	
}

int main(){

int n = 4;
int W = 7;
int w[] = {1,3,4,5};
int v[] = {1,4,5,7};

cout<<"Maximum value is knapsack: "<<knapsack(W,w,v,n)<<endl;


}
