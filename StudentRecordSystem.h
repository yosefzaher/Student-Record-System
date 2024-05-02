/**
************************************************************
** @author :  ENG.Yoesf Zaher
** @brief  :  Has All Function Declaration In The Project for :-
              - Memory Management
              - Data Management
              - Admin Function
              - Student Function
              - File Access System
** @file   :  StudentRecordSystem.c
************************************************************
**/

#ifndef _STUDENTRECORDSYSTEM_H_
#define _STUDENTRECORDSYSTEM_H_

#include "DataType.h"


#define ERROR 0
#define NO_ERROR 1

#define MAX_LEN_INPUT 100
#define Max_Student 1



typedef struct{
    char *Name ;
    uint32_t Grade ;
    uint32_t Password ;
    uint32_t Id ;
}Student_t ;

typedef struct{
    Student_t **Student ;
    uint32_t Password ;
    uint32_t Student_Count ;
    uint32_t MaxSize ;
}Admin_t ;

typedef enum{
    ADMIN = 4 ,
    USER
}AdminOrStudent_t ;

/*Admin Functions Start*/
/**
  * @brief  Allocate the space for Admin object in the memory and
            allocate space for each student object in the memory
  * @param  (Status) Pointer to return status of the process in it
  * @retval The Address of the space that allocate for the admin
**/
Admin_t * Objects_Initialization(uint8_t *Status) ;

/**
  * @brief  Add New Student Recoed
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t Add_Student_Record(Admin_t *Admin) ;

/**
  * @brief Remove Student Record
  * @param  (Id) Id of the student that Admin want to remove
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t Remove_Student_Record(Admin_t *Admin ,uint32_t Id) ;

/**
  * @brief  View Student Recoed
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Id) Id of the student that Admin want to View his Record
  * @retval The status of the Process
**/
uint8_t View_Student_Record(Admin_t *Admin ,uint32_t Id) ;

/**
  * @brief  View All Records in the System
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t View_All_Records(Admin_t *Admin) ;

/**
  * @brief  Edit Admin Password
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Password) The New Password that admin want to set
  * @retval The status of the Process
**/
uint8_t Edit_Admin_Password(Admin_t *Admin ,uint32_t Password) ;

/**
  * @brief  Edit Student Grade
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @param  (Id) Id of the student that Admin want to Edit his Grade
  * @retval The status of the Process
**/
uint8_t Edit_Student_Grade(Admin_t *Admin ,uint32_t Grade ,uint32_t Id) ;

/**
  * @brief  reallocation the data base in the heap to make it Bigger by 2X
  * @param  (Admin) Pointer Point to the Admin object in the memeory
  * @retval The status of the Process
**/
uint8_t ResizeOrNot(Admin_t *Admin) ;
/*Admin Functions End*/


/*Student Function Start*/
uint8_t View_Your_Record(Admin_t *Admin ,uint32_t Id) ;
uint8_t Edit_Your_Name(Admin_t *Admin ,uint32_t Id) ;
uint8_t Edit_Your_Password(Admin_t *Admin ,uint32_t ID) ;
/*Student Function End*/

#endif // _STUDENTRECORDSYSTEM_H_
