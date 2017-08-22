#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime(ll n)
{
  for(ll i = 2;i<=sqrt(n*1.0);i++)
  {  
   if(n%i==0) return false;
  }
  return true;
}
ll ne_prime(ll n)
{
  for(ll j = 2;j<=1000;j+=2)
  {
    if(prime(n-j)) return (n-j);
  }
}
vector<ll> p;
void s_prime()
{
  ll x[1001];
  for(ll i =0;i<1001;i++) x[i] = 1;
  x[0] = x[1] = 0;
  for(ll i =2;i<1001;i++)
  {
    if(x[i])
    {
      for(ll j = 2*i;j<1001;j+=i)
      {
        x[j] = 0;
      }
    }
  }
  for(ll i = 0;i<1001;i++)
  {
    if(x[i]) p.push_back(i);
  }
}
int main()
{
  ll n; cin>>n;
  s_prime();
  if(prime(n)) {cout<<1<<endl; cout<<n; return 0;}
  if(prime(n-2)) {cout<<2<<endl; cout<<2<<" "<<(n-2); return 0;}
  if(prime(n-4)) {cout<<3<<endl; cout<<2<<" "<<2<<" "<<(n-4); return 0;}
 cout<<3<<endl;
  ll k = ne_prime(n); cout<<k<<" ";
  ll d = n - k;
  if(prime(d)) { cout<<d; return 0;}
  for(ll i =0;i<p.size();i++)
  {
    ll d1 = d-p[i];
    if(d1<=1) break;
    for(ll j = 0;j<p.size();j++)
    {
      if(p[j] == d1) { cout<<p[i]<<" "<<p[j]; return 0;}
    }
  }

  return 0;
}
