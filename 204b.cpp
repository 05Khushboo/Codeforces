#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  map<ll,pair<ll,ll> > m;
  for(ll i = 0;i<n;i++)
  {
    ll x,y; cin>>x>>y;
    if(m.find(x)==m.end()) m[x] = make_pair(1,0);
    else m[x].first++;
    if(m.find(y)==m.end()) m[y] = make_pair(0,1);
    else if(x!=y) m[y].second++;
  }
  ll ans =1E15,sz;
  sz = ceil(n/2.0);
//   cout<<sz<<" ";
  for(auto k : m)
  { 
//     cout<<k.first<<"K";
    pair<ll,ll> p = k.second;
    ll x = p.first;
    ll y = p.second;
//     cout<<x<<" "<<y<<" ";
    if(x>=sz) { ans = 0; break; }
    else if((x+y)>=sz)
    {
      ans = min(ans,(sz-x));
    }
  }
  if(ans==1E15) ans = -1;
  cout<<ans;
  return 0;
}
