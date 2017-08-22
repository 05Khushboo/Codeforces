#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll a[n];
  for(ll i = 0;i<n;i++) cin>>a[i];
  ll dp[501][501];
  for(ll ik = 0;ik<n;ik++)
  {
    for(ll i = 0;i<n;i++)
    {
      ll j = i+ik;
      if(j<n)
      {
        if(i>j) dp[i][j] = 0;
        else if(i==j) dp[i][j] = 1;
        else
        {
          dp[i][j] = (j-i+1);
          if(j==(i+1)&&a[i]==a[j]) dp[i][j] = min(dp[i][j],1LL);
          if(i<(n-1)&&(i+1)<=j) 
          {
            ll mn = (1+dp[i+1][j]);
            dp[i][j] = min(mn,dp[i][j]);
          }
          if((((i+2)<n)&&a[i]==a[i+1])&&(i+2)<=j) dp[i][j] = min(dp[i][j],1+dp[i+2][j]);
          for(ll k = i+2;k<=j;k++)
          {
            if(a[i]==a[k])
            {
              ll mn = dp[i+1][k-1];
              if((k+1)<=j) mn+=dp[k+1][j];
              dp[i][j] = min(dp[i][j],mn);
            }
          }
        }
//         cout<<dp[i][j]<<" ";
      }
    }
//     cout<<endl;
  }
  cout<<dp[0][n-1];
  return 0;
}
