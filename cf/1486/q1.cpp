#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	int k = 0;
	for(int i=0;i<n;i++){
		k = k + a[i] - (i);
		if(k < 0){
			cout<<"NO"<<endl;
			return;
		}
	}

	cout<<"YES"<<endl;
	
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
