#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 1;
ll dp[N];
ll m = 1E9 + 7;
void fun(ll k)
{
  dp[0] = 1;
  for(ll i=1;i<N;i++){
    if((i-k)>=0) dp[i]= (dp[i-1]+ dp[i-k])%m;
    else dp[i] = dp[i-1];
  }
}
int main(){
  ll t,k; cin>>t>>k;
  fun(k);
  ll pre[N];
  pre[0] = 0;
  for(ll i =1;i<N;i++) pre[i]=(dp[i]+pre[i-1])%m;
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    ll ans = ((pre[b]- pre[a-1])%m + m)%m;
    cout<<ans<<endl;
  }
  return 0;
}

