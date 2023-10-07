#include "node.h"
#include "tree.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fileToRead;
    ofstream fileToWrite;

    FILE *outFile;

    string outFileName;
    string fileName;
    string outFileNameBase;
    string data;
    string word;
    int wordLength;

    tree bstTree;

    switch (argc) {
        case 1:
            cout << "Keyboard input: enter words seperated by spaces, and use ctrl+D as EOF token." << endl;
            fileToWrite.open("temp.dat");
            while (getline(cin, data)) {
                fileToWrite << data << endl;
            }
            outFileNameBase = "out";

            fileToRead.open("temp.dat");
            break;
        case 2: 
            cout << "File input" << endl;
            fileName = argv[1];
            fileName.append(".f23");
            fileToRead.open(fileName.c_str());
            outFileNameBase = argv[1];
            break;
        default:
            cout << "ERROR: Incorrect parameters, exiting application..." << endl;
            return 0;
            break;

    }

    if (fileToRead.good()){
        while (fileToRead >> word) {
            wordLength = int(word.length());
            bstTree.buildTree(wordLength, word);
        }

        outFileName = outFileNameBase + ".inorder";
            outFile = fopen(outFileName.c_str(), "w");
            cout << "Generating " << outFileNameBase << ".inorder" << endl;
            bstTree.printInorder(bstTree.getRoot(bstTree), outFile);
            fclose(outFile);
            
        outFileName = outFileNameBase + ".preorder";
            outFile = fopen(outFileName.c_str(), "w");
            cout << "Generating " << outFileNameBase << ".preorder" << endl;
            bstTree.printPreorder(bstTree.getRoot(bstTree), outFile);
            fclose(outFile);
            
        outFileName = outFileNameBase + ".postorder";
            outFile = fopen(outFileName.c_str(), "w");
            cout << "Generating " << outFileNameBase << ".postorder" << endl;
            bstTree.printPostorder(bstTree.getRoot(bstTree), outFile);
            fclose(outFile);
            
            fileToRead.close();
            
            //clean up the temporary file - temp.dat
            remove("temp.dat");
            
            return 0;
    } else {
        cout << "ERROR: Problem reading file" << fileName << " Exiting application..." << endl;
        return 0;
    }
}