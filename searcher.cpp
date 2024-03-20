//
// Created by mary on 3/19/24.
//

#include "searcher.h"
#define Doing_amounts 11
#include <string.h>
#include <iostream>

using namespace number_;
int searcher::finding_do(MYSQL* mysql){

    //每项都要更改为item=val and的形式
    int i=0,flag=0;
    char titles[6][10]={
            "id","name","gender","birthday","tel","addr"
    };
    char titles_chinese[6][100]={
            "编号","姓名","性别","生日","电话","地址"
    };
    char birthday_bak[2100]="";
    strcpy(birthday_bak,*(this->finding_conditions+8));
    change_birthday(birthday_bak,*(this->finding_conditions+8));
    for(;i<(Doing_amounts-5);i++){
        if(!strcmp(*(this->finding_conditions+i),"")){
            continue;//不指定未指定的项目
        }
        char str_origin[1024]="";
        strcpy(str_origin,*(this->finding_conditions+i));
        snprintf(*(this->finding_conditions+i),1024,"%s = '%s' and ",*(titles+i),str_origin);
        flag=1;
    }
    if(!flag){
        cout<<"[INFO]searcher:没有搜索条件";
        return 1;
    }
    char sql_syntax[1024]="select id,name,gender,birthday,addr,tel,appendix from menbers_table where ";
    i=0;
    for(;i<(Doing_amounts-5);i++){
        strcat(sql_syntax,*(this->finding_conditions+i));

    }
    strcat(sql_syntax,"2>1;");//最后会多一个and
    cout<<"[INFO]searcher:SQL查询命令为:"<<sql_syntax<<endl;
    int result=mysql_real_query(mysql,sql_syntax,(unsigned long)strlen(sql_syntax));
    if(result){
        cout<<"[ERROR]mysql_searcher:查询失败 "<<mysql_error(mysql)<<endl;
        return 1;
    }
    this->finding_results= mysql_store_result(mysql);
    MYSQL_ROW finding_result={0} ;
    flag=0;
    while((finding_result= mysql_fetch_row(finding_results))){
        flag++;
        cout<<"*************************\n找到第"<<to_string(flag)<<"条数据:\n";
        for(i=0;i<6;i++){
            cout<<*(titles_chinese+i)<<":"<<*(finding_result+i)<<endl;
        }
    }
    if(!flag){
        cout<<"[INFO]searcher:没有找到相关数据\n";
        return 1;
    }

    mysql_free_result(this->finding_results);
    this->finding_results=NULL;
    return 0;
}