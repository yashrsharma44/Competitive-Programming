#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int s,n; cin>>s>>n;
	multiset<pair<int,int>> ms;
	for(int i=0;i<n;i++){
		int u,v; cin>>u>>v;
		ms.insert({u,v});
	}
	while(ms.size() > 0 && s > ms.begin()->first){
		s += ms.begin()->second;
		ms.erase(ms.begin());
	}
	if(ms.size() > 0){
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
	}
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
