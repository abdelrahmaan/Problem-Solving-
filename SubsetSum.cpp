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
const int N = 1e2 +5 , M = 1e4 +5, OO = 1000000007;
int n, A[N], k;
vector<int> solution;

void printSubset(){
  for(int q : solution)
    printf("%d ", q);
  puts("");
}

bool solveSS(int i = 0, int sum = 0){
  if(sum == k)  return 1;
  if(i==n)  return 0;
  if(sum+A[i]<=k){
    solution.push_back(A[i]);
    if(solveSS(i+1, sum+A[i]))  return 1;
    solution.pop_back();
  }
  if(solveSS(i+1, sum))  return 1;
  return 0;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d %d", &n, &k);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  if(solveSS())
    printSubset();
  else
    printf("No Solution\n");
  return 0;
}
