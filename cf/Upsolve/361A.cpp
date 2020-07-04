#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;

	if(n == 1){
		cout<<k<<endl;
		return;
	}

	int a = -1, b = -1;
	if(k <= n){
		a = 0;
		b = k;
	} else {
		for(int i=1;i<=k;i++){

			int z = (k - i) / (n - 1);
			if(z >= 0 && z <= 1000){
				a = z;
				break;
			}
		}
	
	}
	b = k - ((n-1)*a);
	vector<vector<int> > ans(n, vector<int>(n, a));
	for(int i=0;i<n;i++){
		ans[i][i] = b;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}


	
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
