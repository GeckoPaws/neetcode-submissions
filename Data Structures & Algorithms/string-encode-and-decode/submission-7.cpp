class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encodedStr = "";
        for(string s : strs)
        {
            encodedStr += to_string(s.length());
            encodedStr += "#";
            encodedStr += s;
            
        }
        //cout<<encodedStr<<endl;
        return encodedStr;
    }

    vector<string> decode(string s) 
    {
        
        vector<string> decodedStr(0);
        string word = "";

        for(int k = 0; k < s.length(); k++)
        {
            //if I encounter a number, thats how many characters long the word is
            if( isdigit(s.at(k)) )
            {
                //cout<<"digit here "<< s.at(k)<<endl;
                //to find the word size, read each number char in the string untill hitting '#'
                //'#' singifies the end of the number
                int j = k;
                string wordSizeStr = "";
                while(j  < s.length() && isdigit(s.at(j)))
                {
                    wordSizeStr += s.at(j);
                    j++;
                }

                int wordSize = stoi(wordSizeStr);
                //cout<< "word size is "<< wordSize<<endl;
                if(wordSize == 0)//if the word size is 0, push back an empty string
                    {
                        decodedStr.push_back("");
                        word = "";
                        continue;
                    }
                else
                {
                    decodedStr.push_back(s.substr(j+1, wordSize));

                    k = j + wordSize;
                }
                
            }
        }
        //cout<<decodedStr.size();
        return decodedStr;
    }
};
