class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(),folder.end());
        vector<string>result;
        result.push_back(folder[0]);
        for (int i=1; i<folder.size(); i++){  //int i =1, because first folder is 0 and is already pushed
            string currentfolder=folder[i];
            string lastfolder=result.back() + '/';
          

            if(currentfolder.find(lastfolder)!=0){  //should start with 0 index..should be matched first with zero index
                result.push_back(currentfolder);
            }
        }
        return result;
    }
};