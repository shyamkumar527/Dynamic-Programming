//TechCoder
#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int jump(int ind,int n,int k,int arr[]){
  if(ind==n-1) return 0;
  if(dp[ind]!=-1) return dp[ind];
  int ans=INT_MAX;
  for(int i=1;i<=k;i++){
      if(ind+i<=n-1){
          ans=min(ans,abs(arr[ind]-arr[ind+i])+jump(ind+i,n,k,arr));
      }
  }
  return dp[ind]=ans;
}
int main(){
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<jump(0,n,k,arr);
}
