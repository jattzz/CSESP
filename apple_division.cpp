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

ll n;
vll v;

ll mindiffCal(ll idx, ll tempSum1, ll tempSum2, vector<ll> &v){
    if(idx == n){
        return abs(tempSum1 - tempSum2);
    }
    ll ch = mindiffCal(idx + 1, tempSum1 + v[idx], tempSum2, v);
    ll nc = mindiffCal(idx + 1, tempSum1, tempSum2 + v[idx], v);
    return min(ch, nc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    v.resize(n);
    for(auto &i: v) cin>>i;
    ll res = mindiffCal(0ll, 0ll, 0ll, v);
    cout<<res<<endl;
}

// since the constraint for n is very lenient, we should exploit that. Just make a recursive function that keeps track of sum of elements in set 1 and set 2, and just return the min. difference. 
