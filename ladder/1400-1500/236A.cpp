#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	string s; cin>>s;
	set<char> elem;
	for(char c : s) elem.insert(c);

	if(elem.size() % 2 == 0){
		cout<<"CHAT WITH HER!"<<endl;
	} else {
		cout<<"IGNORE HIM!"<<endl;
	}
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
