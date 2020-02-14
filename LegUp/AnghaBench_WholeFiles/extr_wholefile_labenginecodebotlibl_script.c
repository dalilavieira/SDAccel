#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {TYPE_1__* punctuations; TYPE_3__** punctuationtable; } ;
typedef  TYPE_2__ script_t ;
struct TYPE_10__ {scalar_t__* p; struct TYPE_10__* next; } ;
typedef  TYPE_3__ punctuation_t ;
struct TYPE_8__ {char* p; int n; } ;

/* Variables and functions */
 int /*<<< orphan*/  Com_Memset (TYPE_3__**,int /*<<< orphan*/ ,int) ; 
 scalar_t__ GetMemory (int) ; 
 scalar_t__ strlen (scalar_t__*) ; 

void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations)
{
	int i;
	punctuation_t *p, *lastp, *newp;

	//get memory for the table
	if (!script->punctuationtable) script->punctuationtable = (punctuation_t **)
												GetMemory(256 * sizeof(punctuation_t *));
	Com_Memset(script->punctuationtable, 0, 256 * sizeof(punctuation_t *));
	//add the punctuations in the list to the punctuation table
	for (i = 0; punctuations[i].p; i++)
	{
		newp = &punctuations[i];
		lastp = NULL;
		//sort the punctuations in this table entry on length (longer punctuations first)
		for (p = script->punctuationtable[(unsigned int) newp->p[0]]; p; p = p->next)
		{
			if (strlen(p->p) < strlen(newp->p))
			{
				newp->next = p;
				if (lastp) lastp->next = newp;
				else script->punctuationtable[(unsigned int) newp->p[0]] = newp;
				break;
			} //end if
			lastp = p;
		} //end for
		if (!p)
		{
			newp->next = NULL;
			if (lastp) lastp->next = newp;
			else script->punctuationtable[(unsigned int) newp->p[0]] = newp;
		} //end if
	} //end for
}

char *PunctuationFromNum(script_t *script, int num)
{
	int i;

	for (i = 0; script->punctuations[i].p; i++)
	{
		if (script->punctuations[i].n == num) return script->punctuations[i].p;
	} //end for
	return "unknown punctuation";
}

