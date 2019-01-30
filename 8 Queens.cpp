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
const int N = 1e2+5 , Max = 8, OO = 1000000007;
const double EPS = 0.00001;
int  a , b , sols , t , r[2 * Max] , dL[2 * Max] , dR[2 * Max] , ans[2 * Max];

void printSolution(){
	if(++sols < 9)	printf(" ");
	printf("%d     ", sols);
	for(int r = 0; r < 8; ++r)
		printf(" %d", ans[r]);
	puts("");
}
void init(){
	memset(r  , 0 , sizeof r);
	memset(dR , 0 , sizeof dR);
	memset(dL , 0 , sizeof dL);
	memset(ans, 0 , sizeof ans);
	sols = 0;
	r[a] = dR[a + b] = dL[Max + a - b] = 0;
	ans[b] = a;
}

void Queen8(int col = 0)
{
//    if(col == b){
//            Queen8(col + 1);
//            return;
//    }
    if(col == 8){
            printSolution();
            return;
    }
        for(int row = 0; row < 8; ++row){
            if(!r[row] && !dL[Max + row - col] && !dR[row + col]){
                r[row] = dL[Max + row - col ] = dR[row + col] = 1;
                ans[col] = row;                                               //Do
                Queen8(col + 1);                                             // Rec
                r[row] = dL[Max + row - col ] = dR[row + col] = 0;           // UnDO
            }
        }
}
int main(){
    scanf("%d" ,&t);
   while(t--){
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		scanf("%d %d", &a, &b);
		init();
		Queen8();
		if(t)	puts("");
	}

  return 0;
}


*****************************
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
const int N = 1e2+5 , Max = 8, OO = 1000000007;
const double EPS = 0.00001;
int  a , b , sols , t , r[Max] , dL[2 * Max] , dR[2 * Max] , ans[Max];

void printSolution(){
	if(++sols < 10)	printf(" ");
	printf("%d     ", sols);
	for(int r = 1; r < 9; ++r)
		printf(" %d", ans[r]);
	puts("");
}
void init(){
	memset(r  , 0 , sizeof r);
	memset(dR , 0 , sizeof dR);
	memset(dL , 0 , sizeof dL);
	memset(ans, 0 , sizeof ans);
	sols = 0;
	r[a] = dR[a + b] = dL[Max + a - b] = 0;
	ans[b] = a;
}

void Queen8(int col)
{
//    if(col == b){
//            Queen8(col + 1);
//            return;
//    }
    if(col == 8){
            printSolution();
            return;
    }
        for(int row = 0; row < 8; ++row){
            if(!r[row] && !dL[Max + row - col] && !dR[row + col]){
                r[row] = dL[Max + row - col ] = dR[row + col] = 1;
                ans[col] = row;                                               //Do
                Queen8(col + 1);                                             // Rec
                r[row] = dL[Max + row - col ] = dR[row + col] = 0;           // UnDO
            }
        }
}
int main(){
    scanf("%d" ,&t);
   while(t--){
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		scanf("%d %d", &a, &b);
		init();
		Queen8(0);
		if(t)	puts("");
	}

  return 0;
}

