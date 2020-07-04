#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	
	int a = -1, b = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i%j == 0 && i*j > n && i/j < n){
				a = i; b = j;
				break;
			}
		}
	}

	if(a==-1){
		cout<<-1<<endl;
		return;
	}

	cout<<a<<" "<<b<<endl;
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
