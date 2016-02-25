// Given two strings S and T, determine if they are both one edit distance apart. -Facebook

boolean isOneEditDistance(String s, String t) {

    if (Math.abs(s.length()- t.length()) > 1) {
        return false;
    }
    if (s.length()< t.length()) {
        String tmp = s;
        s = t;
        t = tmp;
    }
    if (s.length() == t.length()) {
        if (s.equals(t)) {   //what does this mean? o, if they are same then return false? abc, abc, return false? yeah ok
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                if (i == s.length() - 1) {
                    return true;
                } else {
                    return s.substring(i + 1).equals(t.substring(i + 1));
                }
            }
        }
        return true;
    } else {
        for (int i = 0; i < t.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                return t.substring(i).equals(s.substring(i + 1));
            }
        }
        return true;
    }
    
}

第一种:
bool isOneEditDistance(string s, string t) 
{

    string &ss = s, &tt = t;
    if (ss.size() > tt.size()) swap(ss, tt);

    int lens = ss.size(), lent = tt.size();
    if (lent -lens >= 2) return false;

    int diffcount = 0;
    int notequal = lens == lent ? 0: 1;

    for (int i = 0; i < lent; i++)
    {
        if (t[i] != s[i - diffcount*notequal])
        {
            diffcount++;
        }
    }

    return diffcount == 1;
}


第二种
for (int i = 0; i < min(s.size(), t.size()); i++) {
        if (s.at(i) != t.at(i)) {
            return s.substr(i + (s.size() >= t.size() ? 1 : 0)).compare(t.substr(i + (s.size() <= t.size() ? 1 : 0))) == 0;
        }
    }
    return s.size() - t.size() == 1 || s.size() - t.size() == -1;

    bool isOneEditDistance(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (abs(lens - lent) > 1) {
            return false;
        }

        if（lens >= lent) {
            return OneED(s, t);
        } else {
            return OneED(t, s);
        }
    }

    bool OneED(string s, string t) {
        int diff = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s.size() > t.size()) {
                if (diff == 0 && s[i] != t[i]) {
                    diff++;
                }
                if (diff == 1 && s[i+1] != t[i]) {
                    return false;
                }
            }
            else {
                if (s[i] != t[i]) {
                    diff++;
                }
                if (diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }