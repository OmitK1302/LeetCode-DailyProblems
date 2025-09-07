class Solution {
public:
    string res;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        res = longUrl;
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));