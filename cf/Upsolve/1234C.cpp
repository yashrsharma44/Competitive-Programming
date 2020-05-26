
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	
	vector<string> grid(2);
	cin>>grid[0]>>grid[1];

	set<char> L,S;
	L.insert({'3','4','5','6'});
	S.insert({'2','1'});

	int dr[3] = {0,-1,1};
	int dc[3] = {1,0,0};

	ll r=0,c=0;
	char prevR = 0;
	while(r<2 && c<n){

		char el = grid[r][c];
		if(L.find(el)!=L.end()){
			
			if(prevR == r){
				if(r==0){
					grid[r][c] = '4';
					prevR = r;
					r=r+1;
				} else {
					grid[r][c] = '5';
					prevR = r;
					r = r-1;
				}
			} else {
				
				if(r == 0){
					grid[r][c] = '3';
					prevR = r;
				} else {
					grid[r][c] = '6';
					prevR = r;
				}
				c=c+1;
			}
			

		} else {

			if(prevR == r){
				grid[r][c] = '2';
				c+=1;
				prevR = r;
			} else {
				cout<<"NO"<<endl;
				return;
			}
		}

	}

	if(r == 1 && c == n){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main(){

	ll t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
}