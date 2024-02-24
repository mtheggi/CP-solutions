class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map <int ,vector<pair<int ,int >>> graph;  
        for(auto i : meetings ){
            graph[i[0]].push_back(make_pair(i[1] , i[2])); 
            graph[i[1]].push_back(make_pair(i[0] , i[2]));
        } 
        vector<int> time(n , INT_MAX); 
        time[0] =0 ; 
        time[firstPerson] =0 ;
        queue<pair<int ,int >> q; 
        q.push(make_pair(firstPerson , 0)); 
        q.push(make_pair(0, 0));

        while(q.size()){
            pair<int ,int > front = q.front(); 
            q.pop(); 
            int meetingTime = front.second , per = front.first; 
            for(auto ch : graph[per]) {                
                if(meetingTime <= ch.second && ch.second < time[ch.first]){
                    time[ch.first] = ch.second;
                    q.push(ch); 
                }
            }
        }
        vector<int> ans; 
        for(int i =0 ;i < n ; i++) {
            if(time[i] != INT_MAX) ans.push_back(i);
        }
        return ans ;
    }
};
