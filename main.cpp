//15вариант, БД-Гербарий, Сортировка-слияние.

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "subfunc.h"

using namespace std;

void menu(Herbarium *collection)
{
    char res[2];
    res[0] = 'y';
    while(res[0] == 'y')
    {
        char respond[256];
        char respond1[256];
        char respond2[256];
        char respond3[256];
        printf("What to do?\n 1: show file\n 2: sort by latin name\n 3: sort by latin name backwards\n 4: sort by russian name\n 5: sort by russian name backwards\n 6: sort by date\n 7: sort by date backwards\n 8: sort by location\n 9: sort by location backwards\n\n");
        scanf("%s", &respond);

        if(!strcmp(respond, "1"))
        {
            showFile(collection);
        }
        if(!strcmp(respond, "2"))
        {
            mergeSort(collection, 0, findSize(collection)-1, latnameCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "3"))
        {
            mergeSortBackwards(collection, 0, findSize(collection)-1, latnameCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "4"))
        {
            mergeSort(collection, 0, findSize(collection)-1, rusnameCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "5"))
        {
            mergeSortBackwards(collection, 0, findSize(collection)-1, rusnameCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "6"))
        {
            mergeSort(collection, 0, findSize(collection)-1, dateCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "7"))
        {
            mergeSortBackwards(collection, 0, findSize(collection)-1, dateCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "8"))
        {
            mergeSort(collection, 0, findSize(collection)-1, locCompare);
            cout<<"Done!" << endl;
        }
        if(!strcmp(respond, "9"))
        {
            mergeSortBackwards(collection, 0, findSize(collection)-1, locCompare);
            cout<<"Done!" << endl;
        }
        printf("More menu? (y/n)\n", respond);
        scanf("%s", &res);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Herbarium *collection;
    collection=new Herbarium[256];
    openFileBin(collection);
    menu(collection);
    saveFileBin(collection);

    delete[] collection;
    collection=0;
    return 0;
}
