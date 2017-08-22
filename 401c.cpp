#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n,m; cin>>n>>m;
  if(n>(m+1)) { cout<<-1; return 0;}
  ll k = ceil(m/2.0 )- 1;
//   cout<<k<<" "<<n<<"n";
  if(n<k) { cout<<-1; return 0;}
  string s="";
  while(((k+1)<n)&&n!=0&&m!=0)
  {
    s+="01";
    n--;m--;
    k = ceil(m/2.0) - 1;
  }
//   if(m==0&&n!=0) {s+="0";n--;}
  while(m>1)
  {
    s+="011";
    m-=2;
    n--;
  }
  if(m==0) { s+="0"; n--;}
  if(m!=0) { s+="010"; n-=2;}
  if(n==-2) {
  for(ll i=1;i<s.size()-1;i++) cout<<s[i];
  }
  else if(n==-1) 
  {
    for(ll i=1;i<s.size();i++) cout<<s[i];
  }
  else cout<<s;
  return 0;
}
