#include<stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib,"ws2_32.lib") // ��̬��	
//-lws2_32
void getIPs(const string& host)
{	
	WORD v = MAKEWORD(1, 1);      
	WSADATA wsaData;      
	WSAStartup(v, &wsaData); // �����׽��ֿ�     	
	int i = 0;    
	struct hostent *phostinfo = gethostbyname(host.c_str());  	
	for(i = 0; NULL != phostinfo&& NULL != phostinfo->h_addr_list[i]; ++i)	
	{		
		char *pszAddr = inet_ntoa(*(struct in_addr *)phostinfo->h_addr_list[i]);		
		printf("%s\n", pszAddr);	
	} 	
	WSACleanup( );  
} 

int main()
{	
	string host;
	cout<<"��������������me��ʾ��̨�������:";
	cin>>host;
	if(host=="me")	host.clear();
	getIPs(host);	
	return 0;
}

