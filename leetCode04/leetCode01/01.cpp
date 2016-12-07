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
˼·��������vector����˳��ϲ���������ͬʱ�������ֵ���Ƚ�
	  Ȼ�����vector.size()��������ż�����������median

Get�ĵ㣺1.��vector������������auto i=nums.begin, i++, *i
         2.���������������double���ʱ������ĸǿ��ת��Ϊdouble
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
		double Median = 0; //��ŷ���ֵ
		//������vector���մ�С�����ŵ�nums��
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
		//�󷵻�ֵ
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