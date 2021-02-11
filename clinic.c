#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Sheet.h"

#define	Password	1234

				
int main(void)
{
	
  while(1)
  { u8 Entery_Point;
	printf("***************************************************\n");
    printf("*Welcom,\n*For login Click 1\n");
	printf("*For Close System Click 2\n");
	scanf("%d",&Entery_Point);
	if(Entery_Point == 1)
	{
	u8 flag_pass = 0;
	printf("***************************************************\n");
	printf("*Choose Your Mode :\n");
	printf("*For Admin Mode Click 1\n");
	printf("*For User Mode Click 2\n");
	u32 SelectMode = 0;
	scanf("%d",&SelectMode);
	if(SelectMode == 1)
	{
		for(u32 i=0;i<3;i++)
		{
			u32 pass = 0;
			printf("Please Enter Your Password : ");
			scanf("%d",&pass);
			if(pass == Password)
			{
				flag_pass = 1;
				break;
			}
			else if (pass == Password && i != 2)
			{
				printf("Incorrect Password, try again\n");
			}
		}
		if(flag_pass == 0)
		{
			break;
		}
		else
		{
			printf("***************************************************\n");
			printf("*Choose Your Operation \n");
			printf("*For Add new patient record Click 'A' \n");
			printf("*For Edit patient record Click 'E' \n");
			printf("*For Reserve a slot with the doctor Click 'R' \n");
			printf("*For Cancel reservation. Click 'C' \n");
			char Operation ;
			scanf(" %c",&Operation);
			if(Operation == 'A')
			{
				u8 * Add_Name  ; 
				u32   Add_Age   ;
				u32   Add_Gender;
				u32   Add_ID    ;
				printf("***************************************************\n");
				printf("Please Enter Your Name : ");
			scanf(" %[^\n]s",&Add_Name);
				printf("Please Enter Your  Age : ");
				scanf("%d",&Add_Age);
				printf("Please Enter Your Gender :\nFor Male click 'M' or 'm'\nFor Female click 'F' or 'f' : ");
				scanf(" %c",&Add_Gender);
				printf("Please Enter Your ID : ");
				scanf("%d",&Add_ID);
				Add(Add_Name,Add_Age,Add_Gender,Add_ID);
				printf("Done, Thank You \n\n\n");
			}
			else if (Operation == 'E')
			{
				u8 * Add_Name ;
				u32   Add_Age   ;
				u8   Add_Gender;
				u32   Add_ID    ;
				printf("Please Enter Your ID : ");
				scanf("%d",&Add_ID);
				if(Find(Add_ID) == null)
					printf("Incorrect ID\n");
				else {
				printf("Please Enter Your Name : ");
				scanf("%s",&Add_Name);
				printf("Please Enter Your  Age : ");
				scanf("%d",&Add_Age);
				printf("Please Enter Your Gender : ");
				scanf(" %c",&Add_Gender);
				Edit(Add_ID,Add_Name,Add_Age,Add_Gender);
				printf("Done, Thank You \n\n\n");
				}
			}

			else if (Operation == 'R')
			{
				u32 Patient_ID;
				u32 Select   ;
				printf("Please Enter Your ID : ");
				scanf("%d",&Patient_ID);
				ViewSlots();
				printf("Please Select Your Date : ");
				scanf("%d",&Select);
				Reserve_aslot(Select,Patient_ID);
				printf("Done, Thank You \n\n\n");
			}
			else if (Operation == 'C')
			{
				u32 Entering_ID;
				printf("Please Enter Your ID : ");
				scanf("%d",&Entering_ID);
				Cancel_Reservation(Entering_ID);
				printf("Done, Thank You \n\n\n");
			}
			else
			{
				printf("Incorrect Input, Tryagain\n");
			}
			
		}
	}
	else if (SelectMode == 2)
	{
			printf("***************************************************\n");
			printf("*Choose Your Operation \n");
			printf("*For View patient record Click 'A' \n");
			printf("*For View today/'s Reservations Click 'B' \n");
			char Operation ;
			scanf(" %c",&Operation);
			if(Operation == 'A')
			{
				u32 Entering_ID;
				printf("Please Enter Your ID : ");
				scanf("%d",&Entering_ID);
				ViewPatientRecord(Entering_ID);
				printf("Done, Thank You \n\n\n");
			}
			else if (Operation == 'B')
			{
				ViewReservedSlots();
				printf("Done, Thank You \n\n\n");
			}
			else
			{
				printf("Incorrect Input, Tryagain\n");
			}
		
	}
	else 
	{
		printf("Incorrect Input, Tryagain\n");
	}
	}
	else
	{
		break;
	}
}	
	return 0;
}