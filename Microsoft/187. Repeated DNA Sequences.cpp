class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> st;
        unordered_set<string> seen;
        vector<string> ans;

        for(int i=0;i<= n-10;i++){
            string res = s.substr(i,10);
            if(st.find(res) != st.end()){
                if(seen.find(res) == seen.end()){
                    seen.insert(res);
                    ans.push_back(res);
                }
            }else{
                st.insert(res);
            }
        }

        return ans;
    }
};