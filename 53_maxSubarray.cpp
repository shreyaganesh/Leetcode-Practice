#include "iostream"
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int result=0;
        int sum=0, max=nums[0];
        for(int i =0; i<nums.size(); i++) {
            sum+=nums[i];
            max=(max>sum?max:sum);
            sum=(sum>0?sum:0);
        }
        return max;
    }
};

int main() {
  std::vector<int> input{-2,1};
  Solution maxSub;
  int result = maxSub.maxSubArray(input);
  std::cout<<"Current input:\n";
  for(auto x:input) {std::cout<<x<<"\t";}
  cout<<"\nMaximum subarray of given input is: "<<result<<endl;
}
