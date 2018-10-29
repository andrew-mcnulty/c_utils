#include<stdio.h>
#include<stdlib.h>
#include "list_int.h"

void add(list_int* head, int dat){
	if(head->data == 0){
		head->data = dat;
		return;
	}	
	
	while(head->next_node != NULL){;
		head = head->next_node;
	}

	list_int *next = malloc(sizeof(list_int));
	next->next_node = NULL;
	next->data = dat;
	
	head->next_node = next;
	
}

list_int* get_node(list_int* head, int loc){
	if(loc == 0){
		return head;
	}else if(head->next_node == NULL){
		return NULL;
	}else{
		get_node(head->next_node, loc - 1);
	}
}

void print_list(list_int* head){	
	
	printf("[");
	
	while(1){
		printf("%d", head->data);
		
		if(head->next_node == NULL){
			printf("]\n");
			return;
		}
		
		printf(",");
		
		head = head->next_node;
	}
}

void delete(list_int** head, int loc){	
	//start of list?
	if(loc == 0){
		*head = (*head)->next_node;
		return;
	}
	
	//end of list?
	if(get_node(*head, loc + 1) == NULL){
		get_node(*head, loc - 1)->next_node = NULL;
		return;
	}
	
	get_node(*head, loc - 1)->next_node = get_node(*head, loc + 1);
	
	free(get_node(*head, loc));
	
	return;
	
}

int get(list_int* head, int loc){
	return get_node(head, loc)->data;
}

