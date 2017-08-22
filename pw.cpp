#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  string s; cin>>s;
  map<ll,ll> m; 
  map<ll,ll> :: iterator it;
  ll a[s.size()+1];
  a[0]=0; ll i=1,j=0,n;
  n=s.size();
  while(i<n)
  {
    if(s[i]==s[j]) {a[i]=j+1;
      m[a[i]]++;
      i++;j++;}
    else {
      if(j!=0)
      {
        j=a[j-1];
      }
      else 
      {
        a[i]=0;
        m[a[i]]++;
        i++;
      }
    }
  } ll f=0,mx=0;
  for(i=0;i<n;i++) cout<<a[i]<<" ";
  if(m[a[n-1]]>=2&&a[n-1]!=0) 
  {
    mx=a[n-1];
    for(i=0;i<mx;i++) cout<<s[i];
    return 0;
  }
  else 
  { 
    cout<<"Just a legend";
  }
  return 0;
}
