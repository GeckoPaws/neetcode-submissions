class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<char> s2;
        vector<char> t2;
        for(int i = 0; i < s.length(); i++)
            s2.push_back(s.at(i));
        for(int i = 0; i < t.length(); i++)
            t2.push_back(t.at(i));

        sort(s2.begin(), s2.end());
        sort(t2.begin(), t2.end());

        for(int i = 0; i < s.length(); i++)
            if(s2[i] != t2[i])
                return false;
        return true;
    }
};
