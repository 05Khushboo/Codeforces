#include<bits/stdc++.h>
using namespace std;
char a[200001],b[200001];
bool equi(int i ,int j,int i1,int j1)
{
  int n = j-i+1,f=0;
  for(int ik = i,jk = i1;ik<=j;ik++,jk++)
  {
    if(a[ik]!=b[jk]) { f=1; break;}
  }
  if(f==0) return 1;
  if(n%2==1)  return 0;
  int a1,a2,b1,b2;
  n/=2;
  f = equi(i,i+n-1,i1,i1+n-1);
  if(f==1) {
    f = equi(i+n,j,i1+n,j1);
    if(f) return 1;
  }
  f = equi(i,i+n-1,i1+n,j1);
  if(f==0) return 0;
  f = equi(i+n,j,i1,i1+n-1);
  if(f) return 1;
  else return 0;
}
int main()
{
  int i =0;
  scanf("%s %s",a,b);
  for(i=0;a[i]!='\0';i++);
  if(equi(0,i-1,0,i-1)) cout<<"YES";
  else cout<<"NO";
  return 0;
}
