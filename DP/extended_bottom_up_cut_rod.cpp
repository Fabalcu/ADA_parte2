#include <iostream>

using namespace std;

int extended_bottom_up_cut_rod(int *p, int n, int *s){
	
	int r[n+1];
	int q;
	r[0]=0;
	for(int j=1; j<=n; ++j){
		
		q=-1;
		for(int i=1; i<=j; ++i) {
			
			if(q<p[i-1]+r[j-i]){

				q=p[i-1]+r[j-i];
				s[j]=i;
			}
		}
		r[j]=q;
	}
	return r[n];
}

void print_cut_rod_solution(int *p, int n){
	
	int s[n+1];
	s[0]=0;
	int r=extended_bottom_up_cut_rod(p,n,s);
	cout<<r<<endl;
	while(n>0){
		cout<<s[n]<<" ";
		n-=s[n];
	}
	return;
}

int main(){

	int n;
	cin>>n;
	int p[10]={1,5,8,9,10,17,17,20,24,30};
	print_cut_rod_solution(p,n);

	return 0;

}
