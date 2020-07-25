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
	char c = 'a';
	vector<string> ans;
	string s = "";
	int z = 0;
	while(z < n && a[z] == 0){
		string xx(1, c);
		ans.push_back(xx);
		c++;
		z++;
	}

	for(int i=z+1;i<n-1;i++){
		
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
