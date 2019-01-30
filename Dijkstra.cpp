

************************************************** Dijkstra Algo**********************************************
~-Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph~-

1- work on non negative weight graph ==> no negative weight
2- relaxation mean == if i remove a node but keep all information about it "entering / outing "
3- periprity queue >> sorting increasing order ==> 10 , 9 , 8 ...
4- why use preiority queue == > because the minimum cost at the begining of the queue


*****************************************Code with greater " without multiplay - " Awsome ************************************************
#include <bits/stdc++.h>
using namespace std;
const int N = (1<<22), M = (1<<18), OO = 0x3f3f3f3f;
typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
#define cost first
#define id second
vector<pii> adj[N];
int n, m, u, v, c, src , ans;
int dis[N];
bool f;
void Dijkstra(int src , int en){ // O(n log n )
    memset(dis, OO, sizeof dis);
    priority_queue< pii,vector<pii>,greater<pii> > pq; // priority_queue< pair<int, int> ,vector<pair<int, int> >,greater<pair<int, int> > > pq;
	pq.push({0, src});
	dis[src] = 0;
	while(!pq.empty()){
		pii u = pq.top();
		pq.pop();
		if(d[u.id] < u.cost)    continue;
		 if(u.id == en){
            ans = u.cost;
            return ;
		 }
		for(auto ch : adj[u.id])
            if(d[ch.id] > u.cost + ch.cost){
               d[ch.id] = u.cost + ch.cost;
               pq.push( { (d[ch.id] , ch.id) } );
			}
    }
   f = 1 ;// we couldn't reach target
    return;
}
int main() {
	scanf("%d %d", &n, &m);

	adj = vector< vector<pii> > (n+1);

	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	scanf("%d %d", &src , &en);
	Dijkstra(src , en);
        if(f)    puts("NO");
        else     printf("%d\n" , ans);
//	for(int i = 1 ; i <= n ; ++i){
//		printf("Shortest path from %d to %d is %d\n", s, i, dis[i]);
//	}
  return 0;
}

***********************************************Mohamed magdy*****************************************************
#include <bits/stdc++.h>

using namespace std;

const int N = (1<<22), M = (1<<18), OO = 0x3f3f3f3f;

vector<vector<pair<int ,int >>> adj(20005);
int n, m, u, v, c, src;
int dis[N];

void Dijkstra(int src){ // O(n log n )
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<pair<int, int>> pq; // first ==> from , second ==> source
	pq.push({0, src});
	dis[src] = 0;
	while(!pq.empty()){
		int p = pq.top().second;  // to
		int d = -pq.top().first; // cost
		pq.pop();
		if(d > dis[p])	continue;
		for(pair<int, int> ch : adj[p]){    // other node form p to can reached
		    // ch.first  ==> cost of p to ch
           //  ch.second ==> the adjacent node of p
			if(dis[ch.second] >  d+ch.first){
				dis[ch.second] = d+ch.first;
				pq.push( { -dis[ch.second], ch.second } );
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	adj = vector< vector < pair <int ,int > > >(n+1);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	memset(dis, OO, sizeof dis);
	scanf("%d", &src);
	Dijkstra(src);
	for(int i = 1 ; i <= n ; ++i){
		printf("Shortest path from %d to %d is %d\n", s, i, dis[i]);
	}
  return 0;
}


**********************************************************Dijkstra path****************************************************
int t , n , m , a , b , c , src , en , par[N];
vector<pair<int,int>> adj[N];
bool vis[N] , f;
ll ans , dis[N] ;
vector<int> v;
ll Dijkstra(int src  , int destination){
    memset(par, -1, sizeof par);
    memset(dis , OO , sizeof dis);
    priority_queue<pair<ll , int >> pq;
    pq.push({0 , src});
    dis[src] = 0;
    while(!pq.empty()){
        int p = pq.top().second;      // to
        ll d = -pq.top().first;     // cost
        pq.pop();
        if(d > dis[p])         continue;
        if(p == destination)   break;
        for(pair<ll ,int> ch : adj[p])
            if(dis[ch.second] > d + ch.first){
                dis[ch.second]  = d + ch.first;
                pq.push( {-dis[ch.second] , ch.second} );
                par[ch.second] = p;
            }
        }
    return dis[destination];
}
int main() {
        scanf("%d %d" , &n , &m);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d" , &a , &b ,&c);
            adj[a].push_back({c , b});
            adj[b].push_back({c , a});
        }
        ans = Dijkstra(1 , n);
        if (ans < INF || par[n] != -1){
            int node = n;
            while (node != -1) {
                v.push_back(node);
                node = par[node];
            }
            for (int i = v.size() - 1; i >= 0; --i)     printf("%d%c", v[i] , " \n"[i == 0]);
      } else  puts("-1");
  return 0;
}
