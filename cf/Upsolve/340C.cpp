#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;


void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}	
	sort(a.begin(), a.end());

	// Formula - 2*|ai - aj| + (sum(ai)) / n
	int sum = 0;
	for(auto el : a){
		sum += el;
	}

	int sum2 = 0;
	int pre = 0;
	for(int i=0;i<n;i++){
		sum2 += (i * a[i]) - (pre);
		pre += a[i];
	}	

	int num = 2*sum2 + sum;
	int den = n;

	int div = __gcd(num, den);
	num /= div;
	den /= div;

	cout<<num<<" "<<den<<endl;

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
