#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (isatty(1)) {
        puts(ttyname(1));
    } else {
        return 1;
    }

    return 0;
}
