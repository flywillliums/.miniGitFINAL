#include "brett-miniGit.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
namespace fs = std::filesystem;
int main(){
    miniGit *MG = new miniGit();
    MG->init();
    MG->addFile("original.txt");
    MG->commit();
}