//
// Created by Nie on 2024/11/25.
//


#include <iostream>
#include <stdio.h>

#include <winsock2.h>
#pragma comment(lib,"Ws2_32.lib")
#define ALWAYS true

using namespace std;

// 实现网络的初始化
// 返回值：套接字
// 端口：一台服务器，需要同时对外提供很多功能，每一个功能服务就需要一个端口，端口号就是用来区别服务的。
/**
 * @param port
 * *port表示端口，如果port的值是0，那么会自动分配一个可用的端口
 * 端口统一是 unsigned short 类型
 */
void error_die(const char* str){
    perror(str);
    exit(1);
}

int startup(unsigned short *port){
    // 1. 网络通信的初始化
    WSADATA data;
    int ret = WSAStartup(
            MAKEWORD(1,1), // 1.1 版本协议
            &data
            );

    if(ret){
        // ret != 0
        error_die("WASStartup");
    }
    int server_socket = socket(PF_INET, // 套接字类型
           SOCK_STREAM, // 数据流
           IPPROTO_TCP);
    if(server_socket == -1){
        //打印错误提示，并结束程序
        error_die("socket");
    }

    // 设置端口可复用
    int opt = 1;
    ret = setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,(const char*)&opt,sizeof(opt));
    if(ret == -1){
        error_die("setsockopt");
    }

    // 配置服务器端的网络地址
    struct sockaddr_in server_addr{};
    memset(&server_addr,0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(*port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 绑定套接字
    if(bind(server_socket,
            (struct sockaddr*)&server_addr,
                    sizeof(server_addr)) < 0){
        error_die("bind");
    };

    // 动态分配一个端口
    int nameLen = sizeof(server_addr);
    if(*port == 0){
        if(getsockname(server_socket,
                    (struct sockaddr*) &server_addr,
                            &nameLen) < 0){
            error_die("getsockname");
        }
    }
    // 上面分配了端口，会保存到server_addr 结构体中
    *port = server_addr.sin_port;


    // 创建监听队列
    if(listen(server_socket,5) < 0){
        error_die("listen");
    }

    return server_socket;
}

// #define DWORD __LONG32
// #define __LONG32 long
// 处理用户请求的线程函数
DWORD WINAPI accept_request(LPVOID arg){

    return 0;
}

int main(){
    unsigned short port = 80;
    int server_socket = startup(&port);
    printf("httpd server is starting,listening port: %u ... \n",port);


    //todo
    /*
     * 作为一个服务器，应该无时无刻都在监听端口
     * 所以这里要用一个while(1)
     * */

    struct sockaddr_in client_addr{};
    int client_addr_len = sizeof(client_addr);
    while(ALWAYS){
        // 阻塞式等待用户通过浏览器发起访问
        // 这个是在接待请求，如果有请求接待，则生成新的套接字
        int client_socket = accept(server_socket,
               (struct sockaddr*) &client_addr,
                      &client_addr_len );

        if(client_socket == -1){
            // 创建失败
            error_die("accept");
        }

        // 使用client_socket对用户进行访问
        // 创建一个新的线程()
        DWORD threadId;
        CreateThread(0,
                     0,
                     accept_request,
                     (void*) client_socket,
                     0,
                     &threadId);
    }
    return 0;
}