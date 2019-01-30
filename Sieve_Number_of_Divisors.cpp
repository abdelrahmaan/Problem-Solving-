************************the numbers of divisors for each number By seive*****************************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e8, OO = 2000000007;
int numberOfDivisors[N];
int n;

void sieve(){
  numberOfDivisors[0] = numberOfDivisors[1] = 1;
  for(int i = 2 ; i*i <= N ; ++i){
    if(!numberOfDivisors[i]) 
    for(int j = i ; j < N ; j+=i){
      int e = 0;
      int q = j;
      while(q%i==0){
        ++e;
        q/=i;
      }
      if(numberOfDivisors[j]) numberOfDivisors[j]*=(e+1);
      else  numberOfDivisors[j] = e+1;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d" , &n);
  sieve();
  printf("%d\n" , numberOfDivisors[n]);
//  for(int i = 2 ; i <= 30 ; ++i){		//Note that Primes have exactly 2 divisors
//  	printf("Number %d has %d Divisors\n", i, numberOfDivisors[i]);
//  }
  return 0;
}

************************the numbers of divisors for each number*****************************

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
int n , numFactors[1006] , s ;
int rangeFactorization2(int n){               // suitable for range 210^6
    for(int i = 1; i <= n; i++)              // each divisor
       for(int k = i; k <= n; k += i){       // For each divisble number
            ++numFactors[k];                     //   i divides k
            ++s;
            }
            return s;
}
int main(){
    scanf("%d" , &n);
//    rangeFactorization2(n);
    printf("summation is : %d\n" , rangeFactorization2(n)); // if need summation of divisors
    for(int i = 1; i <= n; i++)     printf("%d\n" ,numFactors[i]);
        return 0 ;
}



***********************************************************************


______________________________________________________________________________
