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
    ll n, m; cin>>n>>m;
    multiset<ll> tickets;
    for(int i = 0; i<n; i++){
        ll x; cin>>x;
        tickets.insert(x);
    }
    for(int i = 0; i<m; i++){
        ll temp; cin>>temp;
        auto it = tickets.ub(temp);
        if(it == tickets.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<(*it)<<endl;
            tickets.erase(it);
        }
    }
}


// just learned that, the generic upper bound syntax (ie. upperbound(container.begin(), container.end(), x)) can and should only be used on linear containers, namely, vectors and arrays, and in some cases deque, but sets, multisets, maps etc follow a heap/tree like structure, that have both forward and backward iterators, hence there if we use this standard upperbound syntax, the search will be linear rather than logarithmic. Instead, for such containers, we should always use only the specified specially tailored upper_bound search, that is container_name.upper_bound(); 

// also, multisets use a red-black tree in the backend to store the elements.

// also, the generic upper bound can only be applied on data structures with random access, since sets, maps etc dont have that, it leads to o(n);
