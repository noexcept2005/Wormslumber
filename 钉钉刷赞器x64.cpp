#define USINGABB
#include <stdcjz.h>
Main{
    int i=0;
	int n=100;	//���� 
	int speed=64;	//ÿ������ 
	int ch;
	POINT pt,pt2;	//������� 
	LONG maxDsc=30;	//���ƫ�Ƽ��޾��� 
	SetTitle("����ˢ����");
	SetConsoleSize(35,20); 
	/*while(!HaveWindow("StandardFrame_DingTalk",NULL) && ch == IDOK){
		ch = MessageBox(GetConsoleWindow(),"û�д򿪶�����\n���ȴ�Ȼ��ȷ����","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL);
	}
	if(ch == IDCANCEL || ch == IDCLOSE)
	{
		SetColor(11,0);
		cout<<"��ȡ��...";
		Sleep(500);
		exit(0);
	}*/
	while(!HaveWindow("StandardFrame",NULL) && ch == IDOK){
		ch = MessageBox(GetConsoleWindow(),"û�д򿪶���ֱ�����ڡ�\n���ȴ�Ȼ��ȷ����","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL);
	}
	if(ch == IDCANCEL || ch == IDCLOSE)
	{
		SetColor(11,0);
		cout<<"��ȡ��...";
		Sleep(500);
		exit(0);
	}
	inp1:
	SetColor(14,0);
	cout<<"����ÿ������(�Ƽ���20~60)��";
	cin>>speed;
	if(speed < 1 || speed > 1000){
		SetColor(11,0);
		cout<<"\n�����Ϸ�Χ(1~1000)!\n";
		goto inp1; 
	} 
	cout<<"���������";
	cin>>n;
	SetColor(10,0);
	cout<<"\n\n׼��������\n�������ش˴��ڣ������\n�������ϵ�����꿪ʼˢ��...\n";
	Sleep(3000);
	HideConsole();
	if(HaveWindow("Msgbox",NULL))
	    KeyPR(VK_SPACE);
	Sleep(1000);
	waitfor(LEFT_CLICK);
	GetCursorPos(&pt);
	//MsgSndTip(); 
	 do{
	 	if(!HaveWindow("Msgbox",NULL))
	 	   Click();
        else
	 	   KeyPR(VK_SPACE);
	 	Sleep((DWORD)1000.0 / speed);
	 	i++;
	 	/*if(kbhit())
	 			   break;*/
        if((i * 5) % speed == 0)	//ÿ���������� 
        {
        	GetCursorPos(&pt2);
        	if(Distance(pt,pt2) > maxDsc)	//��ʱȡ��
			{
				//�Ͳ���������̨�ˣ�ֱ���˳���������ȫ��:)
				exit(-1); 
			 } 
		}
	 }while(i <= n);
	 Sleep(1000);
	 if(HaveWindow("Msgbox",NULL))
	    KeyPR(VK_SPACE);
     FlauntWindow();
     SetColor(11,0);
     cout<<"\nˢ�޳ɹ���\n\n";
     Sleep(600);
     SetColor(5,0);
	 return 0;
} 
