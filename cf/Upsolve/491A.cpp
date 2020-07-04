#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int A,B;
	cin>>A>>B;
	for(int i=1;i<=A;i++){
		cout<<i<<" ";
	}
	int N = A + B +1;
	cout<<N<<" ";
	for(int i=1;i<=B;i++){
		cout<<N - i<<" ";

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
