#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define fo(i,n) for (ll i = 0; i < n; i++)
#define vll(v) vector<ll> v(n);
#define vlln(v, n) vector<ll> v(n);
#define vsort(v) sort(v.begin(), v.end())
// (a+b)%n = (a%n + b%n)%n
// (a*b)%n = (a%n * b%n)%n

//4 5 5 5 1 1 2 1
//0 1 2 3 4 5 6 7
//1 1 2 2 3 3 4 4
//4 5 5 1 1 2 2 

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    //idx i -> occur i/2 + 1 times till i
    map<int, int> freq;
    vector<int> b(n);
    b[0] = a[0];
    freq[a[0]]++;
    for(int i=1; i<n-1; i++){
        int req = min(i/2 + 1, freq[a[i-1]]);
        if(freq[a[i]] < req){
            b[i] = a[i];
            freq[b[i]]++;
        }
        else{
            b[i] = a[i+1];
            freq[b[i]]++;
        }
    }
    b[n-1] = a[n-1];
    for(auto it: b){
        cout<<it<<" ";
    }
    cout<<endl;
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