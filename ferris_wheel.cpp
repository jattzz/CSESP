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
    sort(v.begin(), v.end());
    ll l = 0, r = n-1, cnt = 0;
    while(l<=r){
        if(l == r){
            cnt++;
            break;
        }
        if(v[l] + v[r] <= x){
            l++;
            r--;
            cnt++;
        }
        else{
            r--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

// since, each gondola can only have 1 or 2 children, we can just sort the vector, and then use two pointer to try and pair up the heaviest and the lightest kid, if not possible then only cater the heavier kid. ez
