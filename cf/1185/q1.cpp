#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	vector<int> arr(3);
	cin>>arr[0]>>arr[1]>>arr[2];

	ll d;
	cin>>d;

	sort(arr.begin(), arr.end());

	ll dist1  = abs(arr[0] - arr[1]) >= d ? 0 : d - abs(arr[0] - arr[1]);
	ll dist2  = abs(arr[1] - arr[2]) >= d ? 0 : d - abs(arr[2] - arr[1]);

	cout<<dist1+dist2<<endl;

}

int main(){
	
	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}