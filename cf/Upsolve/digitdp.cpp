#include <bits/stdc++.h>
using namespace std;

#define int long long

int numLimit[1001];

int dfs2(int pos, int n, int sum, bool isPos){

	if(pos > n) return sum;
	int ans = 0;
	int limit = 9;
	if(!isPos) limit = numLimit[pos];

	for(int i=1;i<=limit;i++){
		if(isPos || i < limit) {
			ans += dfs(pos+1, n, sum+i, true);
		} else {
			ans += dfs(pos+1, n, sum+i, false);
		}
	}
	return ans;
}
 
// This function calculates sum of all digits from 0 to (9.. n times) inclusive
int dfs(int pos, int n, int sum){
	// if(n == 0) return 0;
	if(pos > n) return sum;

	int ans = 0;
	for(int i=0;i<=9;i++){
		ans += dfs(pos+1, n, sum + i);
	}

	return ans;
}

void solve(){

	// Generate sum of all digits upto n digits
	// cout<<"Enter a number for sum of digits"<<endl;
	// int a; cin>>a;
	// int ans = dfs(1, a, 0);
	// cout<<"Answer : "<<ans<<endl;

	// Generate sum of digits with num <= a
	cout<<"Enter the number uptil which sum needs to be calculated"<<endl;
	string s; cin>>s;

	for(int i=1;i<=s.length();i++) numLimit[i] = (s[i-1] - '0');

	int ans = dfs2(1, s.length(), 0, true);
	cout<<"Answer : "<<ans<<endl;
}

int32_t main(){
	int t;
	t = 1;
	// cin>>t;
	while(t--) solve();
}