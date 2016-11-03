#include <iostream>
#include <string>
#include <string.h>
 
using namespace std;
string s;
int cnt[30];
int main()
{
   
        cin>>s;
        for (int i=0; i<s.size(); ++i)
                cnt[s[i]-'a']++;
        int odd=0;
        for (int i=0; i<26; ++i)
                if (cnt[i]&1)
                        odd++;
        if ((odd==0) || (odd&1))
                cout<<"First"<<endl;
        else
                cout<<"Second"<<endl;
    return 0;
}
