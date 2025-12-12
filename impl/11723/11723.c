#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    
    bool set[20] = { 0, };

    int N;
    char cmd[7];
    int num;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", cmd);

        if (!strcmp(cmd, "all")) {
            memset(set, true, sizeof(char) * 20);
        }
        else if (!strcmp(cmd, "empty")) {
            memset(set, false, sizeof(char) * 20);
        }
        else {
            scanf("%d", &num);
            if (!strcmp(cmd, "add")) {
                set[num - 1] = true;
            }
            else if (!strcmp(cmd, "remove")) {
                set[num - 1] = false;
            }
            else if (!strcmp(cmd, "check")) {
                printf("%d\n", set[num - 1]);
            }
            else if (!strcmp(cmd, "toggle")) {
                set[num - 1] = !set[num - 1];
            }
        }

    }

    return 0;
}