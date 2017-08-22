#include<bits/stdc++.h>
using namespace std;
int mod = 1E9+7;
const int N = 2E5+1;
int factorial[N];
int power(int a, int b){
  if(b==0) return 1;
  int x = 1;
  while (b>0){
    if(b&1)  x = (long long)x * a % mod;
    a = (long long)a * a % mod;
    b = b>>1;
  }
  return x;
} 
int mi(int n){
  return power(n, mod-2);
}
int nCr(int n, int k){
  if(k>n) return 0;
  int ans = factorial[n];
  ans = (long long)ans * mi(factorial[k]) % mod;
  ans = (long long)ans * mi(factorial[n-k]) % mod;
  return ans;
}
int  main()
{
  int h,w,n; scanf("%d %d %d",&h,&w,&n);
  h--; w--;
  factorial[0] = factorial[1] = 1;
  for(int i = 2;i<N;i++)
    factorial[i]= (long long)factorial[i-1] * i % mod;
  pair<int,int>  v[n+1];
  for(int i = 0;i<n;i++)
  {
    int x,y; scanf("%d %d",&x,&y);
    x--; y--;
    v[i] = {x,y};
  }
  v[n] = {h,w};
  sort(v,v+n+1);
  int dp[n+1];
  for(int i = 0;i<=n;i++)
  {
    int x = v[i].first;
    int y = v[i].second;
    dp[i] = nCr(x+y,x);
    for(int j = 0;j<i;j++)
    {
      int x1 = x-v[j].first;
      int y1 = y-v[j].second;
      if(x1>=0&&y1>=0) 
      {
        dp[i] = (dp[i] - ((long long)dp[j]*nCr(x1+y1,x1)) %mod + mod)%mod;
       }
    }
  }
  printf("%d",dp[n]);
  return 0;
}
