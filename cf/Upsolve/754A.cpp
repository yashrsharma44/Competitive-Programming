#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a;
	int nn = n;
	int sum = 0;
	while(nn--){
		int vl;
		cin>>vl;
		sum+=vl;
		a.push_back(vl);
	}

	if(sum != 0){
		cout<<"YES"<<endl;
		cout<<1<<endl;
		cout<<1<<" "<<n<<endl;
		return;
	}

	sum = 0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum != 0){
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<1<<" "<<i+1<<endl;
			cout<<i+2<<" "<<n<<endl;
			return;
		}
	}

	cout<<"NO"<<endl;

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
