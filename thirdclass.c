
// // #include <stdio.h>

// // float addition(float a, float b) {
// //     return a+b;
// // }

// // float subtraction(float a, float b) {
// //     return a-b;
// // }

// // float division(float a, float b) {
// //     return a/b;
// // }

// // float multiplication(float a, float b) {
// //     return a*b;
// // }
// // int main() {
// //     // int accountBalance = 10000;
// //     // int credit = 50000;
// //     // int debit = 20000;

// //     // int newVariable = accountBalance + credit;
// //     // int anotherVariable = accountBalance - debit;

// //     // accountBalance += credit;
// //     // accountBalance / 2;

// //     // printf("%i\n", accountBalance / 2); // in c we have to be careful about the datatype we use.
    
// //     //int isAdult = 1;
// //     //int isPAUStudent = 1;
    
// //     //boolean, true and false are not data types in C.

// //     //if (isAdult = 2 && isPAUStudent){
// //     //    printf("You can get free lunch\n");
// //     //}

// //     //if (!isAdult == 1 || isPAUStudent == 0) {
// //     //    printf("You can get free lunch\n");
// //     //}
// //     //else {
// //     //    printf("No free lunch for you\n");
// //     //}


// //     //int a = 5;
// //     //int b = 3;

// //     //printf("%i", a|b); //prints it in decimal


// //     /*int age;
// //     printf("Enter your age please: ");
// //     scanf("%i", &age);

// //     if (age > 16) {
// //         printf("You can vote\n");
// //     }
// //     else {
// //         printf("You cannot vote\n");
// //     }
    


// //     int csc201;
// //     int csc205;
// //     int sta205;

// //     printf("Enter your score in csc201: ");
// //     scanf("%i", &csc201);

// //     printf("Enter your score in csc205: ");
// //     scanf("%i", &csc205);

// //     printf("Enter your score in sta205: ");
// //     scanf("%i", &sta205);

// //     int total = csc201 + csc205 + sta205;
// //     printf("The total is %i\n", total);

// //     int average = (csc201 + csc205 + sta205)/3;
// //     printf("The average is %i\n", average);

// //     float percentage = (total/300) * 100;
// //     printf("The percentage is %f\n", percentage);
// //     */

// //    printf("Hello, this is a simple calculator. Enter 1 for addition, 2 for subtraction, 3 for multiplication and 4 for division.");
// //    float option;
// //    scanf("%f", &option);

// //    float number1;
// //    float number2;

// //    printf("Enter your first value please");
// //    scanf("%f", &number1);

// //    printf("Enter your second value please");
// //    scanf("%f", &number2);

// //    if (option == 1) {
// //         addition(number1,number2);
// //    }

// //    else if (option == 2) {
// //     subtraction(number1, number2);
// //    }
// //     else if (option ==3) {
// //         multiplication(number1,number2);
// //     }
// //     else if (option == 4) {
// //         division(number1,number2);
// //     }
// //     else {
// //         return 0;
// //     }

    


// //     return 0;
// // }

// // /*
// //  float addition(float a, float b) {
// //  return a+b;
// //  }

// //  float subtraction, is similar to float addition function.


// //  */


// #include <stdio.h>
// int main() {
//     int i = 0; //here we are initializing the variable i
//     for (i; i < 5; i++) { // the part in the bracket can be written as (i = 0; i < 5; i++). here we are initializing the variable i in the for loop.
//         printf("%d\n", i);
//     }

//     int flag = 1;
//     // while (flag == 1) //while loop. This expression is first tested. The condition is first tested. If not, skip to next set of statements outside the while loop.
//     // {
//     //     printf("Hello world! \n");
//     // }

//     // do 
//     // {
//     //     printf("Hello World!!\n");
//     // } 
//     // while (flag == 1);

//     // return 0;

    
    
// }

// // for loop vs a while loop???
// // no boolean type in built in C.
// // While loop vs Do while loop. Do while loop runs the body first before checking the condition while for a while loop, it checks the condition first
// // before running the body.
// // nested while, do while loops.

#include <stdio.h>
int YorN; 
int totalprice = 0;

int main() {
    printf("Welcome to Mama Cas Restaurant!\n");
    printf("P = Poundo Yam/Edinkaiko Soup - 3200\nF = Fried Rice & Chicken - 3000\n");
    printf("A = Amala & Ewedu Soup - 2500\nE = Eba & Egusi Soup - 2000\n");
    printf("W = White Rice & Stew - 2500\n");

    do {
        printf("Please enter the character of the food you want: ");
        char userinput;
        scanf(" %c", &userinput); 

        int quantity = 0;

        switch (userinput) {
            case 'P': case 'p': 
                printf("Enter the quantity of Poundo Yam/Edinkaiko Soup you want: \n");
                scanf("%d", &quantity);
                totalprice += 3200 * quantity;
                break;

            case 'F': case 'f': 
                printf("Enter the quantity of Fried Rice & Chicken you want: \n");
                scanf("%d", &quantity);
                totalprice += 3000 * quantity;
                break;

            case 'A': case 'a': 
                printf("Enter the quantity of Amala & Ewedu Soup you want: \n");
                scanf("%d", &quantity);
                totalprice += 2500 * quantity;
                break;

            case 'E': case 'e': 
                printf("Enter the quantity of Eba & Egusi Soup you want: \n");
                scanf("%d", &quantity);
                totalprice += 2000 * quantity;
                break;

            case 'W': case 'w': 
                printf("Enter the quantity of White Rice & Stew you want: \n");
                scanf("%d", &quantity);
                totalprice += 2500 * quantity;
                break;

            default:
                printf("You didn't enter a valid character. Try again.\n");
                break;
        }

        printf("Would you like to order again? (1 for Yes, 0 for No): ");
        scanf("%d", &YorN);

    } while (YorN != 0);

    printf("\nYour total is: %d\n", totalprice);

    return 0;
}


