#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

template <class T>
class BestK {
 protected:
  unsigned k = 0;
  multiset<T> best;
  T sum_best = 0;
  multiset<T> others;
  T sum_others = 0;

 public:
  BestK(const unsigned _k) : k(_k), sum_best(0), sum_others(0) { this->k = _k; }

  T get_sum_k_best() { return sum_best; }
  T get_sum_others() { return sum_others; }

  bool erase_single(multiset<T>& my_multiset, const T value) {
    auto itr = my_multiset.find(value);
    if (itr != my_multiset.end()) {
      my_multiset.erase(itr);
      return true;
    }
    return false;
  }

  virtual void remove(const T n) {
    auto itr = others.find(n);
    if (itr != others.end()) {
      others.erase(itr);
      sum_others -= (n);
    } else {
      auto itr_best = best.find(n);
      best.erase(itr_best);
      sum_best -= (n);
    }
  }

  virtual void insert(const T n) = 0;
};

template <class T>
class BestPositiveK : public BestK<T> {
  using BestK<T>::others;
  using BestK<T>::best;
  using BestK<T>::k;
  using BestK<T>::sum_best;
  using BestK<T>::sum_others;
  using BestK<T>::erase_single;

 public:
  BestPositiveK(const long long k) : BestK<T>(k) {}

  void insert(const T n) override {
    others.insert(n);
    sum_others += (n);
    T last = *(--others.end());

    if (best.size() < k) {
      if (last >= 0) {
        erase_single(others, last);
        // others.erase(last);
        sum_others -= (last);

        best.insert(last);
        sum_best += (last);
      }
    } else  // best is full
    {
      if (best.size() > 0) {
        T first_best = *(best.begin());
        if (last > 0 && last > first_best) {
          // found a better element for best
          erase_single(best, first_best);
          // best.erase(first_best);
          sum_best -= (first_best);

          erase_single(others, last);
          //        others.erase(last);
          sum_others -= (last);

          best.insert(last);
          sum_best += (last);

          others.insert(first_best);
          sum_others += (first_best);
        }
      }
    }
  }
};

template <class T>
class BestNegativeK : public BestK<T> {
  using BestK<T>::others;
  using BestK<T>::best;
  using BestK<T>::k;
  using BestK<T>::sum_best;
  using BestK<T>::sum_others;
  using BestK<T>::erase_single;

 public:
  BestNegativeK(const long long k) : BestK<T>(k) {}

  void insert(const T n) override {
    others.insert(n);
    sum_others += (n);
    T last = *(others.begin());

    if (best.size() < k) {
      if (last < 0) {
        // others.erase(last);
        erase_single(others, last);
        sum_others -= (last);

        best.insert(last);
        sum_best += (last);
      }
    } else  // best is full
    {
      if (best.size() > 0) {
        T first_best = *(--best.end());
        if (last < 0 && last < first_best) {
          // found a better element for best
          // best.erase(first_best);
          erase_single(best, first_best);
          sum_best -= (first_best);

          erase_single(others, last);
          // others.erase(last);
          sum_others -= (last);

          best.insert(last);
          sum_best += (last);

          others.insert(first_best);
          sum_others += (first_best);
        }
      }
    }
  }
};

using namespace std;
vector<long long> N;
long long n, k, len;
int main() {
  cin >> n >> len;
  N.resize(n);
  for (long long i = 0; i < n; ++i) cin >> N[i];
  cin >> k;

  BestPositiveK<long long> best_positive(k);
  BestNegativeK<long long> best_negative(k);
  long long ans = numeric_limits<long long>::min();
  for (long long i = 0; i < n; ++i) {
    if (i >= len) {
      best_positive.remove(N[i - len]);
      best_negative.remove(N[i - len]);
    }
    best_positive.insert(N[i]);
    best_negative.insert(N[i]);
    if ((i + 1) >= len) {
      ans = max(ans, abs(best_positive.get_sum_others() -
                         best_positive.get_sum_k_best()));
      ans = max(ans, abs(best_positive.get_sum_others() +
                         best_positive.get_sum_k_best()));

      ans = max(ans, abs(best_negative.get_sum_others() -
                         best_negative.get_sum_k_best()));
      ans = max(ans, abs(best_negative.get_sum_others() +
                         best_negative.get_sum_k_best()));
    }
  }

  cout << ans << endl;

  return 0;
}