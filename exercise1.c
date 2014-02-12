//
//  ch01exercises.c
//  testingC
//
//  Created by Dasgupta, Nataraj on 2/3/14.
//  Copyright (c) 2014 Dasgupta, Nataraj. All rights reserved.
//

// Exercises Chapter 1

#include <stdio.h>
#include <stdbool.h>

// 1-3 and 1-4
// 1-3. Modify the temperature conversion program to print a heading above the table.
// 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.


 main() {
 
 int i;
 float fahr = 0.0;
 
 for (i = 0; i <= 100; i = i + 20) {
 fahr = ((i/5)*9) + 32;
 printf("Celcius: %3d \t Fahrenheit: %3.0f\n", i, fahr);
 }
 }
 ////
 

 // 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
 
 main() {
 
 int i;
 float fahr = 0.0;
 
 for (i = 100; i >= 0; i = i - 20) {
 fahr = ((i/5)*9) + 32;
 printf("Celcius: %3d \t Fahrenheit: %3.0f\n", i, fahr);
 }
 }
 ////
 
 
 // 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 
 main() {
 
 int c;
 
 while ((c=getchar()) != EOF) {
 // do nothing
 }
 putchar(c);
 printf("\n");
 }
 ////
 
 
 // 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 
 main() {
 int c,test;
 bool result;
 while ((c=getchar()) != EOF) {
 //do nothing
 }
 result = (putchar(c)==0);
 if (result==0 || result==1) {
 printf("\nIt is 0 or 1\n");
 }
 }
 
 
 // 1-7. Write a program to print the value of EOF.
 
 main() {
 printf("%d\n",EOF);
 }
 
 
 // 1-8. Write a program to count blanks, tabs, and newlines.
 
 main() {
 
 int bl, tabs, newlines;
 bl = tabs = newlines = 0;
 int c;
 while ((c=getchar()) != EOF) {
 if (c=='\t') ++tabs;
 else if (c==' ') ++bl;
 else if (c=='\n') ++newlines;
 }
 
 printf ("\nBlanks: %3d, Tabs: %3d, Newlines: %3d\n", bl, tabs, newlines);
 
 }
 
 
 // 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 
 main() {
 
 int c;
 
 while ((c = getchar()) != EOF) {
 if (c == ' ') {
 putchar(c);
 while ((c=getchar()) == ' ') {
 //do nothing
 }
 }
 putchar (c);
 }
 
 }
 
 
 // 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
 
 main() {
 
 int c;
 
 while ((c = getchar()) != EOF) {
 if (c == '\\') printf("\\\\");
 else if (c == '\t') printf("\\t");
 else if (c == '\n') printf("\\n");
 else putchar(c);
 }
 
 }
 
 // 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
 // Test with large files, errors with special characters, words with punctuations, etc
 
 
 
 // 1-12. Write a program that prints its input one word per line.
 
 
 main() {
 
 int c;
 
 while ((c = getchar()) != EOF) {
 if (c == ' ') printf("\n");
 else putchar(c);
 
 }
 
 }
 
 
 
 // 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 
 #define MAXWORDLEN 20
 
 int main() {
 int wordmat[MAXWORDLEN];
 int c, p, num, i, ndigit;
 c = p = num = ndigit = 0;
 
 for (i = 0; i <= MAXWORDLEN; ++i) {
 wordmat[i] = 0;
 }
 
 while ((c=getchar()) != EOF) {
 if (c != ' ' && c != '\n') {
 ++ndigit;
 }
 else {
 ++wordmat[ndigit];
 ndigit = 0;
 }
 
 }
 
 for (p = 0; p <= MAXWORDLEN; ++p) {
 //printf("%d word = %d\n", p, wordmat[p]);
 if (wordmat[p] > 0) {
 printf("%2d letter words: ", p);
 
 for (num = 0; num < wordmat[p]; ++num) {
 printf ("-");
 }
 printf("\n");
 }
 
 }
 
 
 }
 
 // Example of running 1-13
 
 I set down one time back in the woods, and had a long think about it.
 I says to myself, if a body can get anything they pray for, why don't
 Deacon Winn get back the money he lost on pork?  Why can't the widow get
 back her silver snuffbox that was stole?  Why can't Miss Watson fat up?
 No, says I to my self, there ain't nothing in it.  I went and told the
 widow about it, and she said the thing a body could get by praying for
 it was "spiritual gifts."  This was too many for me, but she told me
 what she meantI must help other people, and do everything I could for
 other people, and look out for them all the time, and never think about
 myself. This was including Miss Watson, as I took it.  I went out in the
 woods and turned it over in my mind a long time, but I couldn't see no
 advantage about itexcept for the other people; so at last I reckoned
 I wouldn't worry about it any more, but just let it go.
 
 0 letter words: ------
 1 letter words: --------------
 2 letter words: ----------------------
 3 letter words: ----------------------------------------------------------
 4 letter words: -------------------------------------
 5 letter words: -----------------------------
 6 letter words: ------
 7 letter words: ---------
 8 letter words: ------
 9 letter words: --
 10 letter words: ---
 
 Program ended with exit code: 0
 


// 1-14. Write a program to print a histogram of the frequencies of different characters in its input.

#define NUMCHAR 255

main() {
    
    int alphabet[NUMCHAR];
    int c, i, x, num;
    
    for (i = 0; i < NUMCHAR; ++i) {
        alphabet[i] = 0;
    }
    
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
        ++alphabet[c];
        }
    }
    
    printf("\n");
    for (x = 0; x < NUMCHAR; ++x) {
        if (alphabet[x] > 0) {
            putchar(x);
            printf(" : ");
            
            for (num = 0; num < alphabet[x]; ++num) {
                printf("-");
            }
            
            printf("\n");
            
        }
    }

    
}


I set down one time back in the woods, and had a long think about it.
I says to myself, if a body can get anything they pray for, why don't
Deacon Winn get back the money he lost on pork?  Why can't the widow get
back her silver snuffbox that was stole?  Why can't Miss Watson fat up?
No, says I to my self, there ain't nothing in it.  I went and told the
widow about it, and she said the thing a body could get by praying for
it was "spiritual gifts."  This was too many for me, but she told me
what she meantI must help other people, and do everything I could for
other people, and look out for them all the time, and never think about
myself. This was including Miss Watson, as I took it.  I went out in the
woods and turned it over in my mind a long time, but I couldn't see no
advantage about itexcept for the other people; so at last I reckoned
I wouldn't worry about it any more, but just let it go.

" : --
' : ------
, : -------------
. : ------
; : -
? : ---
D : -
I : -----------
M : --
N : -
T : --
W : -----
a : ---------------------------------------------------
b : ---------------
c : -------------
d : -----------------------------
e : ---------------------------------------------------------------
f : --------------
g : ---------------
h : ----------------------------------
i : ----------------------------------------
j : -
k : ---------
l : -------------------------
m : ----------------
n : ----------------------------------------------------
o : -----------------------------------------------------------------
p : -------------
r : ------------------------
s : --------------------------------------
t : --------------------------------------------------------------------------------
u : ---------------------
v : -----
w : -----------------
x : --
y : ---------------------
\227 : --
\302 : --
Program ended with exit code: 0


// 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.


float celciusToFahr(int c);

int main() {
    
    int i;

    for (i = -100; i < 100; i = i + 20) {
        printf("\n Celcius: %4d, Fahrenheit = %3.0f", i, celciusToFahr(i));
    }


    printf("\n ");
    return 0;
}


float celciusToFahr(int c) {
    
    float result;
    result = ((c/5)*9) + 32;
    return result;
}



// 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#define MAXLINE 100
int result(char m[]);


main() {
    
    char line[MAXLINE];
    int result = 1;
    while ((result = getline2(line)) > 0) {
        return 0;
    }
}


int getline2 (char s[]) {
    
    int i, z;
    i = 0;
    int c, count;
    while ((c = getchar()) != EOF) {
        
        s[i] = c;
        
        if (i > 0 && c == '\n') {
            for (count = i - 1; count != 0; --count) {
                if (s[count] == ' ' || s[count] == '\n' || s[count] == '\t') {
                    --i;
                    s[i] = '\n';
                } else {
                    break;
                }
            }
        }
        ++i;
    }

    if (i > 0) {
        for (z = 0; z < i; ++z) {
            putchar(s[z]);
        }
    }

    return 0;
    
}



// 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

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


// 1-23. Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and character constants properly. C comments don’t nest.

#define MAXLINE 200
void removeComment(char s2[]);


main() {
    
    int c, z;
    char hold [MAXLINE];
    int i = 0;
    
    while ((c = getchar()) != EOF) {
        
        if (c == '\n') {
            i = 0;
            removeComment(hold);
            memset(&hold[0], 0, sizeof(hold));
        } else {
        hold[i] = c;
        ++i;
        }
        
    }
}


void removeComment (char s[]) {
    
    int i;
    
    for (i = 0; i < strlen(s); ++i) {
        if (s[i] == '/' && i < strlen(s) && s[i + 1] == '/') {
            break;
        } else {
            //printf("%d", s[i]);
            putchar (s[i]);
        }
        

    }
    putchar('\n');
   
    //return 0;
}




