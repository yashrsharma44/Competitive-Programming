#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s,t;
	cin>>s>>t;
	int count = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == t[0]){
			int len = 0;
			for(int j=0;j<t.length();j++){
				if(s[i+j] == t[j]){
					len++;
				} else {
					break;
				}
			}
			if(len == t.length()){
				s[i+t.length()-1] = '#';
				count++;
			}	
		}
		
	}
	cout<<count<<endl;
	
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
