#include<iostream>
using namespace std;
int reverse(int n){
	int rev=0;
	while(n!=0){
		rev=rev*10+n%10;
		n=n/10;
	}
	return rev;
}


int main(){
	
	
	int t,m,n,add=0;
	cin>>t;
	while(t--){
	cin>>m;cin>>n;
    add=reverse(m)+reverse(n);
    cout<<reverse(add)<<endl;
    

}}
