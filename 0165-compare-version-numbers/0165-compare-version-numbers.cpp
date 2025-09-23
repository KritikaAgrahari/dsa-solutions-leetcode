class Solution {
public:
    // Function to split the version string into tokens separated by '.'
    vector<string> getTokens(string version) {
        stringstream v(version);   // Create a stringstream from version string
        string token_v = "";       // Temporary string to hold each token
        vector<string> version_tokens; // Vector to store all tokens
        
        // Extract tokens separated by '.' and push into version_tokens
        while(getline(v, token_v, '.')) {
            version_tokens.push_back(token_v);
        }
        return version_tokens;     // Return list of tokens
    }

    // Function to compare two version strings
    int compareVersion(string version1, string version2) {

        // Break version1 and version2 into tokens
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);  
        
        int m = v1.size();  // Number of tokens in version1
        int n = v2.size();  // Number of tokens in version2
            
        int i = 0;          // Iterator index for both version tokens

        // Loop until we've checked all tokens from both versions
        while(i < m || i < n) {
            
            // Convert ith token of v1 to integer if exists, else take 0
            int a = i < m ? stoi(v1[i]) : 0 ;
            // Convert ith token of v2 to integer if exists, else take 0
            int b = i < n ? stoi(v2[i]) : 0 ;
            
            // If v1's token is greater, version1 is larger
            if(a > b)
                return 1;
            // If v2's token is greater, version2 is larger
            else if(b > a)
                return -1;
            else
                i++;  // If equal, move to next token
        }

        // If all tokens are equal, versions are same
        return 0;
    }
};
