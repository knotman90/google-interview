#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned clower, cupper, cnumber;
void add(string &s , string c){

	auto it = begin(s);

	if(clower > c.size())
		it = find_if(begin(s), end(s) , [](const char c1){return islower(c1);});
	else if(cupper > c.size())
		it = find_if(begin(s), end(s) , [](const char c1){return isupper(c1);});
	else
		it = find_if(begin(s), end(s) , [](const char c1){return isdigit(c1);});
	
	copy(begin(c), end(c), it);
}

string solve(const string s){
	string ans(s);
	clower = cupper = cnumber = 0;
	for(const char c : s)
	{
		if(islower(c))
			clower++;
		else if(isupper(c))
			cupper++;
		else
			cnumber++;
	}

	if(clower && cupper && cnumber)
		return ans;

	if(!clower && cupper && cnumber)
		add(ans, "a");
	else if(clower && !cupper && cnumber)
		add(ans, "A");
	else if(clower && cupper && !cnumber)
		add(ans, "1");
	else if(!clower && !cupper && cnumber)
		add(ans, "aA");
	else if(!clower && cupper && !cnumber)
		add(ans, "a1");
	else if(clower && !cupper && !cnumber)
		add(ans, "A1");
	return ans;

}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }

  return 0;
}