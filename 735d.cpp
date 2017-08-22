#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool checkprime(ll n)
{
  for(ll i = 2;i<=sqrt(n);i++)
  {
    if(n%i==0) return 0;
  }
  return 1;
}
ll nearestprimeno(ll n)
{
  if(checkprime(n)) return n;
  for(ll j = 2;j<=1000;j++)
  { 
    ll x = n-j;
    if(checkprime(x)) return x;
  }
}
int main()
{
  ll n; cin>>n;
  ll diff = n,ans = 0;
  if(checkprime(n)) ans = 1;
  else if(n%2==0) ans = 2;
  else 
  {
    if(checkprime(n-2)) ans = 2;
    else ans = 3;
  }
  cout<<ans;
  return 0;
}
