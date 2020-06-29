#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;

	if(n <= 2){
		cout<<0<<endl;
		return;
	}
	if(n == 3 || n == 4){
		cout<<4<<endl;
		return;
	}

	int k = n - 3;
	cout<<(4 + (4 * k))<<endl;


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
