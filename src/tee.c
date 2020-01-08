#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TEE_BUF_SIZE
#define TEE_BUF_SIZE 256
#endif

int main(int argc, char** argv) {
    FILE* outfile = NULL;
    if (argc > 1) {
        outfile = fopen(argv[1], "w");
        if (NULL == outfile) {
            perror(argv[1]);
            return 1;
        }
    }

    char buf[TEE_BUF_SIZE] = {0};
    while (NULL != fgets(buf, TEE_BUF_SIZE, stdin)) {
        if (EOF == fputs(buf, stdout)) {
            fprintf(stderr, "%s: stdout: EOF\n", argv[0]);
            return 1;
        } else {
            fflush(stdout);
        }
        if (NULL != outfile) {
            if (EOF == fputs(buf, outfile)) {
                if (ferror(outfile)) {
                    fprintf(stderr, "%s: %s: %s\n", argv[0], argv[1], strerror(ferror(outfile)));
                } else {
                    fprintf(stderr, "%s: %s: EOF\n", argv[0], argv[1]);
                }
                return 1;
            } else {
                fflush(outfile);
            }
        }
    }

    if (NULL != outfile) {
        fclose(outfile);
    }

    return 0;
}
