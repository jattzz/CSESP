#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int> 
#define vll vector<long long>
#define pii pair<int, int> 
#define pic pair<int, char> 
#define mii map<int, int> 
#define mll map<long long, long long>
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sumup(v) accumulate(v.begin(), v.end(), 0)
#define ull unsigned long long int
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define cinv for(auto &i: v) cin>>i
ll power(ll x, ull y){
    if(y==0){
        return 1;
    }
    ll temp = power(x, y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}

vector<string> get(ll n, ll len){
    if(n == 1) return {"0", "1"};
    vector<string> temp = get(n-1, len/2);
    vector<string> res;
    for(int i = 0; i<len/2; i++){
        res.pb("0" + temp[i]);
    }
    for(int i = (len/2)-1; i>=0; i--){
        res.pb("1" + temp[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    ll len = power(2, n);
    vector<string> res = get(n, len);
    for(auto i: res) cout<<i<<endl;
}