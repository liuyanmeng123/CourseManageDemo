//
// Created by 86189 on 2021/8/30.
//

#ifndef COURSEMANAGE_DEBUG_H
#define COURSEMANAGE_DEBUG_H

#define  DEBUG

#ifdef DEBUG
#include <iostream>
#define DEBUG_STDERR(x) do { std::cerr << "[ERROR] " << (x) << std::endl; } while(0)
#define DEBUG_STDOUT(x) do { std::cout  << "[DEBUG] " << (x) << std::endl; } while(0)
#else
#define DEBUG_STDERR(x) do {} while(0)
#define DEBUG_STDOUT(x) do {} while(0)
#endif

#endif //COURSEMANAGE_DEBUG_H
