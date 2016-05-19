#include <iostream>

using namespace std;

int cut_rod(int *p, int n){
	
	if (n==0) return 0;
	int q=-1;
	for(int i=1; i<=n; ++i) q=max(q,p[i-1]+cut_rod(p,n-i));  
	return q;
}

int main(){
	
	int n;
	cin>>n;
	int p[10]={1,5,8,9,10,17,17,20,24,30};
	cout<<cut_rod(p,n);

	return 0;
}
