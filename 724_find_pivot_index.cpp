#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()<1)
            return -1;
        vector<int>left_sum(nums.size(),0);
        vector<int>right_sum(nums.size(),0);
        int i;
        for(i = nums.size()-2; i>=0; i--) {
            right_sum[i]=right_sum[i+1]+nums[i+1];
        }

        for(i = 1; i<nums.size(); i++) {
            if(left_sum[i-1]==right_sum[i-1])
                return (i-1);
            else
                left_sum[i] = left_sum[i-1]+nums[i-1];
        }

        if(left_sum[i-1]==right_sum[i-1])
                return (i-1);
        else
            return (-1);
    }
};

int main() {
  Solution pivot;
  vector<int> input{1,2,3,4,5,10};
  int index = pivot.pivotIndex(input);
  cout<<"Input Vector: ";
  for(auto x:input) {std::cout<<x<<" ";}
  cout<<endl;
  cout<<"Pivot Index: "<<index<<endl;
  return 0;
}
