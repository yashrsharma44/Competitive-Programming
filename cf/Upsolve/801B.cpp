#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string x,y;
	cin>>x>>y;

	string z = "";
	for(int i=0;i<x.length();i++){
		if(y[i] - x[i] <= 0){
			if(y[i] == x[i]){
				if(y[i] == 'z'){
					z+=y[i];
				} else
				z += (char)(y[i]+1);
			} else {
				z += y[i];
			}
		} else {
			cout<<-1<<endl;
			return;
		}
	}
	cout<<z<<endl;

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
