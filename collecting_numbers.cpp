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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vll v(n);
    ll cnt = 0;
    for(auto &i: v) cin>>i;
    unordered_map<ll, ll> m;
    for(int i = 0; i<n; i++){
        ll temp = v[i];
        if(m[temp-1] == 0){
            cnt++;
        }
        m[temp] = 1;
    }
    cout<<cnt<<endl;
}

// 5 4 3 1 2

// first try ez; for each element 'x' in the vector, check whether 'x-1' has already occured or not, if yes, then continue since it will be picked up in that same go, else increment by 1, since you will have to 
// start picking from the front again.
