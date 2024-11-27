/******************
Name:Ori Bahat-Petel
ID:331753830
Assignment: ex2
*******************/
#include <stdio.h>
#include <stdbool.h> 

#define GET_FIRST_DIGIT 10
#define REMOVE_FIRST_DIGIT 10
#define OFFSET 1
#define DIVISABLE_BY_2 2
#define DIVISOR 2
#define MULTI 10
#define FIRST_PRIME 2
#define POSITIVE_CHECK 0

int main() {
    int caseNum,temp,ex1n,ex2n,ex2D,ex2LSum,ex2RSum,ex3n,ex3Sum,ex4n,ex4Rn,ex5n,ex5n1,ex5Sum,ex6n,ex6n1,ex6n2;
    char ex1c1,ex1c2,ex1c3;
    bool flag4;
    do {
        printf("Choose an option:\n\t"
               "1. Happy Face\n\t"
               "2. Balanced Number\n\t"
               "3. Generous Number\n\t"
               "4. Circle Of Joy\n\t"
               "5. Happy Numbers\n\t"
               "6. Festival Of Laughter\n\t"
               "7. Exit\n");
        scanf("%d", &caseNum);
        switch (caseNum) {
            case 1:
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c",&ex1c1,&ex1c2,&ex1c3);
                printf("Enter face size:\n");
                scanf("%d",&ex1n);
                while(ex1n < POSITIVE_CHECK || ex1n % DIVISABLE_BY_2 == 0)
                {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d",&ex1n);
                }
                printf("%c",ex1c1);
                for(int i = 0; i < ex1n;i++) //print spaces between eyes
                {
                    printf(" ");
                }
                printf("%c\n",ex1c1);
                for(int i = 0; i < ex1n/DIVISOR + OFFSET;i++) //print spaces before nose
                {
                    printf(" ");
                }
                printf("%c\n",ex1c2);
                printf("\\");
                for(int i = 0; i < ex1n;i++)
                {
                    printf("%c",ex1c3);
                }
                printf("/");
                printf("\n");
                break;
            case 2:
                ex2LSum = 0;
                ex2RSum = 0;
                printf("Enter a number:\n");
                scanf("%d",&ex2n);
                while(ex2n <= POSITIVE_CHECK)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d",&ex2n);
                }
                temp = ex2n;
                while (temp > 0) //count the digits in the number
                {
                    ex2D++;
                    temp /= REMOVE_FIRST_DIGIT;
                }
                for (int i = 0; i < ex2D /DIVISOR; i++) //add up all digits from the right
                {
                    ex2RSum += ex2n%GET_FIRST_DIGIT;
                    ex2n = ex2n / REMOVE_FIRST_DIGIT;
                }
                if (ex2D % DIVISABLE_BY_2 == 1) //check if length is odd so we can ignore middle number
                {
                    ex2n /= REMOVE_FIRST_DIGIT;
                }
                for (int i = 0; i < ex2D /DIVISOR; i++) //add up all digits from the left
                {
                    ex2LSum += ex2n%GET_FIRST_DIGIT;
                    ex2n = ex2n / REMOVE_FIRST_DIGIT;
                }
                if (ex2LSum == ex2RSum) // check equality
                {
                    printf("This number is balanced and brings harmony!\n");
                } 
                else 
                {
                    printf("This number isn't balanced and destroys harmony.\n");
                }

                break;
            case 3:
                ex3Sum = 0;
                printf("Enter a number:\n");
                scanf("%d",&ex3n);
                while(ex3n <= POSITIVE_CHECK)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d",&ex3n);
                }
                for(int i = OFFSET; i < ex3n; i++) //add up all divisors
                {
                    if(ex3n % i == 0)
                        ex3Sum += i;
                }
                if(ex3Sum > ex3n)
                    printf("This number is generous!\n");
                else
                    printf("This number does not share.\n");
                break;
            case 4:
                ex4Rn = 0;
                flag4 = true;
                printf("Enter a number:\n");
                scanf("%d",&ex4n);
                while(ex4n <= POSITIVE_CHECK)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d",&ex4n);
                }
                temp = ex4n;
                while(temp > POSITIVE_CHECK) //reverse the number
                {
                    ex4Rn = ex4Rn * MULTI;
                    ex4Rn += temp%GET_FIRST_DIGIT;
                    temp = temp/REMOVE_FIRST_DIGIT;
                }
                for(int i = FIRST_PRIME; i < ex4n; i++) //check if the number is prime
                {
                    if(ex4n % i == 0)
                        flag4 = false;
                }
                for(int i = FIRST_PRIME; i < ex4Rn; i++) //check if the reversed number is prime
                {
                    if(ex4Rn % i == 0)
                        flag4 = false;    
                }
                if(ex4n == 1)
                    flag4 = false;
                if(flag4)
                    printf("This number completes the circle of joy!\n");
                else
                    printf("The circle remains incomplete.\n");
                break;
            case 5:
                ex5Sum = 0;
                printf("Enter a number:\n");
                scanf("%d",&ex5n);
                while(ex5n <= POSITIVE_CHECK)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d",&ex5n);
                }
                printf("Between 1 and %d only these numbers bring happiness: ",ex5n);
                for (int i = OFFSET; i <= ex5n; i++) 
                {
                    ex5Sum = i; 
                    while (ex5Sum != 1 && ex5Sum != 4) //every number that doesnt bring happiness goes through 4
                    {
                        temp = ex5Sum;
                        ex5Sum = 0;
                        while (temp > 0)  // sum all of the digit's squares
                        {
                            ex5n1 = temp % GET_FIRST_DIGIT;
                            ex5Sum += ex5n1 * ex5n1;
                            temp /= REMOVE_FIRST_DIGIT;
                        }
                    }
                    if (ex5Sum == 1) 
                    {
                        printf("%d ", i);
                    }
                }
                printf("\n");
                break;
            case 6:
                printf("Enter a smile and cheer number:\n");
                temp = 0;
                while (1) 
                {
                    int result = scanf("smile: %d ,cheer: %d", &ex6n1, &ex6n2);
                    if (result == 2 && ex6n1 > 0 && ex6n2 > 0 && ex6n1 != ex6n2) 
                    {
                        break; // exit the loop if input is good
                    }
                    // handle wrong input
                    if (temp > POSITIVE_CHECK)
                    {
                        printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    }
                    scanf("%*[^\n]");  // discard all characters until new line
                    scanf("%*c"); // discard the newline character
                    temp++;
                }
                printf("Enter maximum number for the festival: \n");
                scanf("%d",&ex6n);
                while(ex6n <= 0)
                {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf("%d",&ex6n);
                }
                for(int i = OFFSET; i <= ex6n; i++) //find for each number if they are divisable by cheer/smile/both
                {
                    if(i % ex6n1 == 0 && i % ex6n2 == 0)
                        printf("Festival!\n");
                    else if(i % ex6n1 == 0)
                        printf("Smile!\n");
                    else if(i % ex6n2 == 0)
                        printf("Cheer!\n");
                    else
                        printf("%d\n",i);
                }
                break;
            case 7:
                printf("Thank you for your journey through Numeria!\n");
                break;
            default: //handle wrong entry
                printf("This option is not available, please try again.\n");
                break;
        }
    } while (caseNum != 7); //repeat until Exit

    return 0;
}
