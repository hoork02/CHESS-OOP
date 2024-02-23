#pragma once
#include<iostream>
#include<Windows.h>
#define BROWN 6
#define GREEN 
#define RED 4
#define LBLUE 9

using namespace std;


void getRowColbyLeftClick(int& rpos, int& cpos);

void gotoRowCol(int rpos, int cpos);

void SetClr(int tcl, int bcl);
