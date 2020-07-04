#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	
	int nn = n;
	int a = 0, b = 0;
	while(nn--){
		int vl;
		cin>>vl;
		if(vl == 1){
			a+=1;
		} else {
			b++;
		}
	}

	if(a == 0){
		cout<<0<<endl;
		return;
	}
	if(b == 0 && a <= 2){
		cout<<0<<endl;
		return;
	}
	int k = 0;
	if(a<b){
		k = a;
	} else {
		k = b;
		a -= b;
		k += (a/3);
	}


	cout<<k<<endl;

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
