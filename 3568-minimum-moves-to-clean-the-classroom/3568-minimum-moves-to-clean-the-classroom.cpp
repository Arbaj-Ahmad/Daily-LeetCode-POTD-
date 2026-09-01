class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> lampId(m, vector<int>(n, -1));
        int sx = 0, sy = 0, cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') {
                    sx = i; sy = j;
                } else if (c == 'L') {
                    lampId[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int fullMask = (1 << cnt) - 1;
        // vis[i][j][e][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false))));

        queue<array<int,4>> q; // {row, col, energy, mask}
        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [i, j, curEnergy, mask] = q.front();
                q.pop();

                if (mask == 0) return ans;
                if (curEnergy <= 0) continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (classroom[ni][nj] == 'X') continue;

                    int nextEnergy = (classroom[ni][nj] == 'R') ? energy : curEnergy - 1;
                    int nextMask = mask;
                    if (classroom[ni][nj] == 'L' && lampId[ni][nj] != -1) {
                        nextMask &= ~(1 << lampId[ni][nj]);
                    }

                    if (!vis[ni][nj][nextEnergy][nextMask]) {
                        vis[ni][nj][nextEnergy][nextMask] = true;
                        q.push({ni, nj, nextEnergy, nextMask});
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};