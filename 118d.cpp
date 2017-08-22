#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll N1,N2,K1,K2;
ll dp[101][101][21][21];
ll mod = 1E8;
int main()
{
  cin>>N1>>N2>>K1>>K2;
  for(ll n1 = 0;n1<=N1;n1++)
  {
    for(ll n2 = 0;n2<=N2;n2++)
    {
      for(ll k1 = 0;k1<=K1;k1++)
      {
        for(ll k2=0;k2<=K2;k2++)
        {
          if(n1==0) 
          {
            if(n2>K2) dp[n1][n2][k1][k2] = 0;
            else dp[n1][n2][k1][k2] = 1;
            
          }
          else if(n2==0)
          {
            if(n1>K1) dp[n1][n2][k1][k2]= 0;
            else dp[n1][n2][k1][k2]= 1;
            
          }
          else if(k1==K1)
          { 
           dp[n1][n2][k1][k2] = dp[n1][n2-1][0][k2+1];
          }
          else  if(k2==K2)
         { dp[n1][n2][k1][k2] = dp[n1-1][n2][k1+1][0];
         }
          else 
            dp[n1][n2][k1][k2] = (dp[n1][n2-1][0][k2+1] + dp[n1-1][n2][k1+1][0])%mod;
        }
      }
    }
  }
  cout<<dp[N1][N2][0][0];
 return 0;
}
