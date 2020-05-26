#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	set<ll> non_color;
	for(ll i=0;i<n;i++){
		non_color.insert(i);
	}

	vector<ll> color(n, -1);
	color[0] = 1;

	ll curr_color = 1;
	char prev = s[0];
	non_color.erase(0);
	while(non_color.size()!=0){

	
		
		for(ll i=0;i<n;i++){

			if(color[i] == -1){

				if((s[i] - prev) >= 0){
					color[i] = curr_color;
					non_color.erase(i);	
					prev = s[i];
				}
			}

		}

		curr_color += 1;

		for(ll i=0;i<n;i++){

			if(color[i] == -1){
				prev = s[i];
				color[i] = curr_color;
				non_color.erase(i);
				break;
			}
		}

	}

	ll maxC = -1;
	for(ll el : color){

		maxC = max(maxC, el);
	}

	cout<<maxC<<endl;
	for(ll el : color){
		cout<<el<<" ";
	}
	cout<<endl;

}

int main(){

	solve();
}