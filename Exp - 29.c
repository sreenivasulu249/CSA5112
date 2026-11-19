
#include <stdio.h>

int main() {
    int block = 1024;
    int lane = 64;
    int capacity = 1600 - block;
    int zero_lanes = capacity / lane;
    int total_lanes = 1600 / lane;

    printf("Block size: %d bits\n", block);
    printf("Capacity: %d bits\n", capacity);
    printf("Total lanes: %d\n", total_lanes);
    printf("Zero lanes initially: %d\n", zero_lanes);

    printf("All capacity lanes receive nonzero bits after ");
    printf("%d message blocks.\n", 1);

    return 0;
}
