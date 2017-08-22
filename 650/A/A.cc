#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ll n; cin>>n;
  map<string,ll> mxy;
  map<ll,ll> mx,my;
  for(ll i=0;i<n;i++)
  {
    ll x,y; cin>>x>>y;
      mx[x]++;
      my[y]++;
      string no = to_string(x);
      no+=" ";
      no+=to_string(y);
      mxy[no]++;
      cout<<mx[x]<<" "<<my[y]<<" "<<mxy[no]<<endl;
  }
  return 0;
}
