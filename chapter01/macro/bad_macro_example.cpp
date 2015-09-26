#include <iostream>
#include "debug.h"

#define MAX(a,b) ((a)>(b)?(a):(b))

int main(int argc, char const* argv[])
{
	int a = 3;
	int b = 7;

	// 期待通り大きいb(=7)が返り，aは4になる
	debug(MAX(++a, b));
	// aは5になり，5が表示されることを予想するが，
	// aはこの時2回インクリメントされる
	debug(MAX(++a, b-7));
	
	return 0;
}
