#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        return 1;
    }
    
    int t;

    t = atoi(argv[1]);

    if (t <= 0) {
        return 1;
    }

    sleep((unsigned int)t);

    return 0;
}
