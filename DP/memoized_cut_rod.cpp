#include <iostream>

using namespace std;

int memoized_cut_rod_aux(int *p,int n,int *r){
	
	if(r[n]>=0) return r[n];
	int q;
	if(n==0) q=0;
	else{
		
		q=-1;
		for(int i=1; i<=n; ++i) q=max(q,p[i-1]+memoized_cut_rod_aux(p,n-i,r));
	}
	r[n]=q;
	return q;
}

int memoized_cut_rod(int *p,int n){
	
	int r[n+1];
	for(int i=0; i<=n; ++i) r[i]=-1;
	return memoized_cut_rod_aux(p,n,r);
}

int main(){
	
	int n;
	cin>>n;
	int p[10]={1,5,8,9,10,17,17,20,24,30};
	cout<<memoized_cut_rod(p,n);

	return 0;
}
