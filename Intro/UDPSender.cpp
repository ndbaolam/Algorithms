// UDPServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include< stdio.h>
#include< conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2,2);
	int ret = 0;
	char host[256];
	ret = WSAStartup(wVersion, &wsaData);

	SOCKET sender;
	SOCKADDR_IN receiverAddr;
	//Tao socket de gui tin
	sender = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//Dien dia chi dich
	receiverAddr.sin_family = AF_INET;
	receiverAddr.sin_port = htons(8888);
	receiverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//Thuc hien gui tin
	char buf[1024];
	int len;
	while(1)
	{
		gets(buf);
		strcat(buf, "\n");
		len = sendto(sender, buf, strlen(buf),0, (SOCKADDR *)&receiverAddr,
			sizeof(receiverAddr));

	}
	closesocket(sender);
	WSACleanup();
	return 0;
	
}

