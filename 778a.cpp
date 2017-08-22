#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string t,p;
ll vi[1000001],a[1000001];
ll fun(ll n)
{ 
  if(n==-1) return -1;
  for(ll i =0;i<=t.size();i++) vi[i]=0;
  for(ll i=0;i<=n;i++) vi[a[i]]=1;
  ll i = 0,j=0;
  while(i<t.size()&&j<p.size())
  {
    if(vi[i+1]==1) { i++; continue;}
    if(t[i] == p[j]) { i++; j++; continue;}
    i++;
  }
  if(j==p.size()) return n+1;
  return -1; 
}
ll bin(ll l, ll h)
{ 
  while(l<=h)
  { 
    //cout<<l<<" "<<h<<endl;
    if(h==l) return fun(l);
    ll mid = (l+h)/2;
    if(fun(mid)!=-1&&fun(mid+1)==-1) return fun(mid);
    if(l==mid) l=mid+1;
    else if(fun(mid)!=-1) l = mid;
    else h = mid-1;
  }
  return 0;
}
int main()
{
  cin>>t>>p;
  for(ll i =0;i<t.size();i++) cin>>a[i];
 ll k = bin(0,t.size()-1);
 if(k==-1)
 {
   ll i=0,j=0;
   while(i<t.size()&&j<p.size())
   {
     if(t[i]==p[j]) { i++;j++;continue;}
     i++;
   }
   if(j==p.size()) k = 0;
 }
 cout<<k;
  return 0;
}
