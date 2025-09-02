    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    for (int cs = 1; cs <= T; ++cs) {
        int N, K; cin >> N >> K;
        int B = 2*(N-1) + 1;
        vector<long long> pw(N+1, 1);
        for (int i = 1; i <= N; ++i) pw[i] = pw[i-1] * B;

        vector<long long> dp(pw[N], 0), ndp;
        dp[0] = 1;

        for (int i = 0; i < N; ++i) for (int j = i+1; j < N; ++j) {
            ndp.assign(pw[N], 0);
            for (size_t idx = 0; idx < dp.size(); ++idx) {
                long long v = dp[idx]; if (!v) continue;
                ndp[idx + 2*pw[i]]                 += v;     // (2,0)
                ndp[idx + pw[i] + pw[j]]           += v*2;   // (1,1)
                ndp[idx + 2*pw[j]]                 += v;     // (0,2)
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (size_t idx = 0; idx < dp.size(); ++idx) {
            long long v = dp[idx]; if (!v) continue;
            int mn = INT_MAX, mx = INT_MIN;
            for (int t = 0; t < N; ++t) {
                int s = int((idx / pw[t]) % B);
                mn = min(mn, s); mx = max(mx, s);
            }
            if (mx - mn > K) ans += v;
        }
        cout << "Case #" << cs << ": " << ans << '\n';
    }
}
