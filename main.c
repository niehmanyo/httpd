#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"



enum Sex{
    male,
    female
};

void printArrAddress(int arr[]){
    printf("%zu\n", sizeof(arr));
}

int findIntMaxArr(int arr[],int len){
    if(len <= 0){
        return -1;
    }
    int max  = arr[0];
    for(int i=1;i<len;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int* p(){
    static int a = 10;
    printf("%p\n",&a);
    return &a;
}

void printPtrInfo(){
    int a = 10;
    int* ptr1 = &a;
    int* * prt2 = &ptr1;
    printf("a 's address is  %p\n",&a);
    printf("ptr1 's address is %p\n",ptr1);
    printf("ptr1 's address is %p\n",&ptr1);

}




int main() {
//    int arr[] = {1,2,3,4,5};
//    printf("%zu\n", sizeof(arr));
//    printArrAddress(arr);
//    printf("%d\n", findIntMaxArr(arr,5));


    printPtrInfo();

//    printf("%s\n",str);
//    char arr[] = {'a','b','c','d','x'};
////    char *b = (char*) malloc(10);
////    b[0] = '1';
//    int len = strlen(arr);
//    printf("%d\n",len);
////    printf("%d\n", strlen(b));
//    printf("%s\n",arr);
//    printf("%p\n",&arr);

    return 0;
}


