//
// Created by mary on 3/19/24.
//

#include "deleter_class.h"
#include "searcher.h"
#include <string.h>
#include <iostream>
using namespace number_;
int deleter_class::delete_do(MYSQL *mysql) {
    searcher* search_for_delete=new searcher;
    strcpy(*(search_for_delete->finding_conditions), to_string(this->id).c_str());
    if(!search_for_delete->finding_do(mysql)){
        cout<<"[INFO]deleter:以上是将要删除的内容\n";
    }else{
        cout<<"[INFO]deleter:这个id下没有记录,请用-s或--search先行查验\n";
        delete search_for_delete;
        search_for_delete= NULL;
        return 1;
    }
    if(!this->yes){
        cout<<"[WARNING]deleter:删除后将无法恢复这条记录,是否继续?(y/n,etc.)";
        char yes_or_no[1024];
        cin>>yes_or_no;
        cout<<endl;
        if(!strcmp(yes_or_no,"y")){
            this->yes=1;
        }else{
            cout<<"[SELECTION]deleter:操作取消\n";
            return 1;
        }
    }
    delete search_for_delete;
    search_for_delete= NULL;
    //接下来准备正式开始删除了
    char sql_syntax[1024]="delete from menbers_table where id=";
    strcat(sql_syntax, to_string(this->id).c_str());
    strcat(sql_syntax,";");
    int result=0;
    cout<<"[info]deleter:将要执行的sql语句为:"<<sql_syntax<<endl;
    result= mysql_real_query(mysql,sql_syntax,1024);
    if(result){
        cout<<"[ERROR]deleter_SQL:删除失败"<<mysql_error(mysql)<<endl;
        return 1;
    }else{
        cout<<"[SUCCESS]deleter:删除成功\n";
    }



    delete search_for_delete;
    search_for_delete=NULL;
    return 0;
}