//
// Created by turha on 1.11.2022.
//

#include "fileWriter.h"
using namespace std;
static string fileName;

void fileWriter::writer(string text,string outputArgv){


    //writing output
    ofstream outputFile(outputArgv);

    outputFile <<text;

    outputFile.close();

}