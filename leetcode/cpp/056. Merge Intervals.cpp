/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

//每次把数组中的元素与已经存入结果的元素比较，注意cmp函数的类型是约定好的

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        if (intervals.size() <= 1) return intervals;
        
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (result.back().end >= intervals[i].start)
            {
                Interval temp(result.back().start, max(intervals[i].end, result.back().end));
                result.pop_back();
                result.push_back(temp);
            }
            else
            {
                result.push_back(intervals[i]);
            }
            
        }
        
        return result;
    }
    
    static bool cmp (const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
};
