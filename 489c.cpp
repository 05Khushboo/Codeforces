#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll m,s; cin>>m>>s;
  ll len = 0,flag = 0,no=s;
  vector<ll> v;
  if(s==0&&m==1) { cout<<"0 0"; return 0;}
  if(s==0) {cout<<"-1 -1"; return 0;}
  if(m==1)
  {
    if(s>9) { cout<<"-1 -1"; return 0;  }
    else { cout<<s<<" "<<s; return 0;}
  }
  while(s!=0){
    for(ll i = 9;i>=1;i--)
    {
      if(((s-i)>=0))
      {
        v.push_back(i);
        s-=i;
        flag = 1;
        break;
      }
    }
    if(flag==0) {
      v.push_back(no);
      len++; break;
    }

    len++;
  }
  if(len>m) {
    cout<<"-1 -1"; return 0;}
  sort(v.begin(),v.end());
  ll diff = m-len;
  if(diff!=0)
  {
    if(v[0]==1){
      cout<<v[0];
      while(diff!=0) { cout<<0;diff--;}
    }
    else
    {
      cout<<1;
      diff--;
      while(diff!=0) {cout<<0; diff--;}
      cout<<v[0]-1;
    }
  }
  else cout<<v[0];
  for(ll i=1;i<v.size();i++)
  {
    cout<<v[i];
  }
  cout<<" ";
  diff = m-len;
  for(ll i =v.size()-1;i>=0;i--) cout<<v[i];
  while(diff!=0) { cout<<0; diff--;}
  return 0;
}
