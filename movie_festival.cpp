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
    vector<pair<ll, ll>> v(n);
    for(auto &i: v){
        cin>>i.first>>i.second;
    }
    sort(v.begin(), v.end(), [](const pair<ll, ll> &i, const pair<ll, ll> &j){
        return i.second<j.second;
    });
    ll t = 0, cnt = 0;
    for(int i = 0; i<n; i++){
        if(v[i].first >= t){
            cnt++;
            t = v[i].second;
        }
    }
    cout<<cnt<<endl;
}


// The right apporach is to sort the vector comparing the second element of the pair, rather than the first one. Since, the correct max ans will always have, in order of watching, ascending order of movie's ending time. Hence, we can just sort it acc. to that in the beginning and then check according to first element, whether we can watch it, and then update our time 't'. This also takes care of greedy cases since, the next entry in the movie will definitely have the second element greater than the previous one. Leading to the max cnt.
