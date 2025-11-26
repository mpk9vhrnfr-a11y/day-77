#include <stdio.h>
int main(void) {
    FILE *in, *out;
    char ch;

    in = fopen("input.txt", "r");
    if(in == NULL) {
        printf("Unable to open input.txt\n");
        return 0;
    }

    out = fopen("output.txt", "w");
    if(out == NULL) {
        printf("Unable to open output.txt\n");
        fclose(in);
        return 0;
    }

    while((ch = fgetc(in)) != EOF) {
        if(ch >= 'a' && ch <= 'z')
            ch = ch - 32;
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    printf("Conversion complete.\n");
    return 0;
}

