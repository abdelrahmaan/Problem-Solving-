


                                    ***Kruskal Minimum Spaninig Tree***

** Minimum Spaninig Tree ==> that's tree which the summation of all weighted edges the small one
1- sorting all Edges By *Weight* "small to big" .
2- connect each edge that not connected before .
3- we need to know
        a ) two node not connected or connected
        b ) if not connect ==> connect

                                            ***Application of MST***

***To find second minimum spaninig tree ==>
        1-  find MST
        2 - for each node from graph
            3- Remove edge from graph
            4- Run MST , compare it for min val
            5- Back the edge for graph
        6- Display Val

*** To build partial MST
        1- for each already built edge
            2- union it
        3- for all edge "NEW"
            4- Run Kruskal


**** Number of ST in Complete graph ==   n ^ n - 2
****************************************************************************************
**********************************************Easy Code****************************************************
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int Parent[MAX], nodes, edges;
pair <long long , pair<int, int> > p[MAX];

void initialize(){  for(int i = 0;i < MAX;++i)  Parent[i] = i;  }
int  findParent(int x){  x == Parent[x] ? x : Parent[x] = findParent(Parent[x]);          }
void union1(int x, int y){
    int p = findParent(x);
    int q = findParent(y);
    Parent[p] = Parent[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost , minimumCost = 0;
    for(int i = 0 ; i < edges ; ++i){
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(findParent(x) != findParent(y)){
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}


**************************************************Code Kruskal *************************************************************************
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
sing namespace std;
const int N = 1e5+5 ,  M = (1 << 16) , MAX = 10  , OO = 0x3f3f3f3f , mod = 1e9+7 ;
int  n , forest;
vector<int> Rank ;
vector<int> Parent;
void init(int n)     {	for(int i = 1 ; i <= n ; ++i)	Parent[i] = i , Rank[i] = 1;      }
int  findParent(int x){  x == Parent[x] ? x : Parent[x] = findParent(Parent[x]);          }
void unionSet(int a, int b){                   // union two Trees
	a = findParent(a), b = findParent(b);
//	if(a == b)  return ;
	if(a != b){
        if(Rank[a] > Rank[b])   swap(a , b);    // a ==> smallest High merge with the big
        Parent[a] = b;                          // link a with b
//        Rank[b] += Rank[a];
        if(Rank[a] == Rank[b]) ++Rank[b];       // if two trees equal
        --forest;
	}
}
int n , m , a , b ,  w ;
vector<pair<int , pair<int , int > > > egdes;
vector<pair<int , int >> showEdges;
int main(){
    scanf("%d %d" , &n , &m );
    init(n);
    for(int i = 0 ; i < m ; ++i){
        scanf("%d %d %d" , &a , &b  , &w);
        edges.push_back( { w , { a , b } } );
    }
    int mstWeight = 0 , mstEdges = 0 , mstIndex = 0;
    sort(edges.begin() , edges.end());
    while(mstEdges < n-1 || mstIndex < m){
        a = edges[mstIndex].second.first;
        b = edges[mstIndex].second.second;
        w = edges[mstIndex].first;
        if(findPrent(a) != findPrent(b)){
            unionSet(a , b);
            mstWeight += w;
            ++mstEdges;
            showEdges.push_back({a , b});
        }
        ++mstIndex;
    }
    return 0;
}

********************************************************************
int t ,n ,m ,u ,v ,w ,parent[N] ,Rank[N] ,components ,totalCost ;
bool hvEdge[N] ;
vector<int,pair<int,int>> hvEdges ;
pair<int,pair<int,int>> edge[N] ; /** pair<((w)),pair<((u)),((v))>> **/
void initial(){
    components=n ;
    totalCost=0;
    memset(Rank,0,sizeof Rank);
    memset(hvEdge,0,sizeof hvEdge);
    for(int i=1;i<=n;++i)parent[i]=i;
}
int gtparent(int ch){
    if(ch==parent[ch])return ch;
    return parent[ch]=gtparent(parent[ch]);
}
bool isConnected(int i,int j){
    return gtparent(i)==gtparent(j);
}
void Union(int i,int j){
    i=gtparent(i) ,j=gtparent(j) ;
    if(i!=j){
        if(Rank[i]<Rank[j])swap(i,j);
        parent[j]=i;
        if(Rank[i]==Rank[j]) ++Rank[i];
    }
}
int main(){
    // get inout
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        edge[i]={w,{u,v}};
        // edge's weight first to sort and work greedy
    }
    initial();
    sort(edge,edge+m);
    // union edges to get minimum spanning tree
    for(int i=0;i<m;++i){
        w=edge[i].first ,u=edge[i].second.first ,v=edge[i].second.second ;
        if(gtparent(u)!=gtparent(v)){
            totalCost+=w;
            --components;
            hvEdges.push_back(edge[i]);
            Union(u,v);
        }
    }

    return 0;
}
