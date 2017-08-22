#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll arr[n],s=0;
  for(ll i = 0;i<n;i++) {cin>>arr[i]; s+=arr[i];}
  if(s%3!=0) cout<<"0";
  else{
    s/=3;
    ll p = 0,cnt[n],sum[n];
    for(ll i = n-1;i>=0;i--)
    {
      p+=arr[i];
      if(p==s) cnt[i] = 1;
      else cnt[i] = 0;
      sum[i] = cnt[i];
      if((i+1)<n) sum[i]+=sum[i+1];
    }
    p = 0;
    set<ll> su(sum,sum+n);
    ll k = su.size()-1;
    ll ans = 0;
    for(ll i = 0;i<n;i++)
    {
      p+=arr[i];
      if((p==s)&&(i+2)<n)
      { 
        ans+=sum[i+2];
      }
    }
    cout<<ans;
  }
  return 0;
}
