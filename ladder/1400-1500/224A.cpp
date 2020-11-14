#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int a,b,c; cin>>a>>b>>c;
	int x = (int)pow((a*c) / b, 0.5);
	int y = (b * x) / c;
	int z = c / x;

	cout<<(4*(x+y+z))<<endl;	
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
