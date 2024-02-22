
class Solution {
public:
    int msbBitValue(int n) {
      for(int i =31 ;i>=0 ; i-- ){
          if((1<<i)&n){
              return (i+1); 
          }
      }
      return 0;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left == right ) return left; 
        int ans =0 ; 
        if(msbBitValue(left) == msbBitValue(right)) {
             int i = msbBitValue(left) -1; 
                while((left&(1<<i))==(right&(1<<i))){
                    ans|=(left&(1<<i)); 
                    i--;
                }
            return ans; 
        }else return 0; 



    }
};




/*
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int l =left , r =right; 
        int cnt =0 ; 
        while(l!=r){
            l>>=1 ; 
            r>>=1 ; 
            cnt++;             
        }
        return l<<cnt; 


    }
};
*/
