#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	string s; cin>>s;
	int nb,ns,nc,pb,ps,pc; cin>>nb>>ns>>nc>>pb>>ps>>pc;
	int r; cin>>r;

	int b = 0, ss = 0, c = 0;
	for(auto ch : s){
		if(ch == 'B') b+=1;
		if(ch == 'S') ss+=1;
		if(ch == 'C') c+=1;
	}

	// brute force:
	// x * pb + y * ps + z * pc <= r
	// such that, (nb+x) / b + (ns+y) / s + (nc+z) / c is max

	// Let's use another approach, lets binary search on the answer
	// for a given hamburger count, lets check if that count is possible or not
	
	function<bool(int)> check = [&](int x) {
		int b1 = b * x, s1 = ss * x, c1 = c * x;
		return max(b1 - nb, 0LL) * pb + max(s1 - ns, 0LL) * ps + max(c1 - nc, 0LL) * pc <= r; 
	};

	int l = 0, ri = 1e12 + 100;
	while(l < ri){
		int m = (l + ri + 1) >> 1;
		if(check(m)){
			l = m;
		} else {
			ri = m-1;
		}
	}

	cout<<l<<endl;



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