#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  string s; cin>>s;
  stack<char> v;
  for(ll i = 0;i<s.size();i++)
  {
    if(v.empty()) v.push(s[i]);
    else if(v.top()==s[i]) v.pop();
    else v.push(s[i]);
  }
  if(v.empty()) cout<<"Yes";
  else cout<<"No";
  return 0;
}
