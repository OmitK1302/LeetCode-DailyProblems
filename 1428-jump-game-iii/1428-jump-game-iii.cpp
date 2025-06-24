class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>que;
        que.push(start);

        int n = arr.size();
        vector<bool>visited(n, false);
        visited[start] = true;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            if(arr[curr] == 0) return true;

            if(curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) {
                que.push(curr - arr[curr]);
                visited[curr - arr[curr]] = true;
            }
            if(curr + arr[curr] < arr.size() && curr + arr[curr]) {
                que.push(curr + arr[curr]);
                visited[curr + arr[curr]] = true;
            }
        }

        return false;
    }
};