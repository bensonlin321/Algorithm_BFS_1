#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>

class Solution2 {
public:
    bool is_perfect_square(double x) {
        // check if the number is perfect square
        double sqrt_num = sqrt(x);
        return ((sqrt_num - floor(sqrt_num)) == 0); 
    }

    int num_squares(int n) {
        // init structure
        std::unordered_set<int> visited;
        std::queue<int> todo;

        todo.push(0);
        visited.insert(0);

        printf("todo size: %d, visited size: %d\n", todo.size(), visited.size());

        // Start BFS
        int steps = 0;
        while(!todo.empty()) {
            steps++;
            printf("===== setps:%d =====\n", steps);
            for(int sz = todo.size() - 1; sz >= 0; --sz) {
                // Retrieve current int
                int cur = todo.front();
                todo.pop();

                for(int j = 1; j < n; ++j) {
                    int sum = cur + j * j;
                    printf("sum: %d, j:%d\n", sum, j);

                    if(sum == n) { 
                        printf("sum(%d) == n(%d)\n", sum, n);
                        return steps;
                    } else if(sum > n) {
                        printf("sum(%d) > n(%d)\n", sum, n);
                        break;
                    } else {
                        if(!visited.count(sum)) {
                            printf("new node: %d\n", sum);
                            todo.push(sum);
                            visited.insert(sum);
                        }
                    }
                }
                printf("visited:\n");
                for (auto itr = visited.begin(); itr != visited.end(); ++itr) {
                    printf("%d ", *itr);
                }
                printf("\n");
            }
        }

        return steps;
    }
};

int main(int argc, char *argv[]) {
    int input = atoi(argv[1]);
    Solution2 *s1 = new Solution2();
    int res = s1 -> num_squares(input);
    printf("result: %d\n", res);
}