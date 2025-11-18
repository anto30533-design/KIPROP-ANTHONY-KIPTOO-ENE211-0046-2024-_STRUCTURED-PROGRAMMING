#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter your full name: ");
    getchar();  // Clear input buffer
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    printf("You entered: %s\n", name);

    int length = strlen(name);
    printf("Length of the string: %d characters\n", length);

    return 0;
}
