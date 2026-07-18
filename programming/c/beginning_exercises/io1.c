#include <stdio.h>
#include <string.h>
#define MAX 34 // 2 extra for \n and \0

int main(void) {

    char str[MAX] = "\0";
    char *ch = NULL;

    printf("Type a string (max of 32 characters): ");

    while (1 == 1) {
        if (fgets(str, MAX, stdin) == NULL) {
            printf("Error getting string.\n");
            return 1;
        }

        // to remove the "\n"
        ch = strchr(str, '\n');
        if (ch != NULL) {
            ch[0] = '\0';

            break;
        } else { // \n not found. Must clear input before carrying on
            int temp = '\0';
            while (1 == 1) {
                temp = fgetc(stdin);
                if (temp == '\n' || temp == EOF) {
                    printf("Input too big. Type a max of 32 characters: ");
                    break;
                }
            }
        }
    }

    printf("%s\n", str);

    return 0;
}

