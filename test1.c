//
// Created by Nie on 2024/11/24.
//
// 数组和指针
#include "stdlib.h"
#include "stdio.h"

typedef struct cat{
    int age;
    char name[2];

} cat;

void method(){
    printf("Hello method\n");
}

int add( int p1, int p2){
    return p1+p2;
}

int sub( int p1, int p2){
    return p1-p2;
}

int multi( int p1, int p2){
    return p1*p2;
}

int divide( int p1, int p2){
    return p1/p2;
}
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

    void (*mPtr)() = method;
    mPtr();

    int (*addPtr)(int,int ) = add;
    printf("%d\n",addPtr(1,2));

    int (*methodPtrs[4])(int,int) = { add, sub, multi, divide};
    printf("%d\n",methodPtrs[1](1,2));

    cat c1;
    c1.name[0] = '1';
    c1.age = 1;

    printf("size = %llu\n", sizeof(cat));
    return 0;


}