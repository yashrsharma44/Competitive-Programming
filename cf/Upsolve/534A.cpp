#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	if(n<=2){
		cout<<1<<endl<<1<<endl;;
		return;
	}
	if(n == 3){
		cout<<2<<endl;
		cout<<1<<" "<<3<<endl;
		return;
	}
	if(n == 4){
		cout<<4<<endl;
		cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
		return;
	}
	int k = 1;
	vector<int> a(n, 0);
	for(int i=1;i<n;i+=2){
		a[i] = k++; 
	}
	for(int i=0;i<n;i+=2){
		a[i] = k++;
	}
	cout<<n<<endl;
	for(int el : a){
		cout<<el<<" ";
	}
	cout<<endl;


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
