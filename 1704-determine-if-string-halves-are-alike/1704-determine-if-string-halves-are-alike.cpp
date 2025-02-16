class Solution {
public:
bool isVowel(char ch){
    return (ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}


    bool halvesAreAlike(string s) {
    int n=s.size();
        int i = 0;
        int mid= n/2;
        int j=mid;
       int countl=0;
       int countr=0;
        while (i<n/2 && j<n){
            if (isVowel(s[i])) countl ++;
                        if (isVowel(s[j])) countr ++;
i++;
j++;

        }
return countl == countr;
        
    }
};