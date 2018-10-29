#include<stdio.h>
#include<stdlib.h>
#include "list_int.h"

void list_int_add(list_int* head, int dat){
	if(head->data == NULL){
		head->data = (int*) malloc(sizeof(int));

		*(head->data) = dat;
		return;
	}	
	
	while(head->next_node != NULL){
		head = head->next_node;
	}

	list_int* next = (list_int*) malloc(sizeof(list_int));
	next->next_node = NULL;
	next->data = (int*) malloc(sizeof(int));
	
	*(next->data) = dat;

	head->next_node = next;
}

list_int* list_int_get_node(list_int* head, int loc){
	if(loc == 0){
		return head;
	}else if(head->next_node == NULL){
		return NULL;
	}else{
		list_int_get_node(head->next_node, loc - 1);
	}
}

void list_int_print_list(list_int* head){	
	
	printf("[");
	
	while(1){
		printf("%d", *(head->data));
		
		if(head->next_node == NULL){
			printf("]\n");
			return;
		}
		
		printf(",");
		
		head = head->next_node;
	}
}

void list_int_delete(list_int** head, int loc){	
	//start of list?
	if(loc == 0){
		*head = (*head)->next_node;
		return;
	}
	
	//end of list?
	if(list_int_get_node(*head, loc + 1) == NULL){
		list_int_get_node(*head, loc - 1)->next_node = NULL;
		return;
	}
	
	list_int_get_node(*head, loc - 1)->next_node = list_int_get_node(*head, loc + 1);
	
	free(list_int_get_node(*head, loc));
	
	return;
	
}

int list_int_get(list_int* head, int loc){
	return *(list_int_get_node(head, loc)->data);
}

const char * list_int_as_string(list_int* head){
	int len = list_int_length(head);

	char* string = (char * )calloc(len + 2, sizeof(char));

	string[0] = '[';
	string[len + 1] = ']';

	for(int i = 1; i < len + 1; i++){
		string[i] = (char) list_int_get(head, i);
	}

	return string;
}

int list_int_length(list_int* head){
	int len = 0;

	while(1){
		len++;

		if(head->next_node == NULL){
			return -1;
		}

		head = head->next_node;
	}

	return len;
}

