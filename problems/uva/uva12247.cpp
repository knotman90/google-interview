#include<iostream>
#include<memory>
#include<cstdlib>
#include<cstring>

using namespace std;
int min(const int a, const int b){
	if(a < b)
		return a;
	return b;
}
void rotate(int*A, const int s){
int p = A[0];
     for(int i=1;i<s;i++){
	int p1 = A[i];
	A[i] = p;
	p=p1;	
	}
A[0] = p;
}

int main(){


int A[3]={-1,-1,-1};
int B[3]={-1,-1,-1};

cin>>A[0]>>A[1]>>A[2];
cin>>B[0]>>B[1];
while(A[0]!=0){
	bool used[52];
	memset(used, false,52);
	for(int i=0;i<3;i++)
	   used[A[i]-1] = true;
	   used[B[0]-1] =  used[B[1]-1]=true;

	int minimum=0;
	bool go = true;
	for(int i=0;i<3 && go;i++){
		int c=0;
		
		rotate(A,3);
		if(A[0] > B[0])
			c++;
		if(A[1] > B[1])
		        c++;
		if(c == 1)
			minimum = max(minimum,A[2]+1);
		if(c == 2 )
			go = false;
		
		c=0;
		if(A[1] > B[0])
			c++;
		if(A[0] > B[1])
		        c++;
		if(c == 1)
			minimum = max(minimum,A[2]+1);
		if(c == 2 )
			go = false;
		
		
	
	}
	if(!go)
		cout<<"-1"<<endl;
	
	else if(minimum == 0){
		int minimum = min(min(A[0],A[1]),A[2])+1;
		bool found=false;
		for(int i=minimum;i<=52 && !found ;i++){
			if(!used[i-1]){
				minimum=i;
				found=true;
				}
		}
	if(!found) cout<<"-1"<<endl;
	else cout<<minimum<<endl;

	}
	else{
		bool found=false;
		for(int i=minimum;i<=52 && !found ;i++){
			if(!used[i-1]){
				minimum=i;
				found=true;
				}
		}
	if(!found) cout<<"-1"<<endl;
	else cout<<minimum<<endl;
	}

	

	cin>>A[0]>>A[1]>>A[2];
	cin>>B[0]>>B[1];
}

return 0;

}
