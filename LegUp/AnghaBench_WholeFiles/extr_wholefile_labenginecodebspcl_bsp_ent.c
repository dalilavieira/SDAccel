#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vec_t ;
typedef  double* vec3_t ;
struct TYPE_15__ {char* string; } ;
typedef  TYPE_1__ token_t ;
typedef  int /*<<< orphan*/  script_t ;
typedef  int qboolean ;
struct TYPE_16__ {char* key; char* value; struct TYPE_16__* next; } ;
typedef  TYPE_2__ epair_t ;
struct TYPE_17__ {TYPE_2__* epairs; } ;
typedef  TYPE_3__ entity_t ;

/* Variables and functions */
 int /*<<< orphan*/  Error (char*,...) ; 
 int /*<<< orphan*/  FreeMemory (char*) ; 
 TYPE_2__* GetMemory (int) ; 
 int MAX_KEY ; 
 size_t MAX_MAP_ENTITIES ; 
 int MAX_VALUE ; 
 int /*<<< orphan*/  PS_ExpectAnyToken (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  PS_ReadToken (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  PS_UnreadLastToken (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  StripDoubleQuotes (char*) ; 
 int /*<<< orphan*/  atof (char*) ; 
 void* copystring (char*) ; 
 TYPE_3__* entities ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 size_t num_entities ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sscanf (char*,char*,double*,double*,double*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int strlen (char*) ; 

void StripTrailing(char *e)
{
	char	*s;

	s = e + strlen(e)-1;
	while (s >= e && *s <= 32)
	{
		*s = 0;
		s--;
	}
}

epair_t *ParseEpair(script_t *script)
{
	epair_t *e;
	token_t token;

	e = GetMemory(sizeof(epair_t));
	memset (e, 0, sizeof(epair_t));
	
	PS_ExpectAnyToken(script, &token);
	StripDoubleQuotes(token.string);
	if (strlen(token.string) >= MAX_KEY-1)
		Error ("ParseEpair: token %s too long", token.string);
	e->key = copystring(token.string);
	PS_ExpectAnyToken(script, &token);
	StripDoubleQuotes(token.string);
	if (strlen(token.string) >= MAX_VALUE-1)
		Error ("ParseEpair: token %s too long", token.string);
	e->value = copystring(token.string);

	// strip trailing spaces
	StripTrailing(e->key);
	StripTrailing(e->value);

	return e;
}

qboolean	ParseEntity(script_t *script)
{
	epair_t *e;
	entity_t	*mapent;
	token_t token;

	if (!PS_ReadToken(script, &token))
		return false;

	if (strcmp(token.string, "{"))
		Error ("ParseEntity: { not found");
	
	if (num_entities == MAX_MAP_ENTITIES)
		Error ("num_entities == MAX_MAP_ENTITIES");

	mapent = &entities[num_entities];
	num_entities++;

	do
	{
		if (!PS_ReadToken(script, &token))
			Error ("ParseEntity: EOF without closing brace");
		if (!strcmp(token.string, "}") )
			break;
		PS_UnreadLastToken(script);
		e = ParseEpair(script);
		e->next = mapent->epairs;
		mapent->epairs = e;
	} while (1);
	
	return true;
}

void PrintEntity (entity_t *ent)
{
	epair_t	*ep;
	
	printf ("------- entity %p -------\n", ent);
	for (ep=ent->epairs ; ep ; ep=ep->next)
	{
		printf ("%s = %s\n", ep->key, ep->value);
	}

}

void 	SetKeyValue (entity_t *ent, char *key, char *value)
{
	epair_t	*ep;
	
	for (ep=ent->epairs ; ep ; ep=ep->next)
		if (!strcmp (ep->key, key) )
		{
			FreeMemory(ep->value);
			ep->value = copystring(value);
			return;
		}
	ep = GetMemory(sizeof(*ep));
	ep->next = ent->epairs;
	ent->epairs = ep;
	ep->key = copystring(key);
	ep->value = copystring(value);
}

char 	*ValueForKey (entity_t *ent, char *key)
{
	epair_t	*ep;
	
	for (ep=ent->epairs ; ep ; ep=ep->next)
		if (!strcmp (ep->key, key) )
			return ep->value;
	return "";
}

vec_t	FloatForKey (entity_t *ent, char *key)
{
	char	*k;
	
	k = ValueForKey (ent, key);
	return atof(k);
}

void 	GetVectorForKey (entity_t *ent, char *key, vec3_t vec)
{
	char	*k;
	double	v1, v2, v3;

	k = ValueForKey (ent, key);
// scanf into doubles, then assign, so it is vec_t size independent
	v1 = v2 = v3 = 0;
	sscanf (k, "%lf %lf %lf", &v1, &v2, &v3);
	vec[0] = v1;
	vec[1] = v2;
	vec[2] = v3;
}

