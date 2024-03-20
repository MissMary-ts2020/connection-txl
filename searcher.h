//
// Created by mary on 3/19/24.
//

#ifndef TXL_FINAL_FXXKU_IFFILED_NEVER_SEARCHER_H
#define TXL_FINAL_FXXKU_IFFILED_NEVER_SEARCHER_H
#include "number.h"
#include <mysql/mysql.h>

using namespace number_;
class searcher {
public:
    char finding_conditions[6][1024];
    MYSQL_RES* finding_results;
    int finding_do(MYSQL* mysql);
};


#endif //TXL_FINAL_FXXKU_IFFILED_NEVER_SEARCHER_H
