#include <bits/stdc++.h>
#define ll long long
#define eps 1e-15
using namespace std;
const int o = 15 , N = 1e6+6 , MAX = 100  , OO = 1e6+6;
ll gcd(ll a, ll b) { return !b ? a : gcd(b , a % b); }
ll lcm(ll x, ll y) { return (x * y / gcd(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//len any int num > 0 ... len = ceil(log10(a+1));

/*
    BFS ==>  *shortest path if costs of Edges = 1 "unweighted" , show path *
             *Bipartite graph

             *Edge Split ==> if cost small like 5 , can split the edge number that's any edge cost's == 1
             EX : nodes = 5 , node 2 to 4 cost = 3..
             /*   2-3 , 3-7 , 7-4 ,,, 3 Edges every one cost == 1 ... Then run BFS code and get shortest path   /*

             *Vertex Split ==> if i pay small  money on some nodes / edges
             EX : nodes = 5 , pay 3 on node 3
             3-6 , 6-7 , 7-8
             in(3) = 3 , out(3) = 8
             shortest path(node 1 , node 3 ) = shortest path(in(1) , out(3) == run BFS on node (1,8)
             every node save in / out

*/
vector<vector<int>> adj;

vector<int> bfsShortestPath(int s , vector<vector<int>> &adj){  // for shortest path one to many && many to one
      // many to many  :  entering all sources in onetime and run th BFS code
    vector<int> len((int)adj.size() , OO);  //  OO == max value
    queue<int> q;
    q.push(s) , len[s] = 0; // length of start = 0
    int dep = 0 , cur = s  , sz = 1; //current size for each level
    for(; !q.empty(); ++dep , sz = q.size()){
        while(sz--){
            cur = q.front() , q.pop();  // tla3 El current
            for(int ch : adj[cur])
            if(len[ch] == OO)   q.push(ch) , len[ch] = dep + 1;     // da5al wladha
//            for(int i = 0; i < (int)adj[cur].size(); ++i)
//                if(len[ adj[cur][i] ] == OO)
//                q.push(adj[cur][i])  , len[ adj[cur][i] ] = dep + 1;
        }
    }
    return len;
}

vector<int> bfsShowPath((int s, int d , vector<vector<int>> &adj){  // for shortest path    one to one
    vector<int> len((int)adj.size() , OO);
    vector<int> parent((int)adjList.size() , -1);
    queue<int> q;
    q.push(s) , len[s] = 0; // length of stat = 0
    int dep = 0 , cur = s  , sz = 1; //current size for each level
    bool ok = true;
    for(; ok && !q.empty(); ++dep , sz = q.size()){
        ++dep , sz = q.size();
        while(ok && sz--){
            cur = q.front() , q.pop();
            for(int ch : adj[cur])
                if(len[ch] == OO)
                len[ch] = dep +1 , q.push(ch) , par[ch] = cur;
//            for(int i = 0; i < (int)adj[cur].size(); ++i)
//                if(len[ adj[cur][i] ] == OO)
//                q.push(adj[cur][i])  , len[ adj[cur][i] ] = dep + 1 , parent[ adjList[cur][i] ] = cur;
                if(adjList[cur][i] == d)    // we found target no need to continue
                {
                    ok = false;
                    break;
                }
        }
    }
        vector<int> path;
        while(d != -1) {
            path.push_back(d);
            d = parent[d];
        }
    reverse(path.begin() , path.end());
    return path;
}
******************************************** Another BFS Code******************************************************
#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 4e3+4 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX =  111 , OO = 0x3f3f3f3f , MOD = 1e9+7  , inf =  1 << 30;
const ll INF = (ll)1e18;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
//bool valid (int i , int j){ return i >= 0 && j >= 0 && i < n && j < m ;}
//int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
//int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//len any int num > 0 ... len = ceil(log10(a+1));
//len any int num > 0 ... len = ceil(log10(a+1));
int n , m  , x , y , ans , adj[N][N] , len[N];  // if n <= 10 ^4
int bfs1(int s ){
    queue<int> q;
    q.push(s) , len[s] = 0;
    int cur = s , dep = 0 , sz = 1;
    for(; !q.empty() ; ++dep , sz = q.size()){
        while(sz--){
            cur = q.front() , q.pop();
            for(int i = 1 ; i <= n ; ++i)
                if( adj[cur][i] && len[i] == OO)    q.push(i) , len[i] = dep + 1;
        }
    }
    return len[n];
}
int main() {
    scanf("%d %d" , &n , &m);
    for(int i = 0 ; i < m ; ++i){
        scanf("%d %d" , &x , &y);
        adj[x][y] = adj[y][x] = 1 ;
    }
    memset(len , OO , sizeof len);
	ans = bfs1(1);
    printf("%d\n", (ans != OO) ? ans : -1);
    return 0;
}
*****************************************************************************************
int main() {


	return 0;
}
