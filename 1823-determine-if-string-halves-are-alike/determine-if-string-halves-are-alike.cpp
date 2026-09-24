class Solution {
public:
    bool halvesAreAlike(string s) {
         int mid = s.size() / 2;
        int left = 0;
        int right = 0;

        string vowels = "aeiouAEIOU";

        for (int i = 0; i < mid; i++) {
            if (vowels.find(s[i]) != string::npos) {
                left++;
            }
        }

        for (int i = mid; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                right++;
            }
        }

        return left == right;
    }
};