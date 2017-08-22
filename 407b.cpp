#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1E9+7;
int main()
{
  ll n; cin>>n;
  ll a[n];
  for(ll i=1;i<=n;i++) cin>>a[i];
  ll dp[n+1],sum = 0;
  dp[0] = 0;
  for(ll i=1;i<=n;i++)
  {
    if(a[i]==i)
    {
      dp[i] = 2;
      dp[i]+=dp[i-1];
      dp[i]%=mod;
    }
    else
    {
      dp[i] = 0;
      dp[i] = (dp[i-1]-dp[a[i]-1]+2+mod)%mod; 
      dp[i]+=dp[i-1];
      dp[i]%=mod;
  }
  }
  cout<<dp[n]<<endl;
  return 0;
}
