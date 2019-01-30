****************************************************** My Code *******************************************
#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e5+5 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX =  111 , OO = 0x3f3f3f3f , MOD = 1e9+7  , inf =  1 << 30;
const ll INF = (ll)1e18;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
//bool valid (int i , int j){ return i >= 0 && j >= 0 && i < n && j < m ;}
//int X[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
//int Y[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//len any int num > 0 ... len = ceil(log10(a+1));
//len any int num > 0 ... len = ceil(log10(a+1));
struct node {   int to  , weight ; };
vector <node> edges[100] ;
int n , m , u , v , w , dist[N] ;
void zeroOneBFS(int src){
    deque <int> dq;
    dist[src] = 0;
    dq.push_back(src);
    int cur = src;
    while (!dq.empty()) {
        cur = dq.front() , dq.pop_front();
        for (int i = 0 ; i < edges[cur].size(); i++) { // checking for the optimal distance
            if (dist[edges[cur][i].to] > dist[cur] + edges[cur][i].weight){
                dist[edges[cur][i].to] = dist[cur] + edges[cur][i].weight;
                // Put 0 weight edges to front and 1 weight
                // edges to back so that vertices are processed
                // in increasing order of weights.
                if (edges[cur][i].weight == 0)  dq.push_front(edges[cur][i].to);
                else                            dq.push_back(edges[cur][i].to);
            }
        }
    }

    // printing the shortest distances
    for (int i = 0 ; i <= n ; ++i)   printf("%d " , dist[i]);
    puts("");
}
int main(){
   scanf("%d %d" , &n , &m);
   for(int i = 0; i < m ; ++i){
        scanf("%d %d %d" , &u , &v , &w);
        edges[u].push_back({v , w});
        edges[v].push_back({u , w});
   }
   edges[n+1];
   memset(dist , OO , sizeof dist);
   zeroOneBFS(0);
   return 0;
}
/***********************************************************************************************************************/

#include <bits/stdc++.h>
#define ll long long
#define clr(v, d)		memset(v, d, sizeof(v))
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define Abdulrahman ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+9 ,  nBits = 2e8 +5 , M = (1 << 16) , MAX =  1000 , OO = 0x3f3f3f3f , MOD = 1e9  , inf =  1 << 30;
const ll INF = (ll)1e18;
ll GCD(ll a, ll b) { return !b ? a : GCD(b , a % b); }
ll LCM(ll x, ll y) { return (x * y / GCD(x, y)); }
ll fact(ll z)      { return (z <= 1) ? 1 : z * fact(z - 1); }
bool valid(int i , int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }
int dx[] = {0 , 0  , 1 , -1 , 1 , -1 ,  1 , -1};
int dy[] = {1 , -1 , 0 , 0 ,  1 , -1 , -1 ,  1};
//int dx[] = {0 , 0  , 1 , -1 };
//int dy[] = {1 , -1 , 0 , 0 };
//len any int num > 0 ... len = ceil(log10(a+1));
//len any int num > 0 ... len = ceil(log10(a+1));

struct node {       // a structure to represent edges
    int to, weight;
};
vector <node> edges[V];         // vector to store edges
// Prints shortest distance from given source to every other vertex
void zeroOneBFS(int src) {
    // Initialize distances from given source
    int dist[V];
    for (int i=0; i<V; i++)     dist[i] = INT_MAX;
    // double ende queue to do BFS.
    deque <int> Q;
    dist[src] = 0;
    Q.push_back(src);

    while (!Q.empty())  {
        int v = Q.front();
        Q.pop_front();

        for (int i=0; i < edges[v].size(); i++)   {  // checking for the optimal distance
            if (dist[edges[v][i].to ] > dist[v] + edges[v][i].weight) {
                    dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
                // Put 0 weight edges to front and 1 weight
                // edges to back so that vertices are processed
                // in increasing order of weights.
                if (edges[v][i].weight == 0)
                    Q.push_front(edges[v][i].to);
                else
                    Q.push_back(edges[v][i].to);
            }
        }
    }

    // printing the shortest distances
    for (int i=0; i<V; i++)
        cout << dist[i] << " ";
}

void addEdge(int u, int v, int wt)
{
   edges[u].push_back({v, wt});
   edges[v].push_back({u, wt});
}

// Driver function
int main()
{
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);
    int src = 0;//source node
    zeroOneBFS(src);
    return 0;
}
