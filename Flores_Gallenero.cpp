#include <stdio.h>
#include <string.h>
// pre paano ba mag-C?

void fcfs(char *filename) {
    // counters
    int i, j;
    
    // input file
    int x, y, z;
    FILE *fptr;
    fptr = fopen(filename, "r");
    fscanf(fptr, "%d %d %d", &x, &y, &z);

    int procie[y][3];

    for(i = 0; i < y; i++) {
        fscanf(fptr, "%d %d %d", &procie[i][0], &procie[i][1], &procie[i][2]);
    }

    fclose(fptr);

    // // print the processes delete after
    // for(i = 0; i < y; i++) {
    //     for(j = 0; j < 3; j++) {
    //         if (j == 2) {
    //             printf("%d\n", procie[i][j]);
    //         }
    //         else {
    //             printf("%d ", procie[i][j]);
    //         }
    //     }
    // }


    // algo start
    int start_time, end_time, waiting_time;
    int sum_wait = 0;
	
	
    start_time = procie[0][1];
    end_time = start_time + procie[0][2];
    waiting_time = procie[0][1];
    for(i = 0; i < y; i++) {
        if(i > 0) {
            start_time = end_time;
            waiting_time = end_time - procie[i][1];
            end_time = end_time + procie[i][2];
        }
        printf("P[%d] Start Time: %d End Time: %d | Waiting Time: %d\n", procie[i][0], start_time, end_time, waiting_time);
        sum_wait += waiting_time;
    }

    float ave_wait = (sum_wait * 1.0) / (y * 1.0);

    printf("Average Waiting Time: %0.1f\n", ave_wait);

    return;
}

void sjf(char *filename) {
    int i, j;
    
    // input file
    int x, y, z;
    FILE *fptr;
    fptr = fopen(filename, "r");
    fscanf(fptr, "%d %d %d", &x, &y, &z);

    int procie[y][3];

    for(i = 0; i < y; i++) {
        fscanf(fptr, "%d %d %d", &procie[i][0], &procie[i][1], &procie[i][2]);
    }

    fclose(fptr);
    // algo start
    int start_time, end_time, waiting_time;
    int sum_wait = 0;
    int t,k;
	
	for(i = 0; i <y; i++){
    	for(j = y; j > i; j--) {
        if(procie[j-1][2] > procie[j][2]){
                for ( k = 0; k < 3; k ++ ) // you will need to define 'k'
                {
                // Swap all columns
                t = procie[j-1][k];             
                procie[j-1][k] = procie[j][k]; 
				procie[j][k] = t;
                }
        }
    }
}

  // //= print the processes delete after
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
        
    start_time = procie[0][1];
    end_time = start_time + procie[0][2];
    waiting_time = procie[0][1];
    for(i = 0; i < y; i++) {
        if(i > 0) {
            start_time = end_time;
            waiting_time = end_time - procie[i][1];
            end_time = end_time + procie[i][2];
        }
        printf("P[%d] Start Time: %d End Time: %d | Waiting Time: %d\n", procie[i][0], start_time, end_time, waiting_time);
        sum_wait += waiting_time;
    }

    float ave_wait = (sum_wait * 1.0) / (y * 1.0);

    printf("Average Waiting Time: %0.1f\n", ave_wait);
     printf("SJF");

    return;
}

void srtf(char *filename) {
    int i, j, x, y, z;
}

void rr(char *filename) {
    // counters
    int i, j;
    
    // input file
    int x, y, z;
    FILE *fptr;
    fptr = fopen(filename, "r");
    fscanf(fptr, "%d %d %d", &x, &y, &z);

    int procie[y][3];

    for(i = 0; i < y; i++) {
        fscanf(fptr, "%d %d %d", &procie[i][0], &procie[i][1], &procie[i][2]);
    }

    fclose(fptr);

    // copy burst times
    int burst_times[y];

    for (i = 0; i < y; i++) {
        burst_times[i] = procie[i][2];
    }

    //  // show copied burst times
    // for (i = 0; i < y; i++) {
    //     printf("%d\n", burst_times[i]);
    // }

    float waiting_times[y];
    int complete[y];
    int total_procie = y;
    int total_time = 0;
    int start_time, end_time, waiting_time, turn_around_time;
    int sum_wait = 0;
    float ave_wait = 0;

    for (i = 0; i < y; i++) {complete[i] = 0;}

    while (total_procie) {
        for (i = 0; i < y; i++) {
            start_time = total_time;

            if (burst_times[i]) {
                if (burst_times[i] <= z) {
                    end_time = total_time + burst_times[i];
                    burst_times[i] = 0;
                    total_time = end_time;
                    complete[i] = total_time;
                    total_procie--;
                }
                else {
                    end_time = total_time + z;
                    burst_times[i] -= z;
                    total_time = end_time;

                    printf("P[%d] Start Time: %d End Time: %d\n", procie[i][0], start_time, end_time);
                }
            }

            if (complete[i]) {
                turn_around_time = complete[i] - procie[i][1];
                waiting_time = turn_around_time - procie[i][2];
                ave_wait += waiting_time;

                printf("P[%d] Start Time: %d End Time: %d | Waiting Time: %d\n", procie[i][0], start_time, end_time, waiting_time);

                complete[i] = 0;
            }
        }
    }

    ave_wait = ave_wait / (y * 1.0);

    printf("Average Waiting Time: %0.1f\n", ave_wait);

    return;
    
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

    // printf("%d %d %d\n", x, y, z); // delete lol
    switch(x) {
        case 0: fcfs(filename); break;
        case 1: sjf(filename); break;
        case 2: srtf(filename); break;
        case 3: rr(filename); break;
    }

    return 0;
}
