class Solution {
private:
    void reverse(string &s, int left, int right){
        while (left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
public:
    void reverseWords(string &s) {
        int left = 0;
        int right = 0;
        
        //remove leading spaces
        while (left < s.size() && isspace(s[left])) left++;
        
        if (left == s.size()){
            s = "";
            return;
        }else if (left > 0){
            s = s.substr(left, s.size()-left);
        }
        left = 0;
        
        //remove trailing spaces
        right = s.size()-1;
        int count = 0;
        while (right >= 0 && isspace(s[right])) {
            right--;
            count++;
        }
        
        if (right < s.size()-1){
            s = s.substr(left, s.size()-count);
        }
        right = 0;
        
        //remove extra spaces - in place
        int newIndex = 0;
        count = 0;
        for (int i = 0; i < s.size(); i++){
            if (isspace(s[i])){
                count++;
                if (count == 1){
                    s[newIndex] = s[i];
                    newIndex++;
                }
            }
            else{
                count =0;
                s[newIndex] = s[i];
                newIndex++;
            }
        }
        
        if (newIndex != s.size()-1){
            s = s.substr(0, newIndex);
        }
        
        //first reverse whole sentence
        reverse(s, left, s.size()-1);
        
        //then reverse each word in the string
        while (left < s.size() && right < s.size()){
            while (left < s.size() && isspace(s[left])) left++;
            if (left == s.size()) break;
            
            right = left;
            while (right < s.size() && !isspace(s[right])) right++;
            
            --right;
            reverse(s, left, right);
            if (right != s.size()-1){
                left = right+1;
            }
            else {
                break;
            }
        }
    }
};