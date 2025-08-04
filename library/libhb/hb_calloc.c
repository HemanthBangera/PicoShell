#include "libhb.h"

void *  hb_calloc(size_t size,size_t total){

    void *ret;
    ret = malloc(size*total);
    if(!ret){
        return (0);
    }
    hb_bzero(ret,size*total);
    return (ret);
}