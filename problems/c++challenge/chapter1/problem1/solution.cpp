#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;
using ull = unsigned long long;

void solve();
void run_all(const unsigned);

#define MEASURE_TIME(function)                                           \
  {                                                                      \
    cerr << #function << endl;                                           \
    high_resolution_clock::time_point t1 = high_resolution_clock::now(); \
    { function; }                                                        \
    high_resolution_clock::time_point t2 = high_resolution_clock::now(); \
    const auto duration = duration_cast<milliseconds>(t2 - t1).count();  \
    cout.flush();                                                        \
    cerr << "--------------" << endl;                                    \
    cerr << "Elapsed Time: " << duration << "ms" << endl;                \
    cerr << "--------------" << endl;                                    \
  }

int main() { solve(); }

void solve() {
  ull limit;
  cin >> limit;
  run_all(limit);
}

void benchmark(const unsigned limit) {
  ull res = 0;
  for (unsigned i = 3; i <= limit; i++)
    if (i % 3 == 0 || i % 5 == 0) res += i;
  cout << res << endl;
}

void multithread(const unsigned limit) {
  ull ans = 0;

  auto multiple3_and_5 = [&]() -> ull {
    ull res = 0;
    for (unsigned i = 3; i <= limit; i += 3) res += i;
    return res;
  };

  auto multiple5_not_3 = [&]() -> ull {
    ull res = 0;

    auto f = async([&]() {
      ull res = 0;
      for (unsigned i = 5; i <= limit; i += 15) res += i;
      return res;
    });
    for (unsigned i = 10; i <= limit; i += 15) res += i;

    return res + f.get();
  };

  auto f3 = async(multiple3_and_5);
  auto f5 = async(multiple5_not_3);
  ans = f3.get() + f5.get();

  cout << ans << endl;
}


void smarter(const unsigned limit) {
	auto sum_n = [](const ull n){
		return n*(n+1)/2;
	};
	const ull ans3or5  = sum_n(limit/3)*3;
	const ull ans3and5 = sum_n(limit/15)*15;
	const ull ans5or3  = sum_n(limit/5)*5;
	const ull ans = ans3or5 + ans5or3 - ans3and5;
	cout << ans << endl;

}

void run_all(const unsigned limit) {
  MEASURE_TIME(multithread(limit););
  MEASURE_TIME(benchmark(limit););
  MEASURE_TIME(smarter(limit););
}