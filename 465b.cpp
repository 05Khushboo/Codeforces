#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n,ans=0; cin>>n;
  vector<ll> v;
  for(ll i = 0;i<n;i++) 
  {
    ll x; cin>>x;
    if(x==1) v.push_back(i);
  }
  if(v.size()==0) ans = 0;
  else
  {
    n = v.size()-1;
    ans = 1;
    for(ll i = 1;i<=n;i++)
    {
      if((v[i]-v[i-1])>1) ans+=2;
      else ans++;
    }
  }
  cout<<ans;
  return 0;
}
