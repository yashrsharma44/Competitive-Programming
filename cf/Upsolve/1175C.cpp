#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){


	int n,k;
	cin>>n>>k;

	vector<int>a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	int l = 1, r = 1e9+7;
	while(l < r){

		int mid = l + (r - l )/ 2;
		
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
