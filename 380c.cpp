#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 1E6 + 1;
ll arr[N];
vector<ll> tree[4*N+1];
struct node{
  ll f,s,l;
};
void build(ll k,ll st,ll en)
{
  if(st==en)
  {
    tree[k].push_back(0);
    if(arr[st]==1)  tree[k].push_back(1),tree[k].push_back(0);
    else tree[k].push_back(0),tree[k].push_back(1);
  }
  else{
    ll mid = (st+en)/2;
    build(2*k+1,st,mid);
    build(2*k+2,mid+1,en);
    ll a1 = tree[2*k+1][0];
    ll b1 = tree[2*k+1][1];
    ll c1 = tree[2*k+1][2];
    ll a2 = tree[2*k+2][0];
    ll b2 = tree[2*k+2][1];
    ll c2 = tree[2*k+2][2];
    ll t = min(b1,c2);
    tree[k].push_back((a1+a2+t));
    tree[k].push_back(b1+b2-t);
    tree[k].push_back(c1+c2-t);
  }
}
node combine(node a,node b)
{
  node c;
  ll a1 = a.f;
  ll b1 = a.s;
  ll c1 = a.l;
  ll a2 = b.f;
  ll b2 = b.s;
  ll c2 = b.l;
  ll t = min(b1,c2);
  c.f= a1+a2+t;
  c.s= b1+b2-t;
  c.l=c1+c2-t;
  return c;
}
node query(ll k,ll st,ll en,ll L,ll R)
{
  if(st==L&&en==R)
  { node a;
    a.f =tree[k][0];
    a.s=tree[k][1];
    a.l=tree[k][2];
    return a;
  }
  ll mid = (st+en)/2;
  if(R<=mid) return query(2*k+1,st,mid,L,R);
  else if(L>mid) return query(2*k+2,mid+1,en,L,R);
  else
  { node a,b,c;
    b= query(2*k+1,st,mid,L,mid);
    c = query(2*k+2,mid+1,en,mid+1,R);
    a =combine(b,c);
    return a; 
  }
}
int main()
{ 
  char s[1000005];
  scanf("%s",s);
  ll  n =0;
  for(ll i=0;s[i]!='\0';i++)
  { n++;
    if(s[i]=='(') arr[i]=1;
    else arr[i] = -1;
  }
  build(0,0,n-1);
  ll m; scanf("%lld",&m);
  while(m--)
  {
    ll l,r; scanf("%lld %lld",&l,&r);
    l--; r--;
    node a = query(0,0,n-1,l,r);
    printf("%lld\n",2*a.f);
  }
  return 0;
}
