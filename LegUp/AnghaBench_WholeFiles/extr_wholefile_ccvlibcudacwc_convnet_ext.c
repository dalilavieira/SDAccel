#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_56__   TYPE_9__ ;
typedef  struct TYPE_55__   TYPE_8__ ;
typedef  struct TYPE_54__   TYPE_7__ ;
typedef  struct TYPE_53__   TYPE_6__ ;
typedef  struct TYPE_52__   TYPE_5__ ;
typedef  struct TYPE_51__   TYPE_4__ ;
typedef  struct TYPE_50__   TYPE_3__ ;
typedef  struct TYPE_49__   TYPE_2__ ;
typedef  struct TYPE_48__   TYPE_1__ ;
typedef  struct TYPE_47__   TYPE_11__ ;
typedef  struct TYPE_46__   TYPE_10__ ;

/* Type definitions */
struct TYPE_49__ {int width; int height; } ;
typedef  TYPE_2__ ccv_size_t ;
struct TYPE_50__ {int x; int y; int width; int height; } ;
typedef  TYPE_3__ ccv_rect_t ;
struct TYPE_51__ {int x; int y; } ;
typedef  TYPE_4__ ccv_point_t ;
typedef  int /*<<< orphan*/  ccv_matrix_t ;
struct TYPE_52__ {int left; int top; int right; int bottom; } ;
typedef  TYPE_5__ ccv_margin_t ;
struct TYPE_53__ {int /*<<< orphan*/  filename; } ;
typedef  TYPE_6__ ccv_file_info_t ;
struct TYPE_48__ {double* f64; float* f32; } ;
struct TYPE_54__ {scalar_t__ cols; scalar_t__ rows; TYPE_1__ data; int /*<<< orphan*/  type; } ;
typedef  TYPE_7__ ccv_dense_matrix_t ;
struct TYPE_55__ {float x; float y; float a; float b; float roll; float pitch; float yaw; } ;
typedef  TYPE_8__ ccv_decimal_pose_t ;
struct TYPE_56__ {float x; float y; } ;
typedef  TYPE_9__ ccv_decimal_point_t ;
struct TYPE_46__ {int c; int type; TYPE_6__ file; TYPE_7__* matrix; } ;
typedef  TYPE_10__ ccv_categorized_t ;
struct TYPE_47__ {int rnum; } ;
typedef  TYPE_11__ ccv_array_t ;

/* Variables and functions */
 int CCV_32F ; 
 int CCV_64F ; 
 int CCV_C1 ; 
#define  CCV_CATEGORIZED_DENSE_MATRIX 129 
#define  CCV_CATEGORIZED_FILE 128 
 int /*<<< orphan*/  CCV_CLI_ERROR ; 
 int /*<<< orphan*/  CCV_CLI_INFO ; 
 int CCV_GET_CHANNEL (int /*<<< orphan*/ ) ; 
 int CCV_IO_ANY_FILE ; 
 int CCV_IO_RGB_COLOR ; 
 int /*<<< orphan*/  FLUSH (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  PRINT (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ alloca (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  ccv_add (TYPE_7__*,TYPE_7__*,int /*<<< orphan*/ **,int) ; 
 scalar_t__ ccv_array_get (TYPE_11__*,int) ; 
 TYPE_7__ ccv_dense_matrix (int,int,int,double*,int /*<<< orphan*/ ) ; 
 TYPE_7__* ccv_dense_matrix_new (scalar_t__,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_7__* ccv_dense_matrix_renew (TYPE_7__*,scalar_t__,scalar_t__,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccv_eigen (TYPE_7__*,TYPE_7__**,TYPE_7__**,int,int) ; 
 int /*<<< orphan*/  ccv_matrix_free (TYPE_7__*) ; 
 int /*<<< orphan*/  ccv_read (int /*<<< orphan*/ ,TYPE_7__**,int) ; 
 int /*<<< orphan*/  ccv_shift (TYPE_7__*,int /*<<< orphan*/ **,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccv_slice (TYPE_7__*,int /*<<< orphan*/ **,int,int,int,int,int) ; 
 int /*<<< orphan*/  ccv_zero (TYPE_7__*) ; 
 int /*<<< orphan*/  memset (double*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) inline static ccv_margin_t ccv_margin(int left, int top, int right, int bottom)
{
	ccv_margin_t margin;
	margin.left = left;
	margin.top = top;
	margin.right = right;
	margin.bottom = bottom;
	return margin;
}

__attribute__((used)) inline static ccv_size_t ccv_size(int width, int height)
{
	ccv_size_t size;
	size.width = width;
	size.height = height;
	return size;
}

__attribute__((used)) inline static int ccv_size_is_zero(ccv_size_t size)
{
	return size.width == 0 && size.height == 0;
}

__attribute__((used)) inline static ccv_rect_t ccv_rect(int x, int y, int width, int height)
{
	ccv_rect_t rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return rect;
}

__attribute__((used)) inline static int ccv_rect_is_zero(ccv_rect_t rect)
{
	return rect.x == 0 && rect.y == 0 && rect.width == 0 && rect.height == 0;
}

__attribute__((used)) inline static ccv_point_t ccv_point(int x, int y)
{
	ccv_point_t point;
	point.x = x;
	point.y = y;
	return point;
}

__attribute__((used)) inline static ccv_decimal_point_t ccv_decimal_point(float x, float y)
{
	ccv_decimal_point_t point;
	point.x = x;
	point.y = y;
	return point;
}

__attribute__((used)) inline static ccv_decimal_pose_t ccv_decimal_pose(float x, float y, float a, float b, float roll, float pitch, float yaw)
{
	ccv_decimal_pose_t pose;
	pose.x = x;
	pose.y = y;
	pose.a = a;
	pose.b = b;
	pose.roll = roll;
	pose.pitch = pitch;
	pose.yaw = yaw;
	return pose;
}

__attribute__((used)) inline static ccv_categorized_t ccv_categorized(int c, ccv_dense_matrix_t* matrix, ccv_file_info_t* file)
{
	assert((matrix && !file) || (!matrix && file));
	ccv_categorized_t categorized;
	categorized.c = c;
	if (matrix)
		categorized.type = CCV_CATEGORIZED_DENSE_MATRIX, categorized.matrix = matrix;
	else
		categorized.type = CCV_CATEGORIZED_FILE, categorized.file = *file;
	return categorized;
}

void cwc_convnet_mean_formation(ccv_array_t* categorizeds, ccv_size_t dim, int channels, int symmetric, ccv_dense_matrix_t** b)
{
	int i, count = 0;
	ccv_dense_matrix_t* c = ccv_dense_matrix_new(dim.height, dim.width, channels | CCV_64F, 0, 0);
	ccv_zero(c);
	ccv_dense_matrix_t* db = *b = ccv_dense_matrix_renew(*b, dim.height, dim.width, channels | CCV_32F, channels | CCV_32F, 0);
	for (i = 0; i < categorizeds->rnum; i++)
	{
		if (i % 23 == 0 || i == categorizeds->rnum - 1)
			FLUSH(CCV_CLI_INFO, " - compute mean activity %d / %d", i + 1, categorizeds->rnum);
		ccv_categorized_t* categorized = (ccv_categorized_t*)ccv_array_get(categorizeds, i);
		ccv_dense_matrix_t* image = 0;
		switch (categorized->type)
		{
			case CCV_CATEGORIZED_DENSE_MATRIX:
				image = categorized->matrix;
				break;
			case CCV_CATEGORIZED_FILE:
				ccv_read(categorized->file.filename, &image, CCV_IO_ANY_FILE | CCV_IO_RGB_COLOR);
				break;
		}
		if (!image)
		{
			PRINT(CCV_CLI_ERROR, "cannot load %s.\n", categorized->file.filename);
			continue;
		}
		ccv_dense_matrix_t* patch = 0;
		if (image->cols != dim.width || image->rows != dim.height)
		{
			int x = (image->cols - dim.width + 1) / 2;
			int y = (image->rows - dim.height + 1) / 2;
			assert(x == 0 || y == 0);
			ccv_slice(image, (ccv_matrix_t**)&patch, CCV_32F, y, x, dim.height, dim.width);
		} else
			ccv_shift(image, (ccv_matrix_t**)&patch, CCV_32F, 0, 0); // converting to 32f
		if (categorized->type != CCV_CATEGORIZED_DENSE_MATRIX)
			ccv_matrix_free(image);
		ccv_add(patch, c, (ccv_matrix_t**)&c, CCV_64F);
		++count;
		ccv_matrix_free(patch);
	}
	if (symmetric)
	{
		int j, k;
		double p = 0.5 / count;
		double* cptr = c->data.f64;
		float* dbptr = db->data.f32;
		for (i = 0; i < db->rows; i++)
		{
			for (j = 0; j < db->cols; j++)
				for (k = 0; k < channels; k++)
					dbptr[j * channels + k] = p * (cptr[j * channels + k] + cptr[(c->cols - j - 1) * channels + k]);
			dbptr += db->cols * channels;
			cptr += c->cols * channels;
		}
	} else {
		double p = 1.0 / count;
		for (i = 0; i < dim.height * dim.width * channels; i++)
			db->data.f32[i] = p * c->data.f64[i];
	}
	ccv_matrix_free(c);
	PRINT(CCV_CLI_INFO, "\n");
}

void cwc_convnet_channel_eigen(ccv_array_t* categorizeds, ccv_dense_matrix_t* mean_activity, ccv_size_t dim, int channels, ccv_dense_matrix_t** eigenvectors, ccv_dense_matrix_t** eigenvalues)
{
	assert(channels == 3); // this function cannot handle anything other than 3x3 covariance matrix
	double* mean_value = (double*)alloca(sizeof(double) * channels);
	memset(mean_value, 0, sizeof(double) * channels);
	assert(CCV_GET_CHANNEL(mean_activity->type) == channels);
	assert(mean_activity->rows == dim.height);
	assert(mean_activity->cols == dim.width);
	int i, j, k, c, count = 0;
	for (i = 0; i < dim.height * dim.width; i++)
		for (k = 0; k < channels; k++)
			mean_value[k] += mean_activity->data.f32[i * channels + k];
	for (i = 0; i < channels; i++)
		mean_value[i] = mean_value[i] / (dim.height * dim.width);
	double* covariance = (double*)alloca(sizeof(double) * channels * channels);
	memset(covariance, 0, sizeof(double) * channels * channels);
	for (c = 0; c < categorizeds->rnum; c++)
	{
		if (c % 23 == 0 || c == categorizeds->rnum - 1)
			FLUSH(CCV_CLI_INFO, " - compute covariance matrix for data augmentation (color gain) %d / %d", c + 1, categorizeds->rnum);
		ccv_categorized_t* categorized = (ccv_categorized_t*)ccv_array_get(categorizeds, c);
		ccv_dense_matrix_t* image = 0;
		switch (categorized->type)
		{
			case CCV_CATEGORIZED_DENSE_MATRIX:
				image = categorized->matrix;
				break;
			case CCV_CATEGORIZED_FILE:
				ccv_read(categorized->file.filename, &image, CCV_IO_ANY_FILE | CCV_IO_RGB_COLOR);
				break;
		}
		if (!image)
		{
			PRINT(CCV_CLI_ERROR, "cannot load %s.\n", categorized->file.filename);
			continue;
		}
		ccv_dense_matrix_t* patch = 0;
		if (image->cols != dim.width || image->rows != dim.height)
		{
			int x = (image->cols - dim.width + 1) / 2;
			int y = (image->rows - dim.height + 1) / 2;
			assert(x == 0 || y == 0);
			ccv_slice(image, (ccv_matrix_t**)&patch, CCV_32F, y, x, dim.height, dim.width);
		} else
			ccv_shift(image, (ccv_matrix_t**)&patch, CCV_32F, 0, 0); // converting to 32f
		if (categorized->type != CCV_CATEGORIZED_DENSE_MATRIX)
			ccv_matrix_free(image);
		for (i = 0; i < dim.width * dim.height; i++)
			for (j = 0; j < channels; j++)
				for (k = j; k < channels; k++)
					covariance[j * channels + k] += (patch->data.f32[i * channels + j] - mean_value[j]) * (patch->data.f32[i * channels + k] - mean_value[k]);
		++count;
		ccv_matrix_free(patch);
	}
	for (i = 0; i < channels; i++)
		for (j = 0; j < i; j++)
			covariance[i * channels + j] = covariance[j * channels + i];
	double p = 1.0 / ((double)count * dim.height * dim.width);
	for (i = 0; i < channels; i++)
		for (j = 0; j < channels; j++)
			covariance[i * channels + j] *= p; // scale down
	ccv_dense_matrix_t covm = ccv_dense_matrix(3, 3, CCV_64F | CCV_C1, covariance, 0);
	ccv_eigen(&covm, eigenvectors, eigenvalues, CCV_64F, 1e-8);
	PRINT(CCV_CLI_INFO, "\n");
}

