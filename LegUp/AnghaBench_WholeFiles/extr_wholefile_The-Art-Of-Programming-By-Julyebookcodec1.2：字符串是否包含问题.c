#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 scalar_t__ contain1 (char*,char*) ; 
 scalar_t__ contain2 (char*,char*) ; 
 scalar_t__ contain3 (char*,char*) ; 
 scalar_t__ contain4 (char*,char*) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 
 int strlen (char*) ; 

int partion1(char * arr, int start, int end)
{
    char tmpChar;
    int i;
    while (*(arr + start) <= *(arr + end) && start < end)
    {
        start++; //start 指向第一个大的数据
    }
    if (start == end)
    {
        return start; //已经有序
    }
    for (i = start + 1; i < end; i++)
    {
        if (*(arr + i) < * (arr + end)) //交换
        {
            tmpChar = *(arr + start);
            *(arr + start) = *(arr + i);
            *(arr + i) = tmpChar;
            start++;
        }
    }
    tmpChar = *(arr + start);
    *(arr + start) = *(arr + i);
    *(arr + i) = tmpChar;
    return start;
}

int partion(char * arr, int start, int end)
{
    char tmpChar = *(arr + start);
    while (start < end)
    {
        while (*(arr + end) >= tmpChar && end > start)
        {
            end--;
        }
        if (start < end)
        {
            *(arr + start) = *(arr + end); //小的往左走
            start++;
        }
        else
        {
            break;
        }
        while (*(arr + start) <= tmpChar && end > start)
        {
            start++;
        }
        if (start < end)
        {
            *(arr + end) = *(arr + start);
            end--;
        }
        else
        {
            break;
        }
    }
    *(arr + start) = tmpChar;
    return start;
}

void quickSort(char * arr, int start, int end)
{
    if (start < end)
    {
        int mid = partion1(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}

void countSort(char * oldArr, char * newArr)
{
    int count[26] = {0};
    int i;
    int lenOld = strlen(oldArr);
    memset(newArr, 0, lenOld); //clear
    int pos;
    for (i = 0; i < lenOld; i++)
    {
        pos = *(oldArr + i) - 'A';
        count[pos]++;
    }
    for (i = 0; i < 25; i++)
    {
        count[i + 1] += count[i];
    }
    for (i = 0; i < lenOld; i++)
    {
        pos = count[*(oldArr + i) - 'A'];
        while (newArr[pos - 1] != 0)
        {
            pos++;
        }
        newArr[pos - 1] = *(oldArr + i);
    }
}

int main()
{
    char stra[50];
    char strb[50];
    char strc[50];
    sprintf(stra, "ABCDEFGHLMNOPQRS");
    sprintf(strb, "DCGSRQPO");
    sprintf(strc, "DCGSRQPZ");

    if (contain1(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain1(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain2(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain2(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain3(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain3(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain4(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain4(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain4("a", "A"))
        printf("a contain A in bit hack method\n");

    /*
     if(contain5("Ab","b")){
     printf("%s contain %s\n",stra,strb);
     }else{
     printf("%s not contain %s\n",stra,strb);
     }
     printf("\n");
     */
    return 0;
}

