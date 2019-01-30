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
    const int N = 1e7+7 ,  nBits = 2e8 +5 , MM = (1 << 16) , MAX =  1111 , OO = 0x3f3f3f3f , MOD = 1e9+7  , inf =  1 << 30;
    //const ll INF = (ll)1e18;
    //ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
    //ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
    //ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
    //bool valid (int i , int j){ return i >= 0 && j >= 0 && i < n && j < m ;}
    //int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
    //int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
    //len any int num > 0 ... len = ceil(log10(a+1));
    //len any int num > 0 ... len = ceil(log10(a+1));
    int t  , z , vb , vs , x , y , mini , maxi ,len ,  A[31] , index , ans;
    bool f1 ;
    ll n ,  num;
    string s;
    ll bTdec(ll n){
        int i = 0 , rem = 0 ;
        ll dec = 0;
        while(n){
            rem = n % 10;
            n /= 10;
            dec += rem * pow(2,i);
            ++i;
        }
        return dec;
    }
int main() {
//  freopen("fileName.in" , "r" , stdin);
    scanf("%lld" , &n);
    num = bTdec(n);
//    num = std::stoi(s, nullptr, 2);
    cout << num << endl;        // Binary number to decimal
    return 0;
}
