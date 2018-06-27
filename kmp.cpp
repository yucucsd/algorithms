void getNext(string needle, int* next){
    int i = 0, k = -1; // k is actually the longest shared prefix and suffix for s[0~i] , k = next[i]
    while (i < needle.size() - 1){
        while(k != -1 && needle[i] != needle[k]){
            k = next[k];
        }
        next[++i] = ++k;
    }
}
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    int* next = new int[needle.size()];
    next[0] = -1;
    getNext(needle, next);
    int j = 0, i = 0;
    int pos = -1;
    while (i < haystack.size()){
        if (haystack[i] == needle[j]){
            i++, j++;
            if (j == needle.size()){
                pos = i - needle.size();
                break;
            }
        }
        else{
            if (next[j] != -1){
                j = next[j];
            }else{
                i++;
            }
        }
    }
    return pos;
}