#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1E5+1;
ll inf = 1E18;
map<ll,ll> graph[N];
void dijkstra(ll s,ll n)
{
  ll dist[n+1],visited[n+1],arr[n+1];
  fill(dist,dist+n+1,inf);
  fill(arr,arr+n+1,0);
  fill(visited,visited+n+1,0);
  dist[s] = 0;
  arr[s] = 0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
  pq.push({0,s});
  while(!pq.empty())
  {
    ll u = pq.top().second;
    ll w = pq.top().first;
    pq.pop();
    if(visited[u]) continue;
    visited[u] = 1;
    for(auto k : graph[u])
    {
      if(visited[k.first]) continue;
      if(dist[k.first]> (w+k.second))
      {
        arr[k.first] = u;
        dist[k.first] = w + k.second;
        pq.push({dist[k.first],k.first});
      }
    }
  }
  if(dist[n]==inf) { cout<<-1; return ;}
  vector<ll> v;
  v.push_back(n);
  for(ll i = n;i>1;)
  {
    v.push_back(arr[i]);
    i = arr[i];
  }
    reverse(v.begin(),v.end());
    for(auto k:v) cout<<k<<" ";
}
int main()
{
  ll n,m;
  cin>>n>>m;
  while(m--)
  {
    ll u,v,w; cin>>u>>v>>w;
    if(graph[u].find(v)==graph[u].end())
    {
      graph[u][v] = graph[v][u] = w;
    }
    else
    {
      ll mx = max(graph[u][v],w);
      graph[u][v] = graph[v][u] = mx;
    }
  }
  dijkstra(1,n);
  return 0;
}
