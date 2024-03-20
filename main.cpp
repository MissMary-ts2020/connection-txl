#include <iostream>
#include "number.h"
#include <string.h>
#include "initiate.h"
#include "add_class.h"
#include "searcher.h"
#include "deleter_class.h"
#include "colors.h"




#define Doing_amounts 12


char doings_abridge[Doing_amounts][6]={
        "-a","-d","-m",
        "-s","-h","-i",
        "-n","-g","-b",
        "-t","-addr","-y"
};
char doings_full[Doing_amounts][12]={
        "--add","--delete","--modify",
        "--search","--help","--id",
        "--name","--gender","--birthday",
        "--telephone","--address","--yes"
};
unsigned int yes=0;

int main(int argc,const char** argv) {
    using namespace std;
    using namespace number_;
    int EXIT_CODE=0;


    int doing_num=-1;
    char finding_conditions[Doing_amounts][1024]={0};
    int i=1;
    if(i>=argc){
        cout<<RED<<"[ERROR]main:未指定参数\n"<<RESET;
        exit(255);
    }
    for(;i<argc;i++){
         int j=0,flag=0;
         for(j=0;j<Doing_amounts;j++){//前4项是操作
             if(!strcmp(*(argv+i),*(doings_abridge+j))||!strcmp(*(argv+i),*(doings_full+j))){
                 if(j<=4){
                     doing_num=j;
                     cout<<"    ->得到操作数"<<*(argv+i)<<endl;
                     //catch到了一个操作参数
                     flag=1;
                     continue;
                 }else if(j<=10){
                     //catch到了一个方法参数
                     cout<<BLUE<<"    ->得到方法参数"<<*(argv+i)<<endl<<RESET;
                     strcpy(*(finding_conditions+j),*(argv+i+1));
                     cout<<PURPLE<<"    ->搜索条件:"<<*(finding_conditions+j)<<endl<<RESET;
                     //方法参数后面要跟搜索条件，因此要跳过检查后面一个参数
                     i++;
                     flag=1;
                     continue;
                 }else if(11==j){
                     //catch到yes
                     cout<<GREEN<<"[OPTION]main:yes模式\n"<<RESET;
                     yes=1;
                     continue;
                 }
             }
         }
         if(!flag){
             //循环跑出去了
             cout<<YELLOW<<"[WARNING]main:未知的参数:"<<*(argv+i)<<endl;
         }
    }
    if(-1==doing_num){
        cout<<"[ERROR]main:未获取有效的操作数\n";
        //这里放打印帮助文本
        exit(1);
    }
    cout<<GREEN<<"[OPTION]main:选择的操作数:"<<doing_num<<endl<<RESET;
    initiate* connection=new initiate();
    connection->get_userdetails();
    connection->connect_now();
    switch(doing_num){
        case 0: {
            add_class *adder = new add_class;
            i = 0;
            for (i = 0; i < Doing_amounts-5; i++) {
                strcpy(*(adder->all_details + i), *(finding_conditions + i + 5));
            }
            if(!adder->add_do(connection->mysql)){
                cout<<GREEN<<"[SUCCESS]main:插入成功\n"<<RESET;
            }else{
                cout<<RED<<"[ERROR]main:插入失败\n"<<RESET;
                EXIT_CODE=3;
            }
            delete adder;
            adder = nullptr;
        }
        break;
        case 3:{
            searcher* search=new searcher;
            for(i=0;i<Doing_amounts-5;i++){
                strcpy(*(search->finding_conditions+i),*(finding_conditions+i+5));
            }
            if(!search->finding_do(connection->mysql)){
                cout<<GREEN<<"[SUCCESS]main:查询成功\n"<<RESET;
            }else{
                cout<<RED<<"[ERROR]main:查询失败\n"<<RESET;
                EXIT_CODE=1;
            }

            delete search;
            search=nullptr;
        }
        break;
        case 1:{
            deleter_class* deleter=new deleter_class;
            deleter->id= atoi(*(finding_conditions+5));
            deleter->yes=yes;
            if(!deleter->delete_do(connection->mysql)){
                cout<<GREEN<<"[SUCCESS]main:删除成功\n"<<RESET;
            }else{
                cout<<RED<<"[ERROR]main:删除失败\n"<<RESET;
                EXIT_CODE=1;
            }
            delete deleter;
            deleter=NULL;
        }
        break;
        case 2:{
            cout<<BLUE<<"[LAZY]main:不做改了,先删除再添加好了\n"<<RESET;
            EXIT_CODE=114;
        }
        break;
        default:{
            cout<<"[SORRY]main:还没做好\n";
            EXIT_CODE=8;
        }
    }


    delete connection;
    connection=nullptr;
    return EXIT_CODE;
}
