class KthLargest {
    int k ; 
    vector<int> nums; 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k= k; 
        this->nums= nums;
        sort(this->nums.begin(), this->nums.end()); 

    }
    int add(int val) {
        auto it = upper_bound(nums.begin(), nums.end() , val); 
        nums.insert(it , val); 
        return nums[nums.size()-k]; 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
