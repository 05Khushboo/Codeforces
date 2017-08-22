#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1E5+1;
ll arr[N],dp[N];
void fun(ll no)
{ 
  set<ll> s;
  if(no==0||no==1) return ;
  ll mx,val;
  for(ll i = 2;i<=sqrt(no);i++)
  {
    if(no%i==0)
    { 
      s.insert(i);
      s.insert(no/i);
    }
  }
  s.insert(no);
  mx = dp[no],val = no;
  for(auto k : s)
  {
    if(mx<dp[k])
    {
      mx = dp[k];
      val = k;
    }
  }
  for(auto k :s )
  {
    if(val==k) dp[k]+=1;
    else dp[k]=(mx+1);
  }
}
int main()
{
  for(ll i = 0;i<N;i++) dp[i] = 0;
  ll n; cin>>n;
  for(ll i = 1;i<=n;i++) cin>>arr[i];
  for(ll i = 1;i<=n;i++)
  {
//     ll value = arr[i];
    fun(arr[i]);
  }
  ll mx = 1;
  for(ll i=2;i<N;i++)
  {
    if(mx<dp[i]) mx = dp[i];
  }
  cout<<mx;
  return 0;
}
