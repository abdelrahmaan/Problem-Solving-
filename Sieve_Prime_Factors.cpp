************************the numbers of Prime Factor by sieve*****************************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
long long num , pF[N];
void seivePF(){
    pF[0] = pF[1] = 1;
    for(long long i = 2; i * i <= N; ++i)
        if(!pF[i])
        for(long long j = i; j < N; j+= i)
            pF[j] = i;
}
int main(){
    scanf("%lld" , &num);
    seivePF();
  while(num > 1 ){
    printf("%lld " , pF[num]);
    num /= pF[num];
  }
        return 0 ;
}
************************the numbers of Prime Factor*****************************
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
int aPraime , ans;
int main(){
    scanf("%d" , &aPraime);
    primeFactor(aPraime);
   for(int x : primes) printf("%d " , x);
   puts("");
   printf("num of prime factor is : %d " , primes.size());
        return 0 ;
}
____________________________________________________________________________________________
************************the numbers of divisors for each number*****************************

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
int n , numFactors[1006] , s ;
int rangeFactorization2(int n){               // suitable for range 2*10^6
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
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6 , MAX = 2e5+5  , OO = 1000000009;
int greatestPF[N];
int n;

void sieve(){
  greatestPF[0] = greatestPF[1] = 1;
  for(int i = 2 ; i*i <= n ; ++i){
    if(!greatestPF[i])  for(int j = i ; j < n ; j+=i){
      greatestPF[j] = i;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  n = N;
  int x;
  sieve();
  for(int i = 0 ; i < n ; ++i){
    scanf("%d", &x);
		printf("Prime Factors of %d are : ", x);
    while(x>1){
      printf("%d ", greatestPF[x]);
      x /= greatestPF[x];
    }
    puts("");
  }
  return 0;
}

______________________________________________________________________________
