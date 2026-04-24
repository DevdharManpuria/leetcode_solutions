class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int blank=0;
        int l=0;
        int r=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') l++;
            else if(moves[i]=='R') r++;
            else blank++;
        }
        return (abs(l-r) + blank);
    }
};