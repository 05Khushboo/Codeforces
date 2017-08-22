#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[2002][2002];
int main()
{
  ll n,k; cin>>n>>k;
  ll mod = 1E9 + 7;
   for(ll i = 0;i<=k;i++)
  {
    for(ll j=0;j<=n;j++)
    {
      dp[i][j] =0;
      if(i==1) dp[i][j] = 1;
    }
  }
  for(ll ik=1;ik<=k;ik++)
  {
  for(ll i = 1;i<=n;i++)
  {
    for(ll j =i;j<=n;j+=i)
    {
    if(ik!=1)  dp[ik][j]+=dp[ik-1][i];
         dp[ik][j]%=mod;
    }
  }
  }
  ll ans =0;
  for(ll i = 1;i<=n;i++) ans+=dp[k][i],ans%=mod;
    cout<<ans;
  return 0;
}
