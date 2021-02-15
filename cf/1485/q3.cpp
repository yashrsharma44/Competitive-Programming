#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int x,y; cin>>x>>y;

	int ans = 0;
	for(int i=2;i<=100000;i++){
		
		if(i > y) break;
		
		if((i*i % (i-1)) == 0 && ((i*i) / (i-1)) <= x) ans++;
	}


	cout<<ans<<endl;
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
