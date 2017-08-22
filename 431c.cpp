#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1E9 + 7;
int main()
{
  ll n,k,d; cin>>n>>k>>d;
  ll dp[n+1][2];
  dp[0][0] = 1;
  dp[0][1] = 0;
  for(ll i = 1;i<=n;i++)
  {
    dp[i][0] = dp[i][1] = 0;
    for(ll j = 1;j<=min(d-1,i);j++)
    {
      dp[i][0]+=dp[i-j][0];
      dp[i][0]%=mod;
    }
    for(ll j=1;j<=min(d-1,i);j++)
    {
      dp[i][1]+=dp[i-j][1];
      dp[i][1]%=mod;
    }
    for(ll j = d;j<=min(i,k);j++)
    {
      dp[i][1]+= (dp[i-j][1] + dp[i-j][0])%mod;
      dp[i][1]%=mod;
    }
  }
  cout<<dp[n][1];
  return 0;
}
