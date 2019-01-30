#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6+6 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX =  100 , OO = 0x3f3f3f3f , MOD = 1e9  , inf =  1 << 30;
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
int index , shifted , mem[100][100] , sz1 , sz2 , f;
char str1[MAX] , str2[MAX];
int solve(int i , int j ){
    if(i == sz1)            return sz2 - j; // insert from str2 to str1
    if(j == sz2)            return sz1 - i; // delete from str1
    int &ret = mem[i][j];
    if(~ret)                return ret;
    if(str1[i] == str2[j])  return ret = solve(i+1 , j+1);
    int ch1 = 1 + solve(i   , j+1);   // add str2[j] before str1[i]
    int ch2 = 1 + solve(i+1 , j);    // delete str1[i]
    int ch3 = 1 + solve(i+1 , j+1); // replace
    return ret = min(ch1 , min(ch2 , ch3));
}
void build(int i , int j){
    if(i == sz1){
        int toAdd = sz2 - j;
        for(int k = 0 ; k < toAdd ; ++k)
            cout << ++index << " Insert " << k+1+i+shifted << "," << str2[k+j] << "\n" ;
        shifted += toAdd;
        return ;
    }
    if(j == sz2){
        int Delete = sz1 - i ;
        for(int k = 0 ; k < Delete ; ++k){
             cout << ++index << " Delete " << k+1+i+shifted << "\n" ;
             --shifted;
        }
        return ;
    }
    if(str1[i] == str2[j]){
        solve(i+1 , j+1);
        return ;
    }
    int ch1 = 1 + solve(i   , j+1);   // add str2[j] before str1[i]
    int ch2 = 1 + solve(i+1 , j);    // delete str1[i]
    int ch3 = 1 + solve(i+1 , j+1); // replace
    int optimal = solve(i , j);
    if(optimal == ch1){
         cout << ++index << " Insert " << 1+i+shifted << "," << str2[j] << "\n" ;
         ++shifted;
         solve(i , j+1);
    }else if(optimal == ch2){
         cout << ++index << " Delete " << 1+i+shifted <<  "\n" ;
         --shifted;
         solve(i+1 , j);
    }else{
        cout << ++index << " Replace " << 1+i+shifted << "," << str2[j]<<  "\n" ;
         solve(i+1 , j+1);
    }
}
int main(){
    while(gets(str1)){
        gets(str2);
        if(f)   puts("");
        f = 1;
        memset(mem , -1 , sizeof mem);
        sz1 = strlen(str1);
        sz2 = strlen(str2);
        printf("%d\n" , solve(0 , 0) );
        index = shifted = 0;
        build(0 , 0);
    }
	return 0;
}
