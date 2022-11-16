/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        long long r = n;
        long long num = (l+r)/2;
        while(guess(num)==1 || guess(num)==-1){
            if(guess(num)==1 ){
                l = num+1;
            }else if(guess(num)==-1){
                r = num;
            }
            num = (l+r)/2;
        }
        return num;
    }
};