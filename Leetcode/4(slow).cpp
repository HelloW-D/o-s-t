#include <iostream>
#include <algorithm>
#include <vector>
//时间复杂度为O(log(min(m, n))), 但是是简单的归并排序求中位数法
//理论上应该还有更好的方法
using namespace std;

class Solution {
public:
    /**
     * @brief 合并两个有序数组直到达到中位数位置
     * @param nums1 第一个有序数组
     * @param nums2 第二个有序数组
     * @param n 两个数组的总长度
     * @return vector<int> 合并后的数组，包含足够计算中位数的元素
     */
    vector<int> mergeArraysUntilMedian(vector<int>& nums1, vector<int>& nums2, int n) {
        int l1 = 0, l2 = 0;
        vector<int> ans;
        while (l1 + l2 <= n / 2 && l1 < nums1.size() && l2 < nums2.size())
        {
            if (nums1[l1] > nums2[l2])
            {
                if (l2 < nums2.size())
                    ans.push_back(nums2[l2++]);
            }
            else 
            { 
                if (l1 < nums1.size())
                    ans.push_back(nums1[l1++]); 
            }
        }
        while (l2 < nums2.size())
            ans.push_back(nums2[l2++]);
        while (l1 < nums1.size())
            ans.push_back(nums1[l1++]);
        return ans;
    }

    /**
     * @brief 计算合并后数组的中位数
     * @param mergedArray 合并后的有序数组
     * @param totalLength 两个原始数组的总长度
     * @return double 中位数值
     */
    double calculateMedian(vector<int>& mergedArray, int totalLength) {
        if (totalLength % 2 == 0)
        {
            return (double)(mergedArray[totalLength/2] + mergedArray[totalLength/2-1]) / 2.0;
        } else {
            return (double)(mergedArray[totalLength/2]);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> mergedArray = mergeArraysUntilMedian(nums1, nums2, n);
        return calculateMedian(mergedArray, n);
    }
};

int main()
{
    vector<int> nums1 = {1, 2}, nums2 = {3};
    Solution o;
    double result = o.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}