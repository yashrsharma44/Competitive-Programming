#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005



void solve(){

	int n; cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	vector<int> chr(26, 0);
	for(auto word : a){
		for(auto cc : word){
			chr[cc - 'a']++;
		}
	}

	for(int i=0;i<26;i++){
		if(chr[i] == 0) continue;
		if(chr[i] % n != 0) {
			cout<<"NO"<<endl;
			return;
		}
	}

	cout<<"YES"<<endl;

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
