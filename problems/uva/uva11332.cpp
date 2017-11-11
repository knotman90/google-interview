#include<iostream>


using namespace std;

int sumDigits(long int l){
int sum=0;
while(l > 0){
  sum+=l%10;
  l/=10;
}
return sum;
}

int sumDigitsR(long int l){
if(l <=0)
  return 0;

return (l%10 )+ sumDigitsR(l/10);

}
int main(){
  int n; cin>>n;
while(n){
  int sd = sumDigitsR(n);
  while(sd >=10)
     sd = sumDigitsR(sd);

cout<<sd<<endl;
cin>>n;

}

  return 0;
}
