#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n;
	cin>>n;
	
	string s;
	cin>>s;
	set<int> one, zero;
	int k = 1;
	char prev = s[0];

	if(prev == '0'){
		one.insert(k);
	} else {
		zero.insert(k);
	}

	vector<int> ans;
	ans.push_back(k);

	for(int i=1;i<n;i++){
		if(prev == '0' && s[i] == '1'){
			int el = *one.begin();
			one.erase(el);
			ans.push_back(el);
			zero.insert(el);

			prev = s[i];
		} else if(prev == '1' && s[i] == '0'){
			int el = *zero.begin();
			zero.erase(el);
			ans.push_back(el);
			one.insert(el);
			prev = s[i];
		} else {
			if(s[i] == '1'){
				if(one.size() == 0){
					one.insert(++k);
				}
				int el = *one.begin();
				one.erase(el);
				ans.push_back(el);
				zero.insert(el);
			} else {
				if(zero.size() == 0){
					zero.insert(++k);
				}
				int el = *zero.begin();
				zero.erase(el);
				ans.push_back(el);
				one.insert(el);
			}
			prev = s[i];
		}
	}
	cout<<k<<endl;
	for(int el : ans){
		cout<<el<<" ";
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
