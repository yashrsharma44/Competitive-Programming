#include <bits/stdc++.h>
using namespace std;

struct vct{
	int first;
	int second;
};

bool cmp(const vct& left, const vct& right){

	return((left.first > right.first)||(left.first == right.first && left.second < right.second));
}

int main(){

	int n, k;
	cin>>n>>k;

	vct list_val[n];

	int i;

	for(i=0;i<n;i++)
	{
		cin>>list_val[i].first>>list_val[i].second;
	}

	sort(list_val,list_val+n, cmp);

	// Set up two pointers for traversing and finding the required kth element's 
	// group

	k -=1;
	int l(k),r(k);

	while(l>0 && list_val[k].first == list_val[l-1].first && list_val[k].second == list_val[l-1].second)
	{
		l-=1;
	}
	while(r<n-1 && list_val[k].first == list_val[r+1].first && list_val[k].second == list_val[r+1].second)
	{
		r+=1;
	}

	cout<<r-l+1;

}