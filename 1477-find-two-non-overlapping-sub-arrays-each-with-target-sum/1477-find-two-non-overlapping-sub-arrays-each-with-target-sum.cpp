 class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> post; // 'pos' ko 'post' kar diya
        post[0] = -1;
        int n = arr.size();
        int s = 0;
        int ans = n + 1;
        int minL = n;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (post.count(s - target)) { // 'pos' ko 'post' kar diya
                int j = post[s - target]; // 'pos' ko 'post' kar diya
                int l = i - j;
                ans = min(ans, l + (j == -1 ? n : arr[j]));
                minL = min(minL, l);
            }
            arr[i] = minL;
            post[s] = i; // 'pos' ko 'post' kar diya
        }

        return ans == n + 1 ? -1 : ans;
    }
};
