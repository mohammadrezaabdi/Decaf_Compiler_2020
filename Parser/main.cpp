#include <Stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << " -i <input> -o <output>" << endl;
        return 1;
    }
    string input_file_name = argv[2];
    string output_file_name = argv[4];

    system("gcc -o a.out parser.tab.c");
    string run = "./a.out tests/" + input_file_name + " out/" + output_file_name;
    system(run.c_str());
}
