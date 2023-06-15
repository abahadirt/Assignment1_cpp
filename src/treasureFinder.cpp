//
// Created by turha on 2.11.2022.
//

#include "treasureFinder.h"

#include <iostream>
using namespace std;
static int moveRow=0;
static int moveCol=0;
static int topLeftIndexRow=0;
static int topLeftIndexCol=0;
static string text="";
void treasureFinder::move(int **key, int **map, int keyRow, int mapRowSize, int mapColSize, int**subMatrix,string outputArgv) {


    //i reckon with top left corner of location for get simplier dot product
    topLeftIndexRow+=moveRow;
    topLeftIndexCol+=moveCol;


    for (int i = 0; i < keyRow; ++i) {      //finding top left corner of location
        for (int j = 0; j < keyRow; ++j) {
            subMatrix[i][j] = map[i+topLeftIndexRow][j+topLeftIndexCol];
        }
    }

    int result=0;


    for(int i1=0; i1 < keyRow; ++i1 ){       //simple dot product
        for (int i2 = 0; i2 <keyRow ; ++i2) {
            result+=subMatrix[i1][i2]*key[i1][i2];
        }
    }




    text+= to_string(topLeftIndexRow+keyRow/2)+","+ to_string(topLeftIndexCol+keyRow/2)
            +":"+to_string(result)+"\n";        //output is stored here



    while(result<0){
        result+5;
    }


    if(result%5==0){         //Ending the game

        //Deleting the arrays
        for(int i = 0; i < keyRow; ++i) {
            delete [] key[i];
        }
        delete [] key;
//        for(int i = 0; i < mapRowSize; ++i) {
//            delete [] map[i];
//        }
//        delete [] map;

        fileWriter::writer(text,outputArgv);   //printing output

    }
    else {
        if (result % 5 == 1) {  //going up
            moveCol = 0;
            if (topLeftIndexRow + 1 > keyRow) {
                moveRow = -keyRow;
            } else {
                moveRow = keyRow;
            }

        } else if (result % 5 == 2) {     //going down
            moveCol = 0;
            if (mapRowSize > (topLeftIndexRow + keyRow - 1) + keyRow) {
                moveRow = keyRow;
            } else {
                moveRow = -keyRow;
            }


        } else if (result % 5 == 3) {       //going right
            moveRow = 0;
            if (mapColSize > (topLeftIndexCol + keyRow - 1) + keyRow) {
                moveCol = keyRow;
            } else {
                moveCol = -keyRow;
            }

        } else if (result % 5 == 4) {        //going left
            moveRow = 0;
            if (topLeftIndexCol + 1 > keyRow) {
                moveCol = -keyRow;
            } else {
                moveCol = keyRow;
            }

        }

        treasureFinder::move(key, map, keyRow, mapRowSize, mapColSize, subMatrix,outputArgv);  //recursion


    }









}



