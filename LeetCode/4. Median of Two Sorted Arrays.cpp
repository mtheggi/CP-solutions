class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedarray ; 
        const int  inf = 1e9; 
        nums1.push_back(inf) ;
        nums2.push_back(inf) ;
        int i =0 ,j =0 ; 
        while(i<nums1.size() && j< nums2.size())
        {
            if(nums1[i] > nums2[j]){
                mergedarray.push_back(nums2[j]) ;
                j++; 
            }else{
                mergedarray.push_back(nums1[i]) ;
                i++; 
            }
        }
        mergedarray.erase(mergedarray.begin() + mergedarray.size()-1);
        for(auto i : mergedarray )cout << i << " "; 
        double median ;
        if(mergedarray.size()&1) median= mergedarray[mergedarray.size()/2];
        else {
            int indx  = mergedarray.size()/2 -1; 
            median = (mergedarray[indx] + mergedarray[indx+1])/ 2.00000; 
        }
        return median; 
    }
};
