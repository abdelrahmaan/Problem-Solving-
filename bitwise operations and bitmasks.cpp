https://en.wikipedia.org/wiki/Bitwise_operation#Arithmetic_shift
1- How does numbers are saved?
  Binary Representation.

Boolean algebra.

What's bitwise operations?

    operation          operator
      and                 &
      or                  |
      Xor                 ^
      invert              ~
      left shift          <<
      right shift         >>

- How to get all the possible permutations of k(e.g k = 3) bits?

  for(int msk = 0 ; msk < (1<<k) ; ++msk){
    // Anything
  }


- How to check oddness of a variable x?

  if(x&1)
    printf("It's Odd\n");
  else
    printf("It's Even\n");


- How to check the state of the bit at position k of some mask?

  if(msk&(1<<k))
    printf("It's ON");
  else
    printf("It's OFF");


- How to ON the bit at position k of some mask?

  msk |= (1<<k);


- How to OFF the bit at position k of some mask?

  msk &= ~(1<<k);


- How to toggle the bit at position k of some mask?

  msk ^= (1<<k);


- How to ON the first n bits of some mask?

  msk |= ((1<<n)-1);



- How to get the most right ON bit of some mask?

  rightON = (msk&(-msk));

  
- How to count the number of ON bits in some mask of n bits?

  int num = 0;
  for(int j = 0 ; j < n ; ++j)
    if(msk&(1<<j))	 ++num;

- if need which number ON "1" 

  for(int i = 0; i < 31; ++i)
        if(n & ( 1 << i))	cout << (1 << i) << "  ";
// íÚäí ÇáÈÊ ÇáãäæÑå Ý ÇáãßÇä  ÂÂí ÇáãæÌæÏ Ý Çá Çä  ... ÇØÈÚ æÇÍÏ ÇÓ ÂÂí 
// ÔæÝ ÇáÈÊ ÇÓ ÂÂÂí(ÇËäíä ÇÓ ÂÂí )  ãäæÑå Ý Çä ... áæ ßÏÇ ÇØÈÚ ÞíãÊåÇ 
***********************************************************************

if i print the binary rebresentation on number x in a lenght y :

#include <bits/stdc++.h>
using namespace std;
void printNum(int n , int len){
    if(!len) return ;
    printNum( n  >> 1  , --len); // remove last bit
    cout << (n & 1) << " ";     // print last bit
}
int main(){
    int n , len;
    scanf("%d%d" , &n , &len);
    printNum(n , len);

              return 0;
}
*************************************************************************

// Let's count bits
// 2==>1 , 8 ==>1 , 23==>4
int countNumBits1(int mask) {	// O(bits Length)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) {
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}
--------
//More efficient
int countNumBits2(int mask) {	//	O(bits Count)		__builtin_popcount
	int ret = 0;
	while (mask) 	{
		mask &= (mask-1);
		++ret;	// Simply remove the last bit and so on
	}
	return ret;
}
----------
//How to count the number of ON bits in some mask of n bits?

  int num = 0;
  for(int j = 0 ; j < n ; ++j)
    if(msk&(1<<j))
      ++num;

*************************************************************************

// Get bit
int getBit(int num, int idx) {
  return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}

*************************************************************************

int setBit1(int num, int idx) {
	return num | (1<<idx);
}

*************************************************************************

int setBit0(int num, int idx) {
	return num & ~(1<<idx);
			// 110100, idx = 3  -->  110100 & ~000100 = 110100 & 111011
}

*************************************************************************
int flipBit(int num, int idx) { // 1 to be 0 , 0 to be 1
	return num ^ (1<<idx);
}

*************************************************************************

// Much staff? Let's use STL!

#include <bitset>		// The power, speed and memory handling in one place

void STL() {
	const int N = 20;		// const
	string s = "000111";
	bitset<N> x(s);			// 00000000000000000111
	x.set();				// 11111111111111111111
	x.flip();				// 00000000000000000000

	x = 10;					// 00000000000000001010

	x |= 3;					// 00000000000000001011

	x = (x<<3);				// 00000000000001011000

	x = ~x;					// 11111111111110100111
	x.set(15, 0);			// 11110111111110100111
	x.set(15);				// 11111111111110100111
	x.flip(0);				// 11111111111110100110
	x.count();				// Returns the number of bits that are set.
	x.any();				// Returns true if any bits are set.
	x.none();				// Returns true if no bits are set.
	x.test(15);
	x.to_ulong();			// Returns an unsigned long represent mask

	// The most interesting
	if(x[2] == 0)
		;

	x[0] = 1;	// Set bit from most right to 1
	x[N-1] = 0;	// Set bit from most left to 0

	cout<<x<<"\n";			// display a string of N bits
}


*************************************************************************
printing number witha all subset
---------------------------------
void printBits(int mask , int len){
    if(!len){
        puts("");
        return  ;
    }
    printBits( (mask >> 1) , --len);
    cout <<  (mask & 1)  <<  " " ;
}
void printAllSubset(int len){
    for(int i = 0; i < (1 << len); ++i)
        printBits( i , len);
}
int  n , l  , r  , maxBits ,  indx , numBits;
vector<int>bitsNumbers;
int main(){
    scanf("%d" , &l);
    printAllSubset(l);
    return  0;
}
