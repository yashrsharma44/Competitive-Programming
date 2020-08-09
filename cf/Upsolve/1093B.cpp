#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s;
	cin>>s;

	map<int,int> chr;
	for(char c : s){
		chr[c-'a']+=1;
	}
	if(chr.size() == 1){
		cout<<-1<<endl;
		return;
	}
	for(auto el : chr){
		for(int i=0;i<el.second;i++){
			cout<<(char)('a'+el.first);
		}
	}
	cout<<endl;
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
