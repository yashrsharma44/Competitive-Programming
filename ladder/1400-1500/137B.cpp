#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	multiset<int> a;
	for(int i=0;i<n;i++){
		int aa; cin>>aa;
		a.insert(aa);	
	} 

	for(int i=1;i<=n;i++){
		if(a.find(i) != a.end()){
			a.erase(a.find(i));
		}
	}

	int ans = a.size(); cout<<ans<<endl;


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
