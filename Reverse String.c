#define MAXLINE 20
int reverse(char s2[]);

main() {

    char hold [MAXLINE];
    int i = 0;
    int c;

    while ((c = getchar()) != EOF) {
        while (c != '\n' && c != EOF) {
            hold[i] = c;
            ++i;
            c = getchar();
        }
        reverse (hold);
        memset(&hold[0], 0, sizeof(hold));
        printf("\n");
        i = 0;
    }

}

int reverse (char s[]) {

    int i, m;
    int x = 0;
    int length = numberOfCharsInArray(s);
    char result[length];

    //printf ("%d", length);

    for (i = length; i != 0; --i) {
        result[i] = s[x];
        //printf("x = %d\n", x);
        //printf("i = %d\n", i);
        //printf("result[i] = %d\n", result[i]);
        //printf("s[x] = %d\n\n", s[x]);
        ++x;
    }

    for (m = 1; m < length + 1; ++m) {
        //printf("%d = \n",m);
        //printf("result[x] = %d\n\n", result[m]);
        putchar(result[m]);
    }

    return 0;
}

int numberOfCharsInArray(char* array) {
    return strlen(array);
}
 
