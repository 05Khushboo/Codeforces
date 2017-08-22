#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  vector<pair<ll,ll> > v;
  for(ll i=0;i<n;i++)
  {
    ll x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(),v.end());
  ll ans = v[0].second;
  for(ll i=0;i<n;i++)
  {
    ll a = v[i].first;
    ll b = v[i].second;
    if(ans>b) ans =a;
    else ans = b;
  }
  cout<<ans;
  return 0;
}
