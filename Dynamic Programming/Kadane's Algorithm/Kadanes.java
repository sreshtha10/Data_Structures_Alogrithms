/* 
Kadane's Algorithm
T - O(n)
S - O(1)

For any continuous sum, two observations can be made:
1. if -ve number is added to that sum, it will always going to decrease.
2. if sum becomes less than zero, any +ve number will make the sum > sum + (-ve negative number).

Therefore, 
We can record the currMax (maximum in the current continuous sub-array) and max (maximum till now).
If we encounter any number such that our currMax becomes less than 0 we can reset it to 0.
If we encounter any number such that our currMax decrease but > 0, it may be possible that after some time total sum becomes greater than maximum. for ex, [1,2,-1,5]. */


class Kadanes {
    public int maxSubArray(int[] nums) {
        int max=nums[0], currMax = 0;
        for(int i=0;i<nums.length;i++){
            currMax += nums[i];
            if(currMax > max){
                max = currMax;
            }
            if(currMax < 0){
                currMax = 0;
            }
        }
        
        return max;
        
    }
}
