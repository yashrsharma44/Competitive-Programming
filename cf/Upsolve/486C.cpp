#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,p; cin>>n>>p;
	string s; cin>>s;
	int ans = 0;
	if(p*2 > n){
		reverse(s.begin(), s.end());
		p = n - p + 1;
	}

	string s2 = s;
	reverse(s2.begin(), s2.end());
	if(s == s2){
		cout<<0<<endl;
		return;
	}

	int l = 0, r = (n-1)/2;

 	while(s[l] == s[n - 1 - l]){
 		l++;
 	}

 	int ii = r + (n+1)%2;
 	while(ii < n && s[r] == s[ii]){
 		r--; ii++;
 	}

 	// cout<<l<<" "<<r<<endl;
 	int l2 = ii, r2 = n-1-l;
 	p--;
 	if(p <= l){
 		ans += r - p;
 	} else if(p >= r){
 		ans += p - l;
 	} else {
 		ans += r - l + min(p - l, r- p);
 	}

 	// cout<<ans<<"P"<<endl;
 	for(int i=0;i<=r-l;i++){
 		// cout<<s[l+i]<<" "<<s[r2-i]<<endl;
 		int val = min(abs(s[l+i] - s[r2-i]), 26 - abs(s[l+i] - s[r2-i]));
 		// cout<<val<<endl;
 		ans +=  val;
 	}

	cout<<ans<<endl;
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
