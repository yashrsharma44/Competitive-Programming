#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	if(n == 1){
		cout<<9<<endl;
		return;
	}
	if(n==2){
		cout<<98<<endl;
		return;
	}
	int ctr = 9;
	cout<<98;
	for(int i=0;i<n-2;i++){
		cout<<((ctr)%10);
		ctr++;
	}

	cout<<endl;
	
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
