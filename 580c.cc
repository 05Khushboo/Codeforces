#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> Adj[N];
int cat[N], m, n;
int ans;

void dfs(int node, int cats, int par){
    int leaf = true;
  for(int adj: Adj[node]){
//     cout<<adj<<"adj"<<" ";
    if(adj == par) continue;
    leaf = false;
    if(cat[adj]){
//       if(cats+1 > m) cerr << "passed for adj: " << adj << endl;
      if(cats+1 > m) continue;
      dfs(adj, cats+1, node);
    }else{
//       cerr << "passed for adj: " << adj << endl;
      dfs(adj, 0, node);
    }
    leaf = false;
  }
  if(leaf){
//     cerr << node << " is leaf " << endl;
    ans++;
  }
}

int main(void){
  int xi, yi;
  cin >> n >> m;
  for(int i = 0; i < n; i += 1) cin >> cat[i];
  for(int i = 0; i < n-1; i++){
    cin >> xi >> yi;
    xi--, yi--;
    Adj[xi].push_back(yi);
    Adj[yi].push_back(xi);
  }
//   for(int i = 0; i < n; i += 1){
//     cerr << i << ": ";
//     for(int adj: Adj[i]) cerr << adj << " ";
//     cerr << endl;
//   }
  if(cat[0])
    dfs(0, 1, -1);
  else
    dfs(0, 0, -1);
  cout << ans << endl;
}

