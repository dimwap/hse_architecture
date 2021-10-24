#include <string.h>
#include "../headers/container.hpp"
#include "time.h"

int main(int argc, char *argv[]) {
    clock_t time_start = clock();

    if (argc != 5) {
        printf("Incorrect amount of arguments");
        return 1;
    }

    printf("Start\n");
    Container c;


    if (!strcmp(argv[1], "-f")) {
        FILE *inputFile = fopen(argv[2], "r");
        if (inputFile == NULL) {
            printf("Incorrect input file");
            return 1;
        }
        c.In(inputFile);
    } else if (!strcmp(argv[1], "-n")) {
        int size = strtol(argv[2], &argv[2], 0);

        srand(time(NULL));
        c.InRnd(size);
    } else {
        printf("Incorrect flag");
        return 1;
    }

    FILE *outputFile1;
    if (!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("File opening failure");
        return -1;
    }

    fprintf(outputFile1, "Filled container:\n");
    c.Out(outputFile1);
    fclose(outputFile1);

    FILE *outputFile2;
    if (!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("File opening failure");
        return -1;
    }

    c.shakeSort();
    c.Out(outputFile2);
    fclose(outputFile2);

    printf("Stop\n");
    printf("Seconds: %f\n", ((double) (clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}
