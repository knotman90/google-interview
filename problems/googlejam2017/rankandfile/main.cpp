#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include <set>
#include <sys/resource.h>

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
#define fill(a, v) memset(a, v, sizeof a)
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
vector<vector<int>> L;
vector<vector<int>> ans;
vector<int> solution;
int N;
void print(auto LL) {
    cout << endl;
    loop0n(i, LL.size()) {
        loop0n(j, LL[i].size()) {
            cout << LL[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check() {
    loop0n(i, L.size()) {
        if (find(ALL(ans), L[i]) == ans.end())
            return false;
    }
    loop0n(i, L.size()) {
        auto f = find(ALL(ans), L[i]);
        if (f != ans.end())
            ans.erase(f);

    }
    solution = ans[0];
    return true;
}
bool solveSmall(int r, int start) {
    cout << r << " " << start << endl;
    if (r >= N)
        return check();
    loopse(i, start, L.size()) {
        loop0n(j, N) {
            ans[r][j] = L[i][j];
        }
        loop0n(col, N) {
            ans[N + col][r] = L[i][col];
        }
        if (solveSmall(r + 1, i + 1))
            return true;
    }
    return false;
}

void solveSmart() {

}


int main() {
    ios_base::sync_with_stdio(false);


    int T;
    read(T);
    while (T--) {

        read(N);
        unordered_map<int, int> c;
        solution.clear();
        loop0n(i, 2 * N - 1) {
            loop0n(j, N) {
                int m; read(m);
                c[m]++;
            }
        }
        for (auto const& el : c) {
            if (el.second & 1)
                solution.push_back(el.first);
        }
        sort(ALL(solution));

        cout << "Case #" << _case_counter++ << ": ";
        loop0n(i, solution.size()) {
            cout << solution[i] << " ";
        }
        cout << endl;
    }
}

int mainSmall() {
    ios_base::sync_with_stdio(false);


    int T;
    read(T);
    while (T--) {

        read(N);
        ans.clear();
        L.clear();
        ans.resize(2 * N);


        loop0n(i, ans.size()) {
            loop0n(j, N) {
                ans[i].push_back(-1);
            }
        }
        loop0n(i, 2 * N - 1) {
            vector<int> A{};
            loop0n(j, N) {
                int m; read(m);
                A.push_back(m);
            }

            L.push_back(A);
        }
        // print(ans);
        sort(ALL(L));
        bool res = false;
        res = solveSmall(0, 0);
        cout << "Case #" << _case_counter++ << ": ";
        loop0n(i, solution.size()) {
            cout << solution[i] << " ";
        }
        cout << endl;
        //print(ans);

    }
    return 0;
}


















