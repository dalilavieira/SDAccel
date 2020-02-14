#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_8__ ;
typedef  struct TYPE_41__   TYPE_7__ ;
typedef  struct TYPE_40__   TYPE_6__ ;
typedef  struct TYPE_39__   TYPE_5__ ;
typedef  struct TYPE_38__   TYPE_4__ ;
typedef  struct TYPE_37__   TYPE_3__ ;
typedef  struct TYPE_36__   TYPE_2__ ;
typedef  struct TYPE_35__   TYPE_1__ ;

/* Type definitions */
struct TYPE_35__ {int width; int height; } ;
typedef  TYPE_1__ ccv_size_t ;
struct TYPE_36__ {int x; int y; int width; int height; } ;
typedef  TYPE_2__ ccv_rect_t ;
struct TYPE_37__ {int x; int y; } ;
typedef  TYPE_3__ ccv_point_t ;
struct TYPE_38__ {int left; int top; int right; int bottom; } ;
typedef  TYPE_4__ ccv_margin_t ;
typedef  int /*<<< orphan*/  ccv_file_info_t ;
struct TYPE_39__ {int step; } ;
typedef  TYPE_5__ ccv_dense_matrix_t ;
struct TYPE_40__ {float x; float y; float a; float b; float roll; float pitch; float yaw; } ;
typedef  TYPE_6__ ccv_decimal_pose_t ;
struct TYPE_41__ {float x; float y; } ;
typedef  TYPE_7__ ccv_decimal_point_t ;
struct TYPE_42__ {int c; int /*<<< orphan*/  file; int /*<<< orphan*/  type; TYPE_5__* matrix; } ;
typedef  TYPE_8__ ccv_categorized_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int CCV_8U ; 
 int CCV_C1 ; 
 int CCV_C3 ; 
 int CCV_C4 ; 
 int /*<<< orphan*/  CCV_CATEGORIZED_DENSE_MATRIX ; 
 int /*<<< orphan*/  CCV_CATEGORIZED_FILE ; 
#define  CCV_IO_ABGR_RAW 138 
 int CCV_IO_ANY_FILE ; 
 int CCV_IO_ANY_RAW ; 
 int CCV_IO_ANY_STREAM ; 
#define  CCV_IO_ARGB_RAW 137 
#define  CCV_IO_BGRA_RAW 136 
#define  CCV_IO_BGR_RAW 135 
#define  CCV_IO_BINARY_FILE 134 
#define  CCV_IO_BMP_FILE 133 
 int CCV_IO_DEFLATE_STREAM ; 
 int CCV_IO_ERROR ; 
 int CCV_IO_FINAL ; 
#define  CCV_IO_GRAY_RAW 132 
#define  CCV_IO_JPEG_FILE 131 
 int CCV_IO_NO_COPY ; 
#define  CCV_IO_PNG_FILE 130 
#define  CCV_IO_RGBA_RAW 129 
#define  CCV_IO_RGB_RAW 128 
 int CCV_IO_UNKNOWN ; 
 int CCV_NO_DATA_ALLOC ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  _ccv_read_abgr_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_argb_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_bgr_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_bgra_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_binary_fd (int /*<<< orphan*/ *,TYPE_5__**,int) ; 
 int /*<<< orphan*/  _ccv_read_bmp_fd (int /*<<< orphan*/ *,TYPE_5__**,int) ; 
 int /*<<< orphan*/  _ccv_read_gray_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_rgb_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_read_rgba_raw (TYPE_5__**,void*,int,int,int,int) ; 
 int /*<<< orphan*/  _ccv_write_binary_fd (TYPE_5__*,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_5__* ccv_dense_matrix_new (int,int,int,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccv_make_matrix_immutable (TYPE_5__*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fread (unsigned char*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (unsigned char*,char*,int) ; 

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

__attribute__((used)) static int _ccv_read_and_close_fd(FILE* fd, ccv_dense_matrix_t** x, int type)
{
	int ctype = (type & 0xF00) ? CCV_8U | ((type & 0xF00) >> 8) : 0;
	if ((type & 0XFF) == CCV_IO_ANY_FILE)
	{
		unsigned char sig[8];
		(void) fread(sig, 1, 8, fd);
		if (memcmp(sig, "\x89\x50\x4e\x47\xd\xa\x1a\xa", 8) == 0)
			type = CCV_IO_PNG_FILE;
		else if (memcmp(sig, "\xff\xd8\xff", 3) == 0)
			type = CCV_IO_JPEG_FILE;
		else if (memcmp(sig, "BM", 2) == 0)
			type = CCV_IO_BMP_FILE;
		else if (memcmp(sig, "CCVBINDM", 8) == 0)
			type = CCV_IO_BINARY_FILE;
		fseek(fd, 0, SEEK_SET);
	}
	switch (type & 0XFF)
	{
#ifdef HAVE_LIBJPEG
		case CCV_IO_JPEG_FILE:
			_ccv_read_jpeg_fd(fd, x, ctype);
			break;
#endif
#ifdef HAVE_LIBPNG
		case CCV_IO_PNG_FILE:
			_ccv_read_png_fd(fd, x, ctype);
			break;
#endif
		case CCV_IO_BMP_FILE:
			_ccv_read_bmp_fd(fd, x, ctype);
			break;
		case CCV_IO_BINARY_FILE:
			_ccv_read_binary_fd(fd, x, ctype);
	}
	if (*x != 0)
		ccv_make_matrix_immutable(*x);
	if (type & CCV_IO_ANY_FILE)
		fclose(fd);
	return CCV_IO_FINAL;
}

__attribute__((used)) static int _ccv_read_raw(ccv_dense_matrix_t** x, void* data, int type, int rows, int cols, int scanline)
{
	assert(rows > 0 && cols > 0 && scanline > 0);
	if (type & CCV_IO_NO_COPY)
	{
		// there is no conversion that we can apply if it is NO_COPY mode
		// NO_COPY mode generate an "unreusable" matrix, which requires you to
		// manually release its data block (which is, in fact the same data
		// block you passed in)
		int ctype = CCV_8U | CCV_C1;
		switch (type & 0xFF)
		{
			case CCV_IO_RGB_RAW:
			case CCV_IO_BGR_RAW:
				ctype = CCV_8U | CCV_C3;
				break;
			case CCV_IO_RGBA_RAW:
			case CCV_IO_ARGB_RAW:
			case CCV_IO_BGRA_RAW:
			case CCV_IO_ABGR_RAW:
				ctype = CCV_8U | CCV_C4;
				break;
			case CCV_IO_GRAY_RAW:
			default:
				/* default one */
				break;
		}
		*x = ccv_dense_matrix_new(rows, cols, ctype | CCV_NO_DATA_ALLOC, data, 0);
		(*x)->step = scanline;
	} else {
		switch (type & 0xFF)
		{
			case CCV_IO_RGB_RAW:
				_ccv_read_rgb_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_RGBA_RAW:
				_ccv_read_rgba_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_ARGB_RAW:
				_ccv_read_argb_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_BGR_RAW:
				_ccv_read_bgr_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_BGRA_RAW:
				_ccv_read_bgra_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_ABGR_RAW:
				_ccv_read_abgr_raw(x, data, type, rows, cols, scanline);
				break;
			case CCV_IO_GRAY_RAW:
				_ccv_read_gray_raw(x, data, type, rows, cols, scanline);
				break;
		}
	}
	if (*x != 0)
		ccv_make_matrix_immutable(*x);
	return CCV_IO_FINAL;
}

int ccv_read_impl(const void* in, ccv_dense_matrix_t** x, int type, int rows, int cols, int scanline)
{
	FILE* fd = 0;
	if (type & CCV_IO_ANY_FILE)
	{
		assert(rows == 0 && cols == 0 && scanline == 0);
		fd = fopen((const char*)in, "rb");
		if (!fd)
			return CCV_IO_ERROR;
		return _ccv_read_and_close_fd(fd, x, type);
	} else if (type & CCV_IO_ANY_STREAM) {
		assert(rows > 8 && cols == 0 && scanline == 0);
		assert((type & 0xFF) != CCV_IO_DEFLATE_STREAM); // deflate stream (compressed stream) is not supported yet
#if _XOPEN_SOURCE >= 700 || _POSIX_C_SOURCE >= 200809L || defined(__APPLE__) || defined(BSD)
		// this is only supported by glibc
#if _XOPEN_SOURCE >= 700 || _POSIX_C_SOURCE >= 200809L
		fd = fmemopen((void*)in, (size_t)rows, "rb");
#else
		ccv_io_mem_t mem = {
			.size = rows,
			.pos = 0,
			.buffer = (char*)in,
		};
		fd = funopen(&mem, readfn, 0, seekfn, 0);
#endif
		if (!fd)
			return CCV_IO_ERROR;
		// mimicking itself as a "file"
		type = (type & ~0x10) | 0x20;
		return _ccv_read_and_close_fd(fd, x, type);
#endif
	} else if (type & CCV_IO_ANY_RAW) {
		return _ccv_read_raw(x, (void*)in /* it can be modifiable if it is NO_COPY mode */, type, rows, cols, scanline);
	}
	return CCV_IO_UNKNOWN;
}

int ccv_write(ccv_dense_matrix_t* mat, char* out, int* len, int type, void* conf)
{
	FILE* fd = 0;
	if (type & CCV_IO_ANY_FILE)
	{
		fd = fopen(out, "wb");
		if (!fd)
			return CCV_IO_ERROR;
	}
	switch (type)
	{
		case CCV_IO_JPEG_FILE:
#ifdef HAVE_LIBJPEG
			_ccv_write_jpeg_fd(mat, fd, conf);
			if (len != 0)
				*len = 0;
#else
			assert(0 && "ccv_write requires libjpeg support for JPEG format");
#endif
			break;
		case CCV_IO_PNG_FILE:
#ifdef HAVE_LIBPNG
			_ccv_write_png_fd(mat, fd, conf);
			if (len != 0)
				*len = 0;
#else
			assert(0 && "ccv_write requires libpng support for PNG format");
#endif
			break;
		case CCV_IO_BINARY_FILE:
			_ccv_write_binary_fd(mat, fd, conf);
			if (len != 0)
				*len = 0;
			break;
	}
	if (type & CCV_IO_ANY_FILE)
		fclose(fd);
	return CCV_IO_FINAL;
}

