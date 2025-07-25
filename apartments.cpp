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
    ll n, m, k; cin>>n>>m>>k;
    vll cand(n), apart(m);
    for(auto &i: cand) cin>>i;
    for(auto &i: apart) cin>>i;
    sort(cand.begin(), cand.end());
    sort(apart.begin(), apart.end());
    ll l = 0, r = 0, res = 0;
    while((l<n) && (r<m)){
        if(abs(cand[l]-apart[r])<=k){
            res++;
            l++; r++;
        }
        else if(cand[l]<apart[r]){
            l++;
        }
        else r++;
    }
    cout<<res<<endl;
}


// just sort the vectors and use 2 pointers from the left of both to check whether an apartment can be allocated, if not, then check whether its because of desired size being too small or too big, 
// if the desired size is too small, then since the pointer is already at the smallest allocatable apartment, we just move to the next candidate.
// similarly if its too large then we move to the next apartment;
