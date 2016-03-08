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
}

C++:
class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& st1) {
        // Write your code here
        if (st1.empty() || st1.size() == 1) {
            return;
        }
        stack<int> st2;
        
        while (!st1.empty()) {
            int top = st1.top();
            st1.pop();
            int count = 0;
            
            while (!st2.empty() && st2.top() < top) {  //把小于top的先暂时放回st1
                st1.push(st2.top());
                st2.pop();
                count++;   // 数一下一共放回了多少个
            }
            st2.push(top);
            for (int i = 0; i < count; i++) {  //等push完top, 再从st1拿回st2
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
};