given a set of unique characters, find the minimun substring which cover all the characters in the set.

Java:

// wow, a hard one....
// actually, this one is different with the leetcode one, which is simpler than that hard one
// FYI, this is a FB phone interview question, oh i see... not the same...let me think
// is the only difference is the set? i forgot the original one

  String minWindow (String s, Set<Character> dict) {
    int left = 0;
    int right = 0;
    int rsLeft = 0;
    int minLen = s.length();
    char[] chs = s.toCharArray();
    int count = 0;
    Map<Character, Integer> smap = new HashMap<>();
    for (right = 0; right < chs.length; right++) {
      char ch1 = chs[right];
      if (dict.contains(ch1)) {
        if (!smap.containsKey(ch1) && count < dict.size()) {
          smap.put(ch1, 1);
          count++;
        } else {
          smap.put(ch1, smap.get(ch1) + 1);
        }
        if (count >= dict.size()) {
          char ch2 = chs[left];
          while (!dict.contains(ch2) || smap.get(ch2) > 1) {
            if (dict.contains(ch2)) {
              smap.put(ch2, smap.get(ch2) - 1);
            }
            ch2 = chs[++left];
          }
          if (right - left + 1 < minLen) {
            rsLeft = left;
            minLen = right - left + 1;
          }
        }
      }
    }
    return count < dict.size() ? "" : s.substring(rsLeft, rsLeft + minLen);
  }

c++:  

string minWindow(string S, unordered_set<char> dict) {
    if (S.size() == 0) {
        return "";
    }
    unordered_map<char, int> window_count;

    int validNum = 0;
    int fast, slow;
    int len = INT_MAX;
    int index = 0;
    for (slow = 0, fast = 0; fast < S.size(); fast++) {
        char c = S[fast];
        if (dict.find(c) != dict.end()) {
            window_count[c]++;
            if (window_count[c] == 1) {
                validNum++;
            }
        }

        if (validNum == dict.size()) {
            while (dict.find(S[slow]) == dict.end() || window_count[S[slow]] > 1) {
                window_count[S[slow]]--;
                slow++;
            }

            if (fast - slow + 1 < len) {
                len = fast - slow + 1;
                index = slow;
            }
        }
    }

    return S.substr(index, len);
}