#include "file_space.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

int getDirectorySize(const std::string& path)
{
    int size = 0;
    directory_entry entry = directory_entry(path);
    if (entry.is_directory()) {
        for (const directory_entry& entry : directory_iterator(path)) {
            size += getDirectorySize(entry.path());
        }
    } else {
        size += entry.file_size();
    }

    return size;
}
