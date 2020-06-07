#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	vector<int>  d;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		d.push_back(vl);
	}
	sort(d.begin(), d.end());

	int ans = d[0] * d[n-1];
	set<int> fact;
	for(int i=2;i*i<=ans;i++){
		if(ans % i == 0){
			fact.insert(i);
			fact.insert(ans / i);
		}
	}

	// sort(fact.begin(), fact.end());
	if(fact.size() != d.size()){
		cout<<-1<<endl;
		return;
	}
	for(int el : fact){
		if(el != d[0]){
			cout<<-1<<endl;
			return;
		}
		d.erase(d.begin());
	}

	cout<<ans<<endl;


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
