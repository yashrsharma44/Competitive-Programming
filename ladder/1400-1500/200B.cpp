#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;

	double sum = 0;

	for(int i=0;i<n;i++){
		int vl; cin>>vl; sum += vl;
	}
	
	double ans = sum / (double)n;
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
