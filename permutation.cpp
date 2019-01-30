#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6+6 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX =  1000 , OO = 0x3f3f3f3f , MOD = 1e9  , inf =  1 << 30;
const ll INF = (ll)1e18;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
//int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
//int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
int X[] = {0 , 0  , 1 , -1 };
int Y[] = {1 , -1 , 0 , 0 };
//len any int num > 0 ... len = ceil(log10(a+1));
//len any int num > 0 ... len = ceil(log10(a+1));
int n , len , vis[N] , cur[N];
string s;

void perm(int i , int n ,  int vis[] , int cur[]){  // BackTracking
    if(i == n){
        for(int j = 0  ; j < n ; ++j)   cout << cur[j];
        puts("");
        return ;
    }
    for(int j = 0 ;  j < n ; ++j)
    if(!vis[j]){
        vis[j] = 1; // do
        cur[i] = j;
        perm(i+1 , n , vis , cur); // rec
        vis[j] = 0 ; // undo
    }
}
void printPer(int len , string s){
    sort(s.begin() , s.end());
    cout << s << endl;
    while(next_permutation(s.begin() , s.end())){
        for(int  i = 0 ; i < len ; ++i) cout << s[i];
        puts("");
    }
    s = "";
    puts("");
}
int main(){
    cin >> s;
    len = s.size();
    puts("");
    printPer(len , s);
	return 0;

}
