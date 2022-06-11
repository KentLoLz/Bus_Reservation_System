#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bus1[40][10] = {
    "1.A1",
    "2.A2",
    "3.A3",
    "4.B1",
    "5.B2",
    "6.B3",
    "7.C1",
    "8.C2",
    "9.C3",
};
char bus2[40][10] = {
    "1.A1",
    "2.A2",
    "3.A3",
    "4.B1",
    "5.B2",
    "6.B3",
    "7.C1",
    "8.C2",
    "9.C3",
};
char bus3[40][10] = {
    "1.A1",
    "2.A2",
    "3.A3",
    "4.B1",
    "5.B2",
    "6.B3",
    "7.C1",
    "8.C2",
    "9.C3",
};

void Bus_Schedule();
void booking();
void Bus_Status1();
void Bus_Status2();
void Bus_Status3();
void Bus_Seat1();
void Bus_Seat2();
void Bus_Seat3();
void cancel();
void Modify_Bus1();
void Modify_Bus2();
void Modify_Bus3();
void Status();
void FAQ();

struct BookingInformation
{
    char seatnum[10];
    char name[50];
};

struct BookingInformation b1[30], b2[30], b3[30];
int index1, index2, index3 = 0;

int main()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("============================ BUS RESERVATION SYSTEM MENU ========================================\n");
        printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[1]=> View Bus Schedule\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[2]=> Buy a Ticket\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[3]=> Cancle Ticket\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[4]=> Bus Status\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[5]=> FAQ\t\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t[6]=> Exit\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            Bus_Schedule();
            break;
        case 2:
            system("cls");
            booking();
            break;
        case 3:
            system("cls");
            cancel();
            break;
        case 4:
            system("cls");
            Status();
            break;
        case 5:
            system("cls");
            FAQ();
            break;
        case 6:
            printf("Welcome back again!");
            break;
        default:
            printf("\nSorry, there is no %d in the option list.\n", choice);
            printf("Press enter to continue the process.....");
        }
        getch();
    } while (choice != 6);

    return 0;
}

void Bus_Schedule()
{
    system("cls");
    char BUS_CODE[10][130] = {"A001", "A002", "A003"};
    char BUS_NAME[10][130] = {"NICE EXPRESS", "JOKER EXPRESS", "EXP EXPRESS"};
    char PLATE_NUMBER[10][130] = {"PKK3133", "JKJ8188", "EXE1234"};
    char FROM[10][130] = {"JB", "SP", "AS"};
    char DESTINATION[10][130] = {"KUL", "PG", "PG"};
    char TIME[10][130] = {"0800-1000", "1200-1400", "1230-1400"};

    int i;

    printf(" |BUS CODE \t|BUS NAME \t|PLATE NUMBER \t|FROM \t|DESTINATION \t|TIME   \t|\n");
    printf(" ****************************************************************************************\n");

    for (i = 0; i < 3; i++)
    {
        printf(" |%s \t\t|%s \t|%s \t|%s \t|%s \t\t|%s      |\n", BUS_CODE[i], BUS_NAME[i],
               PLATE_NUMBER[i], FROM[i], DESTINATION[i], TIME[i]);
    }
}

void booking()
{
    system("cls");
    Bus_Schedule();
    printf("\nPlease select the bus code: ");
    char buscode[10];
    scanf("%s", &buscode);

    if (!strcmp(buscode, "A001"))
    {
        system("cls");
        Bus_Status1();
        Bus_Seat1();
    }
    else if (!strcmp(buscode, "A002"))
    {
        system("cls");
        Bus_Status2();
        Bus_Seat2();
    }
    else if (!strcmp(buscode, "A003"))
    {
        system("cls");
        Bus_Status3();
        Bus_Seat3();
    }
    else
    {
        printf("\nSorry, there is no bus with the bus code %s in the list.\n", buscode);
        printf("Press enter to continue the process.....");
    }
}

void Bus_Seat1()
{
    int totalticket;
    printf("Number Of Ticket : ");
    scanf("%d", &totalticket);

    for (int i = 0; i < totalticket; i++)
    {
        char name[50];
        char temp[50];
        int seatnum;
        int counter = 0;

        printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
        scanf("%d", &seatnum);
        if (strcmp(&bus1[seatnum - 1][2], "X"))
        {
            strcpy(temp, bus1[seatnum - 1]);
            strcpy(&bus1[seatnum - 1][2], "X");
            printf("Enter Name : ");
            scanf("%s", &name);
            printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
        }
        else
        {
            while (1)
            {
                printf("Sorry, this seat is reserved by others. Please enter the seat again.\n");
                printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
                scanf("%d", &seatnum);
                if (strcmp(&bus1[seatnum - 1][2], "X"))
                {
                    strcpy(temp, bus1[seatnum - 1]);
                    strcpy(&bus1[seatnum - 1][2], "X");
                    printf("Enter Name : ");
                    scanf("%s", &name);
                    printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
                    break;
                }
            }
        }
        strcpy(b1[index1].seatnum, temp);
        strcpy(b1[index1++].name, name);
    }
    int sum = totalticket * 50;
    printf("Total price of the tickets is: RM %d \n", sum);
    Bus_Status1();
    printf("Press enter to continue the process.....");
}

void Bus_Seat2()
{
    int totalticket;
    printf("Number Of Ticket : ");
    scanf("%d", &totalticket);

    for (int i = 0; i < totalticket; i++)
    {
        char name[50];
        char temp[50];
        int seatnum;
        int counter = 0;

        printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
        scanf("%d", &seatnum);
        if (strcmp(&bus2[seatnum - 1][2], "X"))
        {
            strcpy(temp, bus2[seatnum - 1]);
            strcpy(&bus2[seatnum - 1][2], "X");
            printf("Enter Name : ");
            scanf("%s", &name);
            printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
        }
        else
        {
            while (1)
            {
                printf("Sorry, this seat is reserved by others. Please enter the seat again.\n");
                printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
                scanf("%d", &seatnum);
                if (strcmp(&bus2[seatnum - 1][2], "X"))
                {
                    strcpy(temp, bus2[seatnum - 1]);
                    strcpy(&bus2[seatnum - 1][2], "X");
                    printf("Enter Name : ");
                    scanf("%s", &name);
                    printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
                    break;
                }
            }
        }
        strcpy(b2[index2].seatnum, temp);
        strcpy(b2[index2++].name, name);
    }
    int sum = totalticket * 50;
    printf("Total price of the tickets is: RM %d \n", sum);
    Bus_Status2();
    printf("Press enter to continue the process.....");
}

void Bus_Seat3()
{
    int totalticket;
    printf("Number Of Ticket : ");
    scanf("%d", &totalticket);

    for (int i = 0; i < totalticket; i++)
    {
        char name[50];
        char temp[50];
        int seatnum;
        int counter = 0;

        printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
        scanf("%d", &seatnum);
        if (strcmp(&bus3[seatnum - 1][2], "X"))
        {
            strcpy(temp, bus3[seatnum - 1]);
            strcpy(&bus3[seatnum - 1][2], "X");
            printf("Enter Name : ");
            scanf("%s", &name);
            printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
        }
        else
        {
            while (1)
            {
                printf("Sorry, this seat is reserved by others. Please enter the seat again.\n");
                printf("Enter Seat Number (Ex.1, 2, 3, 4, 5 etc) : ");
                scanf("%d", &seatnum);
                if (strcmp(&bus3[seatnum - 1][2], "X"))
                {
                    strcpy(temp, bus3[seatnum - 1]);
                    strcpy(&bus3[seatnum - 1][2], "X");
                    printf("Enter Name : ");
                    scanf("%s", &name);
                    printf("Dear Mr/Mrs %s, you have reserved the seat with the number %d successfully.\n", name, seatnum);
                    break;
                }
            }
        }
        strcpy(b3[index3].seatnum, temp);
        strcpy(b3[index3++].name, name);
    }
    int sum = totalticket * 50;
    printf("Total price of the tickets is: RM %d \n", sum);
    Bus_Status3();
    printf("Press enter to continue the process.....");
}

void Bus_Status1()
{
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n");
    printf("_______________________________________________________________________________________________________________\n");
    printf("                                      Bus code: --> A001 ----> NICE EXPRESS                                      \n");
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%s\t\t", bus1[index]);
            index++;
        }
        printf("\n");
    }
}

void Bus_Status2()
{
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n");
    printf("_______________________________________________________________________________________________________________\n");
    printf("                                      Bus code: --> A002 ----> JOKER EXPRESS                                      \n");
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%s\t\t", bus2[index]);
            index++;
        }
        printf("\n");
    }
}

void Bus_Status3()
{
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n");
    printf("_______________________________________________________________________________________________________________\n");
    printf("                                      Bus code: --> A003 ----> EXP EXPRESS                                      \n");
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%s\t\t", bus3[index]);
            index++;
        }
        printf("\n");
    }
}

void cancel()
{
    system("cls");
    Bus_Schedule();
    printf("\nPlease select the bus code: ");
    char buscode[10];
    scanf("%s", &buscode);

    if (!strcmp(buscode, "A001"))
    {
        system("cls");
        Bus_Status1();
        Modify_Bus1();
    }
    else if (!strcmp(buscode, "A002"))
    {
        system("cls");
        Bus_Status2();
        Modify_Bus2();
    }
    else if (!strcmp(buscode, "A003"))
    {
        system("cls");
        Bus_Status3();
        Modify_Bus3();
    }
    else
    {
        printf("\nSorry, there is no bus with the bus code %s in the list.\n", buscode);
        printf("Press enter to continue the process.....");
    }
}

void Modify_Bus1()
{
    printf("Please select your seat number to cancel: ");
    int seatnum;
    scanf("%d", &seatnum);

    if (strcmp(&bus1[seatnum - 1][2], "X"))
    {
        printf("This seat with the number %d has not reserved yet.\n", seatnum);
    }
    else
    {
        for (int i = 0; i < sizeof(b1); i++)
        {
            if (seatnum == atoi(b1[i].seatnum))
            {
                printf("Dear Mr/Mrs %s, you have cancel your seat sucessfully.\n", b1[i].name);
                strcpy(&bus1[seatnum - 1], b1[i].seatnum);
                break;
            }
        }
    }
    Bus_Status1();
    printf("Press enter to continue the process.....");
}

void Modify_Bus2()
{
    printf("Please select your seat number to cancel: ");
    int seatnum;
    scanf("%d", &seatnum);

    if (strcmp(&bus2[seatnum - 1][2], "X"))
    {
        printf("This seat with the number %d has not reserved yet.\n", seatnum);
    }
    else
    {
        for (int i = 0; i < sizeof(b2); i++)
        {
            if (seatnum == atoi(b2[i].seatnum))
            {
                printf("Dear Mr/Mrs %s, you have cancel your seat sucessfully.\n", b2[i].name);
                strcpy(&bus2[seatnum - 1], b2[i].seatnum);
                break;
            }
        }
    }
    Bus_Status2();
    printf("Press enter to continue the process.....");
}

void Modify_Bus3()
{
    printf("Please select your seat number to cancel: ");
    int seatnum;
    scanf("%d", &seatnum);

    if (strcmp(&bus3[seatnum - 1][2], "X"))
    {
        printf("This seat with the number %d has not reserved yet.\n", seatnum);
    }
    else
    {
        for (int i = 0; i < sizeof(b3); i++)
        {
            if (seatnum == atoi(b3[i].seatnum))
            {
                printf("Dear Mr/Mrs %s, you have cancel your seat sucessfully.\n", b3[i].name);
                strcpy(&bus3[seatnum - 1], b3[i].seatnum);
                break;
            }
        }
    }
    Bus_Status3();
    printf("Press enter to continue the process.....");
}

void Status()
{
    char buscode[10];
    system("cls");
    char BUS_CODE[10][130] = {"A001", "A002", "A003"};
    char BUS_NAME[10][130] = {"NICE EXPRESS", "JOKER EXPRESS", "EXP EXPRESS"};
    char PLATE_NUMBER[10][130] = {"PKK3133", "JKJ8188", "EXE1234"};

    printf(" |BUS CODE \t|BUS NAME \t|PLATE NUMBER \t|\n");
    printf(" ************************************************\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" |%s \t\t|%s \t|%s \t|\n", BUS_CODE[i], BUS_NAME[i],
               PLATE_NUMBER[i]);
    }

    printf("Please enter the bus code to review the available seat: ");
    scanf("%s", buscode);

    if (!strcmp(buscode, "A001"))
    {
        system("cls");
        Bus_Status1();
        printf("Press enter to continue the process.....");
    }
    else if (!strcmp(buscode, "A002"))
    {
        system("cls");
        Bus_Status2();
        printf("Press enter to continue the process.....");
    }
    else if (!strcmp(buscode, "A003"))
    {
        system("cls");
        Bus_Status3();
        printf("Press enter to continue the process.....");
    }
    else
    {
        printf("\nSorry, there is no bus with the bus code %s in the list.\n", buscode);
        printf("Press enter to continue the process.....");
    }
}

void FAQ()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("============================ FREQUENTLY ASKED QUESTION (FAQ) ====================================\n");
        printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[1]=> Do I need to print out my booking ticket ?\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[2]=> How long before the actual departure date can i book my ticket?\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[3]=> Can I enjoy two or more promotions/discounts on one purchase?\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[4]=> Will the bus wait for me if I turn up late?\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[5]=> Can I smoke on board?\t\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t[6]=> Exit\t\t\t\t\t\t\t\t\t=\n");
        //printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=\t\t\t\t\t\t\t\t\t\t\t\t=\n");
        printf("=================================================================================================\n\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("Do I need to print out my booking ticket ?\n");
            printf("=> You may either print out your booking ticket or have it ready to view on your phone/tablet.\n=> Either a paper version or an electronic version of your entire order summary is acceptable, as long as the bus counter staff/bus driver can view it clearly.\n");
            printf("Press enter to continue the process.....");
            break;
        case 2:
            system("cls");
            printf("How long before the actual departure date can i book my ticket?\n");
            printf("=> Ticket is open for sales usually 6 - 8 weeks in advance.\n");
            printf("Press enter to continue the process.....");
            break;
        case 3:
            system("cls");
            printf("\nCan I enjoy two or more promotions/discounts on one purchase?\n");
            printf("=> No. The price is nett and final.\n");
            printf("Press enter to continue the process.....");
            break;
        case 4:
            system("cls");
            printf("Will the bus wait for me if I turn up late?\n");
            printf("=> No. Bus will leave on time and cannot wait at the expense of other passengers.\n=> Please turn up at least 30 minutes before the departure.\n");
            printf("Press enter to continue the process.....");
            break;
        case 5:
            system("cls");
            printf("Can I smoke on board?\n");
            printf("=> No! You will be fined when caught smoking on board!\n");
            printf("Press enter to continue the process.....");
            break;
        case 6:
            system("cls");
            printf("thank you and bye\n");
            printf("Press enter to continue the process.....");
            break;
        }
        getch();
    } while (choice != 6);
}