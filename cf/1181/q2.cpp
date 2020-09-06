#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

string add(string &s, string &t){
	while(s.length() < t.length()){
		s = "0" + s;
	}
	while(s.length() > t.length()){
		t = "0" + t;
	}

	string ans = "";
	int sum = 0, carry = 0;
	int n = s.length();
	for(int i=n-1;i>=0;i--){
		int sum = (s[i] - '0') + (t[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans = to_string(sum) + ans;
	}
	while(s[0] == '0') s.erase(s.begin());
	while(t[0] == '0') t.erase(t.begin());
	while(ans[0] == '0') ans.erase(ans.begin());

	return ans;
}

int diff(string &s, string &t){
	while(s.length() < t.length()){
		s = "0" + s;
	}
	while(s.length() > t.length()){
		t = "0" + t;
	}
	int ans = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] != t[i]){
			ans = s[i] > t[i] ? 1 : -1;
			break;	
		}
	}
	while(s[0] == '0') s.erase(s.begin());
	while(t[0] == '0') t.erase(t.begin());

	return ans;
}

void solve(){

	int n; cin>>n;
	string s; cin>>s;

	bool checkZero = false;
	for(char c : s){
		if(c == '0') checkZero = true;
	}
	int k = n / 2;		
	if(!checkZero){

		string ans = "";
		vector<int> delta({-1,0,1});
		for(int i=0;i<3;i++){
			string s1 = s.substr(0, k+delta[i]);
			string s2 = s.substr(k+delta[i]);
			string sum = add(s1, s2);
			if(ans == "") ans = sum;
			if(diff(sum, ans) < 0) ans = sum;
		}
		cout<<ans<<endl;
		return;
	}
	vector<int> delta;
	for(int i=k;i<n;i++){
		if(s[i] != '0'){
			delta.push_back(i);
			break;
		}
	}
	for(int i=k;i>=0;i--){
		if(s[i] != '0'){
			delta.push_back(i);
			break;
		}
	}

	string ans = "";
	for(int el : delta){
		string s1 = s.substr(0, el);
		string s2 = s.substr(el);
		string sum = add(s1, s2);
		if(ans == "") ans = sum;
		if(diff(sum, ans) < 0) ans = sum;
	}
	if(ans == "") ans = "0";
	cout<<ans<<endl;
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
