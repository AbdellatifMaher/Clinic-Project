#define null 0

typedef struct node_patient{
	u8 *  Name		    		;
	u8    Age         		    ;
	u8    Gender       			;
	u32    ID					;
    struct node_patient *  next ;
	
}new_node_patient;

void Add(u8 * Copy_Name,u8 Copy_Age,u8 Copy_Gender,u32 Copy_ID );
void ViewPatientRecord(u32 View_ID);
new_node_patient * Find(u32 find_ID);
void Edit(u32 edit_ID,u8 * Copy_Name,u8 Copy_Age,u8 Copy_Gender);
void ViewSlots(void);
void ViewReservedSlots(void);
void Reserve_aslot(u8 number , u32 RE_ID);
void Cancel_Reservation(u32 RE_ID);

