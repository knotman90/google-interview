#ifndef _SEGMENT_TREE
#define _SEGMENT_TREE

inline int parent(const uint i) {
    return (i-1)/2;
}

inline int lchild(const uint i) {
    return 2*i+1;
}
inline int rchild(const uint i) {
    return 2*i+2;
}

template<class R,class T>
R treef(const T& x, const T& y) {
    return min(x,y);
}

int mid(const int s, const int e) {
    return s +((e-s)/2);
}

template<class R, class T>
void buildSegmentTree(const int l, const int r, const int pos, const vector<T>& input, vector<R>& output
{

    if(l==r) {
        output[pos] = input[l];
        return;
    }
    else{
        int m = mid(l,r);
        buildSegmentTree(l,m,lchild(pos),input,output);
        buildSegmentTree(m+1,r,rchild(pos),input,output);
    }
    output[pos] = treef<R,T>(output[lchild(pos)],output[rchild(pos)]);
}

template <class R>
inline R identity() {
    return INT_MAX;
}

template<class R, class T>
R query(const vector<T>& ST, const int pos, const int lt, const int rt,const int l, const int r) {
    if(l <= lt && r >= rt)
        return ST[pos];
    if((lt < l && rt < l) || (lt > r && rt > r))
        return identity<R>();

    int m = mid(lt,rt);
    int a = query<R,T>(ST,lchild(pos), lt, m,l,r);
    int b = query<R,T>(ST, rchild(pos), m+1 , rt,l,r);
    return treef<R,T>(a,b);
}

#endif // _SEGMENT_TREE
