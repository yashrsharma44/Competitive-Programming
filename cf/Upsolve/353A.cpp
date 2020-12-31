#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<vector<int>> arr;

	int nn = n;
	int s1 = 0, s2 = 0;
	while(nn--){
		int u, v; cin>>u>>v;
		arr.push_back({u, v});
		s1+=u;s2+=v;
	}

	if(s1%2 == 0 && s2%2==0){
		cout<<0<<endl;
		return;
	}
	if(s1%2==1 && s2%2==0 || s1%2==0 && s2%2==1){
		cout<<-1<<endl;
		return;
	}

	bool isPos = false;
	for(auto num : arr){
		if(num[0]%2==1 && num[1]%2==0 || num[0]%2==0 && num[1]%2==1){
			isPos = true;
			break;
		}
	}

	if(isPos){
		cout<<1<<endl;
	} else {
		cout<<-1<<endl;
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
