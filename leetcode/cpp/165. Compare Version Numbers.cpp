
//  一一判断 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cur1 = 0, cur2 = 0;
        int m = version1.length(), n = version2.length();
        
        while (cur1 < m && cur2 < n) {
            int len1 = 0, len2 = 0;
            while(version1[cur1 + len1] != '.' && version1[cur1 + len1] != '\0')
                ++len1;
            while(version2[cur2 + len2] != '.' && version2[cur2 + len2] != '\0')
                ++len2;
                
            int i1 = stoi(version1.substr(cur1, len1));
            // int i1 = stof("0.1");
            int i2 = stoi(version2.substr(cur2, len2));
            
            cout << i1 << i2 << endl;
            cout << len1 << len2 << endl;
            
            if (i1 < i2)
                return -1;
            else if (i1 > i2)
                return 1;
            else { // i1 == i2
                if (version1[cur1 + len1] == '\0' && version2[cur2 + len2] == '\0')
                    return 0;
                else if (version1[cur1 + len1] == '\0')  {
                    return stof(version2.substr(cur2 + len2 + 1)) == 0 ? 0 : -1;
                }
                else if (version2[cur2 + len2] == '\0') {
                    return stof(version1.substr(cur1 + len1 + 1)) == 0 ? 0 : 1;
                }
                    
                else {
                    cur1 = cur1 + len1 + 1;
                    cur2 = cur2 + len2 + 1;
                }
            }
            
        }
        
        return 2;
    }
};
