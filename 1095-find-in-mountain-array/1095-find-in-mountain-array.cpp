/**
 * // This is MountainArray's API interface.
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        
        int s = 0, e = n - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }

        int peak = s;

        
        s = 0;
        e = peak;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            int x = mountainArr.get(mid);

            if(x == target) {
                return mid;
            }
            else if(x < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        
        s = peak + 1;
        e = n - 1;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            int x = mountainArr.get(mid);

            if(x == target) {
                return mid;
            }
            else if(x > target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return -1;
    }
};