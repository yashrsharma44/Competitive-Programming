#include <bits/stdc++.h>

#define MAXN 200006
using namespace std;

// long long a[MAXN];
map<long long,long long> m;

void solve() {
  long long N;
  long long c = 0, i, current = 0, zero = 0;

  scanf("%lld\n", &N);
  long long a[N+1];
  for (i = 1; i <= N; i++) {
    scanf("%lld", &a[i]);
  }

  m.clear();
  zero = m[0] = a[0] = 0;
  for (i = 1; i <= N; i++) {
    if (a[i] == 0) {
      zero = i;
      m[current] = i;
      continue;
    }
 
    current += a[i];
    if (m.find(current) != m.end()) {
      c += min(i - m[current] - 1, i - zero);
      zero = max(m[current] + 1, zero);
    } else {
      c += min(i, i - zero);
    }

    m[current] = i;
  }

  printf("%lld\n", c);
}

int main(){
    // ll t;
    // cin>>t;

    solve();
}