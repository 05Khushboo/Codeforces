#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  vector<ll> v[10],ne;
  v[2].push_back(2);v[3].push_back(3);
  v[4].push_back(2);v[4].push_back(2);v[4].push_back(3);
  v[5].push_back(5);v[6].push_back(3);v[6].push_back(5);
  v[7].push_back(7);v[8].push_back(2);v[8].push_back(2);
  v[8].push_back(2);v[8].push_back(7);v[9].push_back(3);
  v[9].push_back(3);v[9].push_back(2);v[9].push_back(7);  
  while(n--)
  {
    char a1; cin>>a1;
    ll a = a1-48;
    if(a<2) continue;
    else{
      for(ll i=0;i<v[a].size();i++)
        ne.push_back(v[a][i]);
    }
  }
  sort(ne.begin(),ne.end());
  for(ll i=ne.size()-1;i>=0;i--) cout<<ne[i];
  return 0;
}
