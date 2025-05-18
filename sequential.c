#include<stdio.h>

void main(){
    int size, num, filesize, cnt, curr = 0;
    
    // Input total number of blocks
    printf("Enter number of blocks: ");
    scanf("%d", &size);

    // Initialize disk array to 0 (all blocks free)
    int disk[size];
    for (int i = 0; i < size; i++) {
        disk[i] = 0;  // Mark all blocks as free initially
    }

    // Input number of files
    printf("Enter number of files: ");
    scanf("%d", &num);

    // Process each file
    for (int i = 0; i < num; i++) {
        cnt = 0;  // Flag to indicate if allocation is possible

        // Input file size
        printf("Enter file %d size: ", i + 1);
        scanf("%d", &filesize);

        // Check if there is enough space from current position to allocate the file
        if (size - curr >= filesize) {  // Check if there are enough blocks left
            // Check if the blocks from curr to curr + filesize - 1 are free
            for (int j = curr; j < curr + filesize; j++) {
                if (disk[j] != 0) {  // Block is already occupied
                    cnt = 1;  // Set flag to indicate failure
                    break;
                }
            }
        } else {
            cnt = 1;  // Not enough space left in the disk
        }

        // If file cannot be allocated
        if (cnt == 1) {
            printf("File %d not allocated\n", i + 1);
        } else {
            // Allocate file to the blocks
            for (int k = curr; k < curr + filesize; k++) {
                disk[k] = i + 1;  // Mark block as occupied by file i + 1
            }
            curr = curr + filesize;  // Update the current block to the next free block
            printf("File %d allocated from index %d\n", i + 1, curr - filesize);
        }
    }

    // Display disk allocation status
    printf("\nDisk Allocation Status:\n");
    for (int i = 0; i < size; i++) {
        if (disk[i] == 0) {
            printf("Block %d: Free\n", i);
        } else {
            printf("Block %d: Occupied by File %d\n", i, disk[i]);
        }
    }
}
