/*Documentation Section Start*/
/**
************************************************************
** @author :  ENG.Yoesf Zaher
** @brief  :  Has All Function Definition In The Project for :-
              - Memory Management
              - Data Management
              - Admin Function
              - Student Function
              - File Access System
** @file   :  StudentRecordSystem.c
************************************************************
**/
/*Documentation Section End*/

/*include language library section start*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
/*include language library section start*/

/*include user defined library section start*/
#include "StudentRecordSystem.h"
/*include user defined library section start*/

/*sub-program section start*/

/*Admin Functions Section Start*/
/**
  * @brief  Allocate the space for Admin object in the memory and
            allocate space for each student object in the memory
  * @param  (Status) Pointer to return status of the process in it
  * @retval The Address of the space that allocate for the admin
**/
Admin_t * Objects_Initialization(uint8_t *Status)
{
    Admin_t *Admin = NULL ;
    uint8_t MaxSize = 0 ;
    Admin = (Admin_t *)malloc(sizeof(Admin_t)) ;
    if(!(Admin) || !(Status))
    {
        Admin = NULL ;
        Status = NULL ;
    }
    else
    {
        Admin->Student = (Student_t **)malloc(Max_Student*sizeof(Student_t *)) ;
        if(!(Admin->Student))
        {
            free(Admin) ;
            Admin = NULL ;
            *Status = ERROR ;
        }
        else
        {
            for(int i = 0 ; i < Max_Student ;i++)
            {
                Admin->Student[i] = (Student_t *)malloc(Max_Student*sizeof(Student_t)) ;
                if(!(Admin->Student[i]))
                {
                    for(int j = 0 ; j < i ; j++)
                    {
                        free(Admin->Student[j]) ;
                    }
                    free(Admin->Student) ;
                    free(Admin) ;
                    Admin = NULL ;
                    *Status = ERROR ;
                }
                else
                {
                    Admin->Student[i]->Password = 1234 ;
                    Admin->Student[i]->Grade = 0 ;
                    Admin->Student[i]->Id = 0 ;
                    Admin->Student[i]->Name = (uint8_t *)malloc(100*sizeof(uint8_t)) ;
                }
            }
            Admin->Password = 1234 ;
            Admin->Student_Count = 0 ;
            Admin->MaxSize = Max_Student ;

            *Status = NO_ERROR ;
        }
    }
    return Admin ;
}


/**
  * @brief  Add New Student Recoed
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t Add_Student_Record(Admin_t *Admin)
{
    uint8_t *Name = NULL ;
    uint32_t Password = 0 ;
    uint32_t Grade = 0 ;
    uint32_t Id  = 0;
    uint32_t number = 0;
    bool isValidInput = false;
    uint8_t Status = ERROR ;

    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {

        if(Admin->Student_Count == Admin->MaxSize)
        {
            printf("Student Data base is Full Now! \n") ;
            Status = ResizeOrNot(Admin) ;
            printf("==========================\n") ;
        }
        /*Add Id Section Start*/
        while (!isValidInput)
        {
            uint8_t input[MAX_LEN_INPUT];
            printf("=>Enter The Id of The Student :  ");
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
            for(int i = 0 ; i < Admin->Student_Count ; i++)
            {
                if(Id == Admin->Student[i]->Id)
                {
                    printf("This Id is Used ,Please Enter another Id .\n") ;
                    isValidInput = false;
                }
                else{/*Nothing*/}
            }
        }
        Admin->Student[Admin->Student_Count]->Id = Id ;
        printf("Student Id Added Successfully :) \n");
        isValidInput = false ;
        /*Add Id Section End*/

        /*Add Grade Section Start*/
        while (!isValidInput)
        {
            printf("=>Enter The Grade of The Student :  ");
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
                Grade = number ;
            }
            if(Grade < 0 || Grade > 100)
            {
                printf("Invalid Grade ,Grade Should From 0 -> 100 Only!\n") ;
                isValidInput = false ;
            }
            else{/**/}
        }
        Admin->Student[Admin->Student_Count]->Grade = Grade ;
        printf("Student Grade Added Successfully :) \n") ;
        isValidInput = false ;
        /*Add Grade Section End*/

        /*Add Password Section Start*/
        while (!isValidInput)
        {
            printf("=>Enter The Password of The Student :  ");
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
                Password = number ;
            }
        }
        Admin->Student[Admin->Student_Count]->Password = Password ;
        isValidInput = false ;
        printf("Student Password Added Successfully :) \n") ;
        /*Add password Section End*/

        /*Add Name Section Start*/
        char input[MAX_LEN_INPUT];
        while (!isValidInput)
        {
            printf("=>Enter Name of The Student: ");
            fgets(input, sizeof(input), stdin);

            // Remove newline character if present
            if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }

            // Check if input contains only alphabetic characters or spaces
            isValidInput = true;
            for (size_t i = 0; i < strlen(input); i++) {
                if (!isalpha(input[i]) && input[i] != ' ') {
                    isValidInput = false;
                    break;
                }
            }
            if (!isValidInput) {
                printf("Invalid input. Please enter alphabetic characters only.\n");
            }
        }
        // Copy the input name to the allocated memory
        strcpy((char *)Admin->Student[Admin->Student_Count]->Name, input);
        printf("Student Name Added Successfully :) \n");
        isValidInput = false;

        Status = NO_ERROR ;
        (Admin->Student_Count)++ ;

    }
    return Status ;
}


/**
  * @brief Remove Student Record
  * @param  (Id) Id of the student that Admin want to remove
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t Remove_Student_Record(Admin_t *Admin ,uint32_t Id)
{
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {
        if(0 == Admin->Student_Count)
        {
            printf("There is no Student in the System! \n") ;
        }
        else
        {
            for(int i = 0 ; i < Admin->Student_Count ; i++)
            {
                if(Admin->Student[i]->Id == Id)
                {
                    printf("Removed Student :-\n") ;
                    printf("     =>Student Name : %s \n",Admin->Student[i]->Name) ;
                    printf("     =>Student Id : %d \n",Admin->Student[i]->Id) ;
                    printf("     =>Student Password : %d \n",Admin->Student[i]->Password) ;
                    printf("     =>Student Grade : %d \n",Admin->Student[i]->Grade) ;
                    if(i == Admin->Student_Count - 1)
                    {
                        Admin->Student[i]->Grade = 0 ;
                        Admin->Student[i]->Password = 1234 ;
                        Admin->Student[i]->Id = 0 ;
                        free(Admin->Student[i]->Name) ;
                        Admin->Student[i]->Name = NULL ;
                        (Admin->Student_Count)-- ;
                        Status = NO_ERROR ;
                        break ;
                    }
                    else
                    {
                        for(int j = i ; j < Admin->Student_Count  ; j++)
                        {
                            Admin->Student[j]->Grade = Admin->Student[j+1]->Grade ;
                            Admin->Student[j]->Password = Admin->Student[j+1]->Password ;
                            Admin->Student[j]->Id = Admin->Student[j+1]->Id ;
                            Admin->Student[j]->Name = Admin->Student[j+1]->Name ;
                        }
                        (Admin->Student_Count)-- ;
                        Status = NO_ERROR ;
                        break ;
                    }
                }
                else
                {/*Nothing*/}
            }
        }
    }
    return Status ;
}

/**
  * @brief  View Student Recoed
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Id) Id of the student that Admin want to View his Record
  * @retval The status of the Process
**/
uint8_t View_Student_Record(Admin_t *Admin ,uint32_t Id)
{
    uint8_t Status = ERROR ;
    if(NULL == Admin)
    {
        Status = ERROR ;
    }
    else
    {
        if(0 == Admin->Student_Count)
        {
            printf("There is no Student in the System! \n") ;
        }
        else
        {
            for(int i = 0; i < Admin->Student_Count ; i++)
            {
                if(Admin->Student[i]->Id == Id)
                {
                    printf("Student-%d :-\n",i+1) ;
                    printf("       =>Password :     %d \n",Admin->Student[i]->Password) ;
                    printf("       =>Id :           %d \n",Admin->Student[i]->Id) ;
                    printf("       =>Grade :        %d \n",Admin->Student[i]->Grade) ;
                    printf("       =>Name :         %s \n",Admin->Student[i]->Name) ;
                    Status = NO_ERROR ;
                    return Status ;
                }
                else
                {/*Nothing*/}
            }
        }
        Status = ERROR ;
    }
    return Status ;
}

/**
  * @brief  View All Records in the System
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t View_All_Records(Admin_t *Admin)
{
    uint8_t Status = ERROR ;
    if(NULL == Admin)
    {
        Status = ERROR ;
    }
    else
    {
        if(0 == Admin->Student_Count)
        {
            printf("There is no Student in the System! \n") ;
        }
        else
        {
            for(int i = 0; i < Admin->Student_Count ; i++)
            {
                    printf("Student-%d :-\n",i+1) ;
                    printf("       =>Password :     %d \n",Admin->Student[i]->Password) ;
                    printf("       =>Id :           %d \n",Admin->Student[i]->Id) ;
                    printf("       =>Grade :        %d \n",Admin->Student[i]->Grade) ;
                    printf("       =>Name :         %s \n",Admin->Student[i]->Name) ;
            }
        }
    }
    return Status ;
}

/**
  * @brief  Edit Admin Password
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Password) The New Password that admin want to set
  * @retval The status of the Process
**/
uint8_t Edit_Admin_Password(Admin_t *Admin ,uint32_t Password)
{
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {
        printf("Old Password : %d \n",Admin->Password) ;
        Admin->Password = Password ;
        Status = NO_ERROR ;
    }
    return Status ;
}

/**
  * @brief  Edit Student Grade
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Id) Id of the student that Admin want to Edit his Grade
  * @retval The status of the Process
**/
uint8_t Edit_Student_Grade(Admin_t *Admin ,uint32_t Grade ,uint32_t Id)
{
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {
        if(0 == Admin->Student_Count)
        {
            printf("There is no Student in the System! \n") ;
        }
        else
        {
            for(int i = 0 ; i < Admin->Student_Count ; i++)
            {
                if(Admin->Student[i]->Id == Id)
                {
                    printf("Old Grade = %d \n",Admin->Student[i]->Grade) ;
                    Admin->Student[i]->Grade = Grade ;
                    Status = NO_ERROR ;
                    break ;
                }
                else
                {/*Nothing*/}
            }
        }
    }
    return Status ;
}

/**
  * @brief  reallocation the data base in the heap to make it Bigger by 2X
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t ResizeOrNot(Admin_t *Admin)
{
    Student_t **Temp = NULL ;
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {
        if(Admin->Student_Count != Admin->MaxSize)
        {
            Status = NO_ERROR ;
        }
        else
        {
            Temp = (Student_t **)realloc(Admin->Student ,(Admin->MaxSize)*2*sizeof(Student_t *)) ;
            if(!Temp)
            {
                Status = ERROR ;
                printf("Resize the Data base is Failled !!\n") ;
            }
            else
            {
                Admin->Student = Temp ;
                (Admin->MaxSize) *= 2 ;
                Status = NO_ERROR ;
                for(int i = Admin->Student_Count ; i < Admin->MaxSize ; i++)
                {
                    Admin->Student[i] = (Student_t *)malloc(sizeof(Student_t)) ;
                    if(!Admin->Student[i])
                    {
                        printf("Error In the Memory !!!!!!!!!\n") ;
                        Status = ERROR ;
                        break ;
                    }
                    else
                    {
                        Admin->Student[i]->Grade = 0 ;
                        Admin->Student[i]->Password = 1234 ;
                        Admin->Student[i]->Id = 0 ;
                        Admin->Student[i]->Name = (uint8_t *)malloc(100*sizeof(uint8_t)) ;
                    }
                }
                printf("Resize the Data base is Successfully Done !!\n") ;
            }
        }
    }
    return Status ;
}
/*Admin Functions Section Start*/

/*Student Functions section Start*/
uint8_t View_Your_Record(Admin_t *Admin ,uint32_t Id)
{
    uint32_t number = 0 ;
    bool isValidInput = false;
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR  ;
    }
    else
    {
        for(int i = 0 ; i < Admin->Student_Count ; i++)
        {
            if(Id == Admin->Student[i]->Id)
            {
                printf("Student-%d :-\n",i+1) ;
                printf("       =>Password :     %d \n",Admin->Student[i]->Password) ;
                printf("       =>Id :           %d \n",Admin->Student[i]->Id) ;
                printf("       =>Grade :        %d \n",Admin->Student[i]->Grade) ;
                printf("       =>Name :         %s \n",Admin->Student[i]->Name) ;
                isValidInput = false;
                Status = NO_ERROR ;
                return Status  ;
            }
            else{/*Nothing*/}
        }
        Status = ERROR ;
    }
    return Status ;
}

uint8_t Edit_Your_Name(Admin_t *Admin ,uint32_t Id)
{
    bool isValidInput = false ;
    char input[MAX_LEN_INPUT];
    uint8_t Status = ERROR ;
    if(!Admin)
    {
        Status = ERROR ;
    }
    else
    {
        while (!isValidInput)
        {
            printf("=>Enter Name of The Student: ");
            fgets(input, sizeof(input), stdin);

            // Remove newline character if present
            if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }

            // Check if input contains only alphabetic characters or spaces
            isValidInput = true;
            for (size_t i = 0; i < strlen(input); i++) {
                if (!isalpha(input[i]) && input[i] != ' ') {
                    isValidInput = false;
                    break;
                }
            }
            if (!isValidInput) {
                printf("Invalid input. Please enter alphabetic characters only.\n");
            }
        }
        // Copy the input name to the allocated memory
        for(int i = 0 ; i < Admin->Student_Count ; i++)
        {
            if(Id == Admin->Student[i]->Id)
            {
                strcpy((char *)Admin->Student[i]->Name, input);
                printf("Student Name Changed Successfully :) \n");
                Status = NO_ERROR ;
                break ;
            }
            else
            {
                Status = ERROR ;
            }

        }
    }
    return Status ;
}

uint8_t Edit_Your_Password(Admin_t *Admin ,uint32_t ID)
{
    uint32_t number = 0 ;
    bool isValidInput = false;
    uint8_t Status = ERROR ;
    uint32_t Id = 0 ;
    uint32_t Counter = 0 ;
    if(!Admin)
    {
        Status = ERROR  ;
    }
    else
    {
        for(int i = 0 ; i < Admin->Student_Count ; i++)
        {
            if(ID == Admin->Student[i]->Id)
            {
                while (!isValidInput)
                {
                    uint8_t input[MAX_LEN_INPUT];
                    printf("=>Enter The New Password :  ");
                    fgets(input, sizeof(input), stdin);

                    // Remove newline character if present
                    if (input[strlen(input) - 1] == '\n')
                    {
                        input[strlen(input) - 1] = '\0';
                    }

                    // Check if input contains only digits
                    isValidInput = true;
                    for (size_t j = 0; j < strlen(input); j++)
                    {
                        if (!isdigit(input[j])) {
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
                        Admin->Student[i]->Password = number ;
                        printf("Password Changed Successsfully :) \n") ;
                        Status = NO_ERROR ;
                    }
                }
            }
        }
    }
    return Status ;
}
/*Student Function section End*/

/*sub-program section end*/

































