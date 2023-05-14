#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int sumCharacter(FILE *fp) {
    int count = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        count++;
    }

    return count;
}

int sumWord(FILE *fp) {
    int count = 0;
    int c;
    int is_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ' || c == ',') {
            is_word = 0;
        } else if (!is_word) {
            count++;
            is_word = 1;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int count;
    char *type;
    char *filename;

    type = argv[1];

    if (argc == 2) {
        filename = "file.txt";
    } else {
        filename = argv[2];
    }

    fp = fopen(filename, "r");

    if (strcmp(type, "-c") == 0) {
        count = sumCharacter(fp);
        printf("字符数: %d\n", count);
    } else if (strcmp(type, "-w") == 0) {
        count = sumWord(fp);
        printf("单词数: %d\n", count);
    }

    fclose(fp);

    return 0;
}


