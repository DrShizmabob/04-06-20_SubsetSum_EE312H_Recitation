#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool sumsTo(uint x[], uint n, uint k, uint v) {
    if(v == 0 && k == 0) {
        return true;
    }
    if(v != 0 && k ==0) {
        return false;
    }
    if (n == 0) {
        return false;
    }
    int res1 = 0;
    if(v >= x[0]) {
        res1 = sumsTo(x + 1, n - 1, k - 1, v - x[0]);
    }
    int res2 = sumsTo(x + 1, n - 1, k ,v);
    return res1 + res2 > 0;

}

int main() {
    uint array[] = {1, 8, 6, 4, 3};
    if(!sumsTo(array, 5, 3, 9)) {
        printf("false");
    }
    if(sumsTo(array, 5, 2, 9)) {
        printf("true");
    }
    return 0;
}
