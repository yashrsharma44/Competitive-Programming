#include <bits/stdc++.h>
// #define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	int tf = 0, fif = 0;
	for(int i=0;i<n;i++){
		if(a[i] == 25){
			tf++;
			continue;
		}
		if(a[i] == 50){
			if(tf > 0){
				tf--;
				fif++;
			} else {
				cout<<"NO"<<endl;
				return;
			}
		}

		if(a[i] == 100){
			if(tf > 0 && fif > 0 || tf >= 3){
				if(fif == 0) tf-=3;
				else{
					tf--; fif--;
				}
			} else {
				cout<<"NO"<<endl;
				return;
			}
		}
	}

	cout<<"YES"<<endl;
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
