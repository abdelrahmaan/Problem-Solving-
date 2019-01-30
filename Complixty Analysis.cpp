/*
  Session : Time Complexity analysis
  By : Muhammad Magdi
  On : 20/08/2017
*/

* What's time Complexity?
    How does the running time change as the size of input change.

* Running time depends on:
    1- Processor.
    2- Read/Write speed to memory.
    3- 32 bit VS 64 bit.
    4- INPUT.

* What are the cases your code may face?
    1- Best case.
    2- Worst case.
    3- Average case.

* The notations to represent your code's Complexity:
    1- Big O Notation     ---->     the upper bound of the time.
    2- Omega Notation     ---->     the lower bound of the time.
    3- Theta Notation     ---->     the bound itself.    (Calculated mathematically)

* Rules:
    1- Running time is the sum of running times of all consecutive blocks.
    2- Nested loops are multiplied.
        In general -> Nested repetitive Blocks are multiplied.
    3- In Conditional statements pick the "Worst case" one.
    4- Drop Constants (addition, subtraction, multiplication or division).
    5- Drop all lower order terms.


* Some useful Observations:
  Big O                 Name                    Max n
-------------------------------------------------------------------------------------------
  O(1)        ---->     Constant      ---->     1e18      ---->     Math, Observation
  O(Log(n))   ---->     Logarithmic   ---->     1e18      ---->     Binary Search (lower -upper- bound)
  O(n)        ---->     Linear        ---->     1e8       ---->     one loop
  O(n*Log(n)) ---->     LogLinear     ---->     4e5       ---->     Sorting, loop + binary search
  O(n^2)      ---->     Quadratic     ---->     1e4       ---->     nested loop
  O(2^n)      ---->     Exponential   ---->     25        ---->     Bitmasks, finding all possible answers
  O(n!)       ---->     factorial     ---->     11        ---->     finding all permutations


****************************1*************************
int calcSum(int a, int b){
  int sum = a+b;
  return sum;
}
****************************2*************************
double calcAverage(int a, int b){
  double avg = (a+b)/2.0;
  return avg;
}
****************************3*************************
bool isAlphabit(char x){
  return (x>='A' && x<='Z' || x>='a' && x<='z');
}

****************************4*************************

double sumHarmonicSeries(int n){
  double sum = 0;
  for(int i = 1 ; i <= n ; ++i){
    sum += (1.0/i);
  }
  return sum;
}
****************************5*************************
long long calcSumSegment(int a, int b){
  long long sum = 0;
  for(int i = a ; i<=b ; ++i)
    sum += i;
  return sum;
}
****************************6*************************
int fact(int n){
  if(!n || n==1)	return 1;
  return n*fact(n-1);
}
****************************7*************************
int power1(int base, int power){
  if(!power)  return 1;
  return base*power1(base, power-1);
}

****************************8*************************

bool binarySearch(int val){
  int lo = 0, hi = n, mid;
  while(lo<hi){
    mid = ((lo+hi)>>1);
    if(A[mid] == val) return 1;
    if(A[mid] < val)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return 0;
}
****************************9*************************
int calcLog(int n){
	int ret = 0;
	while(n > 1){
		++ret;
		n /= 2;
	}
  return ret;
}
****************************10*************************
int power2(int base, int power){
  if(!power)  return 1;
  int sub = power2(base, power>>1);
  return (power&1? sub*sub*base : sub*sub);
}

****************************11*************************

for(int i = 0 ; i < (1<<n) ; ++i){
  //some O(1) operations
}
/*
8 4 2 1
0 0 0 1
0 0 1 0
0 1 0 0
1 0 0 0

1<<0 = 2^0 = 1
1<<1 = 2^1 = 2
1<<2 = 2^2 = 4
1<<n = 2^n
*/

int fib(int n){
  if(!n || n==1)	return n;
  return fib(n-1)+fib(n-2);
}

****************************12*************************

for(int i = 0 ; i < (1<<n) ; ++i){
  for(int i = 0 ; i < n ; ++i){
    //some constant order statements go here
  }
}

void searchArray(){
  for(int i = 0 ; i < n ; ++i){
    if(binarySearch(B[i]))
      puts("Found");
    else
      puts("Not Found");
  }
}
****************************13*************************
bool isComp[1008];
void sieve(){
  isComp[0] = isComp[1] = 1;
  for(int i = 2 ; i < n ; ++i){
    if(!isComp[i]){
      for(int j = i ; j < n ; j+=i)
        isComp[i] = 1;
    }
  }
}

****************************14*************************

void printPermutations(string s){
  sort(s.begin(), s.end());
	do {
		cout << s << endl;
	} while(next_permutation(s.begin(), s.end()));
}
