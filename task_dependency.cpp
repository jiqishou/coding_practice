/*
题目是这样的，输入是a list of tasks，还有dependency list，相互之间有约束，必须要在dependent tasks结束之后才能做某一个。
比如1，2，3，4， 1优先于2，4优先于3。那么可以这么安排，1 -> 4 -> 2 -> 3，只要给出可行的order就好

*/

C++:

stack<int> st;

vector<int> task_dependency(int nums, vector<pair<int, int>> tasks){
    unordered_map<int, vector<int> > dep;
    for (int i = 0; i < tasks.size(); i++) {
        dep[tasks[i].first].push_back(tasks[i].second);
    }
    unordered_map<int, bool> visit;
    
    for (int i = 1; i <= nums; i++) {
        if (visit[i] == false) {
            taskHelper(visit, dep, i);
        }
    }
    
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

void taskHelper(unordered_map<int, bool> &visit, unordered_map<int, vector<int>> &dep, int task) {
    visit[task] = true;
    for (int i = 0; i < dep[task].size(); i++) {
        if (dep[task][i] == false) {
            taskHelper(visit, dep, dep[task][i]);
        }
    }
    st.push_back(task);
} 

Java:
/* 
题目是这样的，输入是a list of tasks，还有dependency list，相互之间有约束，必须要在dependent tasks结束之后才能做某一个。
比如1，2，3，4， 1优先于2，4优先于3。那么可以这么安排，1 -> 4 -> 2 -> 3，只要给出可行的order就好

*/
List<Integer> dependencyList(int[] tasks, int[][] dependencies) {
    List<Integer> res = new ArrayList<>();
    Map<Integer, List<Integer>> neighbors = new HashMap<>();
    for (int[] d : dependencies) {
        if (!neighbors.containsKey(d[0])) {
            List<Integer> list = new ArrayList<>();
            list.add(d[1]);
            neighbors.put(d[0],list);
        } else {
            neighbors.get(d[0]).add(d[1]);
        }
    }
    boolean[] visited = new boolean[tasks.length];
    Stack<Integer> stack = new Stack<>();
    for (int i = 0; i < tasks.length; i++) {
        if (!visited[i]) {
            helper(i, visited, neighbors, stack);
        }
    }
    while (!stack.isEmpty()) {
        res.add(stack.pop());
    }
    return res;
}

private void helper(int task, boolean[] visited, Map<Integer, List<Integer>> neighbors, Stack<Integer> stack) {
    visited[task] = true;
    if (neighbors.containsKey(task)) {
        for (int neigh : neighbors.get(task)) {
            if (!visited[neigh]) {
                helper(neigh, visited, neighbors, stack);
            }
        }
    }
    stack.push(task);
}
