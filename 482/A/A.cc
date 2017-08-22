#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
ll vi[10000001];
void fun(ll n,ll k)
{
  v.push_back(1);
  ll top = 1;
  vi[top] = 1;
  for(ll i = k;i>=1;i--)
  {
    if(((top+i)<=n)&&vi[top+i]==0) v.push_back(top+i),top=top+i,vi[top]=1;
    else v.push_back(top-i),top=top-i,vi[top]=1;
  }
}
int main()
{
  ll n,k;
  cin>>n>>k;
  fun(k+1,k);
  for(ll i=0;i<=n;i++) vi[i] = 0;
  for(ll i=k+2;i<=n;i++)
  {
    v.push_back(i);
  }
  for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";
  return 0;
}
