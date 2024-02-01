//TechCoder
#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int jump(int ind,int n,int arr[]){
  if(ind==n-1) return 0;
  if(dp[ind]!=-1) return dp[ind];
  int left=abs(arr[ind]-arr[ind+1])+jump(ind+1,n,arr);
  int right=INT_MAX;
  if(ind+2<=n-1){
    right=abs(arr[ind]-arr[ind+2])+jump(ind+2,n,arr);
  }
  return dp[ind]=min(left,right);
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<jump(0,n,arr);
}
