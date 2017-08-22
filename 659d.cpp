#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int  main()
{
  ll n; cin>>n;
  pair<ll,ll> v[n];
  for(ll i = 0;i<n;i++)
  {
    ll x,y; cin>>x>>y;
    v[i].first = x;
    v[i].second = y;
  }
 ll ans = (n-4)/2; 
  cout<<ans;
  return 0;
}
