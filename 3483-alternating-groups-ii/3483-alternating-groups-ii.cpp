class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0;  

        int count = 0;
        int isAlternating = 1; 

        for (int i = 1; i < k; i++) {
            if (colors[i] == colors[i - 1]) {
                isAlternating = 0;
                break;
            }
        }
        if (isAlternating) count++;

        for (int i = 1; i < n; i++) {
            int prev = (i - 1) % n;
            int next = (i + k - 1) % n;

            if (colors[next] == colors[(next - 1 + n) % n]) {
                isAlternating = 0;
            }
            if (colors[prev] == colors[(prev + 1) % n]) {
                isAlternating = 1;
                for (int j = 1; j < k; j++) {
                    if (colors[(i + j) % n] == colors[(i + j - 1) % n]) {
                        isAlternating = 0;
                        break;
                    }
                }
            }

            if (isAlternating) count++;
        }

        return count;
    }
};
