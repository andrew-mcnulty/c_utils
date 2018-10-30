#include<stdio.h>
#include<stdlib.h>
#include "../src/list_int.h"
#define PASS 1
#define FAIL -1

int main(){
    printf("TEST ADD: %d\n", test_add_and_get());
    printf("TEST GET: %d\n", test_get_node());
    printf("TEST DELETE: %d\n", test_list_int_delete_elem());


    return 0;
}

int test_add_and_get(){
    list_int* list = (list_int*) malloc(sizeof(list_int));

    for(int i = 0; i < 100; i++){
        list_int_add(list, i);
    }

    for(int j = 0; j < 100; j++){
        if(list_int_get(list, j) != j){
            return FAIL;
        }
    }

    return PASS;
}

int test_get_node(){
    list_int* list = (list_int*) malloc(sizeof(list_int));

    list_int_add(list, 5);
    list_int_add(list, 8);

    int dat1 = *(list_int_get_node(list, 0)->data);
    int dat2 = *(list_int_get_node(list, 1)->data);

    if(dat1 != 5 || dat2 != 8){
        return FAIL;
    }

    return PASS;

}

int test_list_int_print_list(){

}

int test_list_int_delete_elem(){
    list_int* list = (list_int*) malloc(sizeof(list_int));

    list_int_add(list, 5);
    list_int_add(list, 8);
    list_int_add(list, 2);
    list_int_add(list, 9);

    list_int_delete_elem(&list, 2);
    
    return list_int_length(list) == 3 ? PASS: FAIL;
}

int test_list_int_get(){

}

int test_list_int_as_string(){

}

int test_list_int_length(){

}
