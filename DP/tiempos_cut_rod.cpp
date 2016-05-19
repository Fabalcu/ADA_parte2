#include <iostream>

using namespace std;

int cut_rod(int *p, int n){
	
	if (n==0) return 0;
	int q=-1;
	for(int i=1; i<=n; ++i) q=max(q,p[i-1]+cut_rod(p,n-i));  
	return q;
}

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
	
	int p[15]={1,5,8,9,10,17,17,20,24,30,38,45,52,58,54};
	clock_t tStart;
	for(int i=1; i<=15; ++i){

		cout<<"N="<<i<<endl;
		cout<<"cut_rod: ";
		tStart=clock();
		cut_rod(p,i);
		cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
		cout<<"memoized_cut_rod: ";
		tStart=clock();
		memoized_cut_rod(p,i);
		cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
		cout<<"bottom_up_cut_rod: ";
		tStart=clock();
		bottom_up_cut_rod(p,i);
		cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

	}
	return 0;

}




