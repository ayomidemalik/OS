
#include <stdio.h>

int main() {
    int age = 20;
    //printf("Basit is %d years old\n", age);
    //puts("Hello World");

    //char gender = 'M'; // to c, this is a string because of the double quote and char is supposed to be a single quote
    //printf("%s", gender);
    char name[20]; //this saves 19 characters and a newline character
    //printf prints thing to console while scanf gets things from the console.
    //by default, arrays are pointers. if arrays, no point of ampersands but if for ints,
    //you'd need the ampersand.
    printf("Please enter your name: ");
    scanf("%s", name); //scanf treats them as pointers by default
    printf("Hello %s \n", name);
    return 0;
    // the %s is a place holder for strings while %c is a placeholder for character.
    // Single quote is for char while double quote is for string.
    //input is scanf while output is printf
    //C is basically a line by line language. Define functions and variables before calling them.
    // Main function should be our last funtion, at the bottom of our program.
}