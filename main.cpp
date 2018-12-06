#include <iostream>
#include <string>
#include <fstream>
#include "UniqueBinaryTree.h"

std::string remove_punctuations(const std::string& str)
{
    std::string result;
    std::remove_copy_if(str.begin(), str.end(),
                        std::back_inserter(result), //Store output
                        std::ptr_fun<int, int>(&std::ispunct)
    );
    for (auto c : result) {
        if (c == '?') {
            std::cout << "aaaaaaa\n";
        }
    }
    return result;
}

int main(int argc, char** argv)
{

    // There should be 2 argument, executable and fileName
    if (argc != 2) {
        std::cout << "Please provide a file name. e.g. BST test.txt\n";
        return 0;
    }

    std::ifstream input;
    input.open(*(++argv));
    // if there is no file with the given fileName
    if (!input.is_open()) {
        std::cout << "Please provide valid file name\n";
        return 0;
    }
    UniqueBinaryTree<std::string> bst;
    std::string word;
    // insert words into BST
    while(input >> word) {
        word = remove_punctuations(word);
        // skip words which consist of only from punctuations. e.g. ".,;"
        if (!word.empty()) {
            bst.insertNode(word);
        }
    }
    bst.displayInOrder();
}
