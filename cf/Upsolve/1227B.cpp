#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n;
	cin>>n;
	int nn = n;
	set<int> elems;
	for(int i=1;i<=n;i++){
		elems.insert(i);
	}
	vector<int> a;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	int max_ = -1;
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		if(a[i] > max_){
			ans[i] = a[i];
			elems.erase(a[i]);
		} else {
			ans[i] = -1;
		}
		max_ = max(max_, a[i]);
	}

	for(int i=0;i<n;i++){
		if(ans[i] == -1){
			ans[i] = *elems.begin();
			elems.erase(elems.begin());
		} 
	}
	max_ = -1;
	for(int i=0;i<n;i++){
		max_ = max(max_, ans[i]);
		if(max_ != a[i]){
			cout<<-1<<endl;
			return;
		}
	}

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
