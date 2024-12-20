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
    ll m,a,b,c;
    cin>>m>>a>>b>>c;
    int ans = 0;
    if(a > m){
        ans += m;
        if(b > m){
            ans += m;
        }
        else{
            ans += b + min(c, m-b);
            //seats left = m - b
        }
    }
    else{
        ans += a;
        if(c >= m-a){
            ans += m-a;
            c = c - m + a;
            if(b > m){
                ans += m;
            }
            else{
                ans += b + min(c, m-b);
            }
        }
        else{
            ans += c;
            c = 0;
            ans += min(b, m);
        }
    }
    cout<<ans<<endl;
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