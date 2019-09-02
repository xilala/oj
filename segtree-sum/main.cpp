#include <iostream>
#include <vector>
using namespace std;
#define maxn 100010

struct Node
{
    int l, r, max;
}tree[maxn*4];

int a[maxn];

void PushUp(int k)
{
    tree[k].max = max(tree[k<<1].max, tree[k<<1|1].max);
}
void Build(int l, int r, int k)
{
    tree[k].l = l;
    tree[k].r = r;

    if (l == r)
    {
        tree[k].max = a[l];
        return;
    }
    int m= (l+r)>>1;
    Build(l, m, k<<1);
    Build(m+1, r, k<<1|1);

    PushUp(k);
}

int Query(int x, int y, int k)
{
    int l = tree[k].l;
    int r = tree[k].r;

    //递归终止条件
    if (l==x && r==y)
    {
        return tree[k].max;
    }

    int m = (l+r) >> 1;
    //查询区间[x,y]在当前区间[l,r]的左半子树
    if (m >= y)
    {
        //往左子树调用
        return Query(x, y, k << 1);
    }
    else if(m < x) //查询区间[x,y]在当前区间[l,r]的右半子树
    {
        //往右子树调用
        return Query(x, y, k << 1|1);
    }
    else
    {
        //查询区间[x,y]跨越当前区间[l,r]的左右半子树
        return max(Query(x, m, k << 1), Query(m+1, y, k << 1|1));
    }
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