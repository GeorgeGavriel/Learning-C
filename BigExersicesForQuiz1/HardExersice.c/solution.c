/*
 * EPL232 - PRACTICE EXAM
 * Topics: file I/O, pointers & pointer arithmetic, strings
 *
 * RULES
 *  - Complete ALL the functions marked TODO.
 *  - main() is already complete. DO NOT modify it.
 *  - Inside the functions you write, the operator [] is FORBIDDEN.
 *    Use only pointer arithmetic (*p, *(p+i), p++, p--, p+n, p-q ...).
 *  - You may NOT use these from string.h: strlen, strcpy, strrev, strcmp...
 *    (strtok is used in main only). You may use <ctype.h> (tolower).
 *  - No structs.
 *
 * INPUT FILE FORMAT (data.txt)
 *    line 1        : N  (how many integers follow, 1 <= N <= MAX_NUMS)
 *    line 2        : N integers separated by spaces
 *    remaining     : lines of text (words separated by single spaces)
 *
 * Compile:  gcc practice.c -Wall -o practice
 * Run:      ./practice      (input file: data.txt, output file: e.g. out.txt)
 *
 * Expected out.txt for the given data.txt: see the end of this file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMS 20
#define MAX_LINE 100
#define MAX_WORD 50

/* ---------- Prototypes ---------- */
int  readNumbers(FILE *fp, int *arr, int n);
void printArray(FILE *fp, const int *arr, int n);
int  findMax(const int *arr, int n);
void countEvenOdd(const int *arr, int n, int *even, int *odd);
void reverseArray(int *arr, int n);

int  myStrlen(const char *s);
void myStrcpy(char *dst, const char *src);
void reverseString(char *s);
void toUpperStr(char *s);
int  countVowels(const char *s);
int  isPalindrome(const char *s);
void stripNewline(char *s);

/* ---------- main (COMPLETE - do not change) ---------- */
int main(void) {
    char inName[50], outName[50];
    int nums[MAX_NUMS];
    int n, even, odd;
    char line[MAX_LINE];
    char rev[MAX_WORD], upper[MAX_WORD];
    char *tok;
    int lineNo = 0;
    FILE *in, *out;

    printf("Input file name: ");
    scanf("%49s", inName);
    printf("Output file name: ");
    scanf("%49s", outName);

    in = fopen(inName, "r");
    if (in == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    out = fopen(outName, "w");
    if (out == NULL) {
        perror("Error opening output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    if (fscanf(in, "%d", &n) != 1 || n < 1 || n > MAX_NUMS) {
        fprintf(stderr, "Invalid N in file.\n");
        exit(EXIT_FAILURE);
    }
    if (readNumbers(in, nums, n) != n) {
        fprintf(stderr, "Not enough numbers in file.\n");
        exit(EXIT_FAILURE);
    }
    fgets(line, MAX_LINE, in); /* consume the rest of the numbers line */

    fprintf(out, "Numbers read: ");
    printArray(out, nums, n);

    fprintf(out, "Max: %d\n", findMax(nums, n));
    countEvenOdd(nums, n, &even, &odd);
    fprintf(out, "Even: %d, Odd: %d\n", even, odd);

    reverseArray(nums, n);
    fprintf(out, "Reversed: ");
    printArray(out, nums, n);
    fprintf(out, "\n");

    while (fgets(line, MAX_LINE, in) != NULL) {
        stripNewline(line);
        if (myStrlen(line) == 0)
            continue;
        lineNo++;
        fprintf(out, "Line %d: %s\n", lineNo, line);
        fprintf(out, "  length=%d vowels=%d\n", myStrlen(line), countVowels(line));

        tok = strtok(line, " ");
        while (tok != NULL) {
            myStrcpy(rev, tok);
            reverseString(rev);
            myStrcpy(upper, tok);
            toUpperStr(upper);
            fprintf(out, "  %-10s -> %-10s %-10s palindrome=%s\n",
                    tok, rev, upper, isPalindrome(tok) ? "yes" : "no");
            tok = strtok(NULL, " ");
        }
    }

    fclose(in);
    fclose(out);
    printf("Processing complete.\n");
    return 0;
}

/* ---------- Functions to implement (pointer arithmetic ONLY) ---------- */

/**
 * Reads n integers from the already-open file fp (using fscanf) and stores
 * them in arr. Returns how many integers were successfully read.
 * Stop reading if fscanf fails.
 */
int readNumbers(FILE *fp, int *arr, int n) {
    int *p = arr;
    while (p < arr + n) {
        if (fscanf(fp, "%d", p) != 1)
            break;
        p++;
    }
    return (int)(p - arr);
}

/**
 * Prints the n integers of arr to the file fp on ONE line, each followed by
 * a space, and then a newline.
 */
void printArray(FILE *fp, const int *arr, int n) {
    const int *p;
    for (p = arr; p < arr + n; p++)
        fprintf(fp, "%d ", *p);
    fprintf(fp, "\n");
}

/**
 * Returns the largest element of arr (n >= 1).
 */
int findMax(const int *arr, int n) {
    const int *p = arr + 1;
    int max = *arr;
    while (p < arr + n) {
        if (*p > max)
            max = *p;
        p++;
    }
    return max;
}

/**
 * Counts the even and the odd elements of arr and returns the results
 * through the pointers even and odd. (0 counts as even)
 */
void countEvenOdd(const int *arr, int n, int *even, int *odd) {
    const int *p;
    *even = 0;
    *odd = 0;
    for (p = arr; p < arr + n; p++) {
        if (*p % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

/**
 * Reverses arr in place. Hint: use two pointers, one at the start and one
 * at the end, moving towards each other. Do NOT use a second array.
 */
void reverseArray(int *arr, int n) {
    int *start = arr, *end = arr + n - 1, tmp;
    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

/**
 * Returns the length of s (without the '\0'). Do not use strlen.
 */
int myStrlen(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}

/**
 * Copies the string src (including '\0') into dst. Do not use strcpy.
 * dst is assumed to be large enough.
 */
void myStrcpy(char *dst, const char *src) {
    while ((*dst = *src) != '\0') {
        dst++;
        src++;
    }
}

/**
 * Reverses the string s in place ("abc" -> "cba").
 * You may call myStrlen.
 */
void reverseString(char *s) {
    char *start = s, *end = s + myStrlen(s) - 1, tmp;
    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

/**
 * Converts every lowercase letter of s to uppercase, in place.
 * Do not use toupper; use the ASCII difference between 'a' and 'A'.
 */
void toUpperStr(char *s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z')
            *s = *s - ('a' - 'A');
        s++;
    }
}

/**
 * Returns how many vowels (a, e, i, o, u - upper or lower case) s contains.
 */
int countVowels(const char *s) {
    int count = 0;
    while (*s != '\0') {
        switch (tolower((unsigned char)*s)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                count++;
        }
        s++;
    }
    return count;
}

/**
 * Returns 1 if s reads the same forwards and backwards, ignoring upper/lower
 * case, otherwise 0. Use two pointers (start / end). A string of length
 * 0 or 1 is a palindrome.
 */
int isPalindrome(const char *s) {
    const char *start = s, *end = s + myStrlen(s) - 1;
    while (start < end) {
        if (tolower((unsigned char)*start) != tolower((unsigned char)*end))
            return 0;
        start++;
        end--;
    }
    return 1;
}

/**
 * Replaces the first '\n' (or '\r') of s with '\0'. If there is none,
 * s is left unchanged. (Useful after fgets.)
 */
void stripNewline(char *s) {
    while (*s != '\0') {
        if (*s == '\n' || *s == '\r') {
            *s = '\0';
            return;
        }
        s++;
    }
}

/*
 * ---------------- EXPECTED out.txt for the given data.txt ----------------
 * Numbers read: 12 7 -3 20 45 8 0 33 -18 6
 * Max: 45
 * Even: 6, Odd: 4
 * Reversed: 6 -18 33 0 8 45 20 -3 7 12
 *
 * Line 1: The level of noon
 *   length=17 vowels=6
 *   The        -> ehT        THE        palindrome=no
 *   level      -> level      LEVEL      palindrome=yes
 *   of         -> fo         OF         palindrome=no
 *   noon       -> noon       NOON       palindrome=yes
 * Line 2: racecar is a Palindrome
 *   length=23 vowels=9
 *   racecar    -> racecar    RACECAR    palindrome=yes
 *   is         -> si         IS         palindrome=no
 *   a          -> a          A          palindrome=yes
 *   Palindrome -> emordnilaP PALINDROME palindrome=no
 * Line 3: Pointers are fun
 *   length=16 vowels=5
 *   Pointers   -> sretnioP   POINTERS   palindrome=no
 *   are        -> era        ARE        palindrome=no
 *   fun        -> nuf        FUN        palindrome=no
 */