#include "generator.h"

using namespace std;

Generator::Generator(string size, string outputFilePath)
    : size(move(size)), outputFilePath(move(outputFilePath)) {}

void Generator::generateFile() const {
    ofstream file(outputFilePath, ios::binary);
    if (!file) {
        cerr << "Error abriendo archivo para escritura " << outputFilePath << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, numeric_limits<int>::max());

    long long fileSize;
    if (size == "SMALL") {
        fileSize = SMALL_SIZE;
    } else if (size == "MEDIUM") {
        fileSize = MEDIUM_SIZE;
    } else if (size == "LARGE") {
        fileSize = LARGE_SIZE;
    } else {
        cerr << "Opcion de SIZE invalida. Elija SMALL, MEDIUM, or LARGE." << endl;
        return;
    }

    size_t numIntegers = fileSize / sizeof(int);
    for (size_t i = 0; i < numIntegers; ++i) {
        int number = dis(gen);
        file.write(reinterpret_cast<char*>(&number), sizeof(number));
    }

    file.close();
    cout << "Archivo generado con exito. " << outputFilePath << endl;
}

void Generator::parseArguments(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: generator --size <SIZE> --output <OUTPUT FILE PATH>" << endl;
        exit(EXIT_FAILURE);
    }

    string sizeArg = argv[1];
    string sizeValue = argv[2];
    string outputArg = argv[3];
    string outputFilePath = argv[4];

    if (sizeArg != "--size" || outputArg != "--output") {
        cerr << "Argumentos Invalidos" << endl;
        exit(EXIT_FAILURE);
    }

    setSize(sizeValue);
    setOutputFilePath(outputFilePath);

    generateFile();
}

int main(int argc, char* argv[]) {
    Generator generator("", "");
    generator.parseArguments(argc, argv);

    return 0;
}
