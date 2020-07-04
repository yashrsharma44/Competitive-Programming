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
	string ans="";
	for(int k=0;k<n;k++){

		int el = a[k];
		if(el == 0 && k<n-1){	
			ans+="R";
		} else {
			if(k<n-1){
				for(int i=1;i<=el;i++){
					ans += "PRL";
				}
				ans+="R";
			} else {
				for(int i=1;i<=el;i++){
					ans+="PLR";
				}
			}
		}
	}
	cout<<ans<<endl;

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
