#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int n,m;
	cin>>n>>m;
	vector<int> a, b;
	while(n--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}	

	while(m--){
		int vl;
		cin>>vl;
		b.push_back(vl);
	}
	set<int> aa;
	for(int el : a){
		aa.insert(el);
	}
	for(int el : b){
		if(aa.find(el) != aa.end()){
			cout<<"YES"<<endl;
			cout<<1<<" "<<el<<endl;
			return;
		}
	}

	cout<<"NO"<<endl;

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
