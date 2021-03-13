#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve()
{
	
	int n,k; cin>>n>>k;
	// if(n <= 3){
	// 	cout<<n-1<<endl;
	// 	for(int i=1;i<=n;i++){
	// 		if(i == k) continue;
	// 		cout<<i<<" ";
	// 	}
	// 	cout<<endl;
	// 	return;
	// }
	set<int> nums;
	for(int i=1;i<=n;i++){
		nums.insert(i);
	}

	for(int j=k-1;j>=(k+1)/2;j--){
		nums.erase(k - j);
	}
	nums.erase(k);
	if(k%2==0) nums.insert(k/2);
	cout<<nums.size()<<endl;
	for(auto el : nums){
		cout<<el<<" ";
	}
	cout<<endl;
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
