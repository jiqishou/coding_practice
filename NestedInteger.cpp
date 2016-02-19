/**
* Given a nested list of integers, returns the sum of all integers in the list weighted by their depth
* For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, one 2 at depth 1).
* Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3)
*/

public interface NestedInteger
{
    /** @return true if this NestedInteger holds a single integer, rather than a nested list */
    boolean isInteger();

    /** @return the single integer that this NestedInteger holds, if it holds a single integer
     * Return null if this NestedInteger holds a nested list */
    Integer getInteger();

    /** @return the nested list that this NestedInteger holds, if it holds a nested list
     * Return null if this NestedInteger holds a single integer */
    List<NestedInteger> getList();
}

public int depthSum (List<NestedInteger> input)
{
    int res = 0;
    depth(input, 1, res);
    return res;
}

void (List<NestedInteger> &input, int step, int &res){
    for (int i=0; i<input.size(); i++){
        if (input[i].isInteger()){
            res += input[i].getInteger * step;
        }
        else{
            depth(input[i].getList, step+1, res);
        }
    }
}

public int depthSum (List<NestedInteger> input)
{
    //implement your code here
  //  if (input.isInteger) return 0;
    
    int sum = 0;
    Queue<NestedInteger> queue = new LinkedList<>();  
    for (NestedInteger ni : input) {
        queue.offer(ni);
    }
    int level = 0;
    while(!queue.isEmpty()) {
        level++;
        int n = queue.size();
        for (int i = 0; i < n; i++) {
            NestedInteger ni = queue.poll(); //poll means get top() and pull()? pull
            if (ni.isInteger()) {
                sum += ni.getInteger() * level;
            } else {
                for (NestedInteger nii : ni.getList) {
                    queue.offer(nii);
                }
            }
        }
    }
    return sum;
}