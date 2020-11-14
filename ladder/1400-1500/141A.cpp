#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	string s,t,u; cin>>s>>t>>u;
	vector<int> chr(26, 0);
	for(char c : s) chr[c-'A']++;
	for(char c : t) chr[c-'A']++;

	for(char c : u) chr[c-'A']--;

	for(int i=0;i<26;i++){
		if(chr[i] != 0){
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
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
