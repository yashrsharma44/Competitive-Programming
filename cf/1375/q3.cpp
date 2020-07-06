#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n;
	cin>>n;
	int nn = n;
	vector<int> a;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	if(a[0] == 1){
		cout<<"YES"<<endl;
		return;
	}
	if(a[n-1] == 1 || a[0] == n){
		cout<<"NO"<<endl;
		return;
	}

	int idx = -1;
	for(int i=0;i<n;i++){
		if(a[i] == 1){
			idx = i;
		}
	}
	int m1 = a[0], m2 = -1;
	for(int i=0;i<idx;i++){
		m1 = min(m1, a[i]);
	}
	for(int i=idx;i<n;i++){
		m2 = max(m2, a[i]);
	}

	if(m1 < m2 && m1!=-1 && m2!=-1){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	

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
