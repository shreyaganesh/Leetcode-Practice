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
#include <vector>

class Solution {
public:
  static int caseCheck=0;
    std::vector<int> result;
    std::vector<int> twoSum(vector<int>& nums, int target) {
			switch(caseCheck) {
        case 0: //Brute Force
            for(int i = 0; i<nums.length()-1; i++){
              for(int j = i+1; j<nums.length(); j++) {
                if(nums[i]+nums[j]==target){
                  result[0] = i;
                  result[1] = j;
                  return result;
                }
              }
            }
            break;

	case 1: //Two-pass Map
        std::map<int,int> numMap;

	//FIRST PASS: populating the map with key as required difference between current element and target
        for(int i=0; i<nums.length(); i++) {
	int numToFind = target-nums[i];
        numMap[numToFind]=i;
        }
        //SECOND PASS: traversing populated map to find the first element with a match (expecting it's the only element)
        for(int i = 0; i<nums.length(); i++) {
		if((numMap.find(numToFind)!=numMap.end()) && (numMap[nums[i]]!=i)){
			result[0]=i;
			result[1]=numMap[nums[i]];
			break;
		}
        }
        break;

        case 2: //Single pass map
        std::map<int,int>numMap;
        for(int i=0; i<nums.length(); i++) {
          if((numMap.find(nums[i])!=numMap.end()) && (numMap[nums[i]]!=i)) {
            result[0]=i;
            result[1]=numMap[nums[i]];
            return result;
          }
          else {
            int numToFind = target-nums[i];
            numMap[numToFind]=i;
          }
        }
        break;

        default: std::cout<<"Invalid case\n";
      }
    }
};

int main() {
	Solution.caseCheck = 0;
	std::vector<int> arrayVals{1,2,3,4,5};
	int findNum = 8;
	std::vector<int> result;
	Solution two_sum = new Solution();

	result=two_sum.twoSum(arrayVals,findNum);
	cout<<"Brute force result: "<<result[0]<<","<<result[1]<<"\n";
	Solution.caseCheck++;
	result=two_sum.twoSum(arrayVals,findNum);
	cout<<"Two-pass result: "<<result[0]<<","<<result[1]<<"\n";
	Solution.caseCheck++;
	result=two_sum.twoSum(arrayVals,findNum);
	cout<<"Single pass result: "<<result[0]<<","<<result[1]<<"\n";
	return 0;
}
