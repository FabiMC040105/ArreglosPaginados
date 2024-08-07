#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <sstream>
#include <vector>
#include <limits>
#include <cerrno>

using namespace std;

class Generator {
private:
    string size;
    string outputFilePath;

    const long long SMALL_SIZE = 512LL * 1024 * 1024; // 512 MB
    const long long MEDIUM_SIZE = 1LL * 1024 * 1024 * 1024; // 1 GB
    const long long LARGE_SIZE = 2LL * 1024 * 1024 * 1024; // 2 GB

    void generateFile() const;

public:
    Generator(string size, string outputFilePath);

    void parseArguments(int argc, char* argv[]);

    string getSize() const { return size; }
    string getOutputFilePath() const { return outputFilePath; }


    void setSize(const string& newSize) { size = newSize; }
    void setOutputFilePath(const string& newOutputFilePath) { outputFilePath = newOutputFilePath; }
};

#endif // GENERATOR_H
