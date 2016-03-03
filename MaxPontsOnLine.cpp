Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

public int maxPoints(Piont[] points) {
        if (points.length < 3) {
            return points.length;
        }
        int max = 1;
        for (int i = 0; i < points.length - 1; i++) {
            Map<Double, Integer> map = new HashMap<>();
            Point p = points[i];
            int ver = 1;
            int dup = 0;
            for (int j = i + 1; j < points.length; j++) {
                Point q = points[j];
                if (p.x == q.x) {
                     if (p.y == q.y) {
                       dup++;
                   } else {
                     ver++;
                   }
                    continue;
                }
                double k = 0.0 + ((double)q.y - p.y) / (q.x - p.x);
                if (!map.containsKey(k)) {
                    map.put(k, 2);
                } else {
                    map.put(k, map.get(k) + 1);
                }
            }
            int iMax = 1;
            for (int v : map.values()) {
                if (v > iMax) {
                    iMax = v;
                }
            }
            if (ver > iMax) {
                iMax = ver;
            }
            iMax += dup;
            if (iMax > max) {
                max = iMax;
            }
        }
        return max;
    }

    C++:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> mymap;
        int maxNum = 0;
        for (int i = 0; i < points.size(); i++) {
            int samePoint = 1;
            int vertical = 0;
            mymap.clear();
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samePoint++;
                }
                else if (points[i].x == points[j].x) {
                    //mymap[INT_MAX]++;
                    vertical++;  //加个变量来代替可能有的worse case
                } else {
                    double slope = double(points[i].y-points[j].y)/double(points[i].x-points[j].x);
                    mymap[slope]++;
                }
            }
            int temp_max = 0;
            for (auto m : mymap) {
                temp_max = max(temp_max, m.second);
            }
            temp_max = max(temp_max, vertical);
            maxNum = max(maxNum, temp_max + samePoint);
        }
        return maxNum;
    }