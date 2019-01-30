*******************generate_divisors****************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
long long n , m ;
set<long long> st;
void generateDivisores(long long n){             //O(sqrt(N)*log(n))== >O(sqrt(n))
    for(long long i = 1; i * i <= n; ++i)        
        if(n % i == 0)
            st.insert(i) , st.insert(n/i);     //O(log(n))
}
int main(){
	scanf("%lld", &n);
	generateDivisores(n);
	for(long long x : st) printf("%lld\n" , x);
	return 0;
}
_________________________________________________________
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
    vector<int>v;
void divisors(int n){
    for(int i= 1; i * i <= n; ++i){
	if(i*i == n) v.push_back(i);
        else if(n % i == 0) v.push_back(i) , v.push_back(n/i);
			}
        
}
int n , sum , ans , s;
int main(){
    scanf("%d" , &n);
    divisors(n);
    for(int x : v) printf("%d " , x);

        return 0 ;
}

------------------------------------------------------------------
*******************divisors of num*******************

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
vector<int> primes;
void primeFactor(int n){
    for (int i = 2; i*i <= n; ++i)
        while (n % i == 0)
            primes.push_back(i), n /= i;
     if (n > 1) primes.push_back(n);
}
int n , ans;
int main(){
    scanf("%d" , &n);
    primeFactor(n);
   for(int x : primes) printf("%d " , x);
        return 0 ;
}
------------------------------------------------------------------
*******************number of exactly 2 primes in range for each number****************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
string sBits = "0101";
//bitset<N> x(sBits);
vector<bool> isPrime (3003  , 1 );
void seive(){
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 2; i*i <= 3003; ++i)
        if(isPrime[i])
        for(int j = 2*i; j <= 3003; j +=i)
        isPrime[j] = 0;
    }
bool almost(int n){
    int two =0;
    for(int i = 2; i <= n; ++i)
    if(isPrime[i] && n % i == 0) ++two;
    if(two == 2) return 1;
    else         return 0;
}
int aPraime , ans;
int main(){
    scanf("%d" , &aPraime);
    seive();
   for(int k = 2; k <= aPraime; ++k) if(almost(k)) ++ans;
        return 0 ;
}
---------------------------------------------------------------