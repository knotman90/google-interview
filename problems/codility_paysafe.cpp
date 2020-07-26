#include <chrono>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void read_vector(vector<int>& V, const int n) {
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    V.push_back(a);
  }
}

template <typename Map>
typename Map::iterator greatest_less(Map& m, typename Map::key_type const& k) {
  typename Map::iterator it = m.lower_bound(k);
  if (it != m.begin()) {
    return --it;
  }
  return m.end();
}
using Roads = map<int, int>;

int value(const int l, const int r) { return r - l - 1; }
void delete_roads(Roads& roads, Roads::iterator it, int bound,
                  int& roads_value) {
  while (it != roads.end() && it->second <= bound) {
    roads_value -= it->second - it->first - 1;
    roads.erase(it++);
  }
}

vector<int> solve(const vector<int>& A, const vector<int>& B, int n) {
  Roads roads;
  const int nroads = A.size();
  vector<int> ans;
  int roads_value = 0;
  roads[A[0]] = B[0];
  roads_value = B[0] - A[0]-1;
   ans.push_back(n - roads_value);
  for (int i = 1; i < nroads; i++) {
    auto it = roads.lower_bound(A[i]);
    /*if (it == roads.end()) {
      roads[A[i]] = B[i];
      roads_value += B[i]-A[i]-1;
      continue;
    }*/
    // new interval contained in old one
    if (it != roads.end() && it->first == A[i] && it->second >= B[i]) continue;
    // new interval contains old one
    else if (it != roads.end() && it->first == A[i] && it->second <= B[i]) {
      delete_roads(roads, it, B[i], roads_value);
      roads[A[i]] = B[i];
      roads_value += B[i] - A[i] - 1;
       ans.push_back(n - roads_value);
      continue;
    }

    // new interval come strictly before the old one
    if (it != roads.end() && it->first > A[i]) {
      if (B[i] <= it->first) {
        roads[A[i]] = B[i];
        roads_value += B[i] - A[i] - 1;
         ans.push_back(n - roads_value);
        continue;
      } else {
        // new interval contains the old one
        delete_roads(roads, it, B[i], roads_value);
        roads[A[i]] = B[i];
        roads_value += B[i] - A[i] - 1;
         ans.push_back(n - roads_value);
        continue;
      }
    }
    // there is not starting point less than A[i]
    it = greatest_less(roads, A[i]);
    if (it != roads.end()) {
      if (A[i] >= it->second) {  // new interval come strictly after old one
        roads[A[i]] = B[i];
        roads_value += B[i] - A[i] - 1;
         ans.push_back(n - roads_value);
      }
      else if (B[i] <= it->first) {
        roads[A[i]] = B[i];  // new interval come strictly before old one
        roads_value += B[i] - A[i] - 1;
         ans.push_back(n - roads_value);
      } else {
        delete_roads(roads, it, B[i], roads_value);
        roads[A[i]] = B[i];
        roads_value += B[i] - A[i] - 1;
         ans.push_back(n - roads_value);
      }
    }
   
  }
  return ans;
}

int main() {
  int L;
  cin >> L;
  int n;
  cin >> n;
  vector<int> A, B;
  A.reserve(n);
  B.reserve(n);
  read_vector(A, n);
  read_vector(B, n);

  auto ans = solve(A, B, L-1);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " " ;
  }
  cout<<endl;

  return 0;
}
