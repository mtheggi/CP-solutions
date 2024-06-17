class Solution {
public:
    bool judgeSquareSum(int c) {
      
      int z  = sqrt(c); 
      for(int i = 0;  i<= z;  i++ ) {
         int  a= i; 
         int b = sqrt(c - i*i); 
         if(b*b == (c-i*i)){
            return true; 
         }
      } 
      return false ;

    }
};
