#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[3001][3001];
double fun(ll n,ll x,vector<double>& v){
    if(x==0) return 1.0;
    if(n==0) return 0.0;
    if(dp[n][x]!=-1.0) return dp[n][x];
    return dp[n][x]=v[n-1]*fun(n-1,x-1,v)+(1-v[n-1])*fun(n-1,x,v);
}

int main(){
    ll n,x;
    cin>>n;
    x=(n+1)/2;
    vector<double> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++) dp[i][j]=-1.0;
    }
    double ans=fun(n,x,v);
    cout<<setprecision(10)<<ans<<"\n";
}
