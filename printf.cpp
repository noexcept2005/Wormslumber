#include <stdio.h>
#include <unistd.h>
 
// �����Ļ
#define CLEAR() printf("\033[2J")
 
// ���ƹ��
#define MOVEUP(x) printf("\033[%dA", (x))
 
// ���ƹ��
#define MOVEDOWN(x) printf("\033[%dB", (x))
 
// ���ƹ��
#define MOVELEFT(y) printf("\033[%dD", (y))
 
// ���ƹ��
#define MOVERIGHT(y) printf("\033[%dC",(y))
 
// ��λ���
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))
 
// ��긴λ
#define RESET_CURSOR() printf("\033[H")
 
// ���ع��
#define HIDE_CURSOR() printf("\033[?25l")
 
// ��ʾ���
#define SHOW_CURSOR() printf("\033[?25h")
 
//����
#define HIGHT_LIGHT() printf("\033[7m")
#define UN_HIGHT_LIGHT() printf("\033[27m")
 
int main(int argc,char **argv)
{
//	printf("\033[31m");
	printf("\033[31mThe color,%s!\033[1m\n","1m");
	printf("\033[31mThe color,%s!\033[1m\n","1m");
//	system("pause");
	sleep(2);
printf("\033[31mThe color,%s!\033[1m\n","1m");
printf("\033[31mThe color,%s!\033[4m\n","4m");
printf("\033[31mThe color,%s!\033[5m\n","5m");
printf("\033[31mThe color,%s!\033[7m\n","7m");
printf("\033[31mThe color,%s!\033[8m\n","8m");
printf("\033[31mThe color,%s!\033[0m\n","0m");
printf("\033[47;31mThe color,%s!\033[0m\n","haha");
printf("\033[47mThe color,%s!\033[0m\n","haha");
sleep(2);
printf("\033[47m%s!\033[5A\n","up 5");
sleep(2);
printf("\033[47m%s!\033[9B\n","down 9");
sleep(2);
printf("\033[47m%s!\033[19C\n","right 19");
printf("right19");
sleep(2);
printf("\033[47m%s!\033[10D\n","left 10");
printf("left 10");
sleep(2);
printf("\033[47m%s!\033[50;20H\n","move to y:50,x 20");
printf("y50 x 20");
sleep(2);
printf("\033[47m%s!\033[?25l\n","hide cursor");
sleep(2);
printf("\033[47m%s!\033[?25h\n","show cursor");
sleep(2);
printf("\033[47m%s!\033[2J\n","clear screen");
sleep(2);
 
return 0;
}

