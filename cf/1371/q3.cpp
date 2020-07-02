#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int v,c,n,m;
	cin>>v>>c>>n>>m;

	if((n+m) > (v+c)){
		cout<<"No"<<endl;
		return;
	}

	if(v>c){

		int k2 = c;
		int k1 = v;

		if(n<=k1 && m<=k2){
			cout<<"Yes"<<endl;
		} else {
			if(n<=k2&&m<=k1&&n>=(v-c-1)){
				cout<<"Yes"<<endl;
			} else {
				cout<<"No"<<endl;
			}
		}
	} else {
		int k2 = v;
		int k1 = c;

		if(n<=k1&&m<=k2){
			cout<<"Yes"<<endl;
		} else {
			if(n<=k2&&m<=k1&&m>=(c-v)){
				cout<<"Yes"<<endl;
			} else {
				cout<<"No"<<endl;
			}
		}
	}

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
