#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::string path = "D:/Updated Repo DSA/DSA/";          //Path
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path().string() << std::endl;    //Appended .string() when passing it to cout to make an explicit convesrion to string

    std::string path1 = "D:/Updated Repo DSA/DSA/";         //Path
    for (const auto & entry : fs::recursive_directory_iterator(path))
        std::cout << entry.path() << std::endl;

    return 0;
}