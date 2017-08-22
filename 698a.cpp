#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 101;
ll arr[N],dp[N][3],n;
ll fun(ll i,ll pre)
{
  if(i==n) return 0;
  if(dp[i][pre]!=-1) return dp[i][pre];
  if(arr[i]==0) return dp[i][pre] = fun(i+1,0) + 1;
  else if(arr[i]==1)
  {
    if(pre==1)  return dp[i][pre] = fun(i+1,0) + 1;
    else return dp[i][pre] = fun(i+1,1);
  }
  else if(arr[i]==2)
  {
    if(pre==2) return dp[i][pre]= fun(i+1,0) + 1;
    else  return dp[i][pre] = fun(i+1,2);
  }
  else
  {
    if(pre==1) return dp[i][pre] = fun(i+1,2);
    else if(pre==2) return dp[i][pre] = fun(i+1,1);
    else return dp[i][pre] = min(fun(i+1,2),fun(i+1,1));
  }
}
int main()
{
  cin>>n;
  for(ll i = 0;i<n;i++)
  {
    cin>>arr[i];
    dp[i][0] = dp[i][1] =dp[i][2] = -1;
  }
  cout<<fun(0,0);
  return 0;
}
