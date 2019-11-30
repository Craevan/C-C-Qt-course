#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_DIG 1000
#define MAX_LINE_LENGTH 25

int main() {
    srand(time(NULL));
    FILE *fp;
    char *separator = ", ";
    char *endLine = "\n";
//    char dirName[] = "/home/crevan/Документы/Git-Repositories/GitHub/C-C-Qt-course/src/4/HomeWork/out/out";
    char fileName[150];
    for (int i = 0; i < MAX_FILES; ++i) {
        if (i == 0)
            sprintf(fileName, "%s%s", "/home/crevan/Документы/Git-Repositories/GitHub/C-C-Qt-course/src/4"
                                             "/HomeWork/out/out", ".txt");
        else
            sprintf(fileName, "%s%02d%s", "/home/crevan/Документы/Git-Repositories/GitHub/C-C-Qt-course/src/4"
                                          "/HomeWork/out/out", i, ".txt");
        fp = fopen(fileName, "w");
        for (int j = 1; j <= MAX_DIG; ++j) {
            fprintf(fp, "%d", rand() % 10);
            if (j != MAX_DIG) {
                fputs(separator, fp);
                if (j % MAX_LINE_LENGTH == 0)
                    fputs(endLine, fp);
            }
        }
        fclose(fp);
    }
    return 0;
}
