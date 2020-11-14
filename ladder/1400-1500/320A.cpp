#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

int memo[15];

bool check(string &s, int k){
	if(k >= s.length()) return true;

	vector<string> choice({"1","14","144"});
	bool ans = false;

	for(int i=0;i<3;i++){
		int j = 0, kk = k;
		while(j < choice[i].length() && kk < s.length() && choice[i][j] == s[kk]){
			j++; kk++;
		}
		if(j == choice[i].length()){
			ans = ans || check(s, k+j);
		}
	}

	return ans;
}

void solve(){

	int n; cin>>n;
	string s = to_string(n);

	if(check(s, 0)){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return;


	vector<vector<int>> dp(3, vector<int>(s.length()+1, 0));
	dp[0][0] = dp[1][0] = dp[2][0] = 1;
	vector<string> choice({"1","14","144"});
	for(int i=0;i<s.length();i++){
		for(int k=0;k<3;k++){
			if(dp[k][i] == 1){
				int ii = 0;
				int len = choice[k].length(); int j = i;
				while(j < n && choice[k][ii] == s[j]){
					j++; ii++;
				}
				if(ii == len) dp[k][i+len] = 1;
			}
		}

	}

	for(int i=0;i<3;i++){
		for(int el : dp[i]) cout<<el<<" ";
		cout<<endl;
	}


	if(dp[0].back() == 1 || dp[1].back() == 1 || dp[2].back() == 1){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
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
