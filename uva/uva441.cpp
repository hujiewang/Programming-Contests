#include <iostream>

using namespace std;

int k,t;
int v[13];
int main(){
	int counter=0;
	while(cin>>k){
		if(!k)
			break;
		counter++;
		if(counter>1)
			cout<<endl;
		for(int i=0;i<k;i++){
			cin>>v[i];
		}
		for(int a=0;a<k-5;a++)
			for(int b=a+1;b<k-4;b++)
				for(int c=b+1;c<k-3;c++)
					for(int d=c+1;d<k-2;d++)
						for(int e=d+1;e<k-1;e++)
							for(int f=e+1;f<k;f++)
								cout<<v[a]<<" "<<v[b]<<" "<<v[c]<<" "<<v[d]<<" "<<v[e]<<" "<<v[f]<<endl;
	}
	return 0;
}