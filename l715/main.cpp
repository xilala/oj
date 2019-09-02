/*
有一根棍，现在要给他表面镀上一层金属，（本身这根棍是铜的）
铜的价值是1
银得价值是2
金的价值是3
求最后的价值是多少。

分析：
用一个变量e表示这一段节点价值
如果这一段节点有两种金属就让e=-1;
 */
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
    tree[k].sum = tree[k<<1].sum + tree[k<<1|1].sum;
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

void free(int l, int r, int k, ll val)
{
    tree[k].lazy += val;//更新懒标记数值
    tree[k].sum += val*(r-l+1);//区间修改数值
}

//下传懒标记，需要用到k的子树
void PushDown(int l, int r, int k)
{
    int m = (l+r)>>1;
    free(l, m, k<<1, tree[k].lazy);
    free(m+1, r, k<<1|1, tree[k].lazy);

    tree[k].lazy = 0;
}
//区间修改，[x,y]->增加val
void Update(int L, int R, int x, int y, int k, int val)
{
    //递归终止条件
    if (x >= L && y <= R) //如果待维护的区间[x,y]完全在查询区间[L,R]内
    {
        free(x, y, k, val); //修改该区间的lazy并更新相应数值
        return;
    }

    PushDown(x, y, k);
    //回溯之前一直向下传递，每个节点都可以更新到
    int m = (x+y) >> 1;
    //若左子区间[l,m]的一部分或者全部包含在查询区间[L,R]
    if (m >= L) //待维护区间的左子树有节点在查询区间
    {
        //往左子树调用
        Update(L, R, x, m, k << 1, val);
    }
    if (m < R) //待维护区间的右子树有节点在查询区间
    {
        //往右子树调用
        Update(L, R, m+1, y, k << 1|1, val);
    }

    //更新子节点信息后更新本节点
    PushUp(k);
}

ll Query(int L, int R, int x, int y, int k)
{
    ll res = 0;
    //递归终止条件
    if (L <= x && y <= R) //待维护区间完全在查询区间内
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

class RangeModule
{
public:
    RangeModule()
    {

    }
    void addRange(int left, int right)
    {

    }
    void queryRange(int left, int right)
    {

    }
    void removeRange(int left, int right)
    {

    }
private:
    int start;
    int end;

};

int main() {

    int N, M;
    int X, Y, Delta;

    cin >> N >> M;
    cout << "input is " << N << "," << M << endl;
    for (int i=1;i<=N;i++)
    {
        cin >> a[i];
    }
    Build(1, N, 1);
    for (int i=0;i<M;i++)
    {
        cin >> X >> Y >> Delta;
        cout << tree[1].sum << endl;
        Update(X, Y, 1, N, 1, Delta);
        cout << tree[1].sum << endl;

        cout << Query(X, Y, 1, N, 1) << endl;

    }
    return 0;
}