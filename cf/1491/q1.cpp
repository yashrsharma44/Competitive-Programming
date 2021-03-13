#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve(){

	int n,q; cin>>n>>q;
	vector<int> a;
	int one = 0, zero = 0;
	for(int i=0;i<n;i++){
		int u; cin>>u;
		a.push_back(u);
		if(u == 1) one++;
		else zero++;
	}

	vector<vector<int>> qq;
	for(int i=0;i<q;i++){
		int u,v; cin>>u>>v;
		qq.push_back({u,v});
	}

	for(auto quer : qq){
		if(quer[0] == 1){
			int el = a[quer[1] - 1];
			if(el == 1){
				one--;
				zero++;
			} else {
				zero--;
				one++;
			}
			a[quer[1] - 1] = 1 - a[quer[1] - 1];
		} else {
			int pos = quer[1];
			if(pos > one){
				cout<<0<<endl;
			} else {
				cout<<1<<endl;
			}
		}
	}
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin >> t;
	t = 1;

	while (t--)
	{
		solve();
	}
}
