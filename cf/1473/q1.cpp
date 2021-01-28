#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n,d; cin>>n>>d;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	sort(a.begin(), a.end());

	if(a.back() <= d){
		cout<<"YES"<<endl;
		return;
	}

	int m1 = a[0];
	int m2 = a[1];
	int m3 = a[2];

	if(m1 + m2 > d){
		cout<<"NO"<<endl;
		return;
	}

	if(m1 <= d && m2 <= d){
		cout<<"YES"<<endl;
		return;
	}

	if(m1 > d && m2 <=d && m2+m3 <= d){
		cout<<"YES"<<endl;
		return;
	}

	if(m1 <= d && m2 > d && m1+m3 <= d){
		cout<<"YES"<<endl;
		return;
	}

	cout<<"NO"<<endl;
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
