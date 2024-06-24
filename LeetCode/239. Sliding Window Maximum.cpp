class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;  
        priority_queue<pair<int ,int >> mx_heap; 
        for(int i = 0;  i <= nums.size() ;  i++ ){
            if(i<k){
                mx_heap.push(make_pair(nums[i], i)); 
            }else{
                while(mx_heap.top().second<(i-k)) mx_heap.pop(); 
                ans.push_back(mx_heap.top().first); 
                if(i<nums.size()){
                    mx_heap.push(make_pair(nums[i], i));
                }
            }
        }
        return ans; 
    }
};
