#include <stdio.h>  
//�����ַ�����Ԫ��  
void swapPosition(char ch[][11],int oldX,int oldY,int newX,int newY)  
{  
    char temp;  
    temp = *(*(ch + oldX) + oldY);  
    *(*(ch + oldX) + oldY) = *(*(ch + newX) + newY);  
    *(*(ch + newX) + newY) = temp;  
      
}  
//��ӡ����  
void printArray(char (*ch)[11])  
{  
    for(int i = 0;i < 10;i++)  
    {  
        for(int j = 0;j < 10;j++)  
        {  
            printf("%c\t",*(*(ch + i) + j));  
        }  
        printf("\n");  
    }  
}  
int main(int argc, char* argv[])  
{  
    //��������  
    char ch[10][11] = {  
        {'#','#','#','#','#','#','#','#','#','#','\0'},  
        {'#','#','#',' ',' ','#','#','#','#','#','\0'},  
        {'#','0','X',' ',' ','#','#','#','#','#','\0'},  
        {'#','#','#','#',' ','#','#','#','#','#','\0'},  
        {'#','#','#',' ',' ',' ',' ','#','#','#','\0'},  
        {'#','#','#',' ',' ',' ',' ',' ','#','#','\0'},  
        {'#','#','#','#','#',' ',' ',' ','#','#','\0'},  
        {'#','#','#','#','#',' ',' ',' ',' ',' ','\0'},  
        {'#','#','#','#','#','#','#','#',' ',' ','\0'},  
        {'#','#','#','#','#','#','#','#','#','#','\0'}  
    };  
    //��ӡ����  
    printArray(ch);  
    //��¼С�˼�����λ��  
    //����·�ı�־����street  
    int personX = 2,personY = 1,boxX = 2, boxY = 2;  
    char street = ' ';  
    //��ʾ�û������ƶ�����  
    printf("������С���ƶ����򣺣�w-�ϣ�s-�£�a-��d-�ң�\n");  
    //�����¼�û�����ķ���  
    char direction;  
    //���ݷ�����ѭ�����  
    while(1)  
    {  
        scanf("%c",&direction);  
        getchar();//���ռ��̻س���  
        switch(direction)  
        {  
            case 'w':  
            case 'W':  
                if(*(*(ch+personX-1)+personY) == street)  
                {  
                    swapPosition(ch,personX,personY,personX - 1,personY );  
                    personX--;  
                      
                }  
                else if(*(*(ch+personX-1)+personY) == *(*(ch+boxX)+boxY))  
                {  
                    if(*(*(ch+boxX-1)+boxY) == street)  
                    {  
                        swapPosition(ch,boxX,boxY,boxX - 1,boxY);  
                        boxX--;  
                        swapPosition(ch,personX,personY,personX - 1,personY);  
                        personX--;  
                    }  
                }  
         
                break;  
            case 's':  
            case 'S':  
                if(*(*(ch+personX + 1) + personY) == street)  
                {  
                    swapPosition(ch,personX,personY,personX + 1,personY );  
                    personX++;  
                      
                }  
                else if(*(*(ch+personX+1)+personY) == *(*(ch+boxX)+boxY))  
                {  
                    if(*(*(ch+boxX+1)+boxY) == street)  
                    {  
                        swapPosition(ch,boxX,boxY,boxX + 1,boxY);  
                        boxX++;  
                        swapPosition(ch,personX,personY,personX + 1,personY);  
                        personX++;  
                    }  
                }  
                break;  
            case 'a':  
            case 'A':  
                if(*(*(ch+personX)+personY - 1) == street)  
                {  
                    swapPosition(ch,personX,personY,personX ,personY - 1 );  
                    personY--;  
                      
                }  
                else if(*(*(ch+personX)+personY - 1) == *(*(ch+boxX)+boxY))  
                {  
                    if(*(*(ch+boxX)+boxY - 1) == street)  
                    {  
                        swapPosition(ch,boxX,boxY,boxX,boxY - 1);  
                        boxY--;  
                        swapPosition(ch,personX,personY,personX,personY - 1);  
                        personY--;  
                    }  
                }  
                break;  
            case 'd':  
            case 'D':  
                
                if(*(*(ch+personX)+personY + 1) == street)  
                {  
                    swapPosition(ch,personX,personY,personX ,personY + 1 );  
                    personY++;  
                      
                }  
                else if(*(*(ch+personX)+personY + 1) == *(*(ch+boxX)+boxY))  
                {  
                    if(*(*(ch+boxX)+boxY + 1) == street)  
                    {  
                        swapPosition(ch,boxX,boxY,boxX,boxY + 1);  
                        boxY++;  
                        swapPosition(ch,personX,personY,personX,personY + 1);  
                        personY++;  
                    }  
                }  
                break;  
                case 'q':  
                case 'Q':  
                return 0;  
              
        }  
        printArray(ch);  
        //���������־  
        if (boxY == 9) {  
            printf("��ϲ�㣬��Ϸ���أ�\n");  
            return 0;  
        }  
    }  
  
    return 0;  
}  
