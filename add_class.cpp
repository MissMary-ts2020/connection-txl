//
// Created by mary on 3/16/24.
//

#include <string.h>
#include "add_class.h"
#include "number.h"
#include <iostream>
#include "number.h"

using namespace number_;

int add_class::add_do(MYSQL *mysql) {

    char birthday_bak[100]="";
    strcpy(birthday_bak,*(this->all_details+3));
    change_birthday(birthday_bak,*(this->all_details+3));

    char sql_syntax[1024]="";//sql语句准备

    snprintf(sql_syntax,1024,"insert into menbers_table (name,gender,birthday,addr,tel,appendix) values ('%s','%s','%s','%s','%s',%s)",*(this->all_details+1),*(this->all_details+2),*(this->all_details+3),*(this->all_details+4),*(this->all_details+5),"now()");
    cout<<"[INFO_SQL_syntax]SQL:语句为:"<<sql_syntax<<endl;
    int result=mysql_real_query(mysql,sql_syntax,(unsigned int)strlen(sql_syntax));
    if(result){
       cout<<"[ERROR]插入失败:"<<mysql_error(mysql)<<endl;
       return 1;
    }
    return 0;
}