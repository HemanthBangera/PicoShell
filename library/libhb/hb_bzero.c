#include "libhb.h"

void *hb_bzero(void *str,size_t n){
    size_t i=0;

    while(i<n){
        ((char *)str)[i] = '\0';
        i++;
    }

    return str;
}
