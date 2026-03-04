
#include <stdio.h>
#include <string.h>

void addCommas(int number, char *formatted) {
    char buffer[20];
    sprintf(buffer, "%d", number);

    int length = strlen(buffer);
    int commaCount = (length - 1) / 3;

    int i, j;
    for (i = 0, j = 0; i < length; i++, j++) {
        formatted[j] = buffer[i];
        if ((length - i - 1) % 3 == 0 && commaCount > 0) {
            j++;
            formatted[j] = ',';
            commaCount--;
        }
    }
    formatted[j] = '\0';
}

int main() {
    int number = 100000;
    char formatted[20];
    
    addCommas(number, formatted);
    
    printf("%s\n", formatted);
    
    return 0;
}
