#include <stdio.h>
#include <stdlib.h>

int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    
    int *res = (int *)malloc((n + 1) * sizeof(int));
    if (res == NULL) {
        return -1;
    }

    res[0] = 0;
    if (n > 0) {
        res[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            res[i] = res[i / 2];
        } else {
            int ev = i / 2;
            res[i] = res[ev] + res[ev + 1];
        }
    }

    int max_val = 0;
    for (int i = 0; i <= n; i++) {
        if (res[i] > max_val) {
            max_val = res[i];
        }
    }

    free(res);
    return max_val;
}

int main() {
    int n = 7;
    int result = getMaximumGenerated(n);
    printf("The maximum generated value for n = %d is %d\n", n, result);
    return 0;
}
