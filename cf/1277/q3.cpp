#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// ll check(string s){
// 	string s1="one", s2="two", s3="twone";

// 	if(s.find(s1)!=s.end()){
// 		return 0;
// 	}

// 	if(s.find(s2)!=s.end()){
// 		return 1;
// 	}

// 	if(s.find(s3)!=s.end()){
// 		return 2;
// 	}

// 	return -1;
// }

void solve(){
	
	string s;
	cin>>s;

	vector<ll> ans;

	for(ll i=0;i<s.length();i++){

		if(i<=s.length() - 5 && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e'){
			
			s[i+2] = '?';
			ans.push_back(i+2);

		}

		if(i<=s.length() - 3 && s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
			ans.push_back(i+1);
			s[i+1] = '?';
		}

		if(i<=s.length() - 3 && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
			ans.push_back(i+1);
			s[i+1] = '?';
		}

	}

	cout<<ans.size()<<endl;
	for(ll el : ans){
		cout<<el+1<<" ";
	}
	cout<<endl;


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}