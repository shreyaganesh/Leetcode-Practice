/** 1 - Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**/

/**
Code logic works, but some memory issues where Two-pass map isn't working.
**/
#include "iostream"
#include <map>
#include <vector>

class Solution {
public:
    std::map<int,int> numMap;
    std::vector<int> result;
    std::vector<int> twoSum(std::vector<int>& nums, int target, int caseCheck) {
			switch(caseCheck) {
        case 0: //Brute Force
            for(int i = 0; i<nums.size()-1; i++){
              for(int j = i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j]==target){
                  result.push_back(i);
                  result.push_back(j);
                  return result;
                }
              }
            }
            break;

	/*case 1: //Two-pass Map

	//FIRST PASS: populating the map with key as required difference between current element and target
        for(int i=0; i<nums.size(); i++) {
          int numToFind = target-nums[i];
          numMap[numToFind]=i;
        }
        //SECOND PASS: traversing populated map to find the first element with a match (expecting it's the only element)
        for(int i = 0; i<nums.size(); i++) {
          if((numMap.find(nums[i])!=numMap.end()) && (numMap[nums[i]]!=i)){
            result.push_back(i);
            result.push_back(numMap[nums[i]]);
            break;
          }
        }
        break;*/

        case 2: //Single pass map
        for(int i=0; i<nums.size(); i++) {
          if((numMap.find(nums[i])!=numMap.end()) && (numMap[nums[i]]!=i)) {
            result.push_back(i);
            result.push_back(numMap[nums[i]]);
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

	std::vector<int> arrayVals{1,2,3,4,5};
	int findNum = 8;
	std::vector<int> result;
	Solution two_sum;

	result=two_sum.twoSum(arrayVals,findNum,0);
	std::cout<<"Brute force result: "<<result[0]<<","<<result[1]<<"\n";
  /*for(auto x:result)
  std::cout<<x<<",";
  std::cout<<"\n";*/
  result.clear();
	result=two_sum.twoSum(arrayVals,findNum,2);
	std::cout<<"Single pass result: "<<result[0]<<","<<result[1]<<"\n";
	return 0;
}
