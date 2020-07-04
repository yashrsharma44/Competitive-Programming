#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	n*=2;
	int nn=n;
	vector<int>a;
	int sum = 0;
	while(n--){
		int vl;
		cin>>vl;
		sum+=vl;
		a.push_back(vl);
	}
	sort(a.begin(), a.end());
	int s2 = 0;
	for(int i=0;i<nn/2;i++){
		s2+=a[i];
	}
	if(s2*2==sum){
		cout<<-1<<endl;
	} else {
		for(int el : a){
			cout<<el<<" ";
		}
		cout<<endl;
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
