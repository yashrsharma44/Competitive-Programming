#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	int x;
	cin>>x;

	n = n % 6;
	n = 6 - n;
	if(n == 6){
		n = 0;
	}
	// cout<<"N"<<n<<endl;
	string arr[6] = {"012","021","201","210","120","102"};
	string ans = arr[n];
	int an = ans[x]-'0';
	cout<<an<<endl;

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
