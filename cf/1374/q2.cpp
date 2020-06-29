#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	int steps = 0;
	while(n % 6 == 0){
		n /= 6;
		steps +=1;
	}
	if(n == 1){
		cout<<steps<<endl;
		return;
	}
	int k = 0;
	while(n % 3 == 0){
		n /= 3;
		k+=1;
		steps+=1;
	}
	if(n != 1){
		cout<<-1<<endl;
		return;
	}
	steps += k;
	cout<<steps<<endl;
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
