#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define fo(i,n) for (ll i = 0; i < n; i++)
#define vll(v) vector<ll> v(n);
#define vlln(v, n) vector<ll> v(n);
#define vsort(v) sort(v.begin(), v.end())
// (a+b)%n = (a%n + b%n)%n
// (a*b)%n = (a%n * b%n)%n

int rectified(int x, int n){
    if(x == n+1)return 1;
    if(x == 0)return n;
    return x;
}

int mex(vector<int> &a) {
    vector<bool> f(a.size() + 1, 0);
    for (int i : a) if (i <= (int) a.size()) f[i] = 1;
    int mex = 0;
    while (f[mex]) ++mex;
    return mex;
}

void dfs(int i, vector<int>& ans, vector<vector<int>>& adj){
    vector<int> temp;
    for(auto it: adj[i]){
        temp.push_back(ans[it]);
    }
    int new_mex = mex(temp);
    if(ans[i] == new_mex)return;
    ans[i] = new_mex;
    for(auto it: adj[i]){
        dfs(it, ans, adj);
    }
}

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<=n; i++){
        int u = rectified(i+1, n);
        int v = rectified(i-1, n);
        adj[i].push_back(u);
        adj[i].push_back(v);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    adj[x].push_back(y);
    adj[y].push_back(x);

    vector<int> ans(n+1, n+1);

    for(int i=1; i<=n; i++){
        dfs(i, ans, adj);
    }

    //print ans
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}