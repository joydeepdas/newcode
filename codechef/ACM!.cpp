#include<iostream>
#include<algorithm>
using namespace std;
int  main(){
	int t;
	cin>>t;
	while(t--){
		int n,c=0;
		cin>>n;
		int a[n+5];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n-1;i++){
			if(a[i]<a[i+1]){
				c++;
				continue;
			}
			else{
			
				cout<<"NO"<<endl;
					break;
			}
		}
			if(c==n-1){
				cout<<"YES"<<endl;
			}
			
			
		}
	}

