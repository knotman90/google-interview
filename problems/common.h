/*
 Author: Davide Spataro
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
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

// Input macros
#define s(n) scanf("%d", &n)
#define sc(n) scanf("%c", &n)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)

#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second

namespace DS {
template <typename Iterator, typename Lambda>

void for_each(Iterator s, Iterator e, Lambda l) {
  while (s != e) {
    l(*s);
    s++;
  }
}



template <typename Iterator>
void print(Iterator s, Iterator e) {
  auto l = [=](auto& t) { std::cout << t << " "; };
  DS::for_each(s, e, l);
  std::cout << "\n";
}

// this has to be specialized for each class that is SWAPPABLE
template <class T>
inline void swap(T& a, T& b) {
 const  T a_copy = a;
  a = b;
  b = a_copy;
}

template <class T2, size_t N>
void swap(T2(&a)[N], T2(&b)[N]);
// swap ranges

// -- Non-modifying sequence operations --

template <typename T, typename Iterator>
bool contains(const Iterator s, const Iterator e, const T& value) {
  auto predicate_equal = [&](T curr) { return value == curr; };
  bool ret = e == find_if(s, e, predicate_equal);
  return !ret;
}

// Return value
// Iterator to the first element satisfying the condition or last if no such
// element is found.
template <typename Iterator, typename Lambda>
inline Iterator find_if_not(Iterator s, Iterator e, Lambda predicate) {
  auto not_predicate = [&](auto v) { return !predicate(v); };
  return find_if(s, e, not_predicate);
}

// Return value
// Iterator to the first element satisfying the condition or last if no such
// element is found.
template <typename Iterator, typename Lambda>
Iterator find_if(Iterator s, Iterator e, Lambda predicate) {
  while (s != e) {
    if (predicate(*s))
      return s;

    s++;
  }
  return e;
}

template <typename Iterator, typename Lambda>
bool all_of(Iterator s, Iterator e, Lambda predicate) {
  while (s != e) {
    if (!predicate(*s))
      return false;
    s++;
  }
  return true;
}

template <typename Iterator, typename Lambda>
bool any_of(Iterator s, Iterator e, Lambda predicate) {
  while (s != e) {
    if (predicate(*s))
      return true;
    s++;
  }

  return false;
}

template <typename Iterator, typename Lambda>
bool none_of(Iterator s, Iterator e, Lambda predicate) {
  return !any_of(s, e, predicate);
}

// D can't be deduced
template <typename D = int, typename Iterator, typename Lambda>
D count_if(Iterator s, Iterator e, Lambda unary_predicate) {
  auto f = [&](D& acc, auto& val) {
    unary_predicate(val) ? acc++ : acc;
    return acc;
  };
  D count = fold(s, e, 0, f);
  return count;
}

template <typename D = int, typename Iterator, typename T>
D count(Iterator s, Iterator e, const T& t) {
  auto count_equal = [&](const D& acc, const T& val) {
    if (val == t)
      return acc + 1;
    return acc;
  };
  return count_if(s, e, count_equal);
}

// Lambda has type: D -> T -> D
template <typename D, typename Iterator, typename Lambda>
D fold(Iterator s, Iterator e, const D& a, Lambda l) {
  D acc = a;
  while (s != e) {
    acc = l(acc, *s);
    s++;
  }
  return acc;
}

// Lambda has type: D -> T -> D
template <typename D, typename Iterator, typename Lambda>
D fold_idx(Iterator s, Iterator e, const D& a, Lambda l) {
  D acc = a;
  int idx=0;
  while (s != e) {
    acc = l(acc, *s,idx);
    s++;
    idx++;
  }
  return acc;
}


template <class T>
inline T& min(T& op1, T& op2) {
  if (op1 < op2)
    return op1;
  return op2;
}

template <class T>
inline T& max(T& op1, T& op2) {
  if (op1 > op2)
    return op1;
  return op2;
}

template <typename T>
void readVector(std::vector<T>& v, const int size, std::istream& is=std::cin) {
  LOOPUP(i, size) {
    T a;
    is >> a;
    v.push_back(a);
  }
}

template <typename T, unsigned int D>
void readArray(std::array<T, D>& v, std::istream& is=std::cin) {
  LOOPUP(i, D) {
    T a;
    is>> a;
    v[i] = a;
  }
}


void read(auto& v, const unsigned int size, std::istream& is=std::cin) {
    using T=typename std::remove_reference<decltype(v[0])>::type;
  LOOPUP(i, size) {
    T a;
    is>> a;
    v[i] = a;
  }
}

void reverse(auto& v, const unsigned int size) {
using T=typename std::remove_reference<decltype(v[0])>::type;
 LOOPUP(i, size/2) {
    T a = v[i];
    v[i]=v[size-1-i];
    v[size-1-i] = a;
  }

}

template<typename T>
inline T safe_midpoint(const T lo, const T hi){
    return lo+(hi-lo)/2;
}


template<typename T>
inline T unsafe_midpoint(const T lo, const T hi){
    return (hi+lo)/2;
}


template<typename T>
inline bool gte(const T& v1,const T& v2){
    return gt(v1,v2) || eq (v1,v2);
}
template<typename T>
inline bool lte(const T& v1,const T& v2){
    return lt(v1,v2) || eq(v1,v2);
}

template<typename T>
inline bool gt(const T& v1,const T& v2){
    return v1 > v2;
}


template<typename T>
inline bool lt(const T& v1,const T& v2){
    return v1 < v2;
}

template<typename T>
inline bool eq(const T& v1,const T& v2){
    return v1 == v2;
}


// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void bubblesort(Iterator s, Iterator e, CMP_FN cmp) {
  auto it1=s;
  for(; it1 !=e; it1++){
    auto it2 = s;
    for(; it2 != it1; it2++)
        if(cmp(*it1,*it2))
            std::swap(*it1,*it2);
  }
}

// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void insertionsort(Container& v, const int s,const int e, CMP_FN cmp) {
    for(int i=s+1 ; i<e; i++){
        int el = v[i];
        int j = i-1;
        while(cmp(el,v[j]) && j>=s){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]=el;
    }
}

// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void selectionsort(Container& v, const int s,const int e, CMP_FN cmp) {
    for(int i=s ; i<=e ;i++){
            int min = v[i];
            int idxmin = i;
            for(int j=i+1 ; j<=e ;j++)
                if(v[j] < min){
                    min = v[j];
                    idxmin = j;
                }
            swap(v[i],v[idxmin]);
    }
}

//Efficient sorting algorithms

// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void heapsort(Container& v, const int s,const int e, CMP_FN cmp) {

}

//----------------------------
template<class Container, typename CMP_FN>
inline int selectpivotidx(Container& v, const int s, const int e,CMP_FN cmp){
    return e-1;
}

template<class Container, typename CMP_FN>
 int partition(Container& v, const int s, const int e,CMP_FN cmp){
//Lomuto partition scheme
    int pivotidx = selectpivotidx(v,s,e,cmp);
    swap(v[pivotidx],v[e-1]);//put pivot in the last position
    pivotidx = e-1;
    const auto pivot = v[pivotidx];//last element
    int i = s;
    for(int j=s ; j<e ;j++)
        if(cmp(v[j],pivot) ){
            swap(v[i++],v[j]);

        }
    swap(v[i],v[pivotidx]);
    return i;
}

#define TRIGGER_INSERTION (7)
// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
inline void quicksort(Container& v, const int s,const int e, CMP_FN cmp) {

    if(e - s <= TRIGGER_INSERTION)
        DS::insertionsort(v,s,e,cmp);
    else{
        const int p = partition(v,s,e,cmp);
        quicksort(v,s,p,cmp);
        quicksort(v,p+1,e,cmp);
    }
}

//tail recursive version
// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
inline void quicksort_tr(Container& v,  int s,const int e, CMP_FN cmp) {
    if(e - s <= TRIGGER_INSERTION)
        DS::insertionsort(v,s,e,cmp);
    else{
        while(s < e){
        const int p = partition(v,s,e,cmp);
        quicksort(v,s,p,cmp);
        s = p+1;
        }
    }
}


//-------QUICKSORT---------------------

//-------MERGSORT---------------------

// CMP_FN has type: D -> D -> bool
//[s1,e1] and [e1+1,e2] are two ordered sequences. This methods reaggarne the whole
// interval [s1,e2] in a sorted sequence
template < typename Container, typename CMP_FN>
void merge(Container& v, Container& scratch,  int s1,  int e1,  int e2,CMP_FN cmp){
    int s2 = e1+1;
    int ins =0;
    int b = s1;
    while(s1 <= e1 && s2<=e2){
        if(cmp(v[s1],v[s2])){
            scratch[b+ins++] = v[s1++];
        }else{
            scratch[b+ins++] = v[s2++];
        }
    }

    while(s1 <= e1)
        scratch[b+ins++] = v[s1++];
    while(s2 <= e2)
        scratch[b+ins++] = v[s2++];

    for(int i=0 ; i < ins ; i++)
        v[b+i] = scratch[b+i];

//print(ALL(scratch));
}

#define TRIGGER_INSERTIONSORT (4)
// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void mergesort_helper(Container& v,Container& scratch, const int s,const int e, CMP_FN cmp) {
    if(e -s <= TRIGGER_INSERTIONSORT)
        DS::insertionsort(v,s,e,cmp);
    if(s < e){
        int midpoint = safe_midpoint(s,e);
        mergesort_helper(v,scratch,s,midpoint,cmp);
        mergesort_helper(v,scratch,midpoint+1,e,cmp);
        merge(v,scratch,s,midpoint,e,cmp);
    }
}

// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void mergesort(Container& v, const int s,const int e, CMP_FN cmp) {
    Container scratch(v.size());
    mergesort_helper(v,scratch,s,e,cmp);

}


//-------MERGSORT---------------------




//Counting sort works only when you know in advance the range of the elements
//It has LINEAR COMPLEXITY!
// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
void countsort(Container& v, const int s,const int e, CMP_FN cmp) {

}

template < typename Container, typename CMP_FN>
void bucketsort(Container& v, const int s,const int e, CMP_FN cmp) {

}








template<class Iterator, class T, typename CMP_FN>
Iterator binary_search(Iterator begin, Iterator end, T val,CMP_FN cmp=DS::lt)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iterator i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}

template<class Iterator, class T,typename CMP_FN>
inline bool binary_search(Iterator begin, Iterator end, T val,CMP_FN cmp=DS::lt){
    return !binary_search(begin,end,val)==end;
}

inline bool inrange(const int l, const int r, const int idx){
    return idx>=l && idx<=r;
}

template<typename D,class Iterator>
inline D sum(Iterator begin, Iterator end){
    using T=typename std::remove_reference<decltype(*begin)>::type;
    D s = 0.0;
    auto sum_fn = [&](D acc,const T e){
        return acc+e;
    };
    return DS::fold<D>(begin,end,s,sum_fn);
}

template<class Iterator>
inline auto multiply(Iterator begin, Iterator end){
    using T=typename std::remove_reference<decltype(*begin)>::type;
    auto mult_fn = [&](double acc,const auto e){
        return acc*e;
    };
    return DS::fold(begin,end,1,mult_fn);
}

// check those-----------

template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first)
      os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::set<T>& v) {
  bool first = true;
  os << "[";
  for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first)
      os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first)
      os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}

}  // nameapace DS

#endif /* ALGORITHM_H_ */
