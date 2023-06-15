//
// Created by turha on 2.11.2022.
//

#ifndef ASSIGNMENT10_TREASUREFINDER_H
#define ASSIGNMENT10_TREASUREFINDER_H



#include "fileReader.h"
#include "fileWriter.h"
class treasureFinder {
public:
    static void move(int **key, int **map, int keyRow, int mapRowSize, int mapColSize, int ** subMatrix,string outputArgv);
};


#endif //ASSIGNMENT10_TREASUREFINDER_H
