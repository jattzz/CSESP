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
    ll sum = (n*(n+1))/2;
    if(sum%2){
        cout<<"NO"<<endl;
        return 0;
    }
    sum /= 2;
    set<ll> s1, s2;
    for(int i = n; i>=1; i--){
        if(sum >= i){
            sum -= i;
            s1.insert(i);
        }
        else s2.insert(i);
    }
    cout<<"YES"<<endl;
    cout<<s1.size()<<endl;
    for(auto i: s1) cout<<i<<" ";
    cout<<endl<<s2.size()<<endl;
    for(auto i: s2) cout<<i<<" ";
    cout<<endl;
}


// for any given n, just calculate the sum of first n natural no.s and then if the sum id odd, we can just return "no", else we can just start iterating from the last element and if the element is less than temp where temp
// is initially equal to sum/2, is temp is larger than the iterator, then we subtract iterator from the temp, and insert it in a set, else in another set.
