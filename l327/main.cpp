/*
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

示例:

输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

 */
#include <iostream>
#include <vector>
#include <string>

/*using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

    }
};*/
/*
 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8


说明:


	数组仅可以在 update 函数下进行修改。
	你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。
 */
//线段树求解数组和
#define n 1000
class NumArray {
public:
    NumArray(vector<int>& nums) {

    }

    void update(int i, int val) {

    }

    int sumRange(int i, int j) {

    }

private:
    int a[n];
    int t[n<<2];
    int add[];
    void PushUp(int k)
    {
        t[k] = t[k<<1] + t[k<<1|1];
    }
    //build tree,recursive
    void Build(int l, int r, in k)
    {
        if (l == r)
        {
            t[k] = a[l];
            return;
        }

        int m = (l+r)>>1;
        Build(l, m, k<<1);
        Build(m, r, k<<1|1);

        Push(k);
    }
    //build tree,not recursive
    void Build2(int n)
    {
        int N = 1;
        //求得>=n的最小2的整次幂
        while (N < n+2)//?
        {
            N <<= 1;//原数组下标+N=存储下标
        }
        for (int i=N-1;i>0;--i)
        {
            t[i] = t[i<<1] + t[i<<1|1];
            add[i] = 0;
        }
    }

    //update,a[k]+=c
    void Update(int L, int R, int l, int r, int k)
    {
        //递归终止条件
        if (l == r)
        {
            t[k] += c;
            return;
        }

        int m = (l+r) >> 1;
        //若左子区间[l,m]的一部分或者全部包含在查询区间[L,R]
        if (m >= L)
        {
            //往左子树调用
            Update(L, R, l, m, k << 1);
        }
        else
        {
            //往右子树调用
            Update(L, R, m, r, k << 1|1);
        }

        //更新子节点信息后更新本节点
        PushUp(k);
    }

    int Update(int L, int R)
    {

    }

};