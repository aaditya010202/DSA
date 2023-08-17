// leetcode
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord) return level;
            for(int i=0;i<word.size();i++)
            {
                int originalChar=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(st.find(word) != st.end())
                    {
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i]=originalChar;
            }
        }
        return 0;
    }
};