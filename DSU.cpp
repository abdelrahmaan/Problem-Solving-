

                                ***Kruskal Minimum Spaninig Tree "DSU" ***

**Minimum Spaninig Tree ==> that's tree which the summation of all edges the small one
1- sorting all Edges "small to big" .
2- connect each edge that not connected before .
3- we need to know
        a ) two node not connected or connected
        b ) if not connect ==> connect


*/**/* if we know Two noodes connected with each other " in the same component "?
        */**/* each Component have a One Parent :
        node 1 ==> get parent
        node 2 ==> get parent
        if(parent 1 == parent 2)    Two nodes in the same Component && can't connected that's Two nood by Edge
        ***************************************************************************************************

                        */**/* How to union Two components with each other ?

* by connect one parent of first componoet  to the other parent of the second component
        ***************************************************************************************************


1- Path Cpmpression : Distributed the Top Parent on the path
2- union bt Rank ==> Merge the smallest tree with the bigest tree
   Use to        ==> Maximum possible Hight possible

***********************************************Code*************************************************************************
#include <bits/stdc++.h>
#define ll long long
sing namespace std;
const int N = 1e5+5 ,  M = (1 << 16) , MAX = 10  , OO = 0x3f3f3f3f , mod = 1e9+7 ;
int  n , forest;
vector<int> Rank ;
vector<int> Parent;
void init(int n){
    forest = n;
	for(int i = 1 ; i <= n ; ++i)	Parent[i] = i , Rank[i] = 1;
}
int findParent(int x){
    //while (x != Patent[x])  x = Parent[x];
	if(parent[x] == x)	return x;
	return parent[x] = findParent(parent[x]);   // Parent && Path Compression == > 1 Level Tree
}
void link(int a , int b){   // Union
    if(Rank[a] > Rank[b])   swap(a , b);    // a ==> smallest High merge with the big
    Parent[a] = b;      // link a with b
    Rank[b] += Rank[a];
//    if(Rank[a] == Rank[b]) ++Rank[b];   // if two trees equal
}
bool unionSet(int a, int b){    // union two Trees
	a = findParent(a), b = findParent(b);
	if(a != b){
        link(a , b);    // merge anew forest
        --forest;
	}
	return a != b;
}

int main(){
    scanf("%d" , &n);
    init(n);
    return 0;
}



