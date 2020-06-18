#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> p;
	int nn = n;
	while(nn--){

		int vl;
		cin>>vl;
		p.push_back(vl);
	}

	vector<int> ans;
	vector<int> del;
	for(int i=1;i<n;i++){
		del.push_back(p[i] - p[i-1]);
	}

	ans.push_back(p[0]);
	for(int i=1;i<del.size();i++){
		if(del[i] > 0 && del[i-1] < 0 || del[i] < 0 && del[i-1] > 0){
			ans.push_back(p[i]);
		}
	}
	ans.push_back(p[n-1]);
	cout<<(int)(ans.size())<<endl;

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
