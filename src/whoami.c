#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(void) {
    struct passwd* pw;
    uid_t uid;

    uid = geteuid();
    pw = getpwuid(uid);
    if (!pw) {
        perror("getpwuid");
        return 1;
    }

    puts(pw->pw_name);

    return 0;
}
