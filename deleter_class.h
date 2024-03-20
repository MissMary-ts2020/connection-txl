//
// Created by mary on 3/19/24.
//

#ifndef TXL_FINAL_FXXKU_IFFILED_NEVER_DELETER_CLASS_H
#define TXL_FINAL_FXXKU_IFFILED_NEVER_DELETER_CLASS_H
#include "number.h"
#include <mysql/mysql.h>
using namespace number_;

class deleter_class {
public:
    unsigned int id;
    unsigned int yes;
    int delete_do(MYSQL* mysql);

};


#endif //TXL_FINAL_FXXKU_IFFILED_NEVER_DELETER_CLASS_H
