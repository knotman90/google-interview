#ifndef __BIT_MANIPULATION
#define __BIT_MANIPULATION

#include <limits>
#include <vector>
namespace ctci {

/***************************************************************************
Sum of bit differences among all pairs

Given an integer array of n integers, find sum of bit differences in all pairs
that can be formed from array elements. Bit difference of a pair (x, y) is count
of different bits at same positions in binary representations of x and y. For
example, bit difference for 2 and 7 is 2. The Binary representation of 2 is 010
and 7 is 111 ( first and last bits differ in two numbers).

Examples :

Input: arr[] = {1, 2}
Output: 4
All pairs in array are (1, 1), (1, 2)
                       (2, 1), (2, 2)
Sum of bit differences = 0 + 2 +
                         2 + 0
                      = 4

Input:  arr[] = {1, 3, 5}
Output: 8
All pairs in array are (1, 1), (1, 3), (1, 5)
                       (3, 1), (3, 3) (3, 5),
                       (5, 1), (5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0
                       = 8
**************************************************************************/
template <class T>
unsigned bit_difference(T p, T q) {
  unsigned ans = 0;
  unsigned n = 0;
  while (p > 0 || q > 0) {
    ans += (p & 1) != (q & 1);
    p = p >> 1;
    q = q >> 1;
  }
  return ans;
}

template <class T>
long sum_bit_difference_all_pairs_brute_force(const std::vector<T>& V) {
  const auto size = V.size();
  long ans = 0;
  for (unsigned i = 0; i < size; ++i) {
    for (unsigned j = i + 1; j < size; ++j) {
      ans += bit_difference(V[i], V[j]) * 2;
    }
  }
  return ans;
}

template <class T>
long sum_bit_difference_all_pairs_(const std::vector<T>& V) {
  constexpr auto SIZE = std::numeric_limits<T>::digits;
  std::array<unsigned, SIZE> C;
  std::fill(std::begin(C), std::end(C), 0);

  for (int i = 0; i < V.size(); ++i) {
    int n = 0;
    int p = V[i];
    while (n < SIZE && p > 0) {
    }
  }
}

}  // namespace ctci
#endif  //__BIT_MANIPULATION