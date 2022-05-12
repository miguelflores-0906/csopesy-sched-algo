#include <stdio.h>
#include <string.h>
// pre paano ba mag-C?

void fcfs(char *filename) {
    int i, j, x, y, z;
    FILE *fptr;
    fptr = fopen(filename, "r");
    fscanf(fptr, "%d %d %d", &x, &y, &z);

    int procie[y][3];

    for(i = 0; i < y; i++) {
        fscanf(fptr, "%d %d %d", &procie[i][0], &procie[i][1], &procie[i][2]);
    }

    fclose(fptr);

    // print the processes
    for(i = 0; i < y; i++) {
        for(j = 0; j < 3; j++) {
            if (j == 2) {
                printf("%d\n", procie[i][j]);
            }
            else {
                printf("%d ", procie[i][j]);
            }
        }
    }

    return;
}

void sjf(char *filename) {
    int i, j, x, y, z;
}

void srtf(char *filename) {
    int i, j, x, y, z;
}

void rr(char *filename) {
    int i, j, x, y, z;
}

int main() {
    FILE *ptr;

    int x, y, z;
    int i, j;
    char filename[50];
    char ext[] = ".txt";

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    strcat(filename, ext);

    ptr = fopen(filename, "r");

    if (ptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(ptr, "%d %d %d", &x, &y, &z);
    fclose(ptr);

    printf("%d %d %d\n", x, y, z); // delete lol
    switch(x) {
        case 0: fcfs(filename); break;
        case 1: sjf(filename); break;
        case 2: srtf(filename); break;
        case 3: rr(filename); break;
    }

    return 0;
}