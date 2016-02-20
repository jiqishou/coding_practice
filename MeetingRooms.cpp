/* A person going to attend several meeting. You have the list of meeting of <start, end> time schedule. Return whether this person could attend all the meetings. */

/* I will add the follow up question here together. If you are the person to arrange these meetings, what's the minimum number of meeting room needed to assign to all those meetings. */

//pair is a class? yes, it has two values, pair<int, int> means the first one is start, second is end time.

//ok, let's make the question simpler. The number is start from 0, and there's no limitation. 0, 40 is acceptable, only care about the start and end time value is fine.

JAVA:
/* A person going to attend several meeting. You have the list of meeting of <start, end> time schedule. Return whether this person could attend all the meetings. */

/* I will add the follow up question here together. If you are the person to arrange these meetings, what's the minimum number of meeting room needed to assign to all those meetings. */

plz give some input example... pair is a class? yes, it has two values, pair<int, int> means the first one is start, second is end time.

ok, let's make the question simpler. The number is start from 0, and there's no limitation. 0, 40 is acceptable, only care about the start and end time value is fine.
ok
 
boolean attendAllMeetings(List<Pair> list){
    Collections.sort(list, new Comparator<Pair>() {
        public int compare(Pair p1, Pair p2) {
            return p1.start - p2.start;
        }
    });    
    for (int i = 1; i < list.size(); i++) {
        if (list.get(i).start < list.get(i - 1).end) return false;
    }
    return true;
}

int minimumMeetingRooms(List<Pair> list) {
    if (list.isEmpty) return 0;

    Collections.sort(list, new Comparator<Pair>() {
        public int compare(Pair p1, Pair p2) {
            return p1.start - p2.start;
        }
    });
    
    PriorityQueue<Integer> heap = new PriorityQueue();
    heap.offer(list.get(0).end);
    for (int i = 1; i < list.size(); i++) {
        Pair p = list.get(i);
        if (p.start >= heap.peek()) heap.poll(); //what is the value in heap.peek()? greatest or smallest, smallest
        heap.offer(p.end);    
    }
    return heap.size();
}


C++:
struct comparator{
    bool operator() (pair &i, pair &j){
        return i.start < j.start;
    }
};

bool attendAllMettings(vector<pair<int, int>> &meetings){
    int n = meetings.size();
    if (n == 0)
        return true;

    sort(meetings.begin(), meetings.end(), comparator);

    for (int i=1; i<n; i++){
        if (meetings[i].start < meetings[i-1].end)
            return false;
    }

    return true;
}

/***********************************************************************/
struct comparator{
    bool operator() (const pair &i, const pair &j){
        return i.start < j.start;
    }
};

struct comparator_pq{
    bool operator() (const pair &i, const pair &j){
        return i.end > j.end;
    }
};

typedef priority_queue<pair<int,int>, vector<pair<int,int> >, comparator_pq> Priority_Q;

bool minimumMeetingRooms(vector<pair<int, int>> &meetings){
    Priority_Q pq;
    sort<meetings.begin(), meetings.end(), comparator>;

    int number = 0;

    pq.push(meetings[0]);
    for (int i=1; i<n; i++){
        if (meetings[i].start < pq.top().end){
            number++;
            pq.push(meetings[i]);
        }
        else{
            pq.pop();
            pq.push(meetings[i]);
        }
    }

    return number;
}