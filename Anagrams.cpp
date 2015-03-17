class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        //group strings by size
        unordered_map <int, vector<string> *> groupedStrings;
        for (const auto & str : strs){
            int size = (int)str.length();
            if (groupedStrings[size]==NULL){
                groupedStrings[size] = new vector<string>();
            }
            groupedStrings[size]->push_back(str);
        }
        
        //compare strings of same size
        unordered_map <string, int> counter;
        unordered_map <string, string> tempString;
        
        vector<string> * anagrams = new vector<string>();
        for (const auto & group : groupedStrings){
            vector<string> * groupStrs = (vector<string> *)group.second;
            if (groupStrs->size() >1){
                for (const auto & str : (*groupStrs)){
                    string localStr = sort(str);
                    counter[localStr] += 1;
                    if (counter[localStr]==1){
                        tempString[localStr] = str;
                    }
                    else if (counter[localStr]==2){
                        anagrams->push_back(tempString[localStr]);
                        anagrams->push_back(str);
                    }
                    else{
                        anagrams->push_back(str);
                    }
                }
            }
        }
        
        //return vector string
        return *anagrams;
    }
private:
    string sort(string str){
        string * newStr = new string(str);
        sort(*newStr, 0, (int)newStr->length()-1);
        return *newStr;
    }
    //quick sort
    void sort(string & str, int begin, int end){
        int pivot = str[(begin+end)/2];
        int leftIndex = begin;
        int rightIndex = end;
        
        while (leftIndex <= rightIndex){
            while (str[leftIndex] < pivot){
                leftIndex++;
            }
            while (str[rightIndex]>pivot){
                rightIndex--;
            }
            if (leftIndex<= rightIndex){
                char temp = str[rightIndex];
                str[rightIndex] = str[leftIndex];
                str[leftIndex] = temp;
                leftIndex++;
                rightIndex--;
            }
        }
        
        if (begin < leftIndex-1 ){
            sort(str, begin, leftIndex-1);
        }
        
        if (leftIndex < end ){
            sort(str, leftIndex, end);
        }
    }
    
};