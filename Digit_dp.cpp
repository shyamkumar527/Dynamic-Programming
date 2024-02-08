#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long a,b,d,k;
vector<int> v;
ll dp[10][12][2];

ll fun(ll pos,ll c,int f){
    if(c>k) return 0;
    if(pos>=v.size()){
        if(c==k) return 1;
        else return 0;
    }
    if(dp[pos][c][f]!=-1) return dp[pos][c][f];
    ll res=0;
    int lim;
    if(f==0) lim=v[pos];
    else lim=9;
    for(int i=0;i<=lim;i++){
        ll nf=f, nc=c;
        if(i==d) nc++;
        if(f==0 and i<lim) nf=1;
        if(nc<=k) res+=fun(pos+1,nc,nf);
    }
    return dp[pos][c][f]=res;
}
ll solve(int b){
    v.clear();
    while(b){
        v.push_back(b%10);
        b/=10;
    }
    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    ll res=fun(0,0,0);
    return res;
}
int main(){
    cin>>a>>b>>d>>k;
    ll ans= solve(b) - solve(a-1);
    cout<<ans;
}
