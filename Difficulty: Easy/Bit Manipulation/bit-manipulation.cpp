class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        unsigned int get = (num >> i-1) & 1;
        
        unsigned int set = num | (1 << (i-1));
        
        unsigned int clear = num & ~ (1<< (i-1));
        
        cout<< get <<" " <<set <<" " << clear ;
        
    }
};