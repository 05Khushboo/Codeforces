#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 5000002;
ll p[N],d[N];
void prime()
{
  for(ll i =0;i<N;i++) p[i] = 1,d[i]=0;
  p[0] = p[1] = 0;
  for(ll i = 2;i<N;i++)
  {
    if(p[i] == 1)
    { d[i] = 1;
      for(ll j =2*i;j<N;j+=i)
      {
        p[j] = 0;
        ll ne = j;
        while(ne%i==0)
        { d[j]++;
          ne/=i;
        }
      }
    }
  }
 for(ll i = 2;i<N;i++) {d[i]+=d[i-1];}  
}int main()
{
  prime();
  ll t; scanf("%lld",&t);
  while(t--)
  {
    ll a,b; 
    scanf("%lld %lld",&a,&b);
    if(a==b) printf("0\n");
    else  printf("%lld\n",d[a]-d[b]);
  }
  return 0;
}
