#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Sheet.h"
new_node_patient * Head_patient = null; 

u8 * Dates[6] = {"Empty","2pm to 2:30pm","2:30pm to 3pm","3pm to 3:30pm","4pm to 4:30pm","4:30pm to 5pm"};
u32 Dates_ID[6] = {0};

void Add(u8 * Copy_Name,u8 Copy_Age,u8 Copy_Gender,u32 Copy_ID )
{
	new_node_patient * ptr = (new_node_patient *)malloc( sizeof(new_node_patient) ) ;
	
	ptr -> Name   = Copy_Name   ; //ptr1 ptr2 , ptr1 = ptr2 ;
	ptr -> Age    = Copy_Age    ;
	ptr -> Gender = Copy_Gender ;
	ptr -> ID     = Copy_ID     ;
	ptr -> next   = Head_patient;
	Head_patient  = ptr         ;
	
}
void ViewPatientRecord(u32 View_ID)
{
	if( Head_patient != null ){
		
		new_node_patient * temp = Find(View_ID) ;
		if(temp == null)
		{
			printf("NotFound\n");
		}
		else
		{	
			printf("%s\n",&(temp -> Name));
			printf("%d\n",temp -> Age);
			printf("%c\n",temp -> Gender);
			printf("%d\n",temp -> ID);
		}
	}else{
		printf("Your List Empty \n");
	}
	
}
new_node_patient * Find(u32 find_ID)
{
	new_node_patient * temp = Head_patient ;
	for(;temp!= null ; temp=temp->next)
	{
		if(temp->ID == find_ID)
			break;
	}
		return temp;
}
void Edit(u32 edit_ID,u8 * Copy_Name,u8 Copy_Age,u8 Copy_Gender)
{
	new_node_patient * temp = Find(edit_ID);
	new_node_patient * prev = Head_patient;
	if(temp == null)
		printf("Incorrect ID\n");
	else 
	{
		temp -> Name = Copy_Name  ;
		temp -> Age  = Copy_Age   ;
		temp -> Gender = Copy_Gender ;
	}
}
void ViewSlots(void)
{
	
	for(int i = 1; i<6 ; i++)
	{
		if(Dates_ID[i] != 0)
			continue;
		else
		{
			printf("%d- %s\n",i,Dates[i]);
		}
	}
}
void ViewReservedSlots(void)
{
	for(int i = 1; i<6 ; i++)
	{
		if(Dates_ID[i] == 0)
			continue;
		else
		{
			printf("%s\n",Dates[i]);
		}
	}
	
}
void Reserve_aslot(u8 number , u32 RE_ID)
{
	Dates_ID[number]= RE_ID;
}
void Cancel_Reservation(u32 RE_ID)
{
	for(int i = 1;i<6;i++)
	{
		if(Dates_ID[i] == RE_ID)
		{
			Dates_ID[i]=0;
			break;
		}
	}
}