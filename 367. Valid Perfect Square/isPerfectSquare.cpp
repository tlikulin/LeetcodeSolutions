class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = min(num, 46340);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid*mid == num)
                return true;
            if (mid*mid < num)
                left = mid + 1;
            else
                right = mid - 1;                
        }
        return false;
    }
};