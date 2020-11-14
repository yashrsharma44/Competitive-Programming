#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	string s; cin>>s;
	string t = s;
	// for(char c : s){
	// 	t += tolower(c);
	// }	
	set<char> vowel({'a','e','i','o','u',""});
	string ans = "";
	for(char c : t){
		if(vowel.find(c) == vowel.end()) ans += tolower(c);
	}
	// if(ans == ""){
	// 	cout<<"."<<endl;
	// 	return;
	// }
	for(int i=0;i<ans.length();i++){
		if(i == ans.size()-1) cout<<"."<<ans[i]<<endl;
		else {
			cout<<"."<<ans[i];
		}
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
