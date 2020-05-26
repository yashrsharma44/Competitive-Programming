#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){
	return p1.second > p2.second;
}

int main(){

	ll n;
	cin>>n;

	ll sx, sy;
	cin>>sx>>sy;

	vector < pair<ll,ll> > points[4];

	ll nn = n;
		
	vector < pair<ll,ll> > coord(4, make_pair(0,0));

	for(ll i=0;i<4;i++){
		coord[i].first = i;
	}



	while(nn--){

		ll x,y;
		cin>>x>>y;

		if((x - sx) >= 0 && (y - sy) >= 0){
			coord[0].second++;
			points[0].push_back(make_pair(x, y));
		
		} 

		if((x - sx) <= 0 && (y - sy) >= 0){
			coord[1].second++;
			points[1].push_back(make_pair(x, y));
		}

		if((x - sx) >=0 && (y - sy) <= 0){
			coord[2].second++;
			points[2].push_back(make_pair(x, y));
		}

		if((x - sx) <= 0 && (y - sy) <= 0){
			coord[3].second++;
			points[3].push_back(make_pair(x, y));
		}
	}


	sort(coord.begin(), coord.end(), comp);

	cout<<coord[0].second<<endl;

	vector < pair<ll,ll> > pt = points[coord[0].first];

	ll minX = INT_MAX, minY = INT_MAX;

	for(pair<ll,ll> el : pt){

		if(minX > abs(el.first)){
			minX = el.first;
		}

		if(minY > abs(el.second)){
			minY = el.second;
		}
	}

	cout<<(minX + sx)<<" "<<(minY + sy)<<endl;

}