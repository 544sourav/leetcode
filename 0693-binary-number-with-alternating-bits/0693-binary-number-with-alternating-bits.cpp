class Solution {
public:
    bool hasAlternatingBits(int n) {
      string binary =  bitset<32>(n).to_string();
      int i=0;
      while(binary[i]!='1'){
        i++;
      }
      while(i<binary.size()){
        if(binary[i]==binary[i+1])return false;
        i++;
      }
      return true;
    }
};