#include <bits/stdc++.h>
#include <random>
#include <cctype>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
using l = long;
using ll = long long;
using ull = unsigned long long;

void solve();

#define MEASURE_TIME(function)                                         \
  high_resolution_clock::time_point t1 = high_resolution_clock::now(); \
  { function; }                                                        \
  high_resolution_clock::time_point t2 = high_resolution_clock::now(); \
  const auto duration = duration_cast<milliseconds>(t2 - t1).count();  \
  cout.flush();                                                        \
  cerr << "--------------" << endl;                                    \
  cerr << "Elapsed Time: " << duration << "ms" << endl;                \
  cerr << "--------------" << endl;

int main() {
  MEASURE_TIME({ solve(); })
  return 0;
}

//------------PROBLEM CODE-------------

bool is_vowel(const char c){
  static const char v[] = "aeiouy";
  return find(begin(v), end(v), tolower(c)) != end(v);
}

char last_alpha(const string& s){
  return *find_if(rbegin(s), rend(s), [](char c) { return std::isalpha(c, std::locale()); });
}

void solve() {
  string s; 
  getline(std::cin, s, '?');
  
  if(const char lst = last_alpha(s); is_vowel(lst)  )
    cout<<"YES";
  else
    cout<<"NO";
  cout<<endl;
}



