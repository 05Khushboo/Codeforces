#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 1E5 +2;
vector<ll> graph[N];
ll n,visited[N],ans,parent[N];
ll bfs(ll source)
{
  ll u = source; 
  visited[u] = 1;
  vector<ll> arr;
  arr.push_back(source);
  map<ll,ll> maparr;
  maparr[source] = 0;
  ll idx = 0;
  parent[source] = -1;
  while(idx<arr.size())
  {
    for(auto adj : graph[arr[idx]])
    {
      if(visited[adj]==1) continue;
      arr.push_back(adj);
      maparr[adj] = 1;
      visited[adj] = 1;
      parent[adj]=arr[idx];
    }
    idx++;
  }
  ll flag = 0;
  while(idx>1)
  {
    ll last = arr[idx-1];
    arr.pop_back();
    maparr[last]=0;
    idx--;
    for(auto adj : graph[last])
    { 
      if(adj==parent[last]) continue;
      if(maparr[adj]==0) continue;
      if(maparr[adj]==1) return 0;
    }
  }
  return 1;
}
int main()
{
  ll m; cin>>n>>m;
  for(ll i=0;i<m;i++)
  {
    ll x,y; cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  fill(visited,visited+n+1,0);
  for(ll i=1;i<=n;i++)
  {
    if(visited[i]==0) ans+=bfs(i);
    visited[i] = 1;
  }
  cout<<ans;
  return 0;
}
