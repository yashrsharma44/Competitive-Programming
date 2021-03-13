#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005



int positive(vector<int> &a, vector<int> &b){
	vector<int> aa, bb;
	for(auto el : a){
		if(el >= 0) aa.push_back(el);
	}
	for(auto el : b){
		if(el >= 0) bb.push_back(el);
	}

	int n = aa.size(), m = bb.size();
	if(n == 0 || m == 0) return 0;
	vector<int> sufspec({0});
	int p1 = m-1;
	for(int i=n-1;i>=0;i--){
		while(p1 >= 0 && aa[i] < bb[p1]){
			p1--;
		}
		if(p1 >= 0 && aa[i] == bb[p1]){
			sufspec.push_back(sufspec.back() + 1);				
		} else {
			sufspec.push_back(sufspec.back());
		}	
	}

	reverse(sufspec.begin(), sufspec.end()); 

	int k = 0;
	int j = 0;
	int ans = 0;
	for(int i=0;i<m;i++){
		// lets put the first box at bb[i]
		// if aa[0] > bb[i], skip
		if(aa[0] > bb[i]) continue;

		// Lets put aa[0] in bb[i], and calculate the offset
		int offset = bb[i] - aa[0];
		// Lets iterate the pile last pos, if aa[k] < aa[0] + offset + k, then we increase the pile size
		while(k < aa.size() && aa[k] <= aa[0] + offset + k){
			k++;
		}

		// Once we have size, we can check how many special pos within k.
		while(j < bb.size() && bb[j] <= aa[0] + offset + k - 1){
			j++;
		}

		ans = max(ans, j - i + sufspec[k]);
	}
	return ans;
}

int negative(vector<int> &a, vector<int> &b){
	vector<int> aa, bb;
	for(auto el : a){
		if(el < 0) aa.push_back(-el);
	}
	for(auto el : b){
		if(el < 0) bb.push_back(-el);
	}
	reverse(aa.begin(), aa.end());
	reverse(bb.begin(), bb.end());

	return positive(aa, bb);
}

void solve()
{
	int n,m; cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}

	int ans = positive(a, b);
	ans += negative(a, b);
	// cout<<"Neg "<<negative(a,b)<<endl;
	cout<<ans<<endl;

}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	// t = 1;

	while (t--)
	{
		solve();
	}
}
