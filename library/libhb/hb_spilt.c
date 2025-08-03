#include "libhb.h"

void free_arr(char **arr){
    size_t i=0;

    while(arr[i]){
        free(arr[i]);
        i++;
    }

    free(arr);
}