#include<bits/stdc++.h>
using namespace std;
int X[4] = {-1,1,0,0};
int Y[4] = {0,0,1,-1};
int n,m,k;
int vi[101][101],arr[101][101],k1=0,chain[101][101];
vector<pair<int,int> > v[3001];
int check(int x,int y)
{ 
  if(arr[x][y]==0) return 0;
  if((x>=0&&x<n)&&(y>=0&&y<m)) return 1;
  else return 0;
}
void dfs(int s,int s1)
{ 
  v[k1].push_back({s,s1});
  chain[s][s1] = k1;
  vi[s][s1] = 1;
  for(int i = 0;i<4;i++)
  {
    int x = s + X[i];
    int y = s1 + Y[i];
    if((vi[x][y]==0)&&check(x,y)==1)
    {
      dfs(x,y);
    }
  }
}
int main()
{
 cin>>n>>m>>k;
  for(int i = 0;i<n;i++)
  {
    for(int j=0;j<m;j++) 
    { vi[i][j]=0;
      char x; cin>>x;
      if(x=='*') arr[i][j] = 0;
      else arr[i][j] = 1;
    }
  }
   for(int i =0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(vi[i][j]==0&&arr[i][j]==1)
      {        dfs(i,j);
        k1++;
      }
    }
  }
  vector<pair<int,int> > a;
  for(int i = 0;i<k1;i++)
  { int flag = 0;
    for(int j = 0;j<v[i].size();j++)
    {
      int x = v[i][j].first;
      int y = v[i][j].second;
      if(x==0||x==(n-1)||y==0||y==(m-1)) {
        flag = 1; break;
      } 
    }
    if(flag==0)
    { 
      a.push_back({v[i].size(),i});
    }
  }
    sort(a.begin(),a.end());
  int vis[k1],cnt =0;
  int p = a.size();
  for(int i=0;i<k1;i++) vis[i] = 0;
  for(int i = 0;i<(p-k);i++)
  {
    int no = a[i].second;
    vis[no] = 1;
  }
  for(int i = 0;i<a.size();i++)
  { int idx = a[i].second;
    for(int j = 0;j<v[idx].size();j++)
    {
      int x = v[idx][j].first;
      int y = v[idx][j].second;
      if(vis[idx]==1) { arr[x][y]=0; cnt++;}
    }
  }
  cout<<cnt<<endl;
  for(int i =0;i<n;i++)
  {
    for(int j= 0;j<m;j++)
    {
      if(arr[i][j]==0) cout<<"*";
      else cout<<".";
    }
    cout<<endl;
  }
  return 0;
}
