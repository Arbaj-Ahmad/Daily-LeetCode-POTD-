class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int onedelete = arr[0];
        int nodelete = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            // int prev_nodelete = nodelete; // to save previous value and
            // prevent from overwrittrn .

            // nodelete = max(nodelete + arr[i], arr[i]);


            onedelete = max(nodelete, onedelete + arr[i]);
            nodelete = max(nodelete + arr[i], arr[i]);

            ans = max({ans, onedelete, nodelete});
        }
        return ans;
    }
};