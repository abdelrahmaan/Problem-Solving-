#include <bits/stdc++.h>
#define ll long long
#define eps 1e-15
using namespace std;
const int o = 15 , N = 1e6+6 , MAX = 100;  , OO = 1000000009;
ll gcd(ll a, ll b) { return !b ? a : gcd(b , a % b); }
ll lcm(ll x, ll y) { return (x * y / gcd(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};

/*
    DFS ==> topological sort , connected component
*/
vector<pair<int, int> > edgelist;			            //unweighted edge list
vector<pair<int, pair<int, int> > wEdgeList;		    //weighted edge list

bool adjMat[N][N];					                    //unweighted adjacency matrix
int wAdjMat[N][N];					                    //weighted adjacency matrix

vector<int> adjList[N];					                //unweighted adjacency list
bool vis[N];

vector<pair<int, int> > wAdjList[N];			        //weighted adjacency list

vector<int> topsort; //DAG

int n, m, u, v, c;

bool valid(int i, int j) { 	return 1;	}
char maze[MAX][MAX];
bool vis[MAX][MAX];

void DFS(int node){    // O(E+V)
	vis[node] = 1;
	for(int ch : adjList[node])
		if(!vis[ch])	DFS(ch);
    topsort.push_back(node);	// DAG // Other way Indegree / Outdegree OR ==> printf("%d ", node);

}

int ConnectedComponenetsCnt(){  // O(E+V)
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++i)   if(!vis[i])	DFS(i) , ++cnt;
	return cnt;
}

void cntReachalbleCells(int r, int c)
{ // Flood Fill
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
		return;		// invalid position or block position


	vis[r][c] = 1;	// we just visited it, don't allow any one back to it
	cnt++;

	// Try the 4 neighbor cells
	cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
//    for(int k = 0 ; k < 8 ; ++k){
//		int xc = dx[k] + i;
//		int yc = dy[k] + j;
//		if(valid(xc,yc) && !vis[xc][yc] && grid[xc][yc] == 'X' )    dfs(xc,yc);
//	}
}

int main(){
    cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){			//number of edges
		cin >> u >> v;				        // from, to
		adj1[u].push_back(v);
		adj1[v].push_back(u);			    //for undirected graphs

		/*	in a weighted graph
		cin >> u >> v >> c;
		adj2[u].push_back({c, v});
		adj2[v].push_back({c, u});
		*/

		/*	or using adjacency matrix
		adj3[u][v] = c;
		adj3[v][u] = c;
		*/
	}
		// Flood Fill...given maze where cells are . or X. You start at 0, 0..how many cells you could reach?
/*
..X.
.X.X
..X.

...x.
..x..
.x...
x....


....X...
....XXXX
..X.....
.X....XX
..X.X.X.
..X...X.
...X..XX
*/

// A reachable block is called connected components. Each set of positions reachable together are connected component.

    return 0;
}
