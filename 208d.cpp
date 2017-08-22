#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n; cin>>n;
  ll arr[n],b[5],cnt[5];
  for(ll i = 0;i<n;i++) cin>>arr[i];
  for(ll i = 0;i<5;i++) cin>>b[i],cnt[i] = 0;
  ll pre = 0;
  for(ll i = 0;i<n;i++)
  {
    ll total = arr[i] + pre;
    while(1)
    {
      ll idx = upper_bound(b,b+5,total) - b;
//       cout<<idx<<" "<<total<<"T\n";
      if(idx==0&&b[idx]>total)
      {
        pre = total; break;
      }
      else 
      { 
        idx-=1;
        cnt[idx]+=(total/b[idx]);
        total%= b[idx];
      }
    }
  }
  for(ll i = 0;i<5;i++) cout<<cnt[i]<<" ";
  cout<<endl<<pre;
  return 0;
}
