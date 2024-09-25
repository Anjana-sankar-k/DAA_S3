#include<iostream>
#include<string>
using namespace std;

int max(int x, int y){
	if(x>y){
		return x;
	} else{
		return y;
	}
}

int lcs(string X, string Y, int m, int n){
	int  DP[m+1][n+1];
	for(int i =0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if (i==0 or j==0){
				DP[i][j] = 0;
			} else if(X[i-1]==Y[j-1]){
				DP[i][j]= 1+ DP[i-1][j-1];		
			}else{
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}

		}
	
	}
	return DP[m][n];
}

int main(){
	string main, sub;
	int m,n;
	
	main = "pineapple";
        sub = "apple";
        m = 9;
        n = 5;
        int result = lcs(main, sub, m, n);
        cout<<"the longest common subsequence is of the length "<<result<<endl;
        }
