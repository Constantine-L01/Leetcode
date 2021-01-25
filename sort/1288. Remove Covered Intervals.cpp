Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

// this solution will directly get the result
class Solution {
    public int removeCoveredIntervals(int[][] A) {
        int res = 0, left = -1, right = -1;
        Arrays.sort(A, (a, b) -> a[0] - b[0]);
        for (int[] v : A) {            
            System.out.println("left: " + left + " right: " + right);
            System.out.println("v[0]: " + v[0] + " v[1]: " + v[1]);
            if (v[0] > left && v[1] > right) {
                left = v[0];                
                ++res;
                System.out.println("res: " + res);
            }
            right = Math.max(right, v[1]);
        }
        return res;
    }
}
                                       

// this solution will count the number of overlapped interval then get the result by deducting the count.                                        
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] != b[0]){
            return a[0] < b[0];
        }else{
            return a[1] > b[1];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // - Sort the intervals in increasing order of starting point
        // - If starting points are same, in decreasing order of ending point
        sort(intervals.begin(), intervals.end(), comp);
        
        int _max = INT_MIN;
        int count = 0;
        
        // - Compare the ending points in the sorted intervals
		
        // - If at any index the ending point is less than the current maximum ending point
        //   that interval is the included one 
		//   (remember the starting point of the current is already greater than that
		//   of all the previous intervals, so now when the ending point is lesser than the current max ending point
		//   it means that interval is included in atleast one of the previous intervals)
		
        // - Count the included ones and return size()-count
		
		// Note: If the starting index are equal, we sorted according to decreasing ending index so that it can be
		// counted too as an included one
		
        for (int i = 0; i<intervals.size(); i++){
            if (intervals[i][1] <= _max){
                count ++;
            }else{
                _max = intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};                                       
