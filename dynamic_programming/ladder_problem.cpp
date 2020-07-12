#include <iostream>
using namespace std;

// Recursion O(k^n)
int ways(int n){
	// Ground
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans = ways(n-1) + ways(n-2) + ways(n-3);
	return ans;
}

int ways2(int n, int k){
	// Ground
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans = 0;
	for(int j=0;j<=k;j++)
		ans+=ways(n-j,k);
	return ans;
}

// Top Down DP
int topDownDP(int n, int k, int *dp){
	if(n==0)
		dp[n]=1;
	if(dp[n]!==-1)
		return dp[n];
	for(int j=0;j<=k;j++)
		dp[j]+=topDownDP(n-j,k,dp);
	return dp[n];
}


// Bottom Up DP O(k*n), also possible in O(n) by sliding window method dp[n+1]=dp[n]+dp[n]-dp[n-k]
int bottomUpDP(int n,int k){
	int *dp =new int[n];
	dp[0]=1;
	for(int step=1;step<=n;step++){
		dp[step]=0;
		for(int j=0;j<=k;j++)
			if(step-j>=0)
				dp[step]+=dp[step-j];
	}
	return dp[n];
}

// int bottomUpDPOptimized(int n, int k){
// 	int *dp=new int[n];
// 	dp[0]=1;
// 	for(int step=k;step<=n;step++){
// 		dp[step+1]=2*dp[step]-dp[step-k];
// 	}
// 	return dp[n];
// }

int main()
{
	cout<<ways(4)<<endl;
	cout<<ways2(5,3)<<endl;

	cout<<bottomUpDP(5,3)<<endl;
	cout<<bottomUpDPOptimized(5,3)<<endl;

	cin>>n;
	int *dp[5];
	for(int i=0;i<=5;i++)
		dp[i]=-1;
	cout<<topDownDP(5,3,dp)<<endl;
	return 0;
}