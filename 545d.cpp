#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  ll cnt = 1,sum=a[0];
  for(ll i=1;i<n;i++)
  {
    if(a[i]>=sum) {
      sum+=a[i];
      cnt++;}
  }
  cout<<cnt;

  return 0;
}
