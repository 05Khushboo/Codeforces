#include <bits/stdc++.h>

using namespace std;

int main(void){
  long long int n;
  cin >> n;
  long long int a[n];
  for(long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  long long int ans = 0;
  for(long long int i = 0; i < n; i += 1)
    ans += abs(i+1 - a[i]);
  cout << ans << endl;
}

