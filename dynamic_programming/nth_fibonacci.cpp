#include <iostream>
using namespace std;

// Recursion O(2^n)T O(n)S
int fib(int n){
	if(n==0||n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

// Top Down DP = Recursion + Memoization O(n) O(n)S
int topdownDP(int n, int* dp){
	if(n==0||n==1){
		dp[n]=n;
		return n;
	}

	//Already computed
	if(dp[n]!=-1)
		return dp[n];
	else{
		dp[n]=topdownDP(n-1,dp)+topdownDP(n-2,dp);
		return dp[n];
	}
}

// Bottom up Approach = Iterative (Linear DP) O(n),also possible from O(1)  O(n)S
int bottomupDP(int n){
	int *dp = new int[n];
	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++)
		dp[i] = dp[i-1]+dp[i-2];
	return dp[n];
}

int main(){
	cout<<fib(5)<<endl;

	int dp[100];
	for(int i =0;i<100;i++)
		dp[i]=-1;
	cout<<topdownDP(5,dp)<<endl;
	cout<<bottomupDP(5)<<endl;
	return 0;
}