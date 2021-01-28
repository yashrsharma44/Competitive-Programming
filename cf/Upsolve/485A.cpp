#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int a,m; cin>>a>>m;
	set<int> st;
	while(st.find(a) == st.end()){
		st.insert(a);
		a = a + (a % m);
	}

	if(st.find(0) != st.end()){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

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



// 8,9,7 cur date cur year pehl 2100 mein nhi chalega,