#include <bits/stdc++.h>
#define int long long 

using namespace std;

int a2,b2,a3,b3;

bool f(int a,int b){

	if(a2+a3 <= a && b >=max(b2,b3))return true;
	if(a2+b3<=a && b >=max(b2,a3))return true;
	if(a3+b2<=a && b >=max(a2,b3))return true;
	if(b3+b2<=a && b >=max(a2,a3))return true;

	return false;
}

void solve(){

	int a,b;
	cin>>a>>b>>a2>>b2>>a3>>b3;
	if(f(a,b) || f(b,a))cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;


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
