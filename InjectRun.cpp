//by Wormwaker
//����32λ����ó���
//-m32
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

typedef struct _PACKAGE_RUN {	//���а���
	DWORD dwLoadLibraryA;
	DWORD dwGetProcAddress;
	CHAR Kernel32Dll[24];
	CHAR WinExec[16];
	CHAR Command[2048];		//����ܳ����������
}PACKAGE_RUN,*PPACKAGE_RUN;
//������Ͷ���
typedef FARPROC (__stdcall* T_GetProcAddress)(HMODULE, LPCTSTR);
typedef HMODULE(__stdcall* T_LoadLibraryA) (LPCTSTR);
typedef UINT(__stdcall* T_WinExec)(LPCTSTR,UINT);

DWORD WINAPI RemoteThreadProc_Run(LPVOID lpParam)
{			//Զ���߳�
	//ȡ��
	PPACKAGE_RUN pack = (PPACKAGE_RUN)lpParam;
	//����
	T_LoadLibraryA __LoadLibraryA;
	T_GetProcAddress __GetProcAddress;
	T_WinExec _WinExec;
	//ʹ�����ƺŻ�ȡ������ַ
	__LoadLibraryA = (T_LoadLibraryA)pack->dwLoadLibraryA;
	__GetProcAddress = (T_GetProcAddress)pack->dwGetProcAddress;
	//��̬����Kernel32.dll
	HMODULE hMod = __LoadLibraryA(pack->Kernel32Dll);
	//���ԶԻ�����
	_WinExec = (T_WinExec)__GetProcAddress(hMod, pack->WinExec);
	if (!_WinExec)
	{	//fail
		return -1;
	}
	_WinExec(pack->Command, SW_SHOWNORMAL);
	return 0;
}

bool InjectRun(HANDLE hProc, const string& cmd)		//ע��ʽ��???
{				//Ŀ����̾��
	if (!hProc)
	{
		cout << "���󣺾����Ч"  << endl;
		return false;
	}
	PACKAGE_RUN pack{ 0 };
	pack.dwLoadLibraryA = (DWORD)GetProcAddress(GetModuleHandle("KERNEL32.dll"), "LoadLibraryA");
	pack.dwGetProcAddress = (DWORD)GetProcAddress(GetModuleHandle("KERNEL32.dll"), "GetProcAddress");
	lstrcpy(pack.Kernel32Dll,"KERNEL32.dll");
	lstrcpy(pack.WinExec, "WinExec");
	lstrcpy(pack.Command, cmd.c_str());
	if (!pack.dwLoadLibraryA || !pack.dwGetProcAddress)
	{
		cout << "�����޷���ȡLoadLibraryA��GetProcAddress�ĵ�ַ" << endl;
		return false;
	}
	LPVOID lpData = VirtualAllocEx(hProc, NULL, sizeof pack, MEM_COMMIT/* | MEM_RELEASE*/, PAGE_READWRITE);
	if (!lpData)
	{
		cout << "�����޷�Զ�̿����ڴ�1" << endl;
		return false;
	}
	DWORD useless = 0;
	BOOL ret = WriteProcessMemory(hProc, lpData, &pack, sizeof pack, &useless);
	if (!ret)
	{
		cout << "�����޷��޸Ľ����ڴ�1" << endl;
		return false;
	}
	DWORD dwFunSize = 0x2000;	//����
	LPVOID lpCode = VirtualAllocEx(hProc, NULL, dwFunSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!lpCode)
	{
		cout << "�����޷�Զ�̿����ڴ�2" << endl;
		return false;
	}
	ret = WriteProcessMemory(hProc, lpCode, (LPVOID)&RemoteThreadProc_Run, dwFunSize, &useless);
	if (!ret)
	{
		cout << "�����޷��޸Ľ����ڴ�2" << endl;
		return false;
	}
	HANDLE hThread = CreateRemoteThread(hProc, NULL, 0, (LPTHREAD_START_ROUTINE)lpCode, lpData, 0, NULL);
	if (!hThread)
	{
		cout << "�����޷�����Զ���߳�" << endl;
		return false;
	}	//completed
	CloseHandle(hThread);
	CloseHandle(hProc);
	return true; 
}

int main()
{
	SetConsoleTitle("ע��ʽ����- by Wormwaker");
	HANDLE hProc = nullptr;
	cout << "�������ID��" << endl;
	DWORD dwPid = 0;
	cin >> dwPid;
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	if(!hProc || INVALID_HANDLE_VALUE == hProc)
	{
		cout << "�����޷���ȡ���̾�������Կ����ù���ԱȨ�޴򿪱��������ԡ�"<< endl;
		return 0;
	}
	cout << "����Ҫ�������е����" << endl;
	char cmd[1024] = "\0";
	cin.ignore();
	cin.getline(cmd, 1024, '\n');
	cout << "�����������Ϊ��" << cmd << endl;
	cout << "���������ʼע��" << endl;
	_getch();
	bool res = InjectRun(hProc, cmd);
	if(!res)
	{
		cout << "���ۣ�����ʧ�ܣ�������="<< GetLastError() << endl;
	}else{
		cout << "�����ɹ���ɡ�"<< endl;
	}
	return 0;
}
