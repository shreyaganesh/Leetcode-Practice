#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        auto tracker=0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[tracker]!=nums[i]) {
                nums[++tracker]=nums[i];
            }
        }
        return (tracker+1);
    }
};

int main() {
	vector<int> nums{0,0,1,1,1,2,2,3,3,4};
	Solution duplicates;
	int newSize = duplicates.removeDuplicates(nums);
	for(int i=0; i<newSize-1; i++)
		cout<<nums[i]<<", ";
	cout<<nums[newSize-1]<<endl;
	return 0;
}
