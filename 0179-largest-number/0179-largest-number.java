class Solution {

    public String largestNumber(int[] nums) {
        List<String> ls = new ArrayList<>();
        for(int n : nums) {
            ls.add(String.valueOf(n));
        }

        Collections.sort(ls, (a, b) -> (b+a).compareTo(a+b));

        String res = "";
        for(String str : ls) {
            res += str;
        }
        int i = 0;
        while(i<res.length() && res.charAt(i) == '0') {
            i++;
        }

        if(i == res.length()) {
            return "0";
        }
        // else{
            return res.substring(i);
        // }

        // return res;
    }
}