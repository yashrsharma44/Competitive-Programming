#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

bool comp(string s1, string s2){
	if(s1[0] != s2[0]){
		return s1[0] > s2[0];
	}
	return s1.length() > s2.length();
}

void solve(){

	vector<string> a;
	string s;
	cin>>s;
	char prev = s[0];
	string ss = s.substr(0,1);
	for(int i=1;i<s.length();i++){
		if(prev == s[i]){
			ss+=s[i];
		} else {
			if(ss!="")
				a.push_back(ss);
			ss = s[i];
			prev = s[i];
		}
	}
	if(ss!="") a.push_back(ss);

	sort(a.begin(), a.end(), comp);
	int ans = 0;
	for(int i=0;i<a.size();i+=2){
		if(a[i][0] == '1'){
			ans += a[i].size();
		} else {
			break;
		}
	}

	cout<<ans<<endl;
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
