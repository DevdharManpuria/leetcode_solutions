class Interval {
public:
    int start, end;
    Interval(const int _start, const int _end) : start(_start), end(_end) {}  
};

class Solution {
private:
    vector<Interval> getIntervals(const vector<vector<int>>& rectangles, const int isY) {
        vector<Interval> intervals;
        for(const vector<int>& rectangle : rectangles)
            intervals.emplace_back(rectangle[0 + isY], rectangle[2 + isY]);
        
        sort(
                intervals.begin(), intervals.end(), 
                [](const Interval& a, const Interval& b) {
                    return a.start < b.start;
                }
            );
        
        return intervals;
    }

    bool checkValid(const vector<Interval> intervals) {
        vector<Interval> mergedIntervals = {intervals[0]};
        for(int i = 1; i < intervals.size(); i++) {
            const Interval& interval = intervals[i];
            int& end = mergedIntervals.back().end;
            if(end <= interval.start) mergedIntervals.push_back(interval);
            else end = max(end, interval.end);
        }
        return mergedIntervals.size() >= 3;
    }
public:
    bool checkValidCuts(const int n, const vector<vector<int>>& rectangles) {
        return checkValid(getIntervals(rectangles, 0)) || checkValid(getIntervals(rectangles, 1));
    }
};