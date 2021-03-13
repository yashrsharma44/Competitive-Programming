#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve(){	

	int n,k; cin>>n>>k;
	multiset<int> a;
	for(int i=0;i<n;i++)
	{
		int u; cin>>u;
		a.insert(u);
	}	

	if(k == 0){
		set<int> elems(a.begin(), a.end());
		cout<<elems.size()<<endl;
		return;
	}

	int mex1 = 0;
	for(auto el : a){
		if(el == mex1){
			mex1++;
		}
	}
		
	int max_ = *a.rbegin();
	
	// 0 <= mex < max

	if(mex1 >= 0 && mex1 < max_){
		int val = (max_ + mex1 + 1) / 2;
		a.insert(val);

		set<int> elems(a.begin(), a.end());
		cout<<elems.size()<<endl;
		return;
	}

	// max == mex, not possible
	// mex > max
	cout<<(max_ + k + 1)<<endl;
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
