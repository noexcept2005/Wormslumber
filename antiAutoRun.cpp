/* antiAutoRun.cpp *
 * Author:noexcept *
 */
//C++
#include <Windows.h>
#include <io.h>
#include <iostream>
#include <string>	
using namespace std;
#define AUTORUN "autorun.inf"	//ͬ���ļ��� 
#define ANTIDELETE "\\con\\"	//������޷�ɾ�����ļ��е�����,��������ѡ�� 

bool Immune(string szDisk)	//��"C:\"
{	//�������� 
	cout<<"\n��ͼ����...";
	if(access(szDisk.c_str(),S_OK))	//�����ڴ��� 
	{
		cout<<"\nERROR: �����ڴ���"<<szDisk;
		return false;
	}
	
	string dir;
	dir+=szDisk;
	dir+=AUTORUN;
	BOOL bRet = CreateDirectory(dir.c_str(),nullptr);	//�����ļ��� 
	if(!bRet)
	{	//failed
		cout<<"\nERROR: �޷����ߴ��̣�������д�������Ѿ����ߡ�";
		return false;
	}
	
	dir+=ANTIDELETE;
	bRet = CreateDirectory(dir.c_str(),nullptr);
	if(!bRet)
	{	//failed
		cout<<"\nERROR: �޷����ߴ��̣�������д�������Ѿ����ߡ�";
		return false;
	}
	return true;
}
int main()
{
	string szDisk;
	cout<<"������Ҫ���ߵĴ����̷�(like C:\\)�� ";
	cin>>szDisk;
	if(Immune(szDisk))
		cout<<"\n�����ɹ����.";
	else
		cout<<"\n����ʧ��!";
	return 0;
}
