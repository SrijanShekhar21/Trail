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

void solve(){
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(i + j == n)cnt++;
        }
    }
    cout<<cnt<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}