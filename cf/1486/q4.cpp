#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool check(int x, vector<int> &a, int k){
	int n = a.size();
	vector<int> b(a.begin(), a.end());
	for(auto &el : b){
		if(el >= x) el = 1;
		else el = -1;
	}

	vector<int> preMin({0});
	int pre = 0;
	for(int el : b){
		pre += el;
		preMin.push_back(min(preMin.back(), pre));
	}

	pre = 0;
	for(int i=1;i<=k;i++) pre += b[i - 1];

	if(pre > 0) return true;

	for(int i=k+1;i<=n;i++){
		pre	+= b[i-1];
		int mn = preMin[i - k];
		if(pre - mn > 0) return true;

	}

	return false;
}

void solve(){
	
	int n,k; cin>>n>>k;
	vector<int> a;
	for(int i=0;i<n;i++){
		int u; cin>>u;
		a.push_back(u);
	}


	int l = 1; // func(l) is True 
	int r = n+1; // func(r) is False

	while(r - l > 1){

		int m = (l + r) >> 1;
		if(check(m, a, k)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<endl;
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
