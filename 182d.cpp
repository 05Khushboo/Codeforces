#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> div1;
ll divisors(ll n)
{
  for(ll i = 1;i<=(n/2);i++)
  {
    if(n%i==0) div1.push_back(i);
  }
}
bool check(string a,ll d,ll n)
{
  string c="";
  for(ll i = 0;i<d;i++) c+=a[i];
  for(ll i=d;i<n;i+=d)
  {
    string x = a.substr(i,d);
    if(x.compare(c)!=0) return 0;
  }
  return 1;
}
int main()
{
  string a,b;
  cin>>a>>b;
  ll n = a.size();
  ll m = b.size();
  divisors(n);
  ll ans = 0;
  div1.push_back(n);
  for(auto d : div1)
  {
    if(m%d!=0) continue;
    string c = "",x="";
    for(ll i = 0;i<d;i++) c+=a[i];
    for(ll i = 0;i<d;i++) x+=b[i];
    if(c.compare(x)!=0) continue;
    if(check(a,d,n) && check(b,d,m)) ans++;
  }
  cout<<ans;
  return 0;
}
