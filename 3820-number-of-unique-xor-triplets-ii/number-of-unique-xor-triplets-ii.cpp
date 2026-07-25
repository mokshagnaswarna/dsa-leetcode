class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pairXors;
        
        // Step 1: Compute all unique pairwise XORs in O(N^2)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // Using j = i naturally enforces i <= j
                pairXors.insert(nums[i] ^ nums[j]);
            }
        }
        
        // Step 2: Combine pairs with single elements to form triplet XORs
        unordered_set<int> tripletXors;
        for (int pairVal : pairXors) {
            for (int k = 0; k < n; k++) {
                tripletXors.insert(pairVal ^ nums[k]);
            }
        }
        
        return tripletXors.size();
    }
};