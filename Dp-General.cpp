#include <bits/stdc++.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const ll OO = 1e8;

const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;


// Some data will be needed by programs
const int MAX = 100;
vector<int> v;
int n, k;
bool valid(int i, int j) { 	return 1;	}












/*
Dynamic Programming (DP):
	When we solve a recursive problem that its sub-problems overlaps, hence calling sub-problems
	More than once and repeating its calculation in nature that typically makes the order exponentials!
	When the original space is small enough to be memorized, then saving these sub-problems
		makes order small too, as sub-problems calculated once.
*/














// Fibonacci Series: Fib(n) = fib(n-1) + fib(n-2).	Fib(0) = fib(1) = 1
int fib(int n)
{
	if(n <= 1)
		return 1;

	return fib(n-2) + fib(n-1);
}








// what is search space? n
// what is number of recursive calls? We are branching every time to 2 levels that differs in 1
//										fib(5)
//							fib(4)											fib(3)
//				fib(3)					fib(2)						fib(2)			fib(1)
//		fib(2)			fib(1)	fib(1)			fib(0)		fib(1)			fib(0)
//	fib(1)	fib(1)
//
// We almost have 2^N calls





// Wait, a space of N, is called 2^N times!
// A fib of 50 do around ~1125899906842624 call!!!!!!
//
// Then, we must call a state more than once? and it too call other states, that already called!
//
// Check tree above, fib(3) called twice. Fib(2) called three times!
//
// Let's SAVE the answer, and let space of N is called 2N times!




























int savedAnswers[MAX];		// Initialized to -1, means no answer
int fibSave(int n)
{
	if(n <= 1)
		return 1;

	if(savedAnswers[n] != -1)
		return savedAnswers[n];

	return savedAnswers[n] = fib(n-2) + fib(n-1);
}
ll n , mem[N] ;
ll fibMemo(int n){
    if(n <= 1)   return 1;
    ll &ret =    mem[n];
    if(~ret)     return ret;
    return ret = fibMemo(n-2) + fibMemo(n-1);
}
int main(){
    scanf("%lld" , &n);
    memset(mem , -1 , sizeof mem );
    printf("%lld\n" , fibMemo(n));
	return 0;
}

// O(N) Search space, hence O(N) memory -> O(N) Order!











// General Rules:

// 1- Recursive Function
// 2- Sub-calls Overlap
// 3- Small Search Space, so putting in memory is doable

// Do we need to apply DP for merge sort? NEVER, a call will never be repeated! like most of D & C problems.

// Dynamic Programming most typical cases: Minimization, Maximization and Counting. But could have adhock usages.

// In fact, above code is not called DP, it is call Memoization (NOT Memorization).
	// It is a technique when we have a recurive function and save calls)


// DP is to build bottom up according to recurrence while Memoization is top-down













int dp_fib(int n)
{
	int fib[MAX];
	fib[0] = fib[1] = 1;	// base case

	for(int i = 2; i <= n; ++i)
		fib[i] = fib[i-1] + fib[i-2];	// bottom up according to recurrence

	return fib[n];
}


// Writing Memoization is much more natural, although there are cases when DP is a must
// Most of our tutorial is for Memoization






















// Let's move to some other examples! Remember:

// Given grid of positive numbers, Start from 0, 0 and end at n, n. Move only to right and down - find path with sum of numbers is maximum.

/*
15
24
512
678
149
What paths there" 51289, 51789, 51749, 56789, 56749, 56149 ..
				  It is like: 5 { 1 {289, 789, 749}, 6{789, 749, 149} }
				  In other words, 5 needs answer of 1 and of 6 to maximize over them.
*/
int grid[MAX][MAX];

// Think in function F(i, j) that find solution from (i, j) to (n, n)

int maxPathSum(int r, int c)
{
	if( !valid(r, c))
		return 0;

	if (r == n-1 && c == n-1)
		return grid[r][c];	// base

	int path1 = maxPathSum(r, c+1);	// right
	int path2 = maxPathSum(r+1, c);	// down

	return grid[r][c] + max(path1, path2);
}

// How to trun code to memization?
// 1- Create array of input dimensions, and output of its return.
// E.g. int mem[MAX][MAX];
// Initialize it with a value that will never be a correct answer, e.g. -1
// If value is -1, then it is not visited before. Else, use saved value

int mem[MAX][MAX];	// R & C is in range N. Function return int
int maxPathSum_save(int r, int c)
{
	//1- Always hanle invalid calls first
	if( !valid(r, c))
		return 0;

	//2- Handle Base cases
	if (r == n-1 && c == n-1)
		return grid[r][c];	// base

	//3- check if visited before

	if(mem[r][c] != -1)
		return mem[r][c];

	int path1 = maxPathSum_save(r, c+1);	// right
	int path2 = maxPathSum_save(r+1, c);	// down

	return mem[r][c] = grid[r][c] + max(path1, path2);
}




// Dp need good recursive mentality, that views answer in term of recursion! So develop your skills!

// Many DPs follow a certain pattern (style), we will investigate some of them








/*
 Consider an arbitrary sequence of integers. One can place + or - operators between integers in the sequence,
 	 thus deriving different arithmetical expressions that evaluate to different values. Let us, for example,
 	 take the sequence: 17, 5, -21, 15. There are eight possible expressions:
17	+	5	+	-21	+	15	=	16
17	+	5	+	-21	-	15	=	-14
17	+	5	-	-21	+	15	=	58
17	+	5	-	-21	-	15	=	28
17	-	5	+	-21	+	15	=	6
17	-	5	+	-21	-	15	=	-24
17	-	5	-	-21	+	15	=	48
17	-	5	-	-21	-	15	=	18
We call the sequence of integers divisible by K if + or - operators can be placed between integers in the
sequence in such way that resulting value is divisible by K. In the above example, the sequence is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.
You are to write a program that will determine divisibility of sequence of integers.
*/







// called with tryAll1(1, v[0])		// e.g. tryAll1(1, 17)
int tryAll1(int i, int sum) {
	if (i == n)
		return sum % k == 0;

	if (tryAll1(i + 1, sum + v[i]) || tryAll1(i + 1, sum - v[i])	)
		return 1;

	return 0;

}




int fix(int a) {
	return (a % k + k) % k;
}

int tryAll2(int i, int mod) {
	int &ret = mem[i][mod];
	if (ret != -1)
		return ret;
	if (i == n)
		return ret = mod == 0;

	if (tryAll2(i + 1, fix(mod + v[i])) || tryAll2(i + 1, fix(mod - v[i])))
		return ret = 1;
	return ret = 0;

}

/***********************************************************************************************************/


// when the problem Maximization ==> ret = Min number  ==> 0  ;
// when the problem Minimization ==> ret = MAX number  ==> OO ;
#include <bits/stdc++.h>
#define ll long long
#define eps 1e-15
#define PI 3.14159265
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define clr(v, d)		memset(v, d, sizeof(v))
using namespace std;
const int N = 2e6+1 , MAX = 10  , OO = 1000000009;
ll gcd(ll a, ll b) { return !b ? a : gcd(b , a % b); }
ll lcm(ll x, ll y) { return (x * y / gcd(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//bool valid(int i , int j) { return i >= 0 && j >= 0 && i < 8 && j < 8; }
//len any int num > 0 ... len = ceil(log10(a+1));
int n , memo[N] , dp[N];
int fib(int n){     // Recursion
    if(n <= 1)  return 1;
                return fib(n-1) + fib(n-2);
}
int fibMemo(int n){ // Memoizatation
    if(n <= 1)  return 1;
    if(memo[n] != -1)   return  memo[n];
                        return  memo[n] = fibMemo(n-1) + fibMemo(n-2);
}
int fibDp(int n){   // DP
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i <= n ; ++i)   dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int factorialDp(int n ){
    dp[0] = 1;
    for(int i = 1 ; i <= n ; ++i)   dp[i] = dp[i-1] * i;
    return  dp[n];
}
int factorialMemo(int n ){
    if(!n)  return 1;
    int &ans = memo[n];
    if(~ans)    return ans; // if(ans != -1)
    return ans = factorialMemo(n-1) * n ;

}
int main(){
    clr(memo , -1);
  return 0;
}



int main()
{
	freopen(".in", "rt", stdin);
	//freopen(".txt", "wt", stdout);

	return 0;
}
**************************************LIS == Longest Increasing Sub sequance == **********************************
https://github.com/magdy-hasan/competitive-programming/blob/master/uva-/uva%2010617%20-%20Again%20Palindrome.cpp
#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e7 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX = 1e4+4  , OO = 0x3f3f3f3f , mod = 1e9+7 ;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
bool valid(int i , int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//int dx[] = {0 , 0  , 1 , -1 };
//int dy[] = {1 , -1 , 0 , 0 };
//len any int num > 0 ... len = ceil(log10(a+1));
int n , arr[22] , memo[22][22];
int LIS(int i = 0 , int prev = n){
    if(i == n)  return 0;
    int &ret = memo[i][prev];
    if(ret != -1)   return ret;
    int choice1 = 0 , choice2 = 0 ;
    choice1 = LIS(i+1 , prev);
    if(prev == n ||arr[i] > arr[prev])  choice2 = LIS(i+1 , i) + 1;
    return ret = max(choice1 , choice2);
}
int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i)    scanf("%d" , arr + i);
    memset(memo , -1 , sizeof memo);
    printf("%d\n" , LIS());
    return 0;
}

********************************************************** Longest commen subsequance ***************************************************
************************************MeMo*************************************************************************************************
#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e7 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX = 1e4+4  , OO = 0x3f3f3f3f , mod = 1e9+7 ;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
bool valid(int i , int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//int dx[] = {0 , 0  , 1 , -1 };
//int dy[] = {1 , -1 , 0 , 0 };
//len any int num > 0 ... len = ceil(log10(a+1));
char a[105],b[105];
int tc , n,m,dp[105][105];
int LCS(int i,int j){
    if(i == n || j == m)         return 0;  // if we are at the end of one of the string there's no more match
    int &ret = dp[i][j];
    if(ret != -1)                return ret;
    if(a[i] == b[j])             return ret = LCS(i+1,j+1)+1;        // if they're equal then we have a match
//    int choies1 = LCS(i+1 , j);
//    int choies2 = LCS(i   , j+1);      // we try ignore char from a
//    ret = max(choies1 , choies2);     // we try ignore char from b
//    return ret ;
   ret =  max( LCS(i+1,j) , LCS(i,j+1) );                // okk
   return ret;

}

int main(){
    while(gets(a)){
        if(a[0] == '#') break;
        gets(b);
        n = strlen(a);
        m = strlen(b);
        memset(dp , -1 , sizeof(dp));
        printf("Case #%d: you can visit at most %d cities.\n" , ++tc ,LCS(0,0));
    }

  return 0;
}


**********************************************************Dp*****************************************
#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e7 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX = 1e4+4  , OO = 0x3f3f3f3f , mod = 1e9+7 ;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
bool valid(int i , int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//int dx[] = {0 , 0  , 1 , -1 };
//int dy[] = {1 , -1 , 0 , 0 };
//len any int num > 0 ... len = ceil(log10(a+1));
char a[105],b[105];
int tc , n,m,dp[105][105];
int LCS(){
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j){
            if(a[i-1] == b[j-1])    dp[i][j] = dp[i-1][j-1] + 1;
            else                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
        }
        return dp[n][m];
}

int main(){
    while(gets(a)){
        if(a[0] == '#') break;
        gets(b);
        n = strlen(a);
        m = strlen(b);
        memset(dp , 0 , sizeof(dp));
        printf("Case #%d: you can visit at most %d cities.\n" , ++tc ,LCS());
    }

  return 0;
}

