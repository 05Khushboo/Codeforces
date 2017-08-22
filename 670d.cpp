#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n,k; cin>>n>>k;
  ll a[n],b[n];
  vector<pair<ll,ll> > c;
  for(ll i=0;i<n;i++) cin>>a[i];
  for(ll i=0;i<n;i++) cin>>b[i];
  for(ll i=0;i<n;i++)
  {
    ll x = b[i]/a[i];
    c.push_back({x,i});
  }
  sort(c.begin(),c.end());
  ll sum = 0;
  ll x = c[0].first;
  ll idx = c[0].second;
  sum+= a[idx]- (b[idx] - x*a[idx]);
  ll ans = 0;
  ans = 0;
  ll nx = n-1;
  for(ll i=1;i<n;i++)
  { if(sum>k) { nx = i-1;
                break;}
    ll x1 = c[i].first;
    idx = c[i].second;
    if(x1==x) sum+= a[idx]- (b[idx] - x1*a[idx]); 
    else {
      sum+= a[idx]-(b[idx]-x1*a[idx]);
      ll diff = x1-x;
      ans*=(diff+1);
      sum+=ans;
      x = x1;
    }
    ans+=a[idx];
  }
  if(sum<k)
  {
    ll k1 = k -sum;
    ll p1 = ans/k1;
    x+=p1;
    cout<<x;
    return 0;
  }
  while(sum>k) 
  { ll id = c[nx].second;
    ll p = a[id]-(b[id]-x*a[id]);
    ans-=a[id];
    ll x1=x;
    for(ll i = nx-1;i>=0;i--)
    { x1 = c[i].first;
      ll idx = c[i].second;
      if(x1!=x) break;
      ans-=a[idx];
    }
    ll diff = (x1-x);
    p = ans*(diff+1);
    sum-=p;
    if(sum<=k) break;
    nx = x1;
    x = x1;
    if(x==0) break;
  }
  cout<<x;
  return 0;
}
