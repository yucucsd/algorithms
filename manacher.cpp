string longestPalindrome(string s) {
    string t = "#";
    //all palindrome should be of odd length 
    for (int i = 0; i < s.size(); i++){
        t += s[i];
        t += '#';
    }
    string ret = "";
    int* p = new int[t.size()];
    int r = 0; // right point of the rightest palindrome
    int mid = 0; // mid point of the rightest palindrome
    int maxmid = 0;
    int maxlength = 1;
    p[0] = 1;
    for (int i = 0; i < t.size(); i++){
        p[i] = r > i ? min(p[2 * mid - i], r - i) : 1; // if i's symmetric position (2*mid-i) has been calculated 
        while (i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]]){
            p[i]++;                
        }
        if (i + p[i] - 1 > r){
            r = i + p[i] - 1;
            mid = i;
        }
        if (p[i] > maxlength){
            maxmid = i;
            maxlength = p[i];
        }
    }
    ret.append(s.begin() + ((maxmid - maxlength + 1)/2), s.begin() + ((maxmid + maxlength)/2));
    return ret;
}