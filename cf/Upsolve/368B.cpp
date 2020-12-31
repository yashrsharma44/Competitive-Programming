#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n,m;
	cin>>n>>m;

	vector<int> arr, pos, ans;
	int nn = n, mm = m;
	while(nn--){
		int u; cin>>u;
		arr.push_back(u);
	}


	while(mm--){
		int u; cin>>u;
		pos.push_back(u);
	}

	set<int> elems;
	

	for(int i=n-1;i>=0;i--){
		elems.insert(arr[i]);
		ans.push_back((int)(elems.size()));
	}

	reverse(ans.begin(), ans.end());

	for(auto pp : pos){
		cout<<ans[pp-1]<<endl;
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
