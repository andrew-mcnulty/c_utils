#include "list_int.h"
#include<stdlib.h>

int main(){
	list_int* l = malloc(sizeof(list_int));
	
	add(l, 1);
	add(l, 1);
	add(l, 1);
	add(l, 3);
	
	print_list(l);
	
	return 0;
}