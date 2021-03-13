#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){
	int x; cin>>x;
	int ans = -1;

	for(int i=1;i<=10000;i++){
		int y3 = x - i*i*i;
		if(y3 >= 0){
			int y = cbrt(y3);
			if(y*y*y == y3 && y >= 1){
				cout<<"YES"<<endl;
				return;
			} 
		}
	}
	cout<<"NO"<<endl;

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