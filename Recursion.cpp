    #include <bits/stdc++.h>
    #define ll long long
    #define cost first
    #define id second
    #define f first
    #define s second
    #define clr(v, d)		memset(v, d, sizeof(v))
    #define read(FILE)  freopen(FILE, "r", stdin);
    #define write(FILE) freopen(FILE, "w", stdout);
    #define Abdulrahman std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    using namespace std;
    const int N = 1e7+7 ,  nBits = 2e8 +5 , MM = (1 << 16) , MAX =  1111 , OO = 0x3f3f3f3f , MOD = 1e9+7  , inf =  1 << 30;
    const ll INF = (ll)1e18;
    //ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
    //ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
    //ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
    //bool valid (int i , int j){ return i >= 0 && j >= 0 && i < n && j < m ;}
    //int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
    //int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
    //len any int num > 0 ... len = ceil(log10(a+1));
    //len any int num > 0 ... len = ceil(log10(a+1));
    int n , m , vis[111] , ans[111];
    ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
    void triangle1(int n){
        if(n <= 0)  return ;                   //  *
        triangle1(n - 1);                      //  **
        for(int i = 1 ; i <= n ; ++i)          //  ***
            cout << "*" ;                      //  ****
            puts("");                           // *****
    }
    void triangle2(int n){
        if(n <= 0)  return ;
        for(int i = 1 ; i <= n ; ++i)           // *****
            cout << "*";                        // ****
            puts("");                           // ***
            triangle2(n-1);                     // **
                                                // *
    }
    ll f3n_1(int n){
        if(n == 1)         return 1;
        if(n % 2 == 0)     return 1 + f3n_1(n / 2);
                           return 1 + f3n_1(n * 3 + 1);
    }
    void printNum(int n){
        if(n){                                      // 1234     ==> 4
            printNum(n/10);                         // 123      ==> 3
            cout << n % 10 << endl;                 // 12       ==> 2
                                                    // 1        ==> 1
            }                                       // 0
    }
    void printBitsNum(int num){             // 7 ==> 111
        if(num){
            printBitsNum(num / 2);
            cout << num % 2 << " " ;
        }
    }
    void perm(int i , int n , int vis [] , int ans[]){
        if(i == n){
            for(int k = 0; k < n ; ++k){
                cout << ans[k] ;
                puts("");
                return ;
        }
        for(int j = 1 ; j <= n ; ++j)
        if(!vis[j]){
            vis[j] = 1;
            ans[i] = j;
            perm(i+1 , n , vis , ans);
            vis[j] = 0;
        }
    }
    int main(){
    scanf("%d" , &n);
    perm(0 , n , vis , ans);
    return 0;
}
******************************************NQueen**********************************************
#include <cstdio>

using namespace std;
const int N = 15 , M = 1e4 +5, OO = 0x3f3f3f3f;

int n;
bool col[N], md[2*N], sd[2*N];
char board[N][N];

void printGrid(){
  puts("---------------------------------");
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0; j < n ; ++j)
      printf("%c", board[i][j]);
    puts("");
  }
  puts("---------------------------------");
}

bool valid(int r, int c){
  return (!col[c] && !md[r-c+N] && !sd[r+c]);
}

void solveNQ(int r = 0){
  if(r == n){
    printGrid();
  }else{
    for(int c = 0 ; c < n ; ++c){
      if(valid(r, c)){
        col[c] = md[r-c+N] = sd[r+c] = 1;     //do
        board[r][c] = 'Q';                    //do
        solveNQ(r+1);                         //recurse
        col[c] = md[r-c+N] = sd[r+c] = 0;     //undo
        board[r][c] = '.';                    //undo
      }
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)  board[i][j] = '.';
  solveNQ();
  return 0;
}
