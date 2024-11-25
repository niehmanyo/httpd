//
// Created by Nie on 2024/11/25.
//


#include <iostream>
#include "stdlib.h"

using namespace std;

// 实现网络的初始化
// 返回值：套接字
// 端口：一台服务器，需要同时对外提供很多功能，每一个功能服务就需要一个端口，端口号就是用来区别服务的。
/**
 * @param port
 * *port表示端口，如果port的值是0，那么会自动分配一个可用的端口
 * 端口统一是 unsigned short 类型
 */


int startup(unsigned short *port){

    return 0;
}
int main(){
    unsigned short port = 80;
    int server_socket = startup(&port);
    printf("httpd server is starting,listening port: %d ... \n",port);


    //todo
    return 0;
}