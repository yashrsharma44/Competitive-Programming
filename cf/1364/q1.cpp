#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n, x;
	cin>>n>>x;

	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector<int> prefix(n+1, 0);
	for(int i=1;i<=n;i++){
		prefix[i] = prefix[i-1] + a[i-1];
	}
	
	for(int i=0;i<=n;i++){
		prefix[i] = prefix[i] % x;
	}

	int maxLen = -1;
	for(int i=n;i>0;i--){
		if(prefix[i] != 0){
			maxLen = i;
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(prefix[i] != 0){
			maxLen = max(maxLen, ((n - i)));
		}
	}

	cout<<maxLen<<endl;

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
