#include "file_space.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Expected a path argument" << endl;
		return EXIT_FAILURE;
	}

    cout << getDirectorySize(argv[1]) << endl;

	return EXIT_SUCCESS;
}
