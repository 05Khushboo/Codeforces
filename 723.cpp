void dfs(ll s,ll p)
{ 
  for(auto v:graph[s])
  {
    arr[v][s] = 1;
    if(v==p) continue;
    dfs(v,s);
  }
}
