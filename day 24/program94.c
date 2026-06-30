#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void compressString(const char *src, char *dest) {
    int len = strlen(src);
    
   
    if (len == 0) {
        dest[0] = '\0';
        return;
    }

    int destIdx = 0;

    for (int i = 0; i < len; i++) {
        
        dest[destIdx++] = src[i];

       
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }


        int charsWritten = sprintf(&dest[destIdx], "%d", count);
        destIdx += charsWritten;
    }


    dest[destIdx] = '\0';
}

int main() {
    char source[] = "AAAABBBCCDAA";
    
    
    char compressed[2 * sizeof(source)]; 

    compressString(source, compressed);

    printf("Original String:   %s\n", source);
    printf("Compressed String: %s\n", compressed);

    return 0;
}

