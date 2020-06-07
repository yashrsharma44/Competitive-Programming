#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int ang;
	cin>>ang;

	int g = __gcd(180LL, ang);
	int n = 180 / g;
	int k = ang / g;

	if(n == k + 1){
		n *= 2;
		k *= 2;
	}

	cout<<n<<endl;


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
