//
// Created by mary on 3/20/24.
//

#ifndef TXL_FINAL_FXXKU_IFFILED_NEVER_COLORS_H
#define TXL_FINAL_FXXKU_IFFILED_NEVER_COLORS_H
#if __linux__
#define RESET "\033[0m"
#define BLACK "\033[30m"  /* Black */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */
#define PURPLE "\033[35m" /* Purple */
#define CYAN "\033[36m"   /* Cyan */
#define WHITE "\033[37m"  /* White */

#define NORMAL (std::cout << RESET)
#define INFO (std::cout << GREEN)
#define WARN (std::cout << YELLOW)
#define ERROR (std::cout << RED)
#define DEBUG (std::cout << CYAN)
#define END (std::endl)
#define REND "\033[0m" << std::endl
#endif
#endif //TXL_FINAL_FXXKU_IFFILED_NEVER_COLORS_H
