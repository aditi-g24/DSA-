class Solution {
public:
    struct Result {
        long long score;
        vector<int> indices;
    };

    int n;
    vector<vector<int>> a;
    vector<int> nxt;
    vector<vector<Result>> dp;
    vector<vector<bool>> vis;

    bool better(Result A, Result B) {
        if (A.score != B.score)
            return A.score > B.score;

        sort(A.indices.begin(), A.indices.end());
        sort(B.indices.begin(), B.indices.end());

        return A.indices < B.indices;
    }

    Result solve(int i, int k) {
        if (i == n || k == 4)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        Result skip = solve(i + 1, k);

        Result take = solve(nxt[i], k + 1);
        take.score += a[i][2];
        take.indices.push_back(a[i][3]);

        return dp[i][k] = better(take, skip) ? take : skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<int> starts;
        for (auto &x : a)
            starts.push_back(x[0]);

        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = lower_bound(
                starts.begin(),
                starts.end(),
                a[i][1] + 1
            ) - starts.begin();
        }

        dp.assign(n, vector<Result>(5));
        vis.assign(n, vector<bool>(5, false));

        Result ans = solve(0, 0);

        sort(ans.indices.begin(), ans.indices.end());

        return ans.indices;
    }
};