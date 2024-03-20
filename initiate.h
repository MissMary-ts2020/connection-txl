//
// Created by mary on 3/18/24.
//

#ifndef TXL_FINAL_FXXKU_IFFILED_NEVER_INITIATE_H
#define TXL_FINAL_FXXKU_IFFILED_NEVER_INITIATE_H

#include <mysql/mysql.h>
#include "number.h"
using namespace number_;
class initiate {
public:

    char string_details[4][126];

    int port;
    //用于创建登录字符串
    initiate();
    void get_userdetails();
    int connect_now();
    ~initiate();

    MYSQL* mysql;
    //这里只负责连接，不执行增删改查

};


#endif //TXL_FINAL_FXXKU_IFFILED_NEVER_INITIATE_H
