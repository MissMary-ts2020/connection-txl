//
// Created by mary on 3/16/24.
//

#ifndef TXL_FINAL_FXXKU_IFFILED_NEVER_ADD_CLASS_H
#define TXL_FINAL_FXXKU_IFFILED_NEVER_ADD_CLASS_H
#include "number.h"
#define Doing_amounts 12
#include <mysql/mysql.h>
using namespace number_;
class add_class{
public:
    char all_details[6][1024];


    int add_do(MYSQL* mysql);
};


#endif //TXL_FINAL_FXXKU_IFFILED_NEVER_ADD_CLASS_H
