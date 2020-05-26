#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	ll x,y,x1,y1,x2,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;

	if(x1==x2 && (a>=1 || b>=1)){
		cout<<"No"<<endl;
		return;
	}

	if(y1==y2 && (c>=1 || d>=1)){
		cout<<"NO"<<endl;
		return;
	}

	if((x-a+b>=x1 && x-a+b<=x2) && (y-c+d>=y1 && y-c+d<=y2)){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}	


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}