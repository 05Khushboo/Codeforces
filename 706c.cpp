#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll c[n];
  for(ll i = 0;i<n;i++) cin>>c[i];
  string s[n];
  for(ll i=0;i<n;i++) cin>>s[i];
  ll dp[n][2];
  dp[0][0] = 0;
  dp[0][1] = c[0];
  for(ll i = 1;i<n;i++)
  {
    string a = s[i-1];
    string reva = s[i-1];
    reverse(reva.begin(),reva.end());
    string b = s[i];
    string revb = s[i];
    reverse(revb.begin(),revb.end());
    dp[i][0] = dp[i][1] = 1E15;
    if(b>=a) dp[i][0] = dp[i-1][0];
    if(b>=reva) dp[i][0] = min(dp[i][0],dp[i-1][1]);
    if(revb>=a) dp[i][1] = dp[i-1][0];
    if(revb>=reva) dp[i][1] = min(dp[i][1],dp[i-1][1]);
    dp[i][1]+=c[i];
  }
  ll ans = min(dp[n-1][0],dp[n-1][1]);
  if(ans==1E15) ans = -1;
  cout<<ans;
  return 0;
}
