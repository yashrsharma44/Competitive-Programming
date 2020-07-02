#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,r;
	cin>>n>>r;

	int sum = 0;
	

	for(int i=1;i<=r;i++){

		int k = n % i;
		sum += (i - k + 1) / 2;
	}

	if(n%r!=0){
		int times = n / r;
		sum = sum * times;		
		
		int rem = n % r;
		for(int i=1;i<=rem;i++){
			int k = n % i;
			sum += (i - k + 1) / 2;
		}


	}


	
	cout<<sum<<endl;

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
