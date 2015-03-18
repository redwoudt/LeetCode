class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int length = n;
        for (int i = 0; i<n; i++){
            if (A[i]==elem){
                while (A[length-1]==elem){
                    length--;
                }
                if (length>i){
                    A[i] = A[length-1];
                    length--;
                }
            }
        }
        
        return length;
    }
};