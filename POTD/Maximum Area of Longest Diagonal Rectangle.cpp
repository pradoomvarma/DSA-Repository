class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n = dim.size();
        double maxi = INT_MIN;
        int area = INT_MIN;

        for(int i = 0; i < n; ++i) {
            int l = dim[i][0];
            int w = dim[i][1];
            double diagLen = sqrt(l * l + w * w);

            if(diagLen > maxi) {
                maxi = diagLen;
                area = l * w;
            }
            else if(diagLen == maxi) {
                area = max(area, l * w);
            }
        }

        return area;
    }
};