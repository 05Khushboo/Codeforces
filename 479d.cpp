#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll p[100001],n;
ll binarysearch(ll l,ll h,ll x)
{
  ll idx = lower_bound(p,p+n,x)-p;
  //  if(x==7) cout<<p[idx]<<" "<<idx<<" ";
  if(p[idx]==x) return 1;
  else return 0;
}
int main()
{
  ll l,x,y; cin>>n>>l>>x>>y;
  for(ll i = 0;i<n;i++) cin>>p[i];
  ll f = 0,fl = 0;
  for(ll i = 0;i<n;i++)
  {
    ll value = p[i]+x;
    if((value<=l&&value>=0)&&f==0) f=binarysearch(0,n-1,value);
    value = p[i]-x;
    if(value<=l&&value>=0&&f==0)  f=binarysearch(0,n-1,value);

    //     cout<<f<<" ";
    value = p[i]+y;
    if((value<=l&&value>=0)&&fl==0)  fl=binarysearch(0,n-1,value);
    //     cout<<fl<<" ";
    value = p[i]-y;
    if((value<=l&&value>=0)&&fl==0) fl=binarysearch(0,n-1,value);

    if(f==1&&fl==1) break;
  }
  if(f==1&&fl==1) { cout<<"0"; return 0;}
  if(f==1) 
  {
    cout<<"1\n";
    cout<<y;
    return 0;
  }
  if(fl==1)
  {
    cout<<"1\n";
    cout<<x;
    return 0;
  }
  f = 0;
  ll mk = 0;
  for(ll i =0;i<n;i++)
  {
    ll value = p[i] + x;
    if(value<=l&&value>=0)
    {
      if(f==0) f = binarysearch(0,n-1,value-y);
      if(f==0) f= binarysearch(0,n-1,value+y);
      if(f) { mk = value; break;}

    }
    value = p[i]-x;
    if(value<=l&&value>=0) {

      if(f==0) f = binarysearch(0,n-1,value-y);
      if(f==0) f= binarysearch(0,n-1,value+y);
      if(f) { mk = value; break;}
    }
    if(f) break;
  }
  if(f==1) {
    cout<<"1\n";
    cout<<mk;
    return 0;
  }
  f= 0;
  mk = 0;
  for(ll i =0;i<n;i++)
  { 
    ll value = p[i] + y;
    if(value<=l&&value>=0){
      if(f==0) f=binarysearch(0,n-1,value-x);
      if(f==0) f=binarysearch(0,n-1,value+x);
      if(f) { mk = value; break;}

    }
    value = p[i]-y;
    if(value<=l&&value>=0)
    {
      if(f==0) f=binarysearch(0,n-1,value-x);
      if(f==0) f=binarysearch(0,n-1,value+x);
      if(f) { mk = value; break;}
    }
    if(f) break;
  }
  if(f==1) {
    cout<<"1\n";
    cout<<mk;
    return 0;
  }


  cout<<"2\n";
  cout<<x<<" "<<y;
  return 0;
}
