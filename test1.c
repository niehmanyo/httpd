//
// Created by Nie on 2024/11/24.
//
// 数组和指针
#include "stdlib.h"
#include "stdio.h"

int main(){
    int arr[]  = {1,23,3,4,5,'\0'};
    int* ptr1 = arr;
    int* ptr2 = &arr[0];
    printf("%d\n",'\0');
    while(*ptr1 != '\0'){
        printf("the address of %d is %p\n",*ptr1,ptr1);
        ptr1++;
    }

    printf("the size of arr is %llu\n", sizeof(arr)/sizeof(int));

    arr + 1;
    printf("the size of arr is %llu\n", sizeof(arr)/sizeof(int));


    int brr[] = {3,4,45,5,6,7,7,8,'\0'};
    int* arrayPtr[] = {arr,brr};

//    for(int i=0;i<2;i++){
//        int* cur = arrayPtr[i];
//        while(*cur != '\0'){
//            printf("%d %d \n",i,*cur);
//            cur++;
//        }
//    }

    int crr[2][2] = {{1,2,},{3,4}};
//    for(int i=0;i<2;i++){
//        for(int j=0;j<2;j++){
//            printf("%d %d %p\n",i,j,crr[i]);
//        }
//    }
    int* *ppp =  arrayPtr;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d %d %d\n",i,j,*(*ppp+j));
        }
        ppp++;
    }

    int* xxx = arr;
    int(*xyy) [5] = &arr;
    printf("%d\n",*arr);
    printf("%p\n",&arr);
    return 0;
}