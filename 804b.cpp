#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1E9+7;
int main()
{
  string s; cin>>s;
  ll n = s.size()-1;
  ll ans = 0,cb=0;
  for(ll i=0;i<=n;i++)
  {
    if(s[i]=='a') {cb++; cb%=mod;}
    else
    { 
      ans+=cb;
      ans%=mod;
    }
  }
  cout<<ans;
  return 0;
}
