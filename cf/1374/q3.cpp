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

	if(check(s)){
		cout<<0<<endl;
		return;
	}

	int min_ = n;
	string ss = s;
	for(int i=0;i<n;i++){
		
		string ss = s.substr(0,i);
		string tt = s.substr(i+1);

		string nm = ss + tt;
		cout<<nm<<endl;
		if(check(nm+s[i])){
			min_ = min(min_, n - i);
		} else if(check(s[i] + nm)){
			min_ = min(min_, i);
		}
	}


	cout<<min_<<endl;

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
