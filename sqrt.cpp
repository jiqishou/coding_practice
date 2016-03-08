/*Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3
*/

class Solution {
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    public int sqrt(int x) {
        if (x == 0) {
            return x;
        }
        int start = 1;
        int end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid < x / mid) {
                start = mid;
            } else if (mid > x / mid) {
                end = mid;
            } else {
                return mid;
            }
        }
         if (end > x / end || Math.abs(start - x / start) < Math.abs(end - x / end)) {
          return start;
        }
        return end;
      }
}





















/*
Sort a stack in ascending order (with biggest terms on top).

You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (e.g. array).

Given stack =

| |
|3|
|1|
|2|
|4|
 -
return:

| |
|4|
|3|
|2|
|1|
 -
The data will be serialized to [4,2,1,3]. The last element is the element on the top of the stack.

O（n2) is accecptable
*/

Java:
public class Solution {
    /**
     * @param stack an integer stack
     * @return void
     */
    public void stackSorting(Stack<Integer> stack) {
        Stack<Integer> holderStack = new Stack<>();
        while (!stack.isEmpty()) {
            int top = stack.pop();
            int count = 0;
            while (!holderStack.isEmpty() && top > holderStack.peek()) {
                stack.push(holderStack .pop());
                count++;
            }
            holderStack .push(top);
            for (int i = 0; i < count; i++) {
                holderStack .push(stack.pop());
            }
        }
        while (!holderStack.isEmpty()) {
            stack.push(holderStack.pop());
        }
    }
};

C++:
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x == 0 || x == 1) {
            return x;
        }
        
        int start = 1;
        int end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid == x / mid) {
                return mid;
            }
            if (mid > x / mid) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (abs(x / start - start) > abs(x / end - end) && x / end - end > 0) {
            return end;
        } else {
            return start;
        }
    }
};
