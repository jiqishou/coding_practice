fb  电面面经:

/*
有一些任务ABC，每个相同的任务中间会有一些cooldown时间。比如如果cooldown是5的话，那么执行任务AABB就必须是A.....AB.....B。写一个函数输入时任务（字符串），cooldown时间，输出是总时间。

一个伊朗人面的，题目是task scheduler，举例如下
Tasks: AABABCD
Cooldown Time: 2
A__AB_ABCD
Output: 10
就是说同样类型的task之间至少要等2，每个task的执行时间是1
followup: 如果cooldown是个参数，也就是说有可能会很长时间，怎么修改之前的程序

*/
直接走步数比较快 O(n)
int taskScheduler(string tasks, int ct) {
    // value is the time when key can be executed
    map<char, int> cooldown;
    int time = 0;
    
    for (int i = 0; i < (int)tasks.size(); i++) {
        char task = tasks[i];
        if (cooldown.find(task) == cooldown.end()) {
            time++;
            cooldown[task] = time + ct;
        } else {
            if (time < cooldown[task]) {
                time = cooldown[task];
                time++;
            } else {
                time++;
                cooldown[task] = time + ct;
            }
        }
    }
    return time;
}

int main() {
    string str = "AABABCD";
    int res = taskScheduler(str, 2);
    cout<<res<<endl;
}

// 每次去减cooldown, O(n^2)
int taskScheduler(string str, int cd) {
    unordered_map<char, int> cooldown;
    for (int i = 0; i < str.size(); i++) {
        cooldown[str[i]] = 0;
    }
    
    int total = 0;
    int i = 0;
    while (i < str.size()) {
        char task = str[i];
        if (cooldown[task] == 0) {
            i++;
            cooldown[task] = cd + 1;
        }
        for (auto m : cooldown) {
            if (m.second > 0) {
                m.second--;
            }
        }
        total++;
    }
    return total;
}