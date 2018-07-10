//
//  main.cpp
//  est1
//
//  Created by s20171105137 on 2018/7/7.
//  Copyright © 2018年 s20171105137. All rights reserved.
//
/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
    // 写文件
    ofstream outFile;
    outFile.open("student1.csv", ios::out); // 打开模式可省略
 
    outFile.close();
    
    // 读文件
    ifstream inFile("student1.csv", ios::in);
    string lineStr;
    vector<vector<string>> strArray;
    while (getline(inFile, lineStr))
    {
        // 打印整行字符串
        cout << lineStr << endl;
        // 存成二维表结构
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        // 按照逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        strArray.push_back(lineArray);
    }
    
    getchar();
    return 0;
}
*/



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc, const char * argv[])

/*

struct student
{
    
    int numbers;
    char name[20];
    char sex[10];
    int dateofbirt;
    char class1[15];
    char TelPho[15];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("student1.csv","r");
    if(fp1==NULL)
    {
        printf("error");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,&s[i].TelPho,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].TelPho,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;
    
    fp2=fopen("student2.csv","w");
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,score\n");
    
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].TelPho,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
        i++;
    }
    fclose(fp2);
    
    return 0; 
}


 #include<stdio.h>
 #include<stdlib.h>
 int main()
 {
 FILE *fp;
 char ch;
 char name[20][100];
 char numbers[20][100];
 char sex[20][100];
 char birthofdate[20][100];
 char cla[20][100];
 char phNO[20][100];
 char num[100][100][20];
 double average[100];
 int i=0,l=0,m=0,n;
 int max=0,min=101;
 fp=fopen("/Users/s20171105112/Desktop/studentdata.csv","r");
 if(fp==NULL)
 {
 printf("??????");
 }
 else
 {
 ch=fgetc(fp);
 while(ch!=EOF)
 {
 if(i==0){
 if(ch=='\n')
 ++i;
 }
 if(i!=0){
 if(l==0){
 
 if(ch==',')
 {
 l++;
 numbers[i-1][m+1]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 numbers[i-1][m]=ch;
 m++;
 }
 else if(l==1)
 {
 if(ch==',')
 {
 l++;
 name[i-1][m+1]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 name[i-1][m]=ch;
 m++;
 }
 else if(l==2)
 {
 if(ch==',')
 {
 l++;
 sex[i-1][m+1]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 sex[i-1][m]=ch;
 m++;
 }
 else if(l==3)
 {
 if(ch==',')
 {
 l++;
 birthofdate[i-1][m+1]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 birthofdate[i-1][m]=ch;
 m++;
 }
 else if(l==4)
 {
 if(ch==',')
 {
 l++;
 cla[i-1][m]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 cla[i-1][m]=ch;
 m++;
 }
 else if(l==5)
 {
 if(ch==',')
 {
 l++;
 phNO[i-1][m+1]='\0';
 m=0;
 ch=fgetc(fp);
 continue;
 }
 phNO[i-1][m]=ch;
 m++;
 }
 else{
 if(ch==',')
 {
 num[i-1][l-6][m+1]='\0';
 average[i-1]+=atof(num[i-1][l-6]);
 if(max<atoi(num[i-1][l-6]))
 max=atoi(num[i-1][l-6]);
 if(min>atoi(num[i-1][l-6]))
 min=atoi(num[i-1][l-6]);
 l++;
 m=0;
 ch=fgetc(fp);
 continue;
 }
 num[i-1][l-6][m]=ch;
 m++;
 if(ch=='\n')
 {
 num[i-1][l-6][m+1]='\0';
 average[i-1]+=atof(num[i-1][l-6]);
 if(max<atoi(num[i-1][l-6]))
 max=atoi(num[i-1][l-6]);
 if(min>atoi(num[i-1][l-6]))
 min=atoi(num[i-1][l-6]);
 average[i-1]=(average[i-1]-max-min)/(l-7);
 max=0;min=101;
 i++;l=0;m=0;
 }
 }
 }
 ch=fgetc(fp);
 }
 num[i-1][l-6][m+1]='\0';
 average[i-1]+=atof(num[i-1][l-6]);
 if(max<atoi(num[i-1][l-6]))
 max=atoi(num[i-1][l-6]);
 if(min>atoi(num[i-1][l-6]))
 min=atoi(num[i-1][l-6]);
 average[i-1]=(average[i-1]-max-min)/(l-7);
 fclose(fp);
 for(n=0;n<i;n++)
 printf("%s,%s,%s,%s,%s,%s,%.2lf\n",numbers[n],name[n],sex[n],birthofdate[n],cla[n],phNO[n],average[n]);
 fp=fopen("/Users/s20171105112/biao.csv","w+");
 fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n","nummbers","name","sex","dateofbirth","class","phoneNo","average");
 for(n=0;n<i;n++)
 fprintf(fp,"%s,%s,%s,%s,%s,%s,%.2lf\n",numbers[n],name[n],sex[n],birthofdate[n],cla[n],phNO[n],average[n]);
 fclose(fp);
 }
 return 0;
 }

*/

/*

int main()
{
    // 写文件
    ofstream outFile;
    outFile.open("data.csv", ios::out); // 打开模式可省略
    outFile << "name" << ',' << "age" << ',' << "hobby" << endl;
    outFile << "Mike" << ',' << 18 << ',' << "paiting" << endl;
    outFile << "Tom" << ',' << 25 << ',' << "football" << endl;
    outFile << "Jack" << ',' << 21 << ',' << "music" << endl;
    outFile.close();
 
    // 读文件
    ifstream inFile("data.csv", ios::in);
    string lineStr;
    vector<vector<string>> strArray;
    while (getline(inFile, lineStr))
    {
        // 打印整行字符串
        cout << lineStr << endl;
        // 存成二维表结构
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        // 按照逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        strArray.push_back(lineArray);
    }
 
    getchar();
    return 0;

*/
{
    

//ofstream ofile;
//ofile.open("/Users/s20171105137/Desktop/students1.csv",ios::out);
    
    ifstream inFile;
    inFile.open("/Users/s20171105137/Desktop/student1.csv",ios::in);
    string lineStr;
    vector<vector<string>> strArray;
   while (getline(inFile, lineStr))

    {
        
        // 打印整行字符串
        cout << lineStr << endl;
        // 存成二维表结构
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        // 按照逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        strArray.push_back(lineArray);
        };
    

}

