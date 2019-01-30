#include <bits/stdc++.h>
#define ll long long
#define cost first
#define id second
#define f first
#define s second
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6+6 ,  nBits = 2e8 +5 , MM = (1 << 16) , MAX =  1111 , OO = 0x3f3f3f3f , MOD = 1e9+7  , inf =  1 << 30;
const ll INF = (ll)1e18;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
//bool valid (int i , int j){ return i >= 0 && j >= 0 && i < n && j < m ;}
//int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
//int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//len any int num > 0 ... len = ceil(log10(a+1));
//len any int num > 0 ... len = ceil(log10(a+1));
int t , n  , q ,x , y , minii = N , maxii = -N , num , p  , freq[N] , A[N] , a, b , ans;
bool f;
string s;
vector<int>v;
void sS(const string& s) { // s ==> string which read from it
    istringstream is(s);
//    vector< int > v; // Vector to store data
    int tmp;
    while(is >> tmp) {v.push_back(tmp); }
    return tmp;
}
int main(){
    getline(cin , s);
    sS(s);
    for(int x : v)  cout << x << endl;
    return 0;
}
