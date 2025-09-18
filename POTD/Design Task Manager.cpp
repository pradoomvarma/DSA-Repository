class TaskManager {
public:

    unordered_map<int, pair<int, int>> mp;
    set<pair<int, int>> st;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks) {
            int user = it[0];
            int task = it[1];
            int priority = it[2];

            mp[task] = {user, priority};
            st.insert({priority, task});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        st.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [user, priority] = mp[taskId];
        mp[taskId] = {user, newPriority};

        st.erase({priority, taskId});
        st.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto [user, priority] = mp[taskId];
        mp.erase(taskId);
        st.erase({priority, taskId});
    }
    
    int execTop() {
        if(st.empty()) return -1;
        auto [priority, task] = *st.rbegin();
        auto [user, pr] = mp[task];
        rmv(task);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */