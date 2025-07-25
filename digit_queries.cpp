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
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll noDigits = 1, base = 9;
        while(n - (base*noDigits) > 0){
            // cout<<n<<" "<<noDigits<<" "<<base<<endl;
            n -= (base*noDigits);
            base *= 10;
            noDigits++;
        }
        // cout<<"->"<<n<<" "<<noDigits<<endl;
        ll idx = n%noDigits;
        ll number = power(10, noDigits-1) + ((n - 1)/noDigits);
        // cout<<idx<<" "<<number<<endl;
        if(idx>0){
            for(int i = 0; i<noDigits-idx; i++){
                number /= 10;
            }
        }
        cout<<(number%10)<<endl;
    }
}

// 1, 2, 3, 4, 5, 6, 7, 8, 9 => 9
// 10, 11, 12


// another simpler/smarter implementation, similar logic
// int base = 9;
// long digits = 1;
// while (n - base * digits > 0) {
//     n -= base * digits;
//     base *= 10;
//     digits++;
// }

// int index = (n - 1) % digits;
// int offset = (n - 1) / digits;
// long start = pow(10, digits - 1);
// return to_string(start + offset)[index] - '0';

// first we identify the number of digits the number has, then we identify the index of the digit we want, and then we identify which number it actually is.
