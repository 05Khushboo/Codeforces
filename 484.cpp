#include<bits/stdc++.h>
using namespace std;
#define ll long int
const ll N = 1E6+1;
ll arr[N];
ll binary(ll l,ll r,ll x,ll y,ll n)
{
  ll mid = -1;
  while(l<=r)
  {
    if(mid==(l+r)/2) break;
    mid = (l+r)/2;
    if(arr[mid]>y) r = mid;
    else if(arr[mid]<x) l = mid;
    else l = mid;
  }
  if((mid+1)<n)
  {
    if((arr[mid+1]<y)&&arr[mid+1]>x) mid = mid+1;
  }
  if(arr[mid]<=x||arr[mid]>=y) return -1;
  return mid;
}
ll binary1(ll l,ll r,ll x,ll n)
{
  ll mid = -1;
  while(l<=r)
  {
    if(mid==(l+r)/2) break;
    mid = (l+r)/2;
    if(arr[mid]>=x) r = mid;
    else l = mid;
  }
  if((mid+1)<n)
  {
    if(arr[mid+1]<x) return -1;
    else return mid+1;
  }
  return mid;
}
int main()
{
  ll n; cin>>n;
  ll mx,ans=0;
  vector<ll> v;
  for(ll i = 0;i<n;i++) cin>>arr[i];
  v.push_back(arr[0]);
  mx = arr[0];
  for(ll i = 1;i<n;i++) 
  {
    mx = max(mx,arr[i]);
    if(arr[i-1]!=arr[i])
    {
      v.push_back(arr[i]);
    }
  }
  sort(v.begin(),v.end());
  ll p = 0;
  ans = 0;
  for(auto k : v) arr[p++] = k; 
  for(auto k : v)
  {
    if(k==1) continue;
    ll vl = mx/k;
    vector<ll> v1;
    for(ll j = 1;j<=vl;j++)
    {
      v1.push_back(k*j);
    }
    for(auto k1 : v1)
    { 
      ll size = v.size();
      ll idx1 = binary(0,size-1,k1,k1*k,size);
      if(idx1==-1) continue;
      else ans = max(ans,arr[idx1]%k);
    }
  }
  cout<<ans;
  return 0;
}
