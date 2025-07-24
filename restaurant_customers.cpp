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
    vll l(n), r(n), v;
    unordered_map<ll, ll> ml, mr;
    for(int i = 0; i<n; i++){
        cin>>l[i]>>r[i];
        v.pb(l[i]); v.pb(r[i]);
        ml[l[i]]++;
        mr[r[i]]++;   
    }
    sort(v.begin(), v.end());
    ll idx = v[0], cnt = 0, mxcnt = 0, itr = 0;
    while(itr < 2*n){
        if(ml[idx] > 0){
            cnt += ml[idx];
            ml[idx] = 0;
            mxcnt = max(mxcnt, cnt);
        }
        if(mr[idx] > 0){
            cnt -= mr[idx];
            mr[idx] = 0;
            cnt = max(0ll, cnt);
        }
        itr++;
        idx = v[itr];
    }
    cout<<mxcnt<<endl;
}

// the order doesn't matter, we can just store both left and right values in the same vector, and store them in a map also, that will count the frequency of the elements that entered at that time (since it can be more than 1), then we just iterate through the vector, and then depending upon whether the given value is a left value or right value, it will handle both the cases; then we just output the max cnt; (another neat note is that, it also takes care of duplicacies without having us do anything).
