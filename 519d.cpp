#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll a[26];
  string s;
  for(ll i = 0;i<26;i++) {cin>>a[i];}
  cin>>s;
  ll n = s.size();
  ll sum[n];
//   cout<<s<<" ";
  sum[0] = a[s[0]-97];
  vector<ll> v[26];
  v[s[0]-97].push_back(0);
  for(ll i = 1;i<s.size();i++)
  {
    sum[i] = (sum[i-1] + a[s[i]-97]);
    v[s[i]-97].push_back(i);
  }
  ll ans = 0;
  for(ll i = 0;i<26;i++)
  {
//     cout<<i<<"I";
    map<ll,ll> m;
    for(auto k : v[i])
    {
//       cout<<k<<" ";
      ans+=m[sum[k-1]];
      m[sum[k]]++;
    }
//     cout<<endl;
  }
  cout<<ans;
  return 0;
}
