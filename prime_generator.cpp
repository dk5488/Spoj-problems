#include <iostream>
using namespace std;

int main() {
	int t,n,m,flag;
	cin>>t;
	while(t--){
        cin>>n>>m;
		for(int i=n;i<=m;i++){
			flag=0;
			for(int j=1;j<=i/2;j++){
				if(i%j==0){
					flag++;
				}}
				if(flag==1){
					cout<<i<<endl;
				}
		}
	}
	return 0;
}