class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        auto size1 = (int)str1.size();
        auto size2 = (int)str2.size();
        string pref = str1;
        int size_pref = size1;
        while (size_pref != 0) {
            if (size1 % size_pref == 0 && size2 % size_pref == 0) {
                string temp = "";
                for (int i = 0; i < size2 / size_pref; i++)
                    temp += pref;
                if (temp == str2) {
                    temp = "";
                    for (int i = 0; i < size1 / size_pref; i++)
                        temp += pref;
                    if (temp == str1)
                        return pref;
                }
            }
            pref.pop_back();
            size_pref--;
        }
        return pref;
    }
};