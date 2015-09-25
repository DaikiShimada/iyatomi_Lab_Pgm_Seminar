#ifndef KANTOKU_DEBUG_MC
#define KANTOKU_DEBUG_MC
#include <iostream>
#define dump(x)  std::cerr << #x << " = " << (x) << std::endl
#define debug(x) std::cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << std::endl
#define check std::cerr << "check :" << " (L" << __LINE__ << ")" << " " << __FILE__ << std::endl;
#endif
