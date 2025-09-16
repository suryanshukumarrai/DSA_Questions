class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;  // avoids overflow
    }

public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::vector<long long> ans;  // use long long internally
        for (int num : nums) {
            ans.push_back(num);

            while (ans.size() > 1 && gcd(ans.back(), ans[ans.size() - 2]) > 1) {
                long long a = ans.back();
                ans.pop_back();
                long long b = ans.back();
                ans.pop_back();

                ans.push_back(lcm(a, b));
            }
        }
        // Convert back to int (safe if problem guarantees within range)
        return std::vector<int>(ans.begin(), ans.end());
    }
};
