#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll mn = 0,h[n+1],ans[n+1];
  for(ll i = 1;i<=n;i++) cin>>h[i];
  for(ll i = 1;i<=n;i++)
  {
    mn = min(mn,h[i]-i);
    ans[i] = i + mn;
  }
  mn = n+1;
  for(ll i = n;i>=1;i--)
  {
    mn = min(mn,h[i]+i);
    ans[i] = min(ans[i],mn-i);
  }
  ll mx = ans[1];
  for(ll i=1;i<=n;i++)
  {
    mx = max(ans[i],mx);
  }
  cout<<mx;
  return 0;
}
