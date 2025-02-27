class Solution {
public:
    string defangIPaddr(string address) {
        string result;  // Declare result as a string
        int n=address.length();
        for (int i=0; i<n;i++) {
            if (address[i] == '.') 
                result += "[.]";
            else 
                result += address[i];
        }
        return result;
    }
};
