#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        fprintf(stderr, "Please provide a file.\n");
        return 1;
    }

    FILE* infile = fopen(argv[1], "rb");
    if (NULL == infile) {
        perror("fopen");
        return 1;
    }

    char c, l;
    while (EOF != (c = fgetc(infile))) {
        printf("%c", c);
        l = c;
    }

    if (EOF == c && '\n' != l) {
        printf("\n");
    }

    fclose(infile);

    return 0;
}
