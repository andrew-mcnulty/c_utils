#ifndef LISTINT_H_INCLUDED
#define LISTINT_H_INCLUDED

	typedef struct list_int{  
        struct list_int* next_node;
		int data;
    }list_int;
	
    // FUNCTIONS    
	void add(list_int* head, int dat);
	
	list_int* get_node(list_int* head, int loc);
	
	void print_list(list_int* head);
	
	void delete_elem(list_int** head, int loc);
	
	//returns data of item at loc
	int get(list_int* head, int loc);

#endif