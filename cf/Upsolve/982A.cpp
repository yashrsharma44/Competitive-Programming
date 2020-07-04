#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;

	if(n==1){
		if(s[0] == '1')
		cout<<"Yes"<<endl;
		else 
		cout<<"No"<<endl;

		return;
	}
	if(n == 2){
		if(s == "01" || s == "10"){
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		return;
	}
	
	int count = 0;
	for(char c : s){
		if(c == '0'){
			count++;
		} else {
			if(count > 2){
				cout<<"No"<<endl;
				return;
			}
			count = 0;
		}
	}

	for(int i=1;i<s.length()-1;i++){
		if(s[i] == '1'){
			if(s[i-1] == '1' || s[i+1] == '1'){
				cout<<"No"<<endl;
				return;
			}
		}
	}

	if(s[0] == '0'){
		int i=0;
		int cnt = 0;
		while(i < n && s[i++] != '1'){
			cnt++;
		}
		if(cnt > 1){
			cout<<"No"<<endl;
			return;
		}
	}

	if(s[n-1] == '0'){
		int i = n-1;
		int cnt = 0;
		while(i >= 0 && s[i--] != '1'){
			cnt++;
		}
		if(cnt>1){
			cout<<"No"<<endl;
			return;
		}
	}

	cout<<"Yes"<<endl;
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
