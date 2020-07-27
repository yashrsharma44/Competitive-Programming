#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int n;
	cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	
	string s = "";
	for(int k=0;k<200;k++){
		s+='a';
	}
	cout<<s<<endl;
	for(int el : a){
		s[el] = s[el] == 'a' ? 'b' : 'a';
		cout<<s<<endl;
	}

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
