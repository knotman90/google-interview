#include <iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include "../cp.h"

using namespace std;


int main(){
    string s; cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    stringstream ss;
    loop0n(i,s.size())
    {
        if(!(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='e'|| s[i] =='u'))
            ss<<'.'<<s[i];
    }
    cout<<ss.str()<<endl;

    return 0;
}
