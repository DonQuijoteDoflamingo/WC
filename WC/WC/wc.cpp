#include <iostream>
#include <stdio.h>
#include <string>
#include<stdlib.h>
char  str[4096];
using namespace std;
int StringBracket(char *str)//ɾ���ո���Ʊ��
{
	int i,j,len;
	len=strlen(str);
	j=0;
	for(i=0; i<len; i++)
	{
		if(str[i]!=' ' && str[i]!='\t')
		{
			str[j]=str[i];
			j=j+1;
		}
	}
	str[j]='\0';
	if(str[0]=='\n') return 0;
	else return j;
}
void display1(int argc,char *argv[])
{
	int all=0,zs=0,kg=0,j,k=0;
    FILE *fp=NULL;
	fp=fopen(argv[4],"rt");
	while (fgets(str,4096,fp))  //��ȡһ�У����ж��ļ��Ƿ����
	{
		j=StringBracket(str);
		if(k==0)
		{
			if(j==0) 
				kg++;
			else if(str[0]=='/')
			{
				if(strstr(str,"/*")) 
					k=1;
				if(strstr(str, "*/"))
					k=0;
				zs++; 
			}
		}
		else
		{
			if(strstr(str, "*/"))
				k=0;
			zs++;
		}
		all++;
	}	
	char buffer[1003];  //���������洢��ȡ����ÿ�е�����
    int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char ch;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����
	int totalNum[3] = {0, 0, 0};
    if( (fp=fopen(argv[4], "rb")) == NULL ){
        perror(argv[4]);
    }
    // ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLen; i++){
            ch= buffer[i];
            if( ch==' ' || ch=='\t'){  // �����ո�
                !isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
                isLastBlank = 1;
            }else if(ch!='\n'&&ch!='\r'){  // ���Ի��з�
                charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ÿ�λ�������Ϊ1
        // һ�н������������ַ������ܵ�����
       /* totalNum[0]++;  */// ������
        totalNum[1] += charNum;  // ���ַ���
        totalNum[2] += wordNum;  // �ܵ�����
        // ���㣬����ͳ����һ��
        charNum = 0;
        wordNum = 0;
    }
	fclose(fp);
	cout<<"����: "<<all<<endl<<"������:"<<totalNum[2]<<endl<<"�ַ���:"<<totalNum[1]<<endl;
	cout<<"��������:"<<all-zs-kg<<endl<<"ע����:"<<zs<<endl<<"����:"<<kg<<endl;
}
int main(int argc,char *argv[])
{
	display1(argc,argv);
	return 0;
}

