#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,x,m;
	cin>>n>>x>>m;

	vector< pair<int,int> > vv;
	while(m--){
		int u,v;
		cin>>u>>v;
		vv.push_back(make_pair(u,v));
	}

	m = vv.size();
	int l = INT_MAX, r = -1;
	for(auto el : vv){

		if(x >= el.first && x <= el.second){
			l = min(el.first, l);
			r = max(el.second, r);
		} 

		if(l!=INT_MAX && r!=-1){
			if(l >= el.first && l<= el.second || r>= el.first && r<= el.second){
				l = min(el.first, l);
				r = max(el.second, r);
			}
		}
	}

	if(l == INT_MAX || r == -1){
		cout<<1<<endl;
		return;
	}

	cout<<(r - l + 1)<<endl;

	

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
