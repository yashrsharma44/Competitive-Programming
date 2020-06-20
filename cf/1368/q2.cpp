#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int k;
	cin>>k;

	int prev = 0;
	int ctr = 0;
	int prevVal = 0;

	while(prevVal <= k){

		int next = prev + (ctr * (ctr + 1)) / 2;
		prevVal = prevVal + next;
		prev = next;
		ctr+=1;

	}
	cout<<ctr<<endl;
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
