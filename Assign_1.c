#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

void initdate(struct date *ptrdate)
{
    ptrdate->day = 1;
    ptrdate->month = 1;
    ptrdate->year = 2000;
}

void printdateonconsole(struct date *ptrdate)
{
    printf("Date: %d-%d-%d\n", ptrdate->day, ptrdate->month, ptrdate->year);
}

void acceptdatefromconsole(struct date *ptrdate)
{
    printf("Enter day: ");
    scanf("%d", &ptrdate->day);
    printf("Enter month: ");
    scanf("%d", &ptrdate->month);
    printf("Enter year: ");
    scanf("%d", &ptrdate->year);
}

int menu()
{
    int choice;
    printf("\n:MENU:\n");
    printf("1. Initialize Date\n");
    printf("2. Print Date\n");
    printf("3. Accept Date from Console\n");
    printf("4. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    struct date mydate;
    int choice;

    // initdate(&mydate);
    // // acceptdatefromconsole(&mydate);
    // printdateonconsole(&mydate);

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            initdate(&mydate);
            printf("Date initialized successfully!\n");
            break;
        case 2:
            printdateonconsole(&mydate);
            break;
        case 3:
            acceptdatefromconsole(&mydate);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Wrong choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
