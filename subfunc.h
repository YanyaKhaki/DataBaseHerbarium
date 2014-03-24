#ifndef SUBFUNC_H
#define SUBFUNC_H

struct Herbarium
{
    char latname[256]="TheEnd"; //Латинское название
    char rusname[256]; //Русское название
    int date; //Дата находки
    char location[256]; //Место находки
};

int findSize(Herbarium *collection);

void openFileBin(Herbarium *collection);
void saveFileBin(Herbarium *collection);
void showFile(Herbarium *collection);

int latnameCompare(Herbarium list1, Herbarium list2);
int rusnameCompare(Herbarium list1, Herbarium list2);
int dateCompare(Herbarium list1, Herbarium list2);
int locCompare(Herbarium list1, Herbarium list2);

void mergeSort(Herbarium *a, int first, int last, int (*fptr)(Herbarium,Herbarium));
void mergeSortBackwards(Herbarium *a, int first, int last, int (*fptr)(Herbarium,Herbarium));

#endif // SUBFUNC_H
