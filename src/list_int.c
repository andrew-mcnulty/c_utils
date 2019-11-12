#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "list_int.h"

void list_int_add(list_int* head, int dat){
	//If start of list has no data
	if(head->data == NULL){
		head->data = (int*) malloc(sizeof(int));

		*(head->data) = dat;
		return;
	}

	//Iterate to end of list
	while(head->next_node != NULL){
		head = head->next_node;
	}

	//new node
	list_int* next = (list_int*) malloc(sizeof(list_int));
	next->next_node = NULL;
	next->data = (int*) malloc(sizeof(int));

	*(next->data) = dat;

	//update end of list
	head->next_node = next;
}

list_int* list_int_get_node(list_int* head, int loc){
	if(loc == 0){
		return head;
	}else if(head->next_node == NULL){
		return NULL;
	}else{
		//go to next node and decrement location
		//will be at correct noce when loc == 0
		list_int_get_node(head->next_node, loc - 1);
	}
}

void list_int_print_list(list_int* head){

	printf("[");

	while(1){
		//print data of current node
		printf("%d", *(head->data));

		//finish if this is end of list
		if(head->next_node == NULL){
			printf("]\n");
			return;
		}

		printf(",");

		//go to next node
		head = head->next_node;
	}
}

void list_int_delete_elem(list_int** head, int loc){
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

	//pointer to this node now points to next node
	list_int_get_node(*head, loc - 1)->next_node = list_int_get_node(*head, loc + 1);

	free(list_int_get_node(*head, loc));

	return;
}

int list_int_get(list_int* head, int loc){
	return *(list_int_get_node(head, loc)->data);
}

//TODO: Rewrite all of this. Currently broken
//and design does not support multi digit integers
char* list_int_as_string(list_int* head){
	char* string = (char*) calloc(BUFFLEN, sizeof(char));
	sprintf(string, "[");
	int loc = 1;

	while(loc < BUFFLEN - 2){
		loc++;
		//print data of current node
		char num[8];
		sprintf(num, "%d", *(head->data));
		strcat(string, num);
		//finish if this s iend of list
		if(head->next_node == NULL){
			strcat(string, "]\0");
			return string;
		}

		strcat(string, ",");

		//go to next node
		head = head->next_node;
	}
	//reached buffer length
	strcat(string, "]\0");
	return string;
}

int list_int_length(list_int* head){
	if(head->data == NULL){
		return 0;
	}

	int len = 0;
	short atEnd = 0;

	while(atEnd == 0){
		len++;

		if(list_int_get_node(head, len) == NULL){
			atEnd = 1;
		}
	}

	return len;
}
