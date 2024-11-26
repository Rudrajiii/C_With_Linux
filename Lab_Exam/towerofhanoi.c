#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int num_of_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_of_disks);

    printf("The sequence of moves is:\n");
    tower_of_hanoi(num_of_disks, 'A', 'B', 'C');

    return 0;
}
