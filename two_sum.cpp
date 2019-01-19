/** 1 - Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**/

#include "iostream"
#include <map>

class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
			std::map<int,int> numMap;
			std::vector<int> result;
			for(int i=0; i<nums.length(); i++) {
				int numToFind = target-nums[i];
				if(numMap.find(numToFind)!=NULL) {
					result[0]=i;
					result[1]=numMap[numToFind];
					break;
				}
				else {
					
				}
			}

    }
};

int main() {
	// Add content
	return 0;
}
