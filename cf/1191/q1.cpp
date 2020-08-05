#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n;
	cin>>n;

	if((n%4) == 1){
		cout<<"0 A"<<endl;
		return;
	}

	map<int,char> mp;
	mp[0] = 'D';
	mp[1] = 'A';
	mp[2] = 'C';
	mp[3] = 'B';

	map<char,int> m;
	m['A'] = 0;
	m['B'] = 1;
	m['C'] = 2;
	m['D'] = 3;

	int min_ = 4;
	int ans = -1;
	for(int k=0;k<=2;k++){
		int nm = (n+k) % 4;
		if(nm > m[mp[nm]]){
			min_ = m[mp[nm]];
			ans = k;
		}
	}
	cout<<(ans)<<" "<<(char)('A' + min_)<<endl;
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
