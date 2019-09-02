//
// Created by fionaliu on 2019/9/2.
//

#ifndef SEGTREE_H
#define SEGTREE_H

#include <iostream>
#include <vector>
using namespace std;

#define maxn 100010
#define ll long long

template <class T>
struct Node
{
    int l, r;
    T max;
    T sum;
    T lazy;
};

template <class T>
class SegTree
{
public:
    SegTree(vector<T>& input);

    void build(int x, int y, int k);
    T query(int L, int R, int x, int y, int k);
    void update(int L, int R, int x, int y, int k, int delta);

    int getLen(){return N;}

private:
    void pushup(int k);
    void free(int l, int r, int k, ll delta);
    void pushdown(int l, int r, int k);
private:
    Node<T> tree[maxn<<2];
    T a[maxn];
    int N;
};

template <class T>
SegTree<T>::SegTree(vector<T>& input)
{
    int i = 1;
    for (auto it: input)
    {
        a[i++] = it;
    }
    N = i-1;
    build(1, N, 1);
}

template <class T>
void SegTree<T>::pushup(int k)
{
    //tree[k].max = max(tree[k<<1].max, tree[k<<1|1].max);
    tree[k].sum = tree[k<<1].sum + tree[k<<1|1].sum;
}

template <class T>
void SegTree<T>::build(int l, int r, int k)
{
    tree[k].l = l;
    tree[k].r = r;

    if (l == r)
    {
        tree[k].sum = a[l];
        return;
    }
    int m= (l+r)>>1;
    build(l, m, k<<1);
    build(m+1, r, k<<1|1);

    pushup(k);
}

template <class T>
void SegTree<T>::free(int l, int r, int k, ll delta)
{
    tree[k].lazy += delta;//更新懒标记数值
    tree[k].sum += delta*(r-l+1);//区间修改数值
}

//下传懒标记，需要用到k的子树
template <class T>
void SegTree<T>::pushdown(int l, int r, int k)
{
    int m = (l+r)>>1;
    free(l, m, k<<1, tree[k].lazy);
    free(m+1, r, k<<1|1, tree[k].lazy);

    tree[k].lazy = 0;
}
//区间修改，[x,y]->增加val
template <class T>
void SegTree<T>::update(int L, int R, int x, int y, int k, int val)
{
    //递归终止条件
    if (x >= L && y <= R) //如果待维护的区间[x,y]完全在查询区间[L,R]内
    {
        free(x, y, k, val); //修改该区间的lazy并更新相应数值
        return;
    }

    pushdown(x, y, k);
    //回溯之前一直向下传递，每个节点都可以更新到
    int m = (x+y) >> 1;
    //若左子区间[l,m]的一部分或者全部包含在查询区间[L,R]
    if (m >= L) //待维护区间的左子树有节点在查询区间
    {
        //往左子树调用
        update(L, R, x, m, k << 1, val);
    }
    if (m < R) //待维护区间的右子树有节点在查询区间
    {
        //往右子树调用
        update(L, R, m+1, y, k << 1|1, val);
    }

    //更新子节点信息后更新本节点
    pushup(k);
}

template <class T>
T SegTree<T>::query(int L, int R, int x, int y, int k)
{
    ll res = 0;
    //递归终止条件
    if (L <= x && y <= R) //被搜索区间[x,y]完全在查询区间[L,R]内
    {
        return tree[k].sum;
    }

    int m = (x+y) >> 1;
    //PushDown(x, y, k);//todo
    //查询区间[L,R]在被搜索区间[x,y]的左半子树
    if (m >= L)
    {
        //往左子树调用
        res += query(L, R, x, m, k << 1);
    }

    if(m < R) //查询区间[x,y]在当前区间[l,r]的右半子树
    {
        //往右子树调用
        res += query(L, R, m+1, y, k << 1|1);//向右节点更新答案
    }

    return res;
}

#endif //SEGTREE_H

