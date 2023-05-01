#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *fp;
    char filename[100];
    char line[MAX_LINE_LENGTH];
    int char_count = 0;
    int word_count = 0;
    int i;

    printf("Enter the name of the file to count: ");

    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // 统计字符数
        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n' && line[i] != '\r') {
                char_count++;
            }
        }

        // 统计单词数
        i = 0;
        while (line[i] != '\0') {
            // 跳过空格和制表符
            while (isspace(line[i])) {
                i++;
            }

            // 找到单词
            if (line[i] != '\0') {
                word_count++;
            }

            // 继续寻找下一个单词
            while (line[i] != '\0' && !isspace(line[i])) {
                i++;
            }
        }
    }

    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);

    fclose(fp);

    return 0;
}

