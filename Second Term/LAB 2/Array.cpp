//---------------------------------------------------------------------------


#pragma hdrstop

#include "Array.h"

//---------------------------------------------------------------------------

Array::Array()
{
     size = 0;
     price = 0;
}

Array::~Array()
{
     delete[] vector;
}

void Array::Add(String line, String FileName, int index, int order)
{
     size++;

     vecTmp = new Vector [size];
     for (int i = 0; i < size - 1; i++)
     {
         vecTmp[i] = vector[i];
     }
     if (size > 1) delete[] vector;
     vector = vecTmp;
     if (FileName != "") vector[size-1].add(line, FileName, index, order);
     else vector[size-1].add(line, index);
}


String Array::Show (int index, int order)
{
     return vector[index].Show(order);
}

int Array::Price()
{
    size--;
    while (size >= 0)
    {
        price += vector[size].Price();
        size--;
    }
    return price;
}


void Array::qSort(int first, int last, int d)
{
     int i = first, r = last;

     int priv = 0;
     if (d == 1) priv = vector[(first + last) / 2].Amount;
     else priv = vector[(first + last) / 2].Coast;

     while (i <= r)
     {
     	 if (d == 1)
         {
            while (vector[i].Amount < priv) i++;
     	    while (vector[r].Amount > priv) r--;
         }
         else
         {
            while (vector[i].Coast < priv) i++;
     	    while (vector[r].Coast > priv) r--;
         }

	 if (i <= r) Swap(vector[i++], vector[r--]);
     }

     if (first < r)
      	qSort(first, r, d);
     if (last > i)
      	qSort(i, last, d);
}

template<typename T> void Array::Swap(T& a, T& b)
{
     T A = a;
     T B = b;

     a = B;
     b = A;
}


void Array::reverce()
{
     int i = 0, j = size - 1;
     while (j - i >= 0)
     {
           Swap(vector[i], vector[j]);
           i++;
           j--;
     }
}


#pragma package(smart_init)
