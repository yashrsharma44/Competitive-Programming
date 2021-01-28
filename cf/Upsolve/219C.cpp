#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;


void solve(){

	int n,k; cin>>n>>k;
	string s; cin>>s;

	if(k == 2){

		string s1 = "A", s2 = "B";
		for(int i=1;i<n;i++){
			if(s1.back() == 'A'){
				s1 += 'B';
				s2 += 'A';
			} else {
				s1 += 'A';
				s2 += 'B';
			}
		}

		int c1 = 0, c2 = 0;
		for(int i=0;i<n;i++){
			if(s[i] != s1[i])c1++;
			if(s[i] != s2[i])c2++;
		}

		if(c2 < c1){
			cout<<c2<<endl;
			cout<<s2<<endl;
		} else {
			cout<<c1<<endl;
			cout<<s1<<endl;
		}

		return;
	}

	int cnt = 0;
	for(int i=1;i<n-1;i++){
		if(s[i] == s[i-1] || s[i] == s[i+1]){
			int nm = s[i] - 'A', nm1 = s[i-1] - 'A', nm2 = s[i+1] - 'A';
			while(nm == nm1 || nm == nm2){
				nm++;
				nm%=k;
			}

			s[i] = (char)('A' + nm);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	cout<<s<<endl;

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
