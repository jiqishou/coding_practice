/*
一个large array, remove 其中的even number，duplicate其中的odd number，必须in place

Google phone interview
*/

void resetArray(vector<int> &nums) {
    int pOdd = 0, pEven = 0;
    // find first even number
    while (pEven < nums.size() && nums[pEven] % 2 == 1) {
        pEven++;
    }
    pOdd = pEven + 1; 
    
    // swap pEven and pOdd number to partition the array by odd and even
    while (pOdd < nums.size()) {
        while (pOdd < nums.size() && nums[pOdd] %2 == 0) {
            pOdd++;
        }
        if (pOdd >= nums.size()) {
            break;
        }
        swap(nums[pEven], nums[pOdd]);
        pEven++;
    }
    
    // get the count of odd number
    int count_odd = pEven;
    
    // copy the odd number within the unlimitated array
    for (int i = 0; i < count_odd; i++) {
        nums[count_odd + i] = nums[i];
    }
    
    // duplicate odd numbers
    int pos = count_odd;
    for (int i = 0; i < count_odd; i++) {
        nums[i] = nums[count_odd + i];
        nums[i + 1] = nums[i];
    }
    
    // remove even numbers
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] % 2 == 0) {
            nums.pop_back();
        } else {
            break;
        }
    }
}

rewrite version:
void resetArray(vector<int> &nums) {
    int pEven = -1;
    // partition the array by odd and even numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            if (pEven == -1) {
                pEven = i;
            }
        } else {
            if (pEven != -1) {
                swap(nums[i], nums[pEven]);
                pEven++;
            }
        }
    }

    // duplicate odd numbers    
    for (int i = pEven; i >= 1; i--) {
        nums[2 * i - 1] = nums[i - 1];
        nums[2 * i - 2] = nums[i - 2];
    }

    // remove even numbers
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] % 2 == 0) {
            nums.pop_back();
        } else {
            break;
        }
    }
}