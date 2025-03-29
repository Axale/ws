#ifndef __NET_H__
#define __NET_H__

#define DEF_SOCKET 80
#define MAX_BUFFER 4096

#ifdef WIN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#pragma comment(lib, "Ws2_32.lib")

#endif

#ifdef LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

int net_init(void* arg);
int net_listen(void* arg, unsigned char* buffer, size_t length);
int net_close(void* arg);

#endif // __NET_H__
