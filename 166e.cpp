#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[4];
int main()
{
  ll n; cin>>n;
  ll mod = 1E9 + 7;
  dp[0] = 0; dp[1]=dp[2]=dp[3] = 1;
  ll a[4];
  for(ll i=0;i<4;i++) a[i] = 0;
  for(ll j = 2;j<=n;j++)
  {
    for(ll i = 0;i<4;i++)
    {
      a[i]+=(dp[0]+dp[1]+dp[2]+dp[3])%mod;
      if(dp[i]>a[i]) a[i]=(a[i]-dp[i]+mod)%mod;
      else a[i]-=dp[i]; 
    }
    for(ll i=0;i<4;i++)
    {
      dp[i] = a[i];
      a[i] = 0;
//       cout<<dp[i]<<" ";
    }
//     cout<<j<<endl;
  }
  cout<<dp[0];

  return 0;
}
