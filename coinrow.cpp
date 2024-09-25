#include<iostream>
using namespace std;

int coinRow(int coins[],int n ){
       	if(n == 0) return 0;
       	if(n == 1) return coins[0];
       	if(n ==2) return max(coins[0],coins[1]);
       	
       	int dp[n];
       	
       	dp[0] = coins[0];
       	dp[1] = max(coins[0],coins[1]);
       	
       	
       	for(int i = 2; i < n; ++i){
       	   dp[i] = max(dp[i - 1],coins[i] + dp[i -2]);
       	}
       	
       	return dp[n-1];
       	
 }
 
 int main(){
     int n;
     int coins[n];
     cout<<"Enter the size of array: "<<endl;
     cin>>n;
     cout<<"Enter the elements of array: "<<endl;
     for(int i = 0; i < n; i++){
     cin>>coins[i];
     }
     
     
     int result = coinRow(coins, n);
     
     cout<<"THe maximum value that can be collected is "<<result<<endl;
     
     return 0;
     
     }   
