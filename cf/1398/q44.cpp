#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

int MIN = -(1e9+5);
int memo[205][205][205];

int dfs(vector<int> &a1, vector<int> &a2, vector<int> &a3, int i, int j, int k){

	if(memo[i][j][k] != -1) return memo[i][j][k];
	int ans = 0;
	// choose 1 2
	if(i < a1.size() && j < a2.size()){
		ans = max(ans, a1[i] * a2[j] + dfs(a1,a2,a3,i+1, j+1, k));
	} 

	
	// choose 1 3
	if(i < a1.size() && k < a3.size()){
		ans = max(ans, a1[i] * a3[k] + dfs(a1,a2,a3,i+1,j,k+1));
	}

	// choose 2 3
	if(j < a2.size() && k < a3.size()){
		ans = max(ans, a2[j] * a3[k] + dfs(a1,a2,a3,i,j+1,k+1));
	} 

	return memo[i][j][k] = ans;

}

void solve(){

	int r,g,b;
	cin>>r>>g>>b;
	vector<int> rr(r),gg(g),bb(b);
	for(int i=0;i<r;i++) cin>>rr[i];

	for(int i=0;i<g;i++) cin>>gg[i];

	for(int i=0;i<b;i++) cin>>bb[i];

	sort(rr.begin(), rr.end(), greater<int>());
	sort(gg.begin(), gg.end(), greater<int>());
	sort(bb.begin(), bb.end(), greater<int>());

	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			for(int k=0;k<201;k++){
				memo[i][j][k] = -1;
			}
		}
	}


	int ans = dfs(rr,gg,bb, 0,0,0);
	
	cout<<ans<<endl;


}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
