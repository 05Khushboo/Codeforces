#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1E6+1;
ll a[N],b[N],n,k,k1;
ll possible(ll no)
{
  ll sum = 0,p =0;
  for(ll i = 0;i<n;i++)
  {
    sum=(a[i]*no);
    p=b[i];
    if(p>=sum) continue;
    else 
    {
      ll diff = sum-p;
      if(diff>k) return 0;
      k-=diff;
    }
  }
   return 1;
}
ll binary(ll l,ll r)
{
  ll mid = -1;
  while(l<=r)
  { k = k1;
    if(mid==(l+r)/2) break;
    mid = (l+r)/2;
    if(possible(mid)==1) l = mid;
    else r = mid;
  }
  return mid;
}
int main()
{ 
  cin>>n>>k1;
  k = k1;
  ll sum = 0,p=0;
  for(ll i = 0;i<n;i++) cin>>a[i];
  for(ll i =0;i<n;i++)  cin>>b[i];
  ll ans = binary(0,1E10);
  cout<<ans;
}
