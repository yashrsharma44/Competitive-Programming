#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	int a = 1, b = 1;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(i+j == n && __gcd(i,j) == 1 && i < j){
				if(a*i < j*b){
					a = i;
					b=j;
				}
			}
		}
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
