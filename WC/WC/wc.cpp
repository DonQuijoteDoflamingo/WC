#include <iostream>
#include <stdio.h>
#include <string>
#include<stdlib.h>
char  str[4096];
using namespace std;
int StringBracket(char *str)//删除空格和制表符
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
	while (fgets(str,4096,fp))  //读取一行，并判断文件是否结束
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
	char buffer[1003];  //缓冲区，存储读取到的每行的内容
    int bufferLen;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char ch;  // 读取到的字符
    int isLastBlank = 0;  // 上个字符是否是空格
    int charNum = 0;  // 当前行的字符数
    int wordNum = 0; // 当前行的单词数
	int totalNum[3] = {0, 0, 0};
    if( (fp=fopen(argv[4], "rb")) == NULL ){
        perror(argv[4]);
    }
    // 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        // 遍历缓冲区的内容
        for(i=0; i<bufferLen; i++){
            ch= buffer[i];
            if( ch==' ' || ch=='\t'){  // 遇到空格
                !isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
                isLastBlank = 1;
            }else if(ch!='\n'&&ch!='\r'){  // 忽略换行符
                charNum++;  // 如果既不是换行符也不是空格，字符数加1
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
        isLastBlank = 1;  // 每次换行重置为1
        // 一行结束，计算总字符数、总单词数
       /* totalNum[0]++;  */// 总行数
        totalNum[1] += charNum;  // 总字符数
        totalNum[2] += wordNum;  // 总单词数
        // 置零，重新统计下一行
        charNum = 0;
        wordNum = 0;
    }
	fclose(fp);
	cout<<"行数: "<<all<<endl<<"单词数:"<<totalNum[2]<<endl<<"字符数:"<<totalNum[1]<<endl;
	cout<<"代码行数:"<<all-zs-kg<<endl<<"注释行:"<<zs<<endl<<"空行:"<<kg<<endl;
}
int main(int argc,char *argv[])
{
	display1(argc,argv);
	return 0;
}

