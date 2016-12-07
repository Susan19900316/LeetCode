/*
LeetCode:4 Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/*
思路：将两个vector按照顺序合并成两个，同时抽出单个值作比较
	  然后根据vector.size()是奇数和偶数两种情况求median

Get的点：1.将vector当做迭代器，auto i=nums.begin, i++, *i
         2.求两个整数相除的double结果时，将分母强制转换为double
*/
#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		auto p = nums1.begin(), q = nums2.begin();
		double Median = 0; //存放返回值
		//将两个vector按照大小排序存放到nums中
		while (p != nums1.end() && q != nums2.end()){
			if (*p <= *q){
				nums.push_back(*p);
				p++;
			}
			else{
				nums.push_back(*q);
				q++;
			}
		}
		if (p == nums1.end()){
			while (q != nums2.end()){
				nums.push_back(*q);
				q++;
			}
		}
		else if (q == nums2.end()){
			while (p != nums1.end()){
				nums.push_back(*p);
				p++;
			}
		}
		//求返回值
		auto Num = nums.size();
		if (Num % 2 != 0){
			Median = nums[Num / 2];
		}
		else{
			Median = (nums[Num / 2 - 1] + nums[Num / 2]) / double(2);
		}
		return Median;

	}
};
int main()
{

	vector<int> nums1 = { 1, 2 }, nums2 = { 3, 4 };
	Solution result;
	double b;
	b = result.findMedianSortedArrays(nums1,nums2);
	

	
	return 0;
}