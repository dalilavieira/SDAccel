#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int width; int height; } ;
struct TYPE_12__ {int count; TYPE_3__* stage_classifier; TYPE_1__ size; } ;
typedef  TYPE_4__ ccv_bbf_classifier_cascade_t ;
struct TYPE_11__ {int count; double threshold; double* alpha; TYPE_2__* feature; } ;
struct TYPE_10__ {int size; int* px; int* py; int* pz; int* nx; int* ny; int* nz; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int ccv_bbf_classifier_cascade_write_binary (TYPE_4__*,char*,int) ; 
 TYPE_4__* ccv_bbf_read_classifier_cascade (char*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  fwrite (char*,int,int,int /*<<< orphan*/ *) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 

void write_c(ccv_bbf_classifier_cascade_t* cascade)
{

	printf("ccv_bbf_classifier_cascade_t* ccv_bbf_read_classifier_cascade()\n"
		   "{\n"
		   "	ccv_bbf_classifier_cascade_t* cascade = (ccv_bbf_classifier_cascade_t*)malloc(sizeof(ccv_bbf_classifier_cascade_t));\n"
		   "	cascade->count = %d;\n"
		   "	cascade->size = ccv_size(%d, %d);\n"
		   "	cascade->stage_classifier = (ccv_bbf_stage_classifier_t*)malloc(cascade->count * sizeof(ccv_bbf_stage_classifier_t));\n",
			cascade->count, cascade->size.width, cascade->size.height);
	int i, j, k;
	for (i = 0; i < cascade->count; i++)
	{
		printf("	{\n");
		printf("		ccv_bbf_stage_classifier_t* classifier = cascade->stage_classifier + %d;\n", i);
		printf("		classifier->count = %d;\n"
			   "		classifier->threshold = %f;\n",
			   cascade->stage_classifier[i].count, cascade->stage_classifier[i].threshold);
		printf("		classifier->feature = (ccv_bbf_feature_t*)malloc(classifier->count * sizeof(ccv_bbf_feature_t));\n"
			   "		classifier->alpha = (float*)malloc(classifier->count * 2 * sizeof(float));\n");
		for (j = 0; j < cascade->stage_classifier[i].count; j++)
		{
			printf("		classifier->feature[%d].size = %d;\n",
				   j, cascade->stage_classifier[i].feature[j].size);
			for (k = 0; k < cascade->stage_classifier[i].feature[j].size; k++)
			{
				printf("		classifier->feature[%d].px[%d] = %d;\n"
					   "		classifier->feature[%d].py[%d] = %d;\n"
					   "		classifier->feature[%d].pz[%d] = %d;\n",
					   j, k, cascade->stage_classifier[i].feature[j].px[k],
					   j, k, cascade->stage_classifier[i].feature[j].py[k],
					   j, k, cascade->stage_classifier[i].feature[j].pz[k]);
				printf("		classifier->feature[%d].nx[%d] = %d;\n"
					   "		classifier->feature[%d].ny[%d] = %d;\n"
					   "		classifier->feature[%d].nz[%d] = %d;\n",
					   j, k, cascade->stage_classifier[i].feature[j].nx[k],
					   j, k, cascade->stage_classifier[i].feature[j].ny[k],
					   j, k, cascade->stage_classifier[i].feature[j].nz[k]);
			}
			printf("		classifier->alpha[%d] = %f;\n"
				   "		classifier->alpha[%d] = %f;\n",
				   j * 2, cascade->stage_classifier[i].alpha[j * 2], j * 2 + 1, cascade->stage_classifier[i].alpha[j * 2 + 1]);
		}
		printf("	}\n");
	}
	printf("	return cascade;\n}");
}

void write_json(ccv_bbf_classifier_cascade_t* cascade)
{

	printf("{\"count\" : %d, \"width\" : %d, \"height\" : %d, \"stage_classifier\" : [",
		   cascade->count, cascade->size.width, cascade->size.height);
	int i, j, k;
	for (i = 0; i < cascade->count; i++)
	{
		printf("{\"count\":%d,\"threshold\":%le,\"feature\":[",
			   cascade->stage_classifier[i].count, cascade->stage_classifier[i].threshold);
		for (j = 0; j < cascade->stage_classifier[i].count; j++)
		{
			printf("{\"size\":%d,\"px\":[%d", cascade->stage_classifier[i].feature[j].size, cascade->stage_classifier[i].feature[j].px[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].px[k]);
			printf("],\"py\":[%d", cascade->stage_classifier[i].feature[j].py[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].py[k]);
			printf("],\"pz\":[%d", cascade->stage_classifier[i].feature[j].pz[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].pz[k]);
			printf("],\"nx\":[%d", cascade->stage_classifier[i].feature[j].nx[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].nx[k]);
			printf("],\"ny\":[%d", cascade->stage_classifier[i].feature[j].ny[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].ny[k]);
			printf("],\"nz\":[%d", cascade->stage_classifier[i].feature[j].nz[0]);
			for (k = 1; k < cascade->stage_classifier[i].feature[j].size; k++)
				printf(",%d", cascade->stage_classifier[i].feature[j].nz[k]);
			if (j < cascade->stage_classifier[i].count - 1)
				printf("]},");
			else
				printf("]}");
		}
		printf("],\"alpha\":[%le,%le", cascade->stage_classifier[i].alpha[0], cascade->stage_classifier[i].alpha[1]);
		for (j = 1; j < cascade->stage_classifier[i].count; j++)
			printf(",%le,%le", cascade->stage_classifier[i].alpha[j * 2], cascade->stage_classifier[i].alpha[j * 2 + 1]);
		if (i < cascade->count - 1)
			printf("]},");
		else
			printf("]}");
	}
	printf("]};\n");
}

int main(int argc, char** argv)
{
	assert(argc >= 3);
	ccv_bbf_classifier_cascade_t* cascade = ccv_bbf_read_classifier_cascade(argv[1]);
	if (strcmp(argv[2], "bin") == 0)
	{
		assert(argc >= 4);
		int len = ccv_bbf_classifier_cascade_write_binary(cascade, NULL, 0);
		char* s = malloc(len);
		ccv_bbf_classifier_cascade_write_binary(cascade, s, len);
		FILE* w = fopen(argv[3], "w");
		fwrite(s, 1, len, w);
		fclose(w);
		free(s);
	} else if (strcmp(argv[2], "c") == 0) {
		write_c(cascade);
	} else if (strcmp(argv[2], "json") == 0) {
		write_json(cascade);
	} else if (strcmp(argv[2], "cbin") == 0) {
		int len = ccv_bbf_classifier_cascade_write_binary(cascade, NULL, 0);
		char* s = malloc(len);
		ccv_bbf_classifier_cascade_write_binary(cascade, s, len);
		int i;
		for (i = 0; i < len; i++)
			printf("\\x%x", (unsigned char)s[i]);
		fflush(NULL);
		free(s);
	}
	return 0;
}

