#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll tree[10000001],arr[10000001];
void build(ll k,ll st,ll en,ll level)
{
  if(st==en) {
    tree[k] = arr[st];
    return ;}
  else
  {
    ll mid = (st+en)/2;
    build(2*k+1,st,mid,level+1);
    build(2*k+2,mid+1,en,level+1);
    if(level%2==0) tree[k] = tree[2*k+1] | tree[2*k+2];
    else tree[k] = tree[2*k+1] ^ tree[2*k+2];
  }
}
void update(ll k,ll st,ll end,ll idx,ll x, ll level)
{
  if((st==end)&&idx==st)
  {
    tree[k] = x;
  return;
  }
  else
  {
    ll mid = (st+end)/2;
    if(idx<st||idx>end||st>end) return ;
    update(2*k+1,st,mid,idx,x,level+1);
    update(2*k+2,mid+1,end,idx,x,level+1);
    if(level%2==0) tree[k] = tree[2*k+1] | tree[2*k+2];
    else tree[k] = tree[2*k+1] ^ tree[2*k+2];
  }
}
int main()
{ ll n,m; cin>>n>>m;
  ll len = 1<<n;
  for(ll i=0;i<len;i++) cin>>arr[i];
  ll level,k = n+1;
  if(k%2==0) level = 0;
  else level = 1;
  build(0,0,len-1,level);
//   for(ll i =0;i<25;i++) cout<<tree[i]<<" ";
  while(m--)
  {
    ll idx,x;
    cin>>idx>>x;
    idx--;
    if(k%2==0) level = 0;
    else level = 1;
    update(0,0,len-1,idx,x,level);
    cout<<tree[0]<<endl;
  }
  return 0;
}
