#ifndef __SEGMENT_TREEE
#define __SEGMENT_TREEE

#include <functional>
#include <iostream>
#include <vector>
using std::cout;

namespace ctci {

inline int left_child(const int node) { return 2 * node; }

inline int right_child(const int node) { return 2 * node + 1; }

inline int parent(const int node) { return node / 2; }
inline int midpoint(const int l, const int r) { return l + (r - l) / 2; }
template <class Collection>
class SegmentTree {
  using T = typename Collection::value_type;
  constexpr static int root_node = 1;

 public:
  template <class Fn>
  SegmentTree(Collection& c, Fn _op) : SegmentTree(c, 0, c.size() - 1, _op){};

  template <class Fn>
  SegmentTree(Collection& _c, const int start, const int end, Fn _op)
      : c(_c), operation(_op) {
    const int size =  2*(end - start + 1);
    int lg = (int)(log2(size)) ;
     if(1<<lg < size)
     	lg++;	
    tree.resize((1<<lg));
    build(start, end, root_node);
  };
  void update(const int pos, const T& val) {
    return update_helper(pos, val, 0, c.size() - 1, root_node);
  }

  T query(const int query_left, const int query_right) {
    return query_helper(query_left, query_right, 0, c.size() - 1, root_node);
  }

  T query_helper(const int query_left, const int query_right, const int start,
                 const int end, const int node) {
    if (query_left <= start && query_right >= end) return tree[node];

    if (start > end || query_right < start || query_left > end) return 0;

    const int mid = midpoint(start, end);
    const int left = left_child(node);
    const int right = right_child(node);

    return query_helper(query_left, query_right, start, mid, left) +
           query_helper(query_left, query_right, mid + 1, end, right);
  }

  // private:
  std::vector<T> tree;
  Collection& c;
  const std::function<T(const T& l, const T& r)> operation;

  void update_helper(const int pos, const T& val, const int start,
                     const int end, const int node) {
    if (start == end) {
      tree[node] = c[pos] = val;
      cout<<"updating "<<pos<<" "<<c[pos]<<std::endl;

      return;
    }
    const int mid = midpoint(start, end);
    const int left = left_child(node);
    const int right = right_child(node);
    if (pos <= mid)
      update_helper(pos, val, start, mid, left);
    else
      update_helper(pos, val, mid + 1, end, right);

    tree[node] = operation(tree[left], tree[right]);
  }

  void build(const int start, const int end, const int node) {

    
      cout << "build "<<start << " "<<end<<" "<<node<<std::endl;
    
    if (start == end) {
      tree[node] = c[start];
      return;
    }
    const int mid = midpoint(start, end);
    const int left = left_child(node);
    const int right = right_child(node);

    build(start, mid, left);

    build(mid + 1, end, right);

    tree[node] = operation(tree[left], tree[right]);
  }
};

}  // namespace ctci

#endif  //__SEGMENT_TREEE