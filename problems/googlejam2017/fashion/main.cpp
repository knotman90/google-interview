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
int N, M;
constexpr const int SIZE = 100;
enum  TYPE {POINT = 0, ADD, MULT, O};
int MAP[SIZE][SIZE];
int MAPMAX[SIZE][SIZE];
long valMax = LONG_MIN;

void printMatrix(auto MM) {
    cout << endl;
    loop0n(i, N) {
        loop0n(j, N) {
            cout << MM[i][j] << " ";
        }
        cout << endl;
    }
}

void copyMatrix() {
    loop0n(i, N) {
        loop0n(j, N) {
            MAPMAX[i][j] = MAP[i][j];
        }

    }
}

long checkVal() {
    long ans = 0;
    loop0n(i, N) {
        loop0n(j, N) {
            int p = 0;
            if (p != TYPE::POINT )
                p++;
            if (p == TYPE::O )
                p++;
            ans += p;
        }
    }
    return ans;
}


bool checkRows() {

    loop0n(i, N) {
        int sum = 0;
        loop0n(j, N) {
            if (MAP[i][j] != TYPE::POINT && MAP[i][j] != TYPE::ADD)
                sum++;
            if (sum > 1)
                return false;
        }
    }
    return true;
}
bool checkCols() {
    loop0n(i, N) {
        int sum = 0;
        loop0n(j, N) {
            if (MAP[j][i] != TYPE::POINT && MAP[j][i] != TYPE::ADD)
                sum++;
            if (sum > 1)
                return false;
        }
    }
    return true;

}

unordered_map<int, int> MM;
bool checkDiags() {
    MM.clear();
    loop0n(i, N) {
        loop0n(j, N) {
            int val = i + j;
            int val2 = i - j;
            if (MAP[i][j] != TYPE::POINT && MAP[i][j] != TYPE::MULT) {

                MM[val]++;
                if (val != val2)
                    MM[val2]++;
                if (MM[val] > 1 || MM[val2] > 1)
                    return false;
            }
        }
    }
    return true;
}


bool legal() {
    return checkRows() &&
           checkCols() &&
           checkDiags() ;
}


void solve(int x, int y) {
    if ( y >= N)
    {
        long ansval = checkVal();
        if (ansval > valMax) {
            valMax = ansval;
            copyMatrix();
        }
        return;

    }

    bool present = MAP[x][y] != TYPE::POINT;
    int start = MAP[x][y];
    int inc = 1;
    if (present && start == TYPE::ADD)
        inc += 2;
    for (int i = start ; i <= TYPE::O ; i += inc) {
        int oldval = MAP[x][y];
        MAP[x][y] = i;
        if (legal()) {
            int nx = x < (N - 1) ? x + 1 : 0;
            int ny = y;
            if (nx == 0)
                ny++;

            solve(nx, ny);

        }
        MAP[x][y] = oldval;
    }
    //return false;

}



int main() {
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--) {
        read(N, M);
        loop0n(i, N) {
            loop0n(j, N) {
                MAPMAX[i][j]=MAP[i][j] = TYPE::POINT;

            }
        }

        loop0n(i, M) {
            char c; read(c);
            int x, y; read(x, y);
            x--;
            y--;
            TYPE val = TYPE::ADD;
            if (c == 'x')
                val = TYPE::MULT;
            else if (c == 'o')
                val = TYPE::O;

            MAP[x][y] = val;
        }
        printMatrix(MAP);
        solve(0, 0);
        printMatrix(MAPMAX);

    }
    return 0;
}


















