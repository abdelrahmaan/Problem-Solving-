Frequency Array:
  -Introduction Problem:
    Given n Integers, for each number from 1 to 3 print the number of its occurrences.
      ans   ---->   Three variables.

  -Classical Problem:
    Given n<=1e5 Integers ranging from 1 to 1e5,for each given number print the number of its occurrences.
      ans1    ---->   O(n^2) time.
      ans2    ---->   O(n)  time.

  int x, freq[N] = {0};
  for(int i = 0 ; i < n ; ++i){
    scanf("%d", &x);
    freq[x]++;
  }
  for(int i = 0 ; i < N ; ++i){
    if(freq[i])
      printf("The number %d was found %d times.\n");
  }

-What if the numbers are Integers in the range 1 to 1e9?
-What if they weren't Integers (e.g. Chars, doubles or Strings)?


Cumulative (Prefix) sum:
  -Classical Problem:
    Given n<=1e5 numbers, and q<=1e5 queries asking about sum of elements from l to r.
      ans1    ---->   O(n*q)  time.
      ans2    ---->   O(q)    time.

  int n, A[N], pre[N], ans, l, r, q;
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

-What about Suffix sum?
-What about 2D .. what about ND?

  int n, m, A[N][N], pre[N][N], ans, l1, r1, l2, r2, q;
  void prefixSum2D(){
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
    scanf("%d", &q);
    while(q--){
      scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
      printf("%d\n", pre[l2][r2] - pre[l1-1][r2] - pre[l2][r1-1] + pre[l1-1][r1-1]);
    }
  }


Maximum Intersection:
  -Classical Problem:
    Given n<=1e5 friend who are free from time l to time r<=1e5
    , what's the time in which maximum number of friends are free?
      ans1    ---->   O(n*r)  time    ---->     TLE.
      ans2    ---->   O(n)    time.


  int q, f, t, day[N], maxi = 0, maxday;
  void maximumIntersection(){
    scanf("%d", &q);
    while(q--){
      scanf("%d%d", &f, &t);
      ++day[l], --day[t+1];
    }
    for(int i = 1 ; i <= N ; ++i){
      day[i] += day[i-1];
      if(day[i] > maxi){
        maxi = day[i];
        maxday = i;
      }
    }
    printf("The maximum number of friends is %d in day number %d.\n", maxi, maxday);
  }
