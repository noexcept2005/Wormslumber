#define USINGSTD
#include <stdcjz.h>
void Put(LPCSTR lpText)
{
	int mark=1,shift,inc2;
	FILE *fp;
	char inc[10];
	for(int j=0;j<strlen(lpText);j++)
    {
    Sleep(1);
    inc[0]=lpText[j];
    mark=1;
    if(inc[0]>96&&inc[0]<123)
	inc[0]=inc[0]-32; 
	else if(inc[0]>64&&inc[0]<91)
	{
	mark=4;
	shift=VK_SHIFT;
	}
	else if(inc[0]=='#')
	{
	mark=2;
	shift=VK_SHIFT;  
	inc2=VK_NUMPAD3; 
    }else if(inc[0]==' ')
    {
    mark=3;
    inc2=VK_SPACE;
	}else if(inc[0]=='\n')
    {
    mark=3;
    inc2=VK_RETURN;
	}else if(inc[0]=='.')
	{
		mark=3;
		inc2=VK_DECIMAL;
	}/*else if(inc[0]='<')
	{
		fp=fopen("D:\\cstemp.tmp","w");
		fprintf("")
	}*/
    if(mark==1)
    {
    keybd_event(inc[0], 0, 0, 0); //����  
    keybd_event(inc[0], 0, 2, 0); //�ɿ�  
    }else if(mark==2)
    {
    keybd_event(shift, 0, 0, 0); //����  
    keybd_event(inc2, 0, 0, 0); 
	keybd_event(inc2, 0, 2, 0);  
	keybd_event(shift, 0, 2, 0); 	
	}else if(mark==3)
	{
	keybd_event(inc2, 0, 0, 0); //����  
    keybd_event(inc2, 0, 2, 0); //�ɿ�  
	}else if(mark==4)
	{
	keybd_event(shift, 0, 0, 0); //����  
    keybd_event(inc[0], 0, 0, 0); 
	keybd_event(inc[0], 0, 2, 0);  
	keybd_event(shift, 0, 2, 0); 
	}
	}
}
void Put2(LPCSTR lpText)
{
	FILE *fp;
	fp=fopen("D:\\cstemp.tmp","w");
	fprintf(fp,lpText);
	fclose(fp);
	Execute("Notepad.exe","D:\\cstemp.tmp");
	Sleep(50);
	Keys(KS_CTRL_A);
	Keys(KS_CTRL_C);
	Sleep(100);
	Taskkill("/im notepad.exe /f");
	Click();
	Keys(KS_CTRL_V);
	Sleep(100);
	system("del D:\\cstemp.tmp");
	return;
}
int main()
{
	LPSTR dtpath,dtdpath;
	bool iscon=false,isu=true,ism=false;
	CHAR hr[33],mac[65],maci[513];
	LPSTR macro;
	HWND hwndd=FindWindow("TMainForm",NULL);
	HWND hwnd=GetConsoleWindow();
	system("mode con cols=40 lines=10");//���ڿ�ȸ߶�
	SetColor(14,0);
	SetTitle("DevCpp�������ɳ���- by cjz");
	DrawRow1D(0,0,39,'*',10);
	MessageBeep(MB_ICONEXCLAMATION);
	if(hwndd==NULL)
	{
	SetColor(10,0);
	cout<<"���ڴ�DevCpp������...";
	Sleep(100);
	/*GetDesktopPath(dtpath);
	strcpy(dtdpath,dtpath);
	strcat(dtdpath,"\\Dev-C++.lnk");
	//cout<<dtdpath;Pause();
	//Execute(dtdpath,"");*/
	Execute("D:\\Program Files\\Dev-C++\\Dev-Cpp\\devcpp.exe","");
	while(( hwndd = FindWindow("TMainForm",NULL) )==NULL)
		; 
	cout<<"\r�򿪳ɹ���                           \n";
	}
	Sleep(200);
	SetColor(11,0);
	cout<<"�½�Դ�ļ�...";
	Sleep(200);
	SetCursorPos(717,646); 
	Click();
	Keys(KS_CTRL_N);
	HideWindow(hwnd);
    ShowWindow(hwnd,SW_SHOW);
    Sleep(200);
    FlashWindow(hwnd,true);
    Sleep(150);
    FlashWindow(hwnd,false);
	cout<<"\r�½��ɹ���         \n";
	MessageBeep(MB_ICONEXCLAMATION);
	Sleep(100);
	Cls();
	SetColor(14,0);
	SetTitle("��������");
	DrawRow1D(0,0,39,'*',3);
	UINT headercnt=0;
	do{
	SetColor(11,0);
	cout<<"����ͷ�ļ�:\t";
	KeyPR(VK_SHIFT);
	cin>>hr;
	SetCursorPos(1413,616); 
	Click();
	/*if(headercnt==0)
	Put2("#include <");
	else
	Put2("\n#include <");*//*
	Sleep(100);
	Put2((LPCSTR)hr);
	Sleep(100);
	Put2(">"); */
	FILE *fp;
	fp=fopen("D:\\cstemp1.tmp","w");
	if(headercnt==0)
	fprintf(fp,"#include <%s>",hr);
	else
	fprintf(fp,"\n#include <%s>",hr);
	fclose(fp);
	Execute("Notepad.exe","D:\\cstemp1.tmp");
	Sleep(50);
	Keys(KS_CTRL_A);
	Keys(KS_CTRL_C);
	Sleep(100);
	Taskkill("/im notepad.exe /f");
	Click();
	Keys(KS_CTRL_V);
	Sleep(100);
	system("del D:\\cstemp1.tmp");
	headercnt++;
	HideWindow(hwnd);
    ShowWindow(hwnd,SW_SHOW);
    SetColor(10,0);
    cout<<"ͷ�ļ�������ϣ��Ƿ��������ͷ�ļ���[Space/Enter:����,Esc:��]\t";
    MessageBeep(MB_ICONINFORMATION);
    Sleep(200);
    FlashWindow(hwnd,true);
    Sleep(100);
    FlashWindow(hwnd,false);
    inh://input the header choice
    int chh=getch();
    if(chh==32||chh==13)iscon=true;
    else if(chh==27)iscon=false;
    else goto inh;
    cout<<"\n";
	}while(iscon);
	SetColor(14,0);
	Cls();
	DrawRow1D(0,0,39,'*',2);
	SetColor(11,0);
	cout<<"�Ƿ����\"using namespace std;\"?[Space/Enter:��,Esc:��]\t";
	inu:
		int chu=getch();
		if(chu==32||chu==13)isu=true;
    else if(chu==27)isu=false;
    else goto inu;
    cout<<"\n";
    if(isu)
    {	SetCursorPos(1413,616); 
		Click();
    	Put2("\nusing namespace std;\n");
    	cout<<"\r����ɹ�!                                              \n";
    	MessageBeep(MB_ICONEXCLAMATION);
	}
	SetColor(14,0);
	cout<<"�Ƿ����ꣿ[Space/Enter:��,Esc:��]\t";
	inm:
		int chm=getch();
		if(chm==32||chm==13)ism=true;
    else if(chm==27)ism=false;
    else goto inm;
    cout<<"\n";
    if(ism)
    {
    	do	{
    		iscon=false;
    		SetColor(11,0);
    		cout<<"��������ƣ�\t";
    		SetColor(10,0);
    		cin>>mac;
    		SetColor(11,0);
    		cout<<"����������\t";
    		SetColor(10,0);
    		cin>>maci;
    		Sleep(100);
    		SetCursorPos(1413,616); 
			Click();
			//sprintf(macro,"#define %s %s\n",mac,maci);
			//Put2((LPCSTR)macro);
			FILE *fp1=fopen("D:\\cstemp2.tmp","w");
			fprintf(fp1,"#define %s %s\n",mac,maci);
			fclose(fp1);
			Execute("Notepad.exe","D:\\cstemp2.tmp");
			Sleep(50);
			Keys(KS_CTRL_A);
			Keys(KS_CTRL_C);
			Sleep(100);
			Taskkill("/im notepad.exe /f");
			Click();
			Keys(KS_CTRL_V);
			Sleep(100);
			system("del D:\\cstemp2.tmp");
			HideWindow(hwnd);
    		ShowWindow(hwnd,SW_SHOW);
    		Sleep(200);
    		FlashWindow(hwnd,true);
    		Sleep(100);
    		FlashWindow(hwnd,false);
    		SetColor(11,0);
    		MessageBeep(MB_ICONINFORMATION);
    		cout<<"\n�����ɣ���\n�Ƿ��������ꣿ[Space/Enter:��,Esc:��]\t";
    		inmc://input the macro choice
    		int chm=getch();
    		if(chm==32||chm==13)iscon=true;
    		else if(chm==27)iscon=false;
    		else goto inmc;
    		cout<<"\n";
		}while(iscon);
	}
	SetColor(14,0);
	Pause();
	return 1;
}

