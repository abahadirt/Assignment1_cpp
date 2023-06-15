
#include <iostream>
using namespace std;
#include "fileReader.h"
#include "treasureFinder.h"
#include <sstream>


void fileReader::reader(string mapSizeArgv, string keySizeArgv,string mapMatrixArgv ,string keyMatrixArgv , string outputArgv){


    string tempss2=" ";
    mapSizeArgv.replace(2,1,tempss2);
    stringstream ss;

    ss << mapSizeArgv;
    string tempss;
    int foundArray[]={0,0};
    int found;
    int itemp=0;
    while (!ss.eof()) {
        ss >> tempss;
        if (stringstream(tempss) >> found)
            foundArray[itemp]=found;
        itemp++;
        tempss="";
    }
//this is for only map size inputs converting string to integer

    ifstream keyMatrixFile(keyMatrixArgv);
    string text;

    int x1= stoi(keySizeArgv);




    //All operations and variables below for taking inputs and
    // creating dynamic arrays which are containing ints

    int** A;
    A = new int*[x1];
    for(int i=0;i<x1;i++) {
        A[i] = new int[x1];
    }


    int row = 0;
    int col =0;
    int tempInt;
    string tempString;
    while (getline (keyMatrixFile, text)) {
        col =0;
        stringstream temp(text);
        while (temp.good() && col < x1){
            temp>>tempString;
            tempInt= stoi(tempString);
            A[row][col]=tempInt;
            col++;
        }
        row++;


    }
    keyMatrixFile.close();

    int x=foundArray[0];
    int y=foundArray[1];


    int** B;
    B = new int*[x];
    for(int i=0;i<y;i++) {
        B[i] = new int[y];
    }



    ifstream mapMatrixFile(mapMatrixArgv);

    row = 0;
    col =0;



    while (getline (mapMatrixFile, text)) {
        col =0;
        stringstream temp(text);
        while (temp.good() && row < x){
            temp>>tempString;
            tempInt= stoi(tempString);
            B[row][col]=tempInt;
            col++;
        }
        row++;


    }
    keyMatrixFile.close();


    //Submatrix created for current location information and dot products.
    int** subMatrix;
    subMatrix = new int*[x1];
    for(int i=0;i<x1;i++) {
        subMatrix[i] = new int[x1];
    }

    treasureFinder::move(A,B,x1,x,y,subMatrix,outputArgv);
}









