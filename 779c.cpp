#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
  int diff = a.first - a.second;
  int diff2 = b.first - b.second;
  if (diff < diff2)
    return true;
  return false;
}

int main(void){
  long long n, k;
  cin >> n >> k;;
  long long a[n], b[n];
  for(long long i = 0; i < n; i += 1) cin >> a[i];
  for(long long i = 0; i < n; i += 1) cin >> b[i];
  vector< pair<long long, long long> > vec;
  for(long long i = 0; i < n; i += 1)
    vec.push_back({a[i], b[i]});
  sort(vec.begin(), vec.end(), comp);
  long long ans = 0;
  for(long long i = 0; i < k; i += 1) ans += vec[i].first;
  for(long long i = k; i < n; i += 1) ans += min(vec[i].first, vec[i].second);
  cout << ans << endl;
}
