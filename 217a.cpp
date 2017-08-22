#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1001;
ll graph[N][N],visited[N][N];
void dfs(ll x,ll y)
{
  visited[x][y] = 1;
  for(ll i = 0;i<N;i++)
  {
    if(graph[x][i]&&visited[x][i]==0)
      dfs(x,i);
    if(graph[i][y]&&visited[i][y]==0)
      dfs(i,y);
  }
}
int main()
{
  for(ll i = 0;i<N;i++)
    for(ll j = 0;j<N;j++)
      graph[i][j] = visited[i][j] = 0;
  ll n,ans=0; cin>>n;
  while(n--)
  {
    ll x,y; cin>>x>>y;
    graph[x][y] = 1;
  }
  for(ll i = 1;i<N;i++)
    for(ll j = 1;j<N;j++)
      if(graph[i][j]&&visited[i][j]==0)
        ans++,dfs(i,j);
  cout<<ans-1;
  return 0;
}
