#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


class Solution {
public:
    bool is_subfolder( string& f1,  string& f2)
    {
        if(f1.size() < f2.size())
        {
            auto it = begin(f2) + f1.size();
            if(std::equal(begin(f2), it, begin(f1), end(f1)) && *it=='/')
                return true;
        }
        return false;        
    }
    
    vector<string> removeSubfolders(vector<string>& folder)
    {
        vector<string> ans;
        sort(begin(folder), end(folder));
        
        auto it =  begin(folder);
        while(it != folder.end())
        {
            auto it2 = find_if(it+1, end(folder), [&]( auto f){return !is_subfolder(*it, f);});
            ans.push_back(*it);
            it = it2;
        }
        
        if(it==begin(folder))
            ans.push_back(*it);
        
        return ans;
        
    }
};

int main()
{
    vector<string> f = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    Solution s;
    auto ans = s.removeSubfolders(f);
    return 0;
}