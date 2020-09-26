#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>

class Solution1 {
public:
    bool is_perfect_square(double x) {
        // check if the number is perfect square
        double sqrt_num = sqrt(x);
        return ((sqrt_num - floor(sqrt_num)) == 0); 
    }

    int num_squares(int n) { // n = 12
        // if n == 1, 4, 9, 16 ...
        if(is_perfect_square(n)) {
            printf("input is perfect square\n");
            return 1;
        }

        int tmp = n;
        int res = n;
        int count = 0;
        for(int j = n ; j > 0; j--) {
            tmp   = n;
            count = 0;
            printf("===========\n");
            for(int i = j ; i > 0 ; i--) {
                if(is_perfect_square(i)) {
                    if(count == 0){
                        // avoid to use the same perfect square composition
                        // example: 
                        // first composition is 9 + 1 + 1 + 1, do not use 9 as the first number again for the next try
                        j = i - 1;
                    }
                    // record how many num of perfect square
                    count++;
                    tmp = tmp - i;
                    printf("candidate: %d\n", i);

                    // start from new tmp
                    i = tmp + 1;
                }
                if (tmp < 0) {
                    printf("fail, try next\n");
                    break;
                } else if(tmp == 0) {
                    // update result
                    if (res > count) {
                        printf("update result, count:%d\n", count);
                        res = count;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    int input = atoi(argv[1]);
    Solution1 *s1 = new Solution1();
    int res = s1 -> num_squares(input);
    printf("result: %d\n", res);
}