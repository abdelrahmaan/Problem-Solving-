*****umulative (Prefix) sum:****
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5  , OO = 1000000009;
int n, A[N], pre[N], ans, l, r, q;
int main(){
void prefixSum(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d", &A[i]);
        pre[i] = pre[i-1] + A[i];
    }
    scanf("%d", &q);
    while(q--){
      scanf("%d%d", &l, &r);
      printf("%d\n", pre[r]-pre[l-1]);
    }
  }
// http://www.spoj.com/problems/CSUMQ/
//

********************************************
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5  , OO = 1000000009;
int n, m, A[55][55], pre[55][55], x , y,  ans;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n ; ++i){
      for(int j = 1 ; j <= m ; ++j){
        scanf("%d", &pre[i][j]);
        pre[i][j]+= pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
      }
    }
//    scanf("%d%d", &x, &y);
    puts("");
    for(int i = 1 ; i <= n ; ++i){
      for(int j = 1 ; j <= m ; ++j){
        printf("%d " , pre[i][j]);
      }
       puts("");
    }
    }
//http://codeforces.com/contest/48/problem/B

*********************************************************************

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5  , OO = 1000000009;
int n, m, A[55][55], pre[55][55], x , y,  ans;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n ; ++i){
      for(int j = 1 ; j <= m ; ++j){
        scanf("%d", &A[i][j]);
        pre[i][j] = pre[i][j-1] + A[i][j];
      }
      for(int j = 1 ; j <= m ; ++j){
        pre[i][j] += pre[i-1][j];
      }
    }
//    scanf("%d%d", &x, &y);
    puts("");
    for(int i = 1 ; i <= n ; ++i){
      for(int j = 1 ; j <= m ; ++j){
        printf("%d " , pre[i][j]);
      }
       puts("");
    }
    }
