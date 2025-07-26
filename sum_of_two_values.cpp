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
    ll n, x; cin>>n>>x;
    vll v(n);
    for(auto &i: v) cin>>i;
    unordered_map<ll, ll> m;
    for(int i = 0; i<n; i++){
        if((x - v[i]) < 0) continue;
        if(m[x - v[i]] > 0){
            cout<<m[x-v[i]]<<" "<<i+1<<endl;
            return 0;
        }
        m[v[i]] = i + 1;
    }
    cout<<"IMPOSSIBLE"<<endl;
}

// almost the same as two sum, with the only twist being that the elements are of size 1e9 so we cant use hash array and moreover, we have to return the index of both elements that add up to the target value.
// so we can just maintain an unordered_map to store the elements and match them with their indexes, and keep looking for target - current vaue
