
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r;

int main() {
  cin>>l>>r;
  if (r-l+1 < 3 or (r-l+1 == 3 and l%2)) { cout<<-1; return 0; }
  cout<<l+l%2<<" "<<l+l%2+1<<" "<<l+l%2+2;
  return 0;
}