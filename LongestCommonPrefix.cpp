class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxlen=0;
        for(int i=1;i<=strs[0].length();i++){
            int flag=1;
            for(int j=0;j<strs.size();j++){
                if(strs[j].substr(0,i).find(strs[0].substr(0,i))!=string::npos)
                    continue;
                else{
                    flag=0;
                    break;
                }
            }
            if(flag && i>maxlen)
                maxlen=i;
            if(!flag)
                break;
        }
        return strs[0].substr(0,maxlen);
    }
};
