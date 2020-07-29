#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int n;
	cin>>n;
	vector<int> a;
	while(n--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	int m;
	cin>>m;
	vector<int> b;
	while(m--){
		int vl;
		cin>>vl;
		b.push_back(vl);
	}
	set<int> aa, bb;
	for(int el : a){
		aa.insert(el);
	}
	for(int el : b){
		bb.insert(el);
	}

	vector<int> ans;
	for(int el : a){
		for(int elb : b){
			int sm = el + elb;
			if(aa.find(sm) == aa.end() && bb.find(sm) == bb.end()){
				ans.push_back(el);
				ans.push_back(elb);
				break;
			}
		}
	}

	cout<<ans[0]<<" "<<ans[1]<<endl;
	
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
