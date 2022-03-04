class Solution {
public:
    vector<string> answer;
    void DFS(string start, map<string, vector<string>>& m){
        while(!m[start].empty()){
            string next = m[start][0];
            m[start].erase(m[start].begin());
            DFS(next, m);
            answer.push_back(next);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> m;
        for(auto fly:tickets){
            m[fly[0]].push_back(fly[1]);
        }
        for(auto &fly:m){
            sort(fly.second.begin(), fly.second.end());
        }

        DFS("JFK", m);
        answer.push_back("JFK");
        reverse(answer.begin(), answer.end());
        return answer;
    }
};