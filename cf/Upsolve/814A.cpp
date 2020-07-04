#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;
	vector<int> a,b;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	for(int i=0;i<k;i++){
		int vl;
		cin>>vl;
		b.push_back(vl);
	}
	sort(b.rbegin(), b.rend());
	int ptr = 0;
	for(int i=0;i<n;i++){
		if(a[i] == 0){
			a[i] = b[ptr++];
		}
	}
	bool isInc = true;
	for(int i=1;i<n;i++){
		if(a[i] <= a[i-1]){
			isInc = false;
			break;
		}
	}
	if(isInc){
		cout<<"No"<<endl;
	} else {
		cout<<"Yes"<<endl;
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
