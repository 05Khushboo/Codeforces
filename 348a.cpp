#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll mx = a[0],x = 0;
  for(ll i = 0;i<n;i++) mx = max(mx,a[i]),x+=a[i];
  x = ceil((x*1.0)/(n-1));
  if(x<mx) x = mx;
  cout<<x;
  return 0;
}
