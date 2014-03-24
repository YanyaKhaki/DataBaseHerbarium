//Не работает функция findSize, потому что там массив char..Не знаю, как указать его размер(при объявлении структуры)

#include <iostream>
#include <fstream>
#include <cstring>
#include "subfunc.h"

using namespace std;

int findSize(Herbarium *collection) //Находим размер
{
    int i=0;
    while(collection[i].latname!="TheEnd")
    {
        i++;
    }
    return i;
}

void openFileBin(Herbarium *collection) //Открываем бинарно
{
    ifstream stream("Herbarium.txt", ios::binary);
    stream.read((char *) collection, 256*sizeof(Herbarium));
    stream.close();
}

void saveFileBin(Herbarium *collection) //Сохраняем в новый файл
{
    ofstream stream("HerbariumSort.txt", ios::binary);
    stream.write((char *) collection, findSize(collection)*sizeof(Herbarium));
    stream.close();
}

void showFile(Herbarium *collection) //Выводим на консоль
{
    for(int i=0; i<findSize(collection); i++)
    {
        cout<<collection[i].latname<<" "<<collection[i].rusname<<" "<<collection[i].date<<" "<<collection[i].location<<endl;
    }
}

int latnameCompare(Herbarium list1, Herbarium list2)
{
    return strcmp(list1.latname,list2.latname);
}

int rusnameCompare(Herbarium list1, Herbarium list2)
{
    return strcmp(list1.rusname,list2.rusname);
}

int dateCompare(Herbarium list1, Herbarium list2)
{
    return list1.date-list2.date;
}
int locCompare(Herbarium list1, Herbarium list2)
{
    return strcmp(list1.location,list2.location);
}

void mergeSort(Herbarium *a, int first, int last, int (*fptr)(Herbarium,Herbarium))//
{
    Herbarium *sortA;
    sortA = new Herbarium[256];
    if(first < last)
    {
        mergeSort(a, first, (last+first)/2, (*fptr));
        mergeSort(a, (last+first)/2+1, last, (*fptr));
        int n = (last+first)/2+1;
        while((first <= (last+first)/2) && (n <= last))
        {
            if((*fptr)(a[first],a[n]) < 0)
            {
                sortA[first] = a[first];
                ++first;
            }
            else
            {
                sortA[first] = a[n];
                ++n;
            }
            ++first;
        }

        if(first <= (last+first)/2)
        {
            for(int k = first; k <= (last+first)/2; k++)
            {
                sortA[first] = a[k];
                ++first;
            }

        }
        else
        {
            for(int b = n; b < last+1; b++)
            {
                sortA[first] = a[b];
                ++first;
            }
        }

        for(int k = first; k <= last; k++)
        {
            a[k] = sortA[k];
        }

        delete[] sortA;
        sortA=0;
    }
}

void mergeSortBackwards(Herbarium *a, int first, int last, int (*fptr)(Herbarium,Herbarium))
{
    Herbarium *sortA;
    sortA = new Herbarium[125];
    if(first < last)
    {
        mergeSortBackwards(a, first, (last+first)/2, (*fptr));
        mergeSortBackwards(a, (last+first)/2+1, last, (*fptr));
        int n = (last+first)/2+1;
        while((first <= (last+first)/2) && (n <= last))
        {
            if((*fptr)(a[first],a[n])>0)
            {
                sortA[first] = a[first];
                ++first;
            }
            else
            {
                sortA[first] = a[n];
                ++n;
            }
            ++first;
        }

        if(first <= (last+first)/2)
        {
            for(int k = first; k <= (last+first)/2; k++)
            {
                sortA[first] = a[k];
                ++first;
            }

        }
        else
        {
            for(int b = n; b < last+1; b++)
            {
                sortA[first] = a[b];
                ++first;
            }
        }

        for(int k = first; k <= last; k++)
        {
            a[k] = sortA[k];
        }

        delete[] sortA;
        sortA=0;
    }
}
