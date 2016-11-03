#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

int lenNext(string& s, int& i){
    int l=0;
    while(i< s.size() && s[i] != '_' && s[i] !=')' && s[i]!='('){
        i++;
        l++;
    }
return l;
}

void skip(string &s, int& i){
    while(i<s.size() && s[i]=='_')
        i++;
}

int main(){
    int n; cin>>n;
string s; cin>>s;
std::transform(s.begin(),s.end(),s.begin(),::tolower);
int longest= 0;
int np=0;
bool par=false;


for(int i=0;i<s.size();){
    skip(s,i);
    if(s[i]==')'){
        par=false;
        i++;
    }
    skip(s,i);

    if(par || s[i]=='('){
        if(!par) i++;
        par=true;
        skip(s,i);
        if(lenNext(s,i)>0)
            np++;

        
        }else{
           par=false;
        int li = lenNext(s,i);
        longest=max(longest,li);
           
    }
        
}

cout<<longest<<" "<<np<<endl;

    return 0;
}
