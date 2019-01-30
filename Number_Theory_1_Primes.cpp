// Facts
// int primelst[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // [1-100]
// (2^31)-1 is a prime number with value 2147483647
// (2^61)-1 is a prime number with value 2305843009213693951
// primesRangeCnt 10^i (4, 25, 168, 1229, 9592, 78498, 664579, 5761455) [e.g. 4 primes <= 10^1] ~= n / log(n)
// 257, 263, 269, 271 -> 4 primes their multiplication > 2^32
// Wilson's theorem: (p-1)!%p = p-1 IFF p is prime

*******************************************************
		***********isPrime**********


bool isprime1(ll n) {       // O(n)
    if(n == 2)   return true;
    if(n < 2)    return false;

    for(int i=2; i < n; i++)
        if(n%i == 0)
            return false;
    return true;
}
____________________________________________
bool isprime2(ll n) {       // O(n)
    if(n == 2)  return true;
    if(n < 2 || n%2 == 0)    return false;

    for(int i=3; i < n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

____________________________________________
// 36 = 1 * 36
// 36 = 2 * 18
// 36 = 3 * 12
// 36 = 4 * 9
// 36 = 6 * 6
// 36 = 9 * 4
// 36 = 12 * 3
// 36 = 18 * 2
// 36 = 36 * 1
// if n = a * b and a <= b       THEN    a <= sqrt(n) and     b >= sqrt(n)
// why trying after sqrt if before it is enough?

bool isprime3(ll n) {   // O( sqrt(n) ? NO
    if(n == 2)              return true;
    if(n < 2 || n%2 == 0)    return false;

    for(ll i=3; i <= sqrt(n); i+=2)
        if(n%i == 0)
            return false;
    return true;
}

____________________________________________
// i <= sqrt(n)      power 2 sides
// i * i <= n        Integer version
bool isprime4(ll n) {   // O( sqrt(n)

    if(n == 2)              return true;

    if(n < 2 || n%2 == 0)    return false;

    for(ll i=3; i*i <= n; i+=2)
    {

        if(n%i == 0)
            return false;
    }
    return true;
}
****************************************************************
		***********countPrimesInRange**********


// Return number of primes in range n
int countPrimesInRange(int n)   // Forward thinking
{   // O(n * sqrt(n) )
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if( isprime4(i) )
            ++cnt;

    return cnt;
}

____________________________________________
// 2, 3, , 5, , 7, , , ....
// Let 2 removes 4, 6, 8, 10.....n
// Let 3 removes 6, 9, 12, 15....
// 4 is removed
// let 5 remove 10, 15, 20.....
// 6 is removed
// could 7 be removed? NEVER, no one before it could divides it!
// Let 7 removes 14, 21 ...
// Do we need to work more than sqrt(n)? No


int countPrimesInRange_sieve(int n) // Backward thinking
{
    vector<bool> isPrime(n+1, true);  // set all of them to primes
    isPrime[0] = isPrime[1] = 0;        // 0, 1 are not primes

    for (ll i = 3; i*i <= n; i+= 2) {   // work
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }



    for (ll i = 2; i*i <= n; ++i) {     //work
        if (isPrime[i]) {
            for (ll j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

    int cnt = 0;

    for (int i = 0; i < (int)isPrime.size(); ++i)
        if(isPrime[i])
            cnt++;

    return cnt;
}
 ***************primes from n to m by sieve**************************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
vector<bool> isPrime(100 , 1);
void sieve() {
    isPrime[0] = isPrime[1] = 0;        // 0, 1 are not primes
    for (int i = 2; i <= 100; ++i)  // without 100 == any num
        if (isPrime[i]) {
            for (int j = i * 2; j <= 100; j += i)    // without 100 == any num
                isPrime[j] = 0;
        }
}
int main(){
	sieve();
	for(int i = 2; i <= 100; ++i)
        if(isPrime[i]) printf("%d\n" , i);
	return 0;
}

____________________________________________
Solution #2:  "Sieve of Eratosthenes"
  bitset<N> isComposite;
  void sieve(){                             //O(N*Log(Log(N)))
    isComposite[0] = isComposite[1] = 1;
    for(int i = 2 ; i <= N ; ++i){      //The Maximum value
      if(!isComposite[i]) for(int j = i*i ; j <= N ; j+=i){
        isComposite[j] = 1;
      }
    }
  }
Goldbech`s conjecture:
  -Every even integer greater than 2 can be expressed as the sum of 2 primes
