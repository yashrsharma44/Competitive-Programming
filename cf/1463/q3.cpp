#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> t,x;
	int nn = n;
	while(nn--){
		int tt,xx; cin>>tt>>xx;
		t.push_back(tt); x.push_back(xx);
	}

	map<vector<int>, vector<int>> mp;
	
	vector<int> delta;
	int prev_t = t[0];
	for(int i=0;i<n-1;i++){
		if(t[i] > prev_t){
			int initial_t = prev_t;
			int final_t = t[i] + abs(x[i] - x[i+1]);

			if(x[i+1] >= x[i]){
				delta.push_back(1);
			} else {
				delta.push_back(-1);
			}
		} else if(t[i] < prev_t){
			delta.push_back(delta.back());
		} else {
			delta.push_back(0);
		}
	}

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
