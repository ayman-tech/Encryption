#include <iostream>
#include<string>
#include<string.h>
#include<istream>
#include<fstream>
#include<ostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<sys/stat.h>

using namespace std;
const float PI = 3.14159265;
int work;

struct node
{
    string f;
    struct node *next;
}*front,*rear,*cur;

void cl(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 3]=tmp[13]; str[ 4]=tmp[25]; str[ 5]=tmp[37]; str[13]=tmp[48]; 
    str[19]=tmp[ 5]; str[25]=tmp[49]; str[31]=tmp[ 4]; str[37]=tmp[50]; 
    str[43]=tmp[ 3]; str[48]=tmp[43]; str[49]=tmp[31]; str[50]=tmp[19]; 
}
void cr(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 3]=tmp[43]; str[ 4]=tmp[31]; str[ 5]=tmp[19]; str[13]=tmp[3]; 
    str[19]=tmp[50]; str[25]=tmp[ 4]; str[31]=tmp[49]; str[37]=tmp[ 5]; 
    str[43]=tmp[48]; str[48]=tmp[13]; str[49]=tmp[25]; str[50]=tmp[37]; 
}

void cu(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 1]=tmp[16]; str[ 4]=tmp[28]; str[ 7]=tmp[40]; str[10]=tmp[ 7]; 
    str[16]=tmp[52]; str[22]=tmp[ 4]; str[28]=tmp[49]; str[34]=tmp[ 1]; 
    str[40]=tmp[46]; str[46]=tmp[10]; str[49]=tmp[22]; str[52]=tmp[34];
}
void cd(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 1]=tmp[34]; str[ 4]=tmp[22]; str[ 7]=tmp[10]; str[10]=tmp[46]; 
    str[16]=tmp[1]; str[22]=tmp[49]; str[28]=tmp[4]; str[34]=tmp[52]; 
    str[40]=tmp[ 7]; str[46]=tmp[40]; str[49]=tmp[28]; str[52]=tmp[16];
}

void bl(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[33]=tmp[36]; str[34]=tmp[37]; str[35]=tmp[38]; str[36]=tmp[39]; str[37]=tmp[40]; 
    str[38]=tmp[41]; str[39]=tmp[42]; str[40]=tmp[43]; str[41]=tmp[44]; str[42]=tmp[33]; 
    str[43]=tmp[34]; str[44]=tmp[35]; str[45]=tmp[51]; str[46]=tmp[48]; str[47]=tmp[45]; 
    str[48]=tmp[52]; str[50]=tmp[46]; str[51]=tmp[53]; str[52]=tmp[50]; str[53]=tmp[47]; 
}
void br(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[33]=tmp[42]; str[34]=tmp[43]; str[35]=tmp[44]; str[36]=tmp[33]; str[37]=tmp[34]; 
    str[38]=tmp[35]; str[39]=tmp[36]; str[40]=tmp[37]; str[41]=tmp[38]; str[42]=tmp[39]; 
    str[43]=tmp[40]; str[44]=tmp[41]; str[45]=tmp[47]; str[46]=tmp[50]; str[47]=tmp[53]; 
    str[48]=tmp[46]; str[50]=tmp[52]; str[51]=tmp[45]; str[52]=tmp[48]; str[53]=tmp[51]; 
}

void fl(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 0]=tmp[ 2]; str[ 1]=tmp[ 5]; str[ 2]=tmp[ 8]; str[ 3]=tmp[ 1]; str[ 5]=tmp[ 7]; 
    str[ 6]=tmp[ 0]; str[ 7]=tmp[ 3]; str[ 8]=tmp[ 6]; str[ 9]=tmp[12]; str[10]=tmp[13]; 
    str[11]=tmp[14]; str[12]=tmp[15]; str[13]=tmp[16]; str[14]=tmp[17]; str[15]=tmp[18]; 
    str[16]=tmp[19]; str[17]=tmp[20]; str[18]=tmp[ 9]; str[19]=tmp[10]; str[20]=tmp[11]; 
}
void fr(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 0]=tmp[ 6]; str[ 1]=tmp[ 3]; str[ 2]=tmp[ 0]; str[ 3]=tmp[ 7]; str[ 5]=tmp[ 1]; 
    str[ 6]=tmp[ 8]; str[ 7]=tmp[ 5]; str[ 8]=tmp[ 2]; str[ 9]=tmp[18]; str[10]=tmp[19]; 
    str[11]=tmp[20]; str[12]=tmp[ 9]; str[13]=tmp[10]; str[14]=tmp[11]; str[15]=tmp[12]; 
    str[16]=tmp[13]; str[17]=tmp[14]; str[18]=tmp[15]; str[19]=tmp[16]; str[20]=tmp[17]; 
}

void dl(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 6]=tmp[14]; str[ 7]=tmp[26]; str[ 8]=tmp[38]; str[14]=tmp[51]; str[15]=tmp[39]; 
    str[16]=tmp[27]; str[17]=tmp[15]; str[18]=tmp[ 8]; str[26]=tmp[52]; str[27]=tmp[40]; 
    str[29]=tmp[16]; str[30]=tmp[ 7]; str[38]=tmp[53]; str[39]=tmp[41]; str[40]=tmp[29]; 
    str[41]=tmp[17]; str[42]=tmp[ 6]; str[51]=tmp[42]; str[52]=tmp[30]; str[53]=tmp[18]; 
}
void dr(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 6]=tmp[42]; str[ 7]=tmp[30]; str[ 8]=tmp[18]; str[14]=tmp[ 6]; str[15]=tmp[17]; 
    str[16]=tmp[29]; str[17]=tmp[41]; str[18]=tmp[53]; str[26]=tmp[ 7]; str[27]=tmp[16]; 
    str[29]=tmp[40]; str[30]=tmp[52]; str[38]=tmp[ 8]; str[39]=tmp[15]; str[40]=tmp[27]; 
    str[41]=tmp[39]; str[42]=tmp[51]; str[51]=tmp[14]; str[52]=tmp[26]; str[53]=tmp[38]; 
}

void tl(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 0]=tmp[12]; str[ 1]=tmp[24]; str[ 2]=tmp[36]; str[ 9]=tmp[11]; str[10]=tmp[23]; 
    str[11]=tmp[35]; str[12]=tmp[45]; str[20]=tmp[ 2]; str[21]=tmp[10]; str[23]=tmp[34]; 
    str[24]=tmp[46]; str[32]=tmp[ 1]; str[33]=tmp[ 9]; str[34]=tmp[21]; str[35]=tmp[33]; 
    str[36]=tmp[47]; str[44]=tmp[ 0]; str[45]=tmp[44]; str[46]=tmp[32]; str[47]=tmp[20];
}
void tr(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 0]=tmp[44]; str[ 1]=tmp[32]; str[ 2]=tmp[20]; str[ 9]=tmp[33]; str[10]=tmp[21]; 
    str[11]=tmp[ 9]; str[12]=tmp[ 0]; str[20]=tmp[47]; str[21]=tmp[34]; str[23]=tmp[10]; 
    str[24]=tmp[ 1]; str[32]=tmp[46]; str[33]=tmp[35]; str[34]=tmp[23]; str[35]=tmp[11]; 
    str[36]=tmp[ 2]; str[44]=tmp[45]; str[45]=tmp[12]; str[46]=tmp[24]; str[47]=tmp[36];
}

void rd(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 2]=tmp[35]; str[ 5]=tmp[23]; str[ 8]=tmp[11]; str[11]=tmp[45]; str[12]=tmp[36]; 
    str[13]=tmp[24]; str[14]=tmp[12]; str[15]=tmp[ 2]; str[23]=tmp[48]; str[24]=tmp[37]; 
    str[26]=tmp[13]; str[27]=tmp[ 5]; str[35]=tmp[51]; str[36]=tmp[38]; str[37]=tmp[26]; 
    str[38]=tmp[14]; str[39]=tmp[ 8]; str[45]=tmp[39]; str[48]=tmp[27]; str[51]=tmp[15]; 
}
void ru(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[ 2]=tmp[15]; str[ 5]=tmp[27]; str[ 8]=tmp[39]; str[11]=tmp[ 8]; str[12]=tmp[14]; 
    str[13]=tmp[26]; str[14]=tmp[38]; str[15]=tmp[51]; str[23]=tmp[ 5]; str[24]=tmp[13]; 
    str[26]=tmp[37]; str[27]=tmp[48]; str[35]=tmp[ 2]; str[36]=tmp[12]; str[37]=tmp[24]; 
    str[38]=tmp[36]; str[39]=tmp[45]; str[45]=tmp[11]; str[48]=tmp[23]; str[51]=tmp[35]; 
}

void lu(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[0 ]=tmp[17]; str[ 3]=tmp[29]; str[ 6]=tmp[41]; str[ 9]=tmp[ 6]; str[17]=tmp[53]; 
    str[18]=tmp[42]; str[19]=tmp[30]; str[20]=tmp[18]; str[21]=tmp[ 3]; str[29]=tmp[50]; 
    str[30]=tmp[43]; str[32]=tmp[19]; str[33]=tmp[ 0]; str[41]=tmp[47]; str[42]=tmp[44]; 
    str[43]=tmp[32]; str[44]=tmp[20]; str[47]=tmp[ 9]; str[50]=tmp[21]; str[53]=tmp[33];
}
void ld(char str[])
{
    char tmp[55];
    strcpy(tmp, str);
    str[0 ]=tmp[33]; str[ 3]=tmp[21]; str[ 6]=tmp[ 9]; str[ 9]=tmp[47]; str[17]=tmp[ 0]; 
    str[18]=tmp[20]; str[19]=tmp[32]; str[20]=tmp[44]; str[21]=tmp[50]; str[29]=tmp[3]; 
    str[30]=tmp[19]; str[32]=tmp[43]; str[33]=tmp[53]; str[41]=tmp[ 6]; str[42]=tmp[18]; 
    str[43]=tmp[30]; str[44]=tmp[42]; str[47]=tmp[41]; str[50]=tmp[29]; str[53]=tmp[17];
}

void shuffle(string f1, string f2, int key)
{
    int count=0;
    char ch;
    ifstream check(f1.c_str());
    if(!check.good())
        return;
    while(check >> ch) 
        ++count;
    if(count<54)
        return;
    else
        count=count/54;
    check.close();
    float k=key;
    k = (k-2)/89;
    unsigned int x = k*255;
    bool set[8];
    for(int i=7; i>=0; i--)
    {
        if(x%2==0)
           set[i]=false;
        else
            set[i]=true;
        x=x>>1;
    }
    cout<<"\n key : "<<key<<" k : "<<k<<" set : ";
    for(int i=0; i<8; i++)
        cout<<set[i]<<" ";
    ifstream file1(f1.c_str());
    ofstream file(f2.c_str(),ios::out);
    char str[55];
    for(int i=0; i<count; i++)
    {
        file1.read(str, sizeof(str)-1);
        if(!set[7])
            cl(str);
        else
            cr(str);
        if(!set[6])
            cu(str);
        else
            cd(str);
        if(!set[5])
            bl(str);
        else
            br(str);
        if(!set[4])
            fl(str);
        else
            fr(str);
        if(!set[3])
            dl(str);
        else
            dr(str);
        if(!set[2])
            tl(str);
        else
            tr(str);
        if(!set[1])
            ru(str);
        else
            rd(str);
        if(!set[0])
            lu(str);
        else
            ld(str);
        file.write(str, sizeof(str)-1);
    }
    if(!file1.eof())
    {
        file1.get(ch);
        do
        {
            file<<ch;
            file1.get(ch);
        }while(!file1.eof());
    }
    file1.close();
    file.close();
    remove(f1.c_str());
    rename(f2.c_str(), f1.c_str());
}

void push(string folder)
{
    cur = new struct node;
    cur->next = NULL;
    cur->f = folder;
    if(front==NULL)
    {
        front = cur;
        rear = cur;
    }
    else
    {
        rear->next = cur;
        rear = cur;
    }
}
void pop()
{
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        cur = front;
        front = front->next;
        delete(cur);
    }
}
int decode(int a)
{
    int d,x = a/10;
    float b,c;
    b=x;
    a = a%10;
    b = b/100000;
    if(a%2==1)
        c = (asin(b) * 180.0 / PI);
    else
        c = (acos(b) * 180.0 / PI);
    d = round(c);
    return d;
}
void dec(string f1, string f2, int key)
{
    shuffle(f1, f2, key);
    int s,num;
    char ch,ch1;
    string str,line;
    ifstream file1(f1.c_str(), ios::in);
    if(!file1.good())
    {
        cout<<"\n File "<<f1<<" doesnt exists, skipping it";
        return;
    }
    work=1;
    ofstream file(f2.c_str(), ios::out);
    while( !file1.eof() )
    {
        getline( file1 , str);
        s = str.size();
        for( int i=0 ; i < s ; i++ )
        {
            ch = str[i];
            if(ch=='!')
                num = 127;
            else
                num = ch;
            num = num - key;
            ch1 = num;
            line = ch1;
            file<<line;
        }
        if(!file1.eof())
            file<<endl;
    }
    file1.close();
    file.close();
    remove(f1.c_str());
    rename(f2.c_str(), f1.c_str());
}
void control(string f1, int key)
{
    string str;
    string path = f1.substr(0, f1.size()-1);
    struct stat s;
    if( stat(path.c_str(),&s) == 0 )
    {
        if( s.st_mode & S_IFDIR )
            str = "ls "+f1+ " >list.txt";
        else if( s.st_mode & S_IFREG )
        {
            dec(path, path+"-dec.txt", key);
            return;
        }
        else
            return;
    }
    else
    {
        cout<<"\n Undefined file, skipping";
        return;
    }
    system(str.c_str());
    string line;
    ifstream list("list.txt", ios::in);
    if(!list.good())
    {
        cout<<"\n Folder "<<f1<<" doesnt exists, aborting !!!";
        exit(0);
    }
    while(!list.eof())
    {
        getline(list,line);
        int s,flag=0;
        string f2 = f1+"encrypt";
        s = line.size();
        for(int i=0; i<s; i++)
        {
            if(line[i]=='.')
                flag=1;
            if(flag==1)
                f2 = f2 + line[i];
        }
        if(flag==1)
        {
            line = f1+line;
            dec(line,f2,key);
        }
        else
        {
            if(line=="")
                continue;
            str = f1+line+"/";
            push(str);
        }
    }
    list.close();
    system("rm list.txt");
}
int main()
{
    //again:
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                              Decrypt"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    string str,f1;
    string f2="decrypt";
    int a,s,key;
    char cwd[80];
    getcwd(cwd, 80);
    printf(" Current directory : %s\n", cwd);
    cout<<endl<<" Enter name of file to be decrypted : ";
    getline(cin , f1);
    work=0;
    /*ifstream file1(f1.c_str(), ios::in);
    if(file1.fail())
    {
        cout<<" No such File exists";
        usleep(1000000);
        system("clear");
        goto again;
    }*/
    cout<<endl<<" Enter key: ";
    cin>>a;
    key = decode(a);
    int flag=0;
    s = f1.size();
    for(int i=0; i<s; i++)
    {
        if(f1[i]=='.')
            flag=1;
        if(flag==1)
            f2 = f2 + f1[i];
    }
    if(flag==1)
        dec(f1,f2,key);
    else
    {
        f1 = f1+"/";
        control(f1,key);
    }
    while(front!=NULL)
    {
        str = front->f; 
        pop();
        control(str, key);
    }
    if(work==0)
    {
        cout<<"\n\n ERROR: Files missing or dont exist anymore.\n Process Terminated\n";
        exit(0);
    }
    cout<<endl<<" Files have been succesfully decrypted \n";
    usleep(2000000);
    return(0);
}
