#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        fprintf(stderr, "usage: %s file [file2...]\n", argv[0]);
        return 1;
    }

    int status = 0;

    for (int i = 1; i < argc; i++) {
        if (-1 == remove(argv[i])) {
            fprintf(stderr, "%s: %s: %s\n", argv[0], strerror(errno), argv[i]);
            status = 1;
        }
    }

    return status;
}
