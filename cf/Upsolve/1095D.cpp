#include <bits/stdc++.h>
#define int long long 

using namespace std;

bool check(pair<int,int> p, int el){
	return (p.first == el || p.second == el);
}

void solve(){

	int n;
	cin>>n;

	vector< pair<int,int> >v;
	v.push_back({-1,-1});

	for(int i=0;i<n;i++){
		int a1,a2;
		cin>>a1>>a2;
		v.push_back({a1, a2});
	}

	set<int> notused;
	vector<int> ans(n+1, -1);
	for(int i=1;i<=n;i++){

		int n1 = v[i].first, n2 = v[i].second;
		if(check(v[n1], n2) && notused.find(n1)==notused.end()){
			ans[i] = n1;
			notused.insert(n1);
		} else {
			ans[i] = n2;
			notused.insert(n2);
		}
	}

	vector<int> a;
	// a.push_back(1);
	int i=1;
	for(;;){
		if(ans[i] < 0){
			break;
		} else {
			a.push_back(ans[i]);
			int nextIdx = ans[i];
			ans[i] = -ans[i];
			i = nextIdx;
		}
	}

	for(int el : a){
		cout<<el<<" ";
	}
	cout<<endl;

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
