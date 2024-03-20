//
// Created by mary on 3/16/24.
//

#include "number.h"
#include <iostream>
#include <string>

using namespace std;
using namespace number_;

void number::print_myself() {
    cout<<this->addr<<endl;
    cout<<this->name<<endl;
    cout<<this->tele_num<<endl;

}
char* change_birthday(const char* birthday_source,char* birthday_result){
    tm* time_formal=new tm;
    *time_formal={0};
    char possible_format[20][10]={
            "%Y-%m-%d",
            "%Y/%m/%d",
            "%Y.%m.%d",
            "%Y_%m_%d",
    };
    int i=0;
    for(;i<sizeof(possible_format)/sizeof(possible_format[0]);i++){
        if(strptime(birthday_source,*(possible_format+i),time_formal)){
            sprintf(birthday_result,"%d-%d-%d",time_formal->tm_year+1900,time_formal->tm_mon+1,time_formal->tm_mday);
            cout<<"[INFO]birthday:标准化生日为:"<<birthday_result<<endl;
            break;
        }
    }
    if(i>sizeof(possible_format)/sizeof(possible_format[0])){
        cout<<"[ERROR]birthday:不支持的格式\n";
        return NULL;
    }
    delete time_formal;
    time_formal=NULL;
    return birthday_result;
}
