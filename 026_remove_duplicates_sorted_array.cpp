#include "iostream"
#include <vector>

using namespace std;

class Solution {
	public:
		    int removeDuplicates(vector<int>& nums) {
			            if(nums.empty())
					                return 0;
				            int lenMaintain = nums.size();
					            for(int i = lenMaintain-1; i>0; i--){
							                if(nums[i]==nums[i-1]) {
										                for(int j = i; j<lenMaintain-1; j++){
													                    nums[j] = nums[j+1];
															                    }
												                lenMaintain--;
														            }
									        }
						            return lenMaintain;        
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
