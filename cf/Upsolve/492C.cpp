#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool comp(vector<int> a1, vector<int> a2){
	return a1[1] < a2[1];
}

void solve(){

	int a,b,c; cin>>a>>b>>c;
	vector<vector<int>> ar;
	int nn = a;
	int sum = 0;
	while(nn--){
		int u,v; cin>>u>>v;
		ar.push_back({u,v});
		sum += u;
	}

	if(sum >= c * a){
		cout<<0<<endl;
		return;
	}

	sort(ar.begin(), ar.end(), comp);
	// for(auto el : ar){
	// 	cout<<el[0]<<" "<<el[1]<<endl;
	// }
	int ans =sum;
	int cnt = 0;
	for(auto el : ar){
		if(ans >= c*a){
			break;
		}
		if(c*a - ans < (b - el[0])){
			cnt += (c*a - ans) * el[1];
			break;
		} else {
			ans += b - el[0];
			cnt += el[1] * (b - el[0]);
		}
	}

	cout<<cnt<<endl;

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
