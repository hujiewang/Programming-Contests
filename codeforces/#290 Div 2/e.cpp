#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
//
// Running time:
//     O(|V|^3)
//
// INPUT: 
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).


struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    //cout<<from<<" --> "<<to<<endl;
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

bitset<40001> bs;
void sieve(LL upperbound){
  int _sieve_size=upperbound+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(LL i=2;i<=_sieve_size;i++){
    if(bs[i]){
      for(LL j=i*i;j<=_sieve_size;j+=i){
         bs[j]=0;
      }
      // primes.push_back(i);
    }
  }
}
int n;
int a[201];
bool vis[201];
bool m[201][201];
vector<vector<int> > rv;
void getCycle(int u){
  vis[u]=true;
  rv[rv.size()-1].push_back(u);
  for(int j=1;j<=n;j++){
    if(!vis[j]&&m[u][j]){
      getCycle(j);
    }
  }
}
int main(){
  sieve(40000);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  PushRelabel pr(n+2);
  for(int i=1;i<=n;i++){
    if(a[i]%2==0){
      for(int j=1;j<=n;j++){
	if(a[j]%2==1&&bs[a[i]+a[j]]){
	  pr.AddEdge(i,j,1);
	}
      }
    }
  }
  int expected=0;
  for(int i=1;i<=n;i++){
    if(a[i]%2==0){
      pr.AddEdge(0,i,2);
      expected+=2;
    }
    else{
      pr.AddEdge(i,n+1,2);
    }
  }
  int maxflow=pr.GetMaxFlow(0,n+1);
  if(maxflow!=expected){
    cout<<"Impossible"<<endl;
    return 0;
  }
  memset(m,false,sizeof(m));
  for(int i=1;i<=n;i++){
    if(a[i]%2==0){
      for(int j=0;j<pr.G[i].size();j++){
	Edge e=pr.G[i][j];
	if(e.cap>0&&e.flow>0){
	  m[i][e.to]=true;
	  m[e.to][i]=true;
	}
      }
    }
  }
  memset(vis,false,sizeof(vis));
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      rv.push_back(vector<int>());
      getCycle(i);
    }
  }
  cout<<rv.size()<<endl;
  for(auto i:rv){
    cout<<i.size();
    for(auto j:i){
      cout<<" "<<j;
    }
    cout<<endl;
  }
  return 0;
}
