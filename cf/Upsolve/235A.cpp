#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n;cin>>n;
	if(n<=2){
		cout<<n<<endl;
		return;
	}

	cout<<(n*(n-1)*(n-2))<<endl;		
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
