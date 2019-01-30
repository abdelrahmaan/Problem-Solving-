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
const int N = 1e2+5 , M = 1e1, OO = 1000000007;
const double EPS = 0.00001;
int n;
bool r[N] , dL[2*N] , dR[2*N] , table[N][N];

bool solveNQ(int col =0)
{
    if(col >= n) return 1;
        for(int row = 0; row < n; ++row){
            if(!r[row] && !dL[row - col + 2 * N + 5] && !dR[row + col]){
                r[row] = dL[row - col +2 * N + 5] = dR[row + col] = table[row][col] = 1;           // Do
                if(solveNQ(col + 1))    return 1;                                                 // Rec
                r[row] = dL[row - col + 2 * N + 5] = dR[row + col] = table[row][col] = 0;        // UnDO
            }
        }
    return 0;
}
int main(){
    scanf("%d" ,&n);
    if(solveNQ()){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
             printf("%c"  ,table[i][j] ? 'Q': '.' );
            }
             puts("");
        }
    }else
    puts("No Answer");
  return 0;
}

