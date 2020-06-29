#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	double a,b,c;
	cin>>a>>b>>c;

	double val = a - (double)(c) / b;
	double val1 = a - ((double)(c) / b) + 1.0;

	double val2 = -val;
	double val3 = -val1;
	int a1 = -1, a2 = -1;
	if(val2 > 0){
		a1 = 1;
	} else if(val3 > 0){
		a1 = (int)b + 1;
	}

	if(val > 0){
		a2 = (int)b;
	} else if(val1 > 0){
		a2 = (int)b;
	}

	cout<<a1<<" "<<a2<<endl;

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
