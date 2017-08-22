#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1E5+1;
ll arr[N],n,m;
vector<ll> v;
void possible()
{
  ll b = 1,sum=0;
  for(ll j = 0;j<n;j++)
  {
    ll k = arr[j],f=0;
    for(ll i = b;i<k;i++)
    { 
      sum+=i;
      if(sum<=m) v.push_back(i); 
      else break;
    }
    if(sum>m) break;
    b = k+1;
  }
  if(sum<m)
  {
    for(ll i = b;;i++)
    {
       sum+=i;
       if(sum>m) break;
       v.push_back(i);
    }
  }
}
int main()
{
  cin>>n>>m;
  for(ll i=0;i<n;i++) cin>>arr[i];
  sort(arr,arr+n);  
  possible();
  cout<<v.size()<<endl;
  for(auto i:v) cout<<i<<" ";
  return 0;
}
