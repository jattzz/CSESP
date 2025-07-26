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
    // ll sum = 0;
    // for(int i = 0; i<n; i++){
    //     cin>>v[i];
    //     sum += v[i];
    // }
    // long double temp = ((1.0*sum)/(1.0*n)) + 0.5;
    // ll avg = temp;
    // ll res = 0;
    // cout<<sum<<" "<<avg<<" "<<temp<<endl;
    // for(auto i: v){
    //     res += abs(i - avg);
    // }
    // cout<<res<<endl;
    for(auto &i: v) cin>>i;
    sort(v.begin(), v.end());
    ll md = v[n/2], res = 0;
    for(auto i: v) res += abs(md - i);
    cout<<res<<endl;
}

// turns out, trying to make them all equal to their average is the wrong appraoch, instead we just have to find the median, and increment the difference of each element and the median in to the res container.
// reason => check out, 1 25 25; the median is 25, and hence the res would be 24. However, making them all equal to their average ie 17, would lead to 32 result. 
// the only time where the average will give correct result is when the difference between the elements is uniform (or just pure luck in some cases).
