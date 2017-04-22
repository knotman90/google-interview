#include <bits/stdc++.h>
#include <functional>
#include <numeric>

// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i, a, b) for (int i = a; i < b; i++)
#define foreach(v, c) \
  for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define checkbit(n, b) ((n >> b) & 1)
#define DREP(a) \
  sort(all(a)); \
  a.erase(unique(all(a)), a.end())
#define INDEX(arr, ind) (lower_bound(all(arr), ind) - arr.begin())

// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)
#define GET_LOOP(_1, _2, _3, _4, NAME, ...) NAME
#define LOOPUP(...) \
  GET_LOOP(__VA_ARGS__, loopsei, loopse, loop0n) \
(__VA_ARGS__)
#define LOOPDWN(...) \
  GET_LOOP(__VA_ARGS__, dloopsei, dloopse, dloop0n) \
(__VA_ARGS__)


#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second
//char to int
inline constexpr int ctoi(const char c)
{ return c - '0'; }
//int to char
inline constexpr char itoc(const int n)
{ return n + '0'; }

template<typename T> inline T clamp(const T& n, const T& lo, const T& hi)
{ return std::max(lo, std::min(n, hi)); }

template<class T> inline void sort(T &a)
{ std::sort(ALL(a)); }

template<class T1, class T2> inline void sort(T1 &a, T2 comp)
{ sort(ALL(a), comp); }

template<class T> inline int read(T& n)
{ return std::cin >> n ? 1 : -1; }
//reads multiple arguments
template<typename T, typename... types> inline int read(T &n, types &...args)
{ return read(n) == -1 ? -1 : read(args...) + 1; }

template<class T> inline void write(const T& n)
{ std::cout << n; }
//reads multiple arguments
template<typename T, typename... types> inline void write(const char sep, T &n, types &...args)
{ write(n); write(sep); write(sep, args...); }



template<typename T> inline constexpr bool odd(const T a)
{ return bool(a & 1); }

template<typename T> inline constexpr bool even(const T a)
{ return !odd(a); }

template<class T>
inline unsigned int mod (const T m, const T n)
{ return m >= 0 ? m % n : ( n - abs( m % n ) ) % n; }

template<class T>
class reader {
public:
    void operator()(T& t) const {
        std::cin >> t;
    }
};

template<class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size, const READ_Fn& rfn = reader<typename CONTAINER::value_type>()) {
    loop0n(i, size) {
        rfn(v[i]);
    }
}

//TYPEDEFS
typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l, l> pll;
typedef std::pair<int, int> pii;
typedef std::pair<uint, uint> puu;

//sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2)
{
    return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
};

//integer power (base^exp)
template<class T>
T ipow(T base, T exp) {
    T result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

//case counter variable
static int _case_counter = 1;
template< typename T>
void printCase(const T& arg) {
    std::cout << "Case #" << _case_counter++ << ": ";
    write(arg);
    write('\n');

}

template< typename... types>
void printCase(const char sep = ' ', types &...args) {
    std::cout << "Case #" << _case_counter++ << ": ";
    write(sep, args...);
    write('\n');

}

//------ PROBLEM CODE ------------------------------------------------

using namespace std;
constexpr const uint MAXKEYS = 401;
constexpr const uint MAXNODES = 200;
int K, N;
vector<vector<int>> keyToNodes(MAXKEYS);
vector<vector<int>> nodeToKeys(MAXNODES);

vector<int> visited;

vector<int> availableKeys(MAXKEYS, 0);
int numAvailableKeys = 0;
int caseN = 1;
bool solve(bool& solved) {
    if (visited.size() == N) {
        cout << "Case #" << caseN++ << ": ";
        loop0n(i, visited.size()) {
            cout << visited[i] + 1 << " ";
        }
        cout << endl;
        solved = true;
        return true;
    }
    if (numAvailableKeys <= 0) {
        return false;
    }


    vector<pii> reachable;
    loop0n(i, availableKeys.size()) {
        if (availableKeys[i] > 0) {
            loop0n(j, keyToNodes[i].size()) {
                reachable.push_back(make_pair(keyToNodes[i][j], i));
            }
        }
    }

   // sort(ALL(reachable));
    auto it = std::unique(ALL(reachable));
    reachable.resize(std::distance(begin(reachable),it));

    loop0n(iii, reachable.size()) {
        int node = reachable[iii].first;
        int key = reachable[iii].second;
        numAvailableKeys--;
        availableKeys[key]--;

        int nodeToVisit =  node;
        if (find(ALL(visited), nodeToVisit ) == end(visited)) {
            visited.push_back(nodeToVisit);
            //add all keys we found in that node
            for (int l = 0; l < nodeToKeys[nodeToVisit].size() ; l++) {
                availableKeys[nodeToKeys[nodeToVisit][l]]++;
                numAvailableKeys++;
            }

            /*cout << "\t visito " << nodeToVisit + 1 << endl;
            loop0n(i, visited.size()) {
                cout << visited[i] + 1 << " ";
            }
            cout << endl;*/
            //call solve recursively
            if (solve(solved))
                return true;

           // cout << "\t non buono " << nodeToVisit + 1 << endl;
            //backtrack: restore status
            visited.pop_back();

            loop0n(l, nodeToKeys[nodeToVisit].size()) {
                availableKeys[nodeToKeys[nodeToVisit][l]]--;
                numAvailableKeys--;
            }

        }
        numAvailableKeys++;
        availableKeys[key]++;

    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(false);

    vector<int> chimidalachiave(MAXKEYS,0);

    int T; read(T);
    while (T--) {
        visited.clear();
        std::fill(ALL(availableKeys), 0);
        loop0n(i, keyToNodes.size()) {
            keyToNodes[i].clear();
        }
        numAvailableKeys = 0;
        loop0n(i, nodeToKeys.size()) {
            nodeToKeys[i].clear();

        }

        bool solved = false;
        read(K, N);
        cout<<K<<" "<<N<<endl;
        loop0n(i, K) {
            int k; read(k);
            availableKeys[k]++;
            chimidalachiave[k]++;
            numAvailableKeys++;
        }

        loop0n(i, N) {
            int key; read(key);
            keyToNodes[key].push_back(i);

            int found_keys; read(found_keys);
            loop0n(j, found_keys) {
                int fk; read(fk);
                nodeToKeys[i].push_back(fk);
                chimidalachiave[fk]++;

            }
        }

        bool ahhhh=false;
        loop0n(i,keyToNodes.size()){
            if(keyToNodes[i].size() > chimidalachiave[i]){
                solved=false;
                ahhhh=true;
            }
        }

        if(!ahhhh) solve(solved);
        if (!solved) {
            cout << "Case #" << caseN++ << ": ";
            cout << "IMPOSSIBLE" << endl;
        }
    }






}


















