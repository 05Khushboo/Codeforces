#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 2001;
vector<ll> graph[N];
ll visited[N],n,arr[N],p=0,mx=0;
void dfs(ll s)
{ 
  visited[s] = 1;
  for(auto adj : graph[s])
  {
    if(visited[adj]==0)
    {
      p++;
      if(p>mx) mx = p;
      dfs(adj);
      p--;
    }
  }
}
int main()
{
  cin>>n;
  for(ll i = 1;i<=n;i++)
  {
   visited[i] = 0; 
    ll x; cin>>x;
    arr[i] = x;
    if(x!=-1) 
    {
      graph[x].push_back(i);
      graph[i].push_back(x);
    }
  }
  for(ll i = 1;i<=n;i++)
  {
    if(visited[i]==0&&arr[i]==-1)
    { 
      p = 0;
      dfs(i);
    }
  }
  cout<<mx+1;
  return 0;
}
