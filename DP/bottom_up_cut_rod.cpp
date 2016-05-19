#include <iostream>

using namespace std;

int bottom_up_cut_rod(int *p, int n){
	
	int r[n+1];
	int q;
	r[0]=0;
	for(int j=1; j<=n; ++j){
		
		q=-1;
		for(int i=1; i<=j; ++i) q=max(q,p[i-1]+r[j-i]);
		r[j]=q;
	}
	return r[n];
}


int main(){

	int n;
	cin>>n;
	int p[10]={1,5,8,9,10,17,17,20,24,30};
	cout<<bottom_up_cut_rod(p,n);

	return 0;

}
