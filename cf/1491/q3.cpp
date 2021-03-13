#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve()
{
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int j=0;j<n;j++){
		int el = -1;
		for(int i=0;i<n;i++){
			if(a[i] > 1){
				el = i;
				break;
			}
		}
		if(el == -1){
			break;
		}
		ans+=1;
		int i=el;
		while(i < n){
			a[i] -= 1;
			i += a[i] + 1;
		}
	}

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
