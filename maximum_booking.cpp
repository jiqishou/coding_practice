From AirBnB

/*
Given a set of numbers in an array which represent number of consecutive days of AirBnB reservations
pick the sequence which maximizes the number of day of occupancy, at the same time, leaving at least
1 day gap in between bookings for cleaning.
For example,
[5,1,1,5] -> 10
[3,6,4] -> 7
 */
 
 // are you there yes ok
 // book[i] = max( book[i-2] + val[i], book[i-1])
                 //book today        or not book today
                 
 int maximumNumberBooking(vector<int> &nums) {
     if (nums.size() == 0) {
         return 0;
     }
     if (nums.size() == 1) {
         return nums[0];
     }
     if (nums.size() == 2) {
         return nums[0] > nums[1] ? nums[0] : nums[1];
     }
     
     vector<int> book(nums.size(), 0);
     book[0] = nums[0];
     book[1] = nums[0] > nums[1] ? nums[0] : nums[0];
     
     for (int i = 0; i < nums.size(); i++) {
         book[i] = max((book[i-2] + nums[i]), book[i-1]);
     }
     
     return book[nums.size()-1];
 }
 
 // that's good