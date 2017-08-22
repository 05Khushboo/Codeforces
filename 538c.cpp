#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll possible(ll d,ll h,ll d1,ll h1,ll mid)
{
  ll diff = mid - h;
  d = d + diff;
  if(d>d1) return 0;
  diff = mid - h1;
  d = d + diff;
  if(d>d1) return 0;
  else  return 1;
}
ll binary_search(ll d,ll h,ll d1,ll h1,ll l,ll r)
{
  ll mid=-1,f = 0;
  while(l<=r)
  {
    if((mid)==((l+r)/2)) break;
    mid = ((l+r)/2);
    if(possible(d,h,d1,h1,mid)) l=mid,f=1;
    else r = mid;
  }
  if(possible(d,h,d1,h1,mid+1)) mid=mid+1,f=1;
  if(f) return mid;
  else return -1;
}
int main()
{
  ll n,m,d,h;
  cin>>n>>m>>d>>h;
  ll ans=-1,f=0;
  m--;
  ans = d+h-1;
  while(m--)
  {
    ll d1,h1; cin>>d1>>h1;
    ll mx = binary_search(d,h,d1,h1,max(h,h1),1E9);
    if(mx!=-1)  ans = max(ans,mx);
    else  f = 1;
    d=d1,h=h1;
  }
  ans = max(ans,(n-d)+h);
  if(f==0) cout<<ans;
  else  cout<<"IMPOSSIBLE";
}



