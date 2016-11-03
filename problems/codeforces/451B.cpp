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

using namespace std;

template<typename FN>
int skipSortedSeq(int* a, int s, FN cmp) {
    for(int i=s; i<s-1; i++) {
        if(cmp(a[i],  a[i+1]))
            return i;
    }
    return s;

}

#define MAX (100000)
int N[MAX];


void reverse(int *N, const int size, const int i, const int j) {
    int d = j-i+1;
    loop0n(k,d/2) {
        swap(N[i+k],N[j-k]);
    }
}

bool isordered(int *N, const int size) {
    loop0n(i,size-1) {
        if(N[i] > N[i+1])
            return false;
    }
    return true;
}
int main() {
        int n;
        cin>>n;
        loop0n(i,n) {
            cin>>N[i];
        }
        //fine the first decreasing segment
        int s=-1;
        int e=n-1;
        loop0n(i,n-1)
        {
            if(s==-1 && N[i] > N[i+1])
                s=i;
            if(s != -1 && N[i] < N[i+1]) {
                e=i;
                break;
            }
        }
        if(s==-1 || n==1)
            s=e=0;

        reverse(N,n,s,e);
        if(isordered(N,n)){
            cout<<"yes\n"<<s+1<<" "<<e+1<<endl;
        }
        else
            cout<<"no\n";
    return 0;
}

