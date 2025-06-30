class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        int boats=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                j--;
                i++;
            }
            else{
                j--;

            }
            boats +=1;
        }
      
        return boats;
    }
};