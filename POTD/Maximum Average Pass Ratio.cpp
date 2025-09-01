class Solution {
public:

    // Greedy fails so find max delta(improvement) and assign to that class -> maxHeap 

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < classes.size(); ++i) {
            double cr = (double)classes[i][0] / (double)classes[i][1];
            double pr = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
            pq.push({pr - cr, i});
        }

        while(!pq.empty() && extraStudents) {
            auto [maxi, i] = pq.top();   pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double cr = (double)classes[i][0] / (double)classes[i][1];
            double pr = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
            extraStudents--;
            pq.push({pr - cr, i});
        }

        int n = pq.size();
        double avg = 0.0;
        for(int i = 0; i < classes.size(); ++i) {
            avg += (double)classes[i][0] / (double)classes[i][1];
        }

        avg /= 1.0 * n;
        return avg;
    }
};