#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,k; cin>>n>>k;
	while(k > 3){
		n-=1;
		k-=1;
		cout<<1<<" ";
	}

	if(n%2==1){
		int v = (n - 1) / 2;
		cout<<1<<" "<<v<<" "<<v<<endl;
		return;
	}

	int val = 0;
	while(n % 2 == 0){
		val+=1;
		n/=2;
	}
	// cout<<"V"<<val<<endl;
	if(n == 1){
		int v1 = 1 << (val-1), v2 = 1 << (val - 2);
		cout<<v1<<" "<<v2<<" "<<v2<<endl;
		return;
	}

	int v = (n - 1) / 2;
	v *= (1 << val);
	cout<<(1 << val)<<" "<<v<<" "<<v<<endl;

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