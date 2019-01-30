*************************GCD*********************
//can i use built in fun __gcd(a,b);
#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5 +5;
int a , b;
ll gcd(ll a, ll b) { return !b ? a : gcd(b , a % b); }
int main(){
    scanf("%d%d" , &a  , &b);
    //    printf("%d\n" , findGcd(a , b));
    while(a != b){
        if(a > b) a -=b;
        else      b -=a;
//        cout <<a << "  " << b<< endl;
    }
    cout << b <<endl;
    return 0;
}

************************LCM*************************
#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5 +5;
int a , b;
int findGcd(int a , int b){
if(b == 0) return a;
return findGcd( b , a % b);
}
int main(){
    scanf("%d%d" , &a  , &b);
   printf("%d\n" , (a * b) / findGcd(a , b) );
    return 0;
}
************************************Permutation && Combinations: **************************

***** Permutations: of set of objects: is an arrangement of those objects into a particular order 


**what if we need arrangement of r elements. Same way: n x (n-1) x (n-2) x .....x (n- r + 1)
 P(n, r) = n! / (n-r)!


*****Combinations: The number of ways of picking????? r unordered elements out of n elements order does not matter 
C(n, r) = n! / ( (n-r)!  * r!)


// How to calculate?
// P(n, r) = C(n, r) * r!
// n! / (n-r)! = C(n, r) * r!
// C(n, r) = n! / ( (n-r)!  * r!)








********************************************Power***********************************



// Divide and Conquer
// 10^16 = (10^8)^2
// 10^17 = (10^8)^2 * 10
int pow(int b, int p) {         // O(log(p) base 2)
    if(p == 0)  return 1;
    int sq = pow(b, p/2);
    sq = sq*sq;
 
    if(p%2 == 1)
        sq = sq*b;
 
    return sq;
}
 


// What about calculating: (a^1+a^2+a^3+a^4+a^5+a^n) ???
 
// Let's try even power
// (a^1+a^2+a^3+a^4+a^5+a^6)       = (a^1+a^2+a^3)+(a^1*a^3+a^2*a^3+a^3*a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+ a^1+a^2+a^3 - (a^1+a^2))
//
 
// what about odd n
// (a^1+a^2+a^3+a^4+a^5+a^6+a^7)   = a + a*(a^1+a^2+a^3+a^4+a^5+a^6)
//                                 = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
 
 
ll sumPows(ll a, int k) { // Return a^1+a^1+a^2+.....a^k    in O(k)
    if (k == 0)
        return 0;
 
    if (k % 2 == 1)
        return a * (1 + sumPows(a, k - 1));
 
    ll half = sumPows(a, k / 2);
    return half * (1 + half - sumPows(a, k / 2 -1) );
}
