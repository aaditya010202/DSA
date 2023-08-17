// coding ninjas
// this code is showing memory exceeded in leetcode
vector<vector<string>> shortestTransitionPaths(string beginWord, string endWord, vector<string>& wordList)
{
    // Write your code here.
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<string> temp;
        temp.push_back(beginWord);
        q.push(temp);
        st.erase(beginWord);
        vector<vector<string>> ans;
        int level=0;

        while(!q.empty())
        {
                vector<string> vec=q.front();
                q.pop();
                string word=vec.back();
                if(vec.size()>level)
                {
                    level++;
                    for(auto x: temp)
                    {
                        st.erase(x);
                    }
                }
                if(word==endWord){
                    if(ans.size()==0)ans.push_back(vec);
                    else if(ans[0].size()==vec.size())ans.push_back(vec);
                } 
                
                for(int i=0;i<word.size();i++)
                {
                    char originalChar=word[i];
                    for(char j='a';j<='z';j++)
                    {
                        word[i]=j;
                        if(st.find(word)!=st.end())
                        {
                            vec.push_back(word);
                            q.push(vec);
                            temp.push_back(word);
                            vec.pop_back();
                        }
                    }
                    word[i]=originalChar;
                }
        }
        return ans;
}