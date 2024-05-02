#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <stdbool.h>
#include <ctype.h>

#include "StudentRecordSystem.h"

/******** The Main Object *********/
Admin_t *Admin = NULL ;
/**********************************/

/*Global Declaration Section Start*/
uint32_t Id = 0 ;
uint32_t *ID = &Id ;
uint8_t *Welcome_Statement = "Hello in Student Record System :) \n" ;
uint8_t Count = 0 ;
AdminOrStudent_t Check = ADMIN ;
uint8_t Status = ERROR ;
int number;
bool isValidInput = false;
uint32_t NewPassword = 0 ;
uint32_t OldPassword = 0 ;
uint32_t OldGrade = 0 ;
uint32_t NewGrade = 0 ;
uint8_t *Name = NULL ;
uint8_t OldId = 0 ;
/*Global Declaration Section End*/

static void Start_Program(uint8_t *Welcome_Statement ,uint8_t Count) ;
static AdminOrStudent_t Check_Who(void) ;
static uint8_t Check_Password_Id(Admin_t *Admin ,AdminOrStudent_t State ,uint32_t *ID) ;

int main()
{
    Admin = Objects_Initialization(&Status) ;

    Start_Program(Welcome_Statement ,Count) ;

    Check = Check_Who();
    if(Check == USER)//Student
    {       Student :
            printf("==========================\n") ;
            printf("Please Wait a Seconds Starting Student Mode");
            for(int i = 0 ; i < 15 ; i++)
            {
                printf(".");
                Sleep(150) ;
            }
            printf("\n");
            printf("==========================\n");
            if(!Admin->Student_Count)
            {
                printf("There is No Student in the System Please Contact with the Admin to Solve this issue \n");
                printf("Gmail : Admin@gmail.com\n");
            }
            else
            {
                Status = Check_Password_Id(Admin ,USER ,ID) ;
                if(!Status)
                {
                    printf("Your Attemptes is Ended Please Try again later :( \n");
                    return 0 ;
                }
                else
                {
                    printf("==========================\n");
                    printf("Student Mode is Active Now :)\n") ;
                    while(1){
                        printf("============================================================================================\n");
                        printf("What do you want to do :- \n") ;
                        Sleep(180) ;
                        printf("    1 => View Your Record .\n") ;
                        Sleep(180) ;
                        printf("    2 => Edit Your Password .\n") ;
                        Sleep(180) ;
                        printf("    3 => Edit Your Name .\n") ;
                        Sleep(180) ;
                        printf("    4 => Quit The System .\n") ;
                        printf("==========================\n");

                        while(1)
                        {
                            while (!isValidInput)
                            {
                                printf("=>Enter a number: ");
                                char input[MAX_LEN_INPUT];
                                fgets(input, sizeof(input), stdin);

                                // Remove newline character if present
                                if (input[strlen(input) - 1] == '\n')
                                {
                                    input[strlen(input) - 1] = '\0';
                                }

                                // Check if input contains only digits
                                isValidInput = true;
                                for (size_t i = 0; i < strlen(input); i++)
                                {
                                    if (!isdigit(input[i])) {
                                        isValidInput = false;
                                        break;
                                    }
                                }
                                if(!isValidInput)
                                {
                                    printf("Invalid input. Please enter numbers only.\n");
                                }
                                else
                                {
                                    number = atoi(input); // Convert input to integer
                                }
                            }
                            if(number == 1 || number == 2 || number == 3 || number == 4)
                            {
                                isValidInput = false ;
                                break ;
                            }
                            else
                            {
                                printf("Invalid Input ,Please Enter Operation from 1 -> 4 !\n");
                                isValidInput = false ;
                            }
                        }
                            switch(number)
                            {
                                case 1 :
                                    Status = View_Your_Record(Admin ,*ID) ;
                                break ;
                                case 2 :
                                    Status = Edit_Your_Password(Admin ,*ID) ;
                                break ;
                                case 3 :
                                    Status = Edit_Your_Name(Admin ,*ID) ;
                                break ;
                                case 4 :
                                    Exit() ;
                                    return 0 ;
                                break ;
                                default :

                                break ;
                            }
                    }
                }
            }
    }
    /*************************************************************************************************************************************************************/
    else//Admin
    {
        Start :
            printf("==========================\n") ;
            printf("Please Wait a Seconds Starting Admin Mode");
            for(int i = 0 ; i < 15 ; i++)
            {
                printf(".");
                Sleep(150) ;
            }
            printf("\n");
            printf("==========================\n");
            Status = Check_Password_Id(Admin ,ADMIN ,ID) ;
            if(!Status)
            {
                printf("Your Attemptes is Ended Please Try again later :( \n");
                return 0 ;
            }
            else
            {
                printf("==========================\n");
                printf("Admin Mode is Active Now :)\n") ;
                while(1){
                    printf("============================================================================================\n");
                    printf("What do you want to do :- \n") ;
                    Sleep(180) ;
                    printf("    1 => Add Student Record .\n") ;
                    Sleep(180) ;
                    printf("    2 => Remove Student Record .\n") ;
                    Sleep(180) ;
                    printf("    3 => View Student Record .\n") ;
                    Sleep(180) ;
                    printf("    4 => View All Records .\n") ;
                    Sleep(180) ;
                    printf("    5 => Edit Admin Password .\n") ;
                    Sleep(180) ;
                    printf("    6 => Edit Student Grade .\n") ;
                    Sleep(180) ;
                    printf("    7 => Quit The System .\n") ;
                    printf("==========================\n");

                    while(1)
                    {
                        while (!isValidInput)
                        {
                            printf("=>Enter a number: ");
                            char input[MAX_LEN_INPUT];
                            fgets(input, sizeof(input), stdin);

                            // Remove newline character if present
                            if (input[strlen(input) - 1] == '\n')
                            {
                                input[strlen(input) - 1] = '\0';
                            }

                            // Check if input contains only digits
                            isValidInput = true;
                            for (size_t i = 0; i < strlen(input); i++)
                            {
                                if (!isdigit(input[i])) {
                                    isValidInput = false;
                                    break;
                                }
                            }
                            if(!isValidInput)
                            {
                                printf("Invalid input. Please enter numbers only.\n");
                            }
                            else
                            {
                                number = atoi(input); // Convert input to integer
                            }
                        }
                        if(number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8)/////////
                        {
                            break ;
                        }
                        else
                        {
                            printf("Invalid Input ,Please Enter Operation from 1 -> 7 !\n");
                            isValidInput = false ;
                        }
                    }
                    switch(number)
                    {
                        case 1 :
                            Status = Add_Student_Record(Admin) ;
                        break ;
                        case 2 :
                            isValidInput = false ;
                            while (!isValidInput)
                            {
                                printf("=>Enter The Id of The Student :  ");
                                char input[MAX_LEN_INPUT];
                                fgets(input, sizeof(input), stdin);

                                // Remove newline character if present
                                if (input[strlen(input) - 1] == '\n')
                                {
                                    input[strlen(input) - 1] = '\0';
                                }

                                // Check if input contains only digits
                                isValidInput = true;
                                for (size_t i = 0; i < strlen(input); i++)
                                {
                                    if (!isdigit(input[i])) {
                                        isValidInput = false;
                                        break;
                                    }
                                }
                                if(!isValidInput)
                                {
                                    printf("Invalid input. Please enter numbers only.\n");
                                }
                                else
                                {
                                    number = atoi(input); // Convert input to integer
                                    Id = number ;
                                }
                            }
                            Status = Remove_Student_Record(Admin ,Id) ;
                            if(!Status)
                            {
                                printf("The Id You Entered is not in the System !\n") ;
                            }
                            else
                            {/*Nothing*/}
                        break ;
                        case 3 :
                            isValidInput = false ;
                            while (!isValidInput)
                            {
                                printf("=>Enter The Id of The Student :  ");
                                char input[MAX_LEN_INPUT];
                                fgets(input, sizeof(input), stdin);

                                // Remove newline character if present
                                if (input[strlen(input) - 1] == '\n')
                                {
                                    input[strlen(input) - 1] = '\0';
                                }

                                // Check if input contains only digits
                                isValidInput = true;
                                for (size_t i = 0; i < strlen(input); i++)
                                {
                                    if (!isdigit(input[i])) {
                                        isValidInput = false;
                                        break;
                                    }
                                }
                                if(!isValidInput)
                                {
                                    printf("Invalid input. Please enter numbers only.\n");
                                }
                                else
                                {
                                    number = atoi(input); // Convert input to integer
                                    Id = number ;
                                }
                            }
                            Status = View_Student_Record(Admin ,Id) ;
                            if(!Status)
                            {
                                printf("The Id You Entered is not in the System .\n") ;
                            }
                        break ;
                        case 4 :
                            Status = View_All_Records(Admin) ;
                        break ;
                        case 5 :
                            isValidInput = false ;
                            while (!isValidInput)
                            {
                                printf("=>Enter The New Password :  ");
                                char input[MAX_LEN_INPUT];
                                fgets(input, sizeof(input), stdin);

                                // Remove newline character if present
                                if (input[strlen(input) - 1] == '\n')
                                {
                                    input[strlen(input) - 1] = '\0';
                                }

                                // Check if input contains only digits
                                isValidInput = true;
                                for (size_t i = 0; i < strlen(input); i++)
                                {
                                    if (!isdigit(input[i])) {
                                        isValidInput = false;
                                        break;
                                    }
                                }
                                if(!isValidInput)
                                {
                                    printf("Invalid input. Please enter numbers only.\n");
                                }
                                else
                                {
                                    number = atoi(input); // Convert input to integer
                                    NewPassword = number ;
                                }
                            }
                            OldPassword = Admin->Password ;
                            Status = Edit_Admin_Password(Admin ,NewPassword) ;
                            if(!Status)
                            {
                                printf("The Id You Entered is not in the System !\n") ;
                            }
                            else
                            {
                                printf("Password Changed Successfully :) \n") ;
                                printf("The New Password : %d \n",NewPassword) ;
                            }
                            isValidInput = false ;
                            goto Start ;
                        break ;
                        case 6 :
                            isValidInput = false ;
                            while (!isValidInput)
                            {
                                printf("=>Enter The Id of The Student :  ");
                                char input[MAX_LEN_INPUT];
                                fgets(input, sizeof(input), stdin);

                                // Remove newline character if present
                                if (input[strlen(input) - 1] == '\n')
                                {
                                    input[strlen(input) - 1] = '\0';
                                }

                                // Check if input contains only digits
                                isValidInput = true;
                                for (size_t i = 0; i < strlen(input); i++)
                                {
                                    if (!isdigit(input[i])) {
                                        isValidInput = false;
                                        break;
                                    }
                                }
                                if(!isValidInput)
                                {
                                    printf("Invalid input. Please enter numbers only.\n");
                                }
                                else
                                {
                                    number = atoi(input); // Convert input to integer
                                    Id = number ;
                                }
                            }
                            printf("Enter The New Grade :  ");
                            fflush(stdin) ;
                            scanf("%d",&NewGrade) ;
                            fflush(stdin) ;
                            Status = Edit_Student_Grade(Admin ,NewGrade ,Id) ;
                            if(!Status)
                            {
                                printf("The Id You Entered is not in the System !\n") ;
                            }
                            else
                            {
                                printf("Grade Changed Successfully :) \n") ;
                                printf("The New Grade : %d \n",NewGrade) ;
                            }
                            isValidInput = false ;
                        break ;
                        case 7 :
                            Exit() ;
                            return 0 ;
                        break ;
                        case 8 :////////////////////////////
                            goto Student ;
                        break ;
                        default :

                        break ;
                    }
                    isValidInput = false ;
                }
        }
    }
    return 0;
}


static AdminOrStudent_t Check_Who(void)
{
    AdminOrStudent_t Check = ADMIN ;
    int number;
    bool isValidInput = false;

    while (!isValidInput) {
        printf("Choose The Mode You Want :\t Admin -> Any Number  \t Student -> Zero\n") ;
        printf("=>Enter a number: ");
        char input[MAX_LEN_INPUT];
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Check if input contains only digits
        isValidInput = true;
        for (size_t i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isValidInput = false;
                break;
            }
        }

        if (!isValidInput) {
            printf("Invalid input. Please enter numbers only.\n");
        } else {
            number = atoi(input); // Convert input to integer
        }
    }
    if(!number)
    {
        Check = USER ;
    }
    else
    {
        Check = ADMIN ;
    }
    return Check;

}

static void Start_Program(uint8_t *Welcome_Statement ,uint8_t Count)
{
    for(int i = 0 ; i < 70 ; i++)
    {
        printf("*") ;
        Sleep(11) ;
    }
    printf("\n\t\t");
    while(Welcome_Statement[Count])
    {
        printf("%c",Welcome_Statement[Count]) ;
        Sleep(10) ;
        Count++ ;
    }
    for(int i = 0 ; i < 70 ; i++)
    {
        printf("*") ;
        Sleep(15) ;
    }
    printf("\n");
}

static uint8_t Check_Password_Id(Admin_t *Admin ,AdminOrStudent_t State ,uint32_t *ID)
{
    uint32_t Counter = 0 ;
    uint32_t Id = 0 ;
    uint8_t Check = 0 ;
    uint8_t Attemptes = 3 ;
    uint32_t number = 0;
    bool isValidInput = false;
    if(ADMIN == State)/*Check The Password of Admin Only*/
    {
        printf("Now You Will Enter Your Password Note That You Have Only Three Attemptes ,And the Password is Only Consists of Numbers!\n");
        printf("==========================\n");
        while(Attemptes)
        {
            while (!isValidInput) {
                printf("Now You Have Only %d Attemptes\t",Attemptes) ;
                printf("Please Enter Your Password :  ") ;
                char input[MAX_LEN_INPUT];
                fgets(input, sizeof(input), stdin);

                // Remove newline character if present
                if (input[strlen(input) - 1] == '\n')
                {
                    input[strlen(input) - 1] = '\0';
                }

                // Check if input contains only digits
                isValidInput = true;
                for (size_t i = 0; i < strlen(input); i++)
                {
                    if (!isdigit(input[i])) {
                        isValidInput = false;
                        break;
                    }
                }

                if (!isValidInput)
                {
                    printf("Invalid Pass. Please enter numbers only.\n");
                }
                else {
                    number = atoi(input); // Convert input to integer
                }
            }
            if(number == Admin->Password)
            {
                Check = NO_ERROR ;
                break ;
            }
            else
            {
                Check = ERROR ;
                Attemptes--;
                isValidInput = false;
            }
        }
    }
    else/*Check The Password And Id of Student*/
    {
        while (!isValidInput) {
            printf("Please Enter Your Id :  ") ;
            char input[MAX_LEN_INPUT];
            fgets(input, sizeof(input), stdin);

            // Remove newline character if present
            if (input[strlen(input) - 1] == '\n')
            {
                input[strlen(input) - 1] = '\0';
            }

            // Check if input contains only digits
            isValidInput = true;
            for (size_t i = 0; i < strlen(input); i++)
            {
                if (!isdigit(input[i])) {
                    isValidInput = false;
                    break;
                }
            }

            if (!isValidInput)
            {
                printf("Invalid Pass. Please enter numbers only.\n");
            }
            else {
                number = atoi(input); // Convert input to integer
            }
        }
        printf("Serch for you in the System") ;
        for(int i = 0 ; i < 15 ; i++)
        {
            printf(".");
            Sleep(250) ;
        }
        printf("\n") ;
        for(int i = 0 ; i < Admin->Student_Count ;i++)
        {
            if(Admin->Student[i]->Id == number)
            {
                Check = NO_ERROR ;
                printf("Hello - %s - How are You :)\n",Admin->Student[i]->Name);
                Counter = i ;
                *ID = number ;
                break ;
            }
        }
        if(!Check)
        {
            Check = ERROR ;
            printf("There is No Student in the System with this Id ,Please Contact with the Admin to Solve this issue \n");
            printf("Gmail : Admin@gmail.com\n");
            return Check ;
        }
        /********************************************************/
        isValidInput = false ;
        printf("Now to access your record please Enter the Password .\n") ;
        while(Attemptes)
        {
            while (!isValidInput) {
                printf("Now You Have Only %d Attemptes\t",Attemptes) ;
                printf("Please Enter Your Password :  ") ;
                char input[MAX_LEN_INPUT];
                fgets(input, sizeof(input), stdin);

                // Remove newline character if present
                if (input[strlen(input) - 1] == '\n')
                {
                    input[strlen(input) - 1] = '\0';
                }

                // Check if input contains only digits
                isValidInput = true;
                for (size_t i = 0; i < strlen(input); i++)
                {
                    if (!isdigit(input[i])) {
                        isValidInput = false;
                        break;
                    }
                }

                if (!isValidInput)
                {
                    printf("Invalid Pass. Please enter numbers only.\n");
                }
                else {
                    number = atoi(input); // Convert input to integer
                }
            }
            if(number == Admin->Student[Counter]->Password)
            {
                Check = NO_ERROR ;
                break ;
            }
            else
            {
                Check = ERROR ;
                Attemptes--;
                isValidInput = false;
            }
        }

    }
    return Check ;
}

void Exit(void)
{
    printf("Closing The System") ;
    for(int i = 0 ; i < 20 ;i++)
    {
        printf(".");
        Sleep(250) ;
    }
    printf("\n") ;
    printf("Press any Key To Exit...........") ;
    getchar() ;
    printf("==========================\n");
}
