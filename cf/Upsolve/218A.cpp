#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;
	vector<int> a;
	for(int i=0;i<(2*n+1);i++){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	for(int i=a.size()-2;i>0&&k>0;i--){

		if(a[i] > a[i-1]+1 && a[i] > a[i+1]+1){
			a[i]-=1;
			k--;
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
