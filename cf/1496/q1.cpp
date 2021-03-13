#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve(){	

	int n,k; cin>>n>>k;
	string s; cin>>s;

	bool isPal = true;
	int p1 = 0, p2 = n-1;
	while(p1 < p2){
		if(s[p1] != s[p2]){
			isPal = false;
			break;
		}
		p1++;p2--;
	}
	if(isPal){
		if(n >= (2 * k) + 1){
			cout<<"YES"<<endl;			
		} else {
			cout<<"NO"<<endl;
		}
		return;
	}
	// cout<<p1<<" "<<p2<<endl;
	int cnt = p1 + n - p2 + 1;
	if(cnt >= 2 * k + 1){
		cout<<"YES"<<endl;
		return;
	} 
		cout<<"NO"<<endl;
	

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
