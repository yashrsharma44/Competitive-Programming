#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k;

	vector<int> a,b;
	int nn = n;
	while(nn--){
		int aa;
		cin>>aa;
		a.push_back(aa);
	}
	nn = m;
	while(nn--){
		int bb;
		cin>>bb;
		b.push_back(bb);
	}

	if(k >= min(n,m)){
		cout<<-1<<endl;
		return;
	}

	for(int i=0;i<n;i++){
		a[i] = a[i] + ta;
	}

	if(a[0] > b[m-1]){
		cout<<-1<<endl;
		return;
	}

	// int p1 = 1, p2 = 0;
	// k-=1;
	// while(p2 < m && p1 < n && a[p1] > b[p2]){
	// 	p2++;
	// }

	// if(k > 0){
	// 	p2+=1;
	// 	k--;
	// }
	int ans = -1;
	for(int i=0;i<=k;i++){

		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		pos += (k - i);
		if(pos >= m){
			cout<<-1<<endl;
			return;
		}
		ans = max(ans, b[pos] + tb);
	}

	cout<<ans<<endl;


// 2 4 6 8
// 1 2 3 9 10	

	

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
