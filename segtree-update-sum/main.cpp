#include <iostream>
using namespace std;
#define maxn 100010
#define ll long long
struct Node
{
    int l, r, max;
    ll sum;
    ll lazy;
}tree[maxn<<2];

int a[maxn];

void PushUp(int k)
{
    //tree[k].max = max(tree[k<<1].max, tree[k<<1|1].max);
    tree[k].sum = max(tree[k<<1].sum, tree[k<<1|1].sum);
}
void Build(int l, int r, int k)
{
    tree[k].l = l;
    tree[k].r = r;

    if (l == r)
    {
        tree[k].sum = a[l];
        return;
    }
    int m= (l+r)>>1;
    Build(l, m, k<<1);
    Build(m+1, r, k<<1|1);

    PushUp(k);
}

void free(int l, int r, int k, ll lazy)
{
    tree[k].lazy += lazy;//更新懒标记数值
    tree[k].sum += k*(r-l+1);//区间修改数值
}

//下传懒标记，需要用到k的子树
void PushDown(int l, int r, int k)
{
    int m = (l+r)>>1;
    free(l, m, k<<1, tree[k].lazy);
    free(m+1, r, k<<1|1, tree[k].lazy);

    tree[k].lazy = 0;
}

void Update(int L, int R, int x, int y, int k)
{
    //递归终止条件
    if (x >= L && y <= R) //如果待维护的区间[x,y]完全在查询区间[L,R]内
    {
        free(x, y, k); //修改该区间的lazy并更新相应数值
        return;
    }

    PushDown(x, y, k);

    int m = (x+y) >> 1;
    //若左子区间[l,m]的一部分或者全部包含在查询区间[L,R]
    if (m >= L) //待维护区间的左子树有节点在查询区间
    {
        //往左子树调用
        Update(L, R, x, m, k << 1);
    }
    if (m < R) //待维护区间的右子树有节点在查询区间
    {
        //往右子树调用
        Update(L, R, m+1, y, k << 1|1);
    }

    //更新子节点信息后更新本节点
    PushUp(k);
}

int Query(int L, int R, int x, int y, int k)
{
    ll res = 0;
    //递归终止条件
    if (L <<= x && y <= R) //待维护区间完全在查询区间内
    {
        return tree[k].sum;
    }

    int m = (x+y) >> 1;
    PushDown(x, y, k);
    //查询区间[x,y]在当前区间[L,R]的左半子树
    if (m >= L)
    {
        //往左子树调用
        res += Query(L, R, x, m, k << 1);
    }

    if(m < R) //查询区间[x,y]在当前区间[l,r]的右半子树
    {
        //往右子树调用
        res += Query(L, R, m+1, y, k << 1|1);//向右节点更新答案
    }

    return res;
}
int main() {

    int N, M;
    int X, Y;

    cin >> N >> M;
    cout << "input is " << N << "," << M << endl;
    for (int i=1;i<=N;i++)
    {
        cin >> a[i];
    }
    Build(1, N, 1);
    for (int i=0;i<M;i++)
    {
        cin >> X >> Y;
        cout << Query(X, Y, 1) << endl;
    }
    return 0;
}