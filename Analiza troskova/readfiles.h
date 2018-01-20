#ifndef READFILES_H
#define READFILES_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "structures.h"
#include "math.h"

int fileList();//function that reads all files from the "account" folder
void renameFile(char *findname);//function that renames the file name
int detectFormat(char *);//function that detects all formats from "bills" folder
NODE *fillHead();//function that forms a list of customers and theys bills
void fillNode(NODE**, POD);//extra function that makes a new customer and his bill
int isValid(POD);//verifies the validity of existing bills

#endif // READFILES_H
