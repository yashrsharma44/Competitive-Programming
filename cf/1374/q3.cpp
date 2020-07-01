#include <bits/stdc++.h>
#define int long long 

using namespace std;

bool  check(string s){

	int cnt = 0;
	for(char c : s){
		if(c == '('){
			cnt+=1;
		} else {
			cnt -= 1;
		}
		if(cnt < 0){
			return false;
		}
	}

	return true;

}

void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;

	int cnt = 0;
	int ans = 0;
	for(char c:s){
		if(c==')'){
			cnt-=1;
		}else{
			cnt+=1;
		}
		ans = min(ans, cnt);
	}

	cout<<max(0LL, -ans)<<endl;

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
