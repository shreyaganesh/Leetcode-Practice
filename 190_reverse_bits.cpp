#include "iostream"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int count=32;
        uint32_t reversed=0;
        for(int i =1; i<=32; i++) {
            reversed=(reversed<<1)|(n&0x01);
            n>>=1;
        }
        return reversed;
    }
};

int main() {
	Solution revBits;
	uint32_t input = 10010100110010001111010101110011;
	uint32_t reversed = revBits.reverseBits(input);
	std::cout<<"Input: "<<input<<"\nReversed: "<<reversed<<std::endl;
	if(revBits.reverseBits(reversed)==input)
		std::cout<<"Output is correct!\n";
	else
		std::cout<<"Incorrect Output. Try again.\n";
	return 0;
}
