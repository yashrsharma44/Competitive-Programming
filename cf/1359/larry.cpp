#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXD 32

int a[MAXN];
int dp[MAXN][MAXD];

void solve() {
  int N, i, j;
  int best = 0;
  
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    for (j = 0; j <= 30; j++) dp[i][j] = 0;
  }

  for (i = 0; i < N; i++) {
    for (j = max(a[i],0); j <= 30; j++) {
      dp[i+1][j] = max(dp[i][j] + a[i], 0);
      best = max(best, dp[i+1][j] - j);
    }
  }
  cout<<"j:     ";
  for(j=0;j<=30;j++){
      printf("%3d ", j);
  } 
  cout<<endl;
  for(i=0;i<=N;i++){
    printf("%2d-----",i);
    for(j=0;j<=30;j++){
      printf("%3d ", dp[i][j]);
    }
    cout<<endl;
  }
  cout<<endl;

  printf("%3d\n", best);
}

int main() {
  solve();

  return 0;
}
