class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
       if(strs.empty())
        return vector<vector<string>>();
        //make key:value pairs for each item in the input array
        //each entry is a key and its value is its characters sorted
        //keys that have the same value are anagrams, so group them
        
        vector<pair<string, string>> pairs;
        for(string s : strs)
        {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            pairs.push_back(pair<string, string>(s, sorted));
        }
            

        sort(pairs.begin(), pairs.end(), 
            [](const pair<string, string> a, const pair<string, string> b)
            {return a.second > b.second;});//sort the pairs

        vector<vector<string>> output;
        vector<string> words;
        string comparison_word = pairs[0].second; //takes the sorted value of first index
        for(int i = 0; i < pairs.size(); i++)
        {
            if(pairs[i].second == comparison_word)
            //if the target pair has same value as the comparison word, its an anagram
                words.push_back(pairs[i].first);
            else
            {
            //if not, the comparison word gets updated, words gets pushed to output
            comparison_word = pairs[i].second;
            output.push_back(words);
            //and words gets cleared
            words.clear();
            words.push_back(pairs[i].first);
            }
        }
        output.push_back(words);
        return output;
    }
};
