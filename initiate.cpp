//
// Created by mary on 3/18/24.
//

#include "initiate.h"
#include <iostream>
#include "number.h"
#include <string.h>
#include "colors.h"
//颜色

using namespace number_;


initiate::initiate():port(0),mysql(NULL) {

    using namespace std;

    this->mysql=mysql_init(this->mysql);
    if(!this->mysql){
        cout<<"[ERROR_SYSTEM]初始化失败："<<mysql_error(this->mysql)<<endl;
        exit(8);
    }
    int i=0;
    for(;i<4;i++){
        strcpy(*(this->string_details+i),"__inited");
    }
}
void initiate::get_userdetails() {
    //从config文件中获取
    using namespace std;
    FILE* config_txt=fopen("config.conf","r");
    if(!config_txt){
        cout<<"[ERROR]配置文件不存在!\n";
        exit(404);
    }
    char item[100];
    char val[125];
    static char items[4][100]={"username","password","ip_addr","port"};//这个很重要，相当提示了字符串对应位置的意义
    while(!feof(config_txt)){
        char line[3000];
        fgets(line,1000,config_txt);
        if(2!=sscanf(line,"%s = %s",item,val)){
            cout<<YELLOW<<"[WARNING]无效行:\""<<line<<"\"\n"<<RESET;
            continue;
        }
        int i=0,flag=0;
        for(i=0;i<4;i++){
            if(!strcmp(item,*(items+i))){
                //命中参数
                strcpy(*(this->string_details+i),val);
                cout<<BLUE<<"[INFO]connection:填入参数:"<<*(items+i)<<",参数为:"<<*(this->string_details+i)<<endl<<RESET;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<YELLOW<<"[WARNING]connection:无效参数\""<<item<<"\"\n"<<RESET;
        }

    }
    //结束后，要转换一下port参数
    int port_val=atoi(*(this->string_details+3));
    if(!port_val){
        //转换失败
        cout<<YELLOW<<"[WARNING]connection:端口号码不正确\n使用通用端口3306\n"<<RESET;
        port_val=3306;
    }
    this->port=port_val;
    //检查一下有无空白
    int i=0,flag=1;
    for(;i<4;i++){
        if(!strcmp(*(this->string_details+i),"__inited")){
            cout<<RED<<"[ERROR]connection:登录信息缺相,"<< *(items+i) <<"请检查配置文件\n"<<RESET;
            flag=0;
        }
    }
    if(!flag){
        exit(404);
    }


    cout<<BLUE<<"[INFO]connection:登录信息如下:\n*******************\n"<<RESET;
    cout<<PURPLE<<"    ->用户名:"<<*(this->string_details+0)<<endl;
    cout<<"    ->密码:"<<*(this->string_details+1)<<endl;
    cout<<"    ->服务器地址:"<<*(this->string_details+2)<<endl;
    cout<<"    ->端口:"<<*(this->string_details+3)<<endl<<RESET;


    fclose(config_txt);
    config_txt=NULL;


}

int initiate::connect_now() {

    this->mysql= mysql_real_connect(this->mysql,*(this->string_details+2),*(this->string_details), *(this->string_details+1),"txl_final",this->port,NULL,0);
    if(!mysql){
        cout<<"[ERROR]connection:数据库连接失败,"<<mysql_error(mysql)<<endl;
        exit(500);
    } else{
        cout<<"[SUCCESS]connection:连接成功\n";
        return 1;
    }
}

initiate::~initiate(){
    if(this->mysql){
        mysql_close(mysql);
    }
}