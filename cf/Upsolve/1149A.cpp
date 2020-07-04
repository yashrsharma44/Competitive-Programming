#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	int nn = n;
	int one = 0, two = 0;
	while(nn--){
		int vl;
		cin>>vl;
		if(vl == 1){
			one++;
		} else {
			two++;
		}
	}

	if(one == 0 || two == 0){
		if(one == 0){
			for(int i=0;i<two;i++){
				cout<<2<<" ";
			}
			cout<<endl;
		} else {
			for(int i=0;i<one;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}
		return;
	}
	cout<<2<<" "<<1<<" ";
	for(int i=0;i<two-1;i++){
		cout<<2<<" ";
	}
	for(int i=0;i<one-1;i++){
		cout<<1<<" ";
	}
	cout<<endl;

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
