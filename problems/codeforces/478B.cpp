#include <bits/stdc++.h>
#include<stdint.h>
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

typedef signed long long int ill;
typedef unsigned long long  ull;


using namespace std;

ull sumConsecutivei(const ull l) {
    return (l*(l+1)/2);
}

ull sumConsecutive(const ull l) {
    return ((1.0+l)/2)*l;
}
int main() {
  //  int T;
   // cin>>T;
   // while(T--)
    //{
        double n,m;
        ull n1,m1;
        cin>>n>>m;
        n1=n;
        m1=m;
        ull p = n1%m1;
        ull max, min;

        max=sumConsecutive(n-m);
        if(p == 0)
            min=sumConsecutive(ceil(n/m)-1)*m;
        else
        min = sumConsecutive(ceil(n/m)-1)*p + sumConsecutive(ceil(n/m)-2)*(m-p);
        if(m==1)
            min=sumConsecutive(n-1);
        cout<<min<<" "<<max<<endl;
//    }
    return 0;
}



