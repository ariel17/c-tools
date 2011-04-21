#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <crack.h>

/* This program checks password strength using the program FascistCheck from
 * Cracklib. Appears in the O'Relly's book "Linux Security Cookbook", with 
 * some corrections.
 *
 * To compile this program you must run:
 *
 * gcc fascistcheck.c -lcrack -o fascistcheck
 */

/*
 * This dictionary is created by 'create-cracklib-dict' command, base on 
 * wordlist files. You can found many of this files on this sites:
 *
 * ftp://ftp.ox.ac.uk/pub/wordlists/
 * ftp://ftp.cerias.purdue.edu/pub/dict/wordlists
 */
#define DICTIONARY "/tmp/dict"

int main(int argc, char *argv[]) {
    char *password, *problem;
    int status = 0;
    printf("\n** This is the Fascist Password Checker.\n\n");
    printf("Enter an empty password or Ctrl-D to quit.\n");
    while ((password = getpass("\nPassword: ")) != NULL && *password ) {
        if ((problem = (char *)FascistCheck(password, DICTIONARY)) != NULL) {
            printf("Bad password: %s.\n", problem);
            status = 1;
        } else {
            printf("Good password!\n");
        }
    }
    printf("\n\nGoodbye!\n");
    exit(status);
}
