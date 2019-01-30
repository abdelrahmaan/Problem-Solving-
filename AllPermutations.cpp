#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
//const ll N = 1e9+9 , Max = 600 ;
//const ll M = 1e9+7;
//ll gcd(ll a, ll b) { return !b ? a : gcd(b , a % b); }
//ll lcm(ll x, ll y) { return (x * y / gcd(x, y)); }
//ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
//len any int num > 0 ... len = ceil(log10(a+1));
//ll mo1(ll a , ll b){ return  ( ( (a % M )  * (b % M) ) % M); }
//ll modNum(ll x , ll num){ return  ( ( (x % M )  * (num % M) ) % M); }
//ll mo3(ll x){ return  ( ( (x % M )  * (divisors % M) ) % M); }
const int N = 1e5 +5 , M = 1e4 +5, OO = 1000000007;
int n, A[N], permutation[N], sitted[N];

void solveAP(int idx = 0){
  if(idx == n){
    for(int i = 0 ; i < n ; ++i)
      printf("%d ", permutation[i]);
    puts("");
    return;
  }
  for(int i = 0 ; i < n ; ++i){
    if(!sitted[i]){
      sitted[i] = 1;
      permutation[idx] = A[i];
      solveAP(idx+1);
      sitted[i] = 0;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  solveAP();
  return 0;
}
************************************
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#define all(v) (((v).begin()) , ((v).end()))
using namespace std;
typedef vector<int> vi ;
int main(){
int n;
scanf("%d" , &n);
  string s;
for(int i=0; i<n; ++i){
        cin>>s;
        sort(s.begin(), s.end());
        do{
                cout<<s<<endl;
        }while(next_permutation(s.begin() , s.end()));
            cout<<endl;
        }
      return 0;
}
