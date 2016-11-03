#include <bits/stdc++.h>

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
inline int chrint(const char c) {
    return c - '0';
}

template<typename T>
inline T clamp(const T& n, const T& lo, const T& hi) {
    return std::max(lo,std::min(n,hi));
}

typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l,l> pll;
typedef std::pair<int,int> pii;
typedef std::pair<uint,uint> puu;

//sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2)
{
    return (p1.first < p2.first) || (p1.first==p2.first && p1.second < p2.second);
};


#include<list>


//------ PROBLEM CODE --------------
#define SIZE (200000)

using namespace std;

vector<int> C(SIZE);
vector<vector<int>> graph(SIZE);
vector<bool> V(SIZE,false);
unordered_map<int,long long> freq;
long long s,M;
void dfs(unsigned int i) {

    if(!V[i]) {
        V[i]=true;
        freq[C[i]]++;
        s++;
        M = max(M,freq[C[i]]);
        loop0n(j,graph[i].size()) {
            dfs(graph[i][j]);
        }
    }

}


int main() {
    int n,m,k;
    cin>>n>>m>>k;
    M=s=0;

    loop0n(i,n)
    {
        cin>>C[i];
    }
    loop0n(i,m)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    long long cost=0;
    loop0n(i,n) {
        if(graph[i].size() > 0 &&!V[i]) {
            dfs(i);
            //s is the num of nodes in the connected component
            //M is the number of nodes which all shares the 
            //color which appears the maxz number of times in the connected component.
            cost+= s-M;
            freq.clear();
            s=0; M=0;


        }
    }

    cout<<cost<<endl;
    return 0;
}


