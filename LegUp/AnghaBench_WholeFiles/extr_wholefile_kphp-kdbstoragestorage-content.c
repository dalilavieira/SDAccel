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
typedef  enum ContentType { ____Placeholder_ContentType } ContentType ;

/* Variables and functions */
#define  TL_STORAGE_FILE_GIF 148 
#define  TL_STORAGE_FILE_JPEG 147 
#define  TL_STORAGE_FILE_MOV 146 
#define  TL_STORAGE_FILE_MP3 145 
#define  TL_STORAGE_FILE_MP4 144 
#define  TL_STORAGE_FILE_PARTIAL 143 
#define  TL_STORAGE_FILE_PDF 142 
#define  TL_STORAGE_FILE_PNG 141 
#define  TL_STORAGE_FILE_UNKNOWN 140 
#define  TL_STORAGE_FILE_WEBP 139 
#define  ct_gif 138 
#define  ct_jpeg 137 
#define  ct_last 136 
#define  ct_mov 135 
#define  ct_mp3 134 
#define  ct_mp4 133 
#define  ct_partial 132 
#define  ct_pdf 131 
#define  ct_png 130 
#define  ct_unknown 129 
#define  ct_webp 128 
 int /*<<< orphan*/  memcmp (unsigned char const*,char*,int) ; 

int detect_content_type (const unsigned char *const buff, int size) {
  const unsigned int *a = (const unsigned int *) buff;
  switch (buff[0]) {
    case 0:
      if (size >= 12) {
        if (a[0] == 0x14000000 && a[1] == 0x70797466 && a[2] == 0x20207471) {
          return ct_mov;
        }
        if (!(a[0] & 0x00ffffff) && a[1] == 0x70797466 && (a[2] & 0x00ffffff) == 0x0034706d) {
          return ct_mp4;
        }
      }
      break;
    case '%':
      if (size >= 4 && !memcmp (&buff[1], "PDF", 3)) {
        return ct_pdf;
      }
      break;
    case 'I':
      if (size >= 3 && !memcmp (&buff[1], "D3", 2)) {
        return ct_mp3;
      }
      break;
    case 'G':
      if (size >= 5 && !memcmp (&buff[1], "IF", 2)) {
        return ct_gif;
      }
      break;
    case 'R':
      if (size >= 4 && !memcmp (&buff[1], "IFF", 3)) {
        if (size >= 12 && !memcmp (&buff[8], "WEBP", 4)) {
          return ct_webp;
        }
        return ct_mp3;
      }
      break;
    case 0x89:
      if (size >= 4 && !memcmp (&buff[1], "PNG", 3)) {
        return ct_png;
      }
      break;
    case 0xff:
      if (size >= 2 && buff[1] == 0xd8) {
        return ct_jpeg;
      }
      if (size >= 2 && buff[1] >= 0xe0) {
        return ct_mp3;
      }
      break;
  }
  return ct_unknown;
}

int ext_to_content_type (char ext[4]) {
  int r = ext[0];
  r <<= 8;
  r |= ext[1];
  r <<= 8;
  r |= ext[2];
  r |= 0x202020; /* lowercase */
  switch (r) {
    case 0x62696e: return ct_partial; /* bin */
    case 0x676966: return ct_gif;
    case 0x6a7067: return ct_jpeg;
    case 0x6d7033: return ct_mp3;
    case 0x6d7034: return ct_mp4;
    case 0x6d6f76: return ct_mov;
    case 0x706466: return ct_pdf;
    case 0x706e67: return ct_png;
    case 0x776270: return ct_webp; /* wbp */
  }
  return ct_unknown;
}

int content_type_to_file_type (enum ContentType content_type) {
  switch (content_type) {
    case ct_unknown: return TL_STORAGE_FILE_UNKNOWN;
    case ct_jpeg: return TL_STORAGE_FILE_JPEG;
    case ct_gif: return TL_STORAGE_FILE_GIF;
    case ct_png: return TL_STORAGE_FILE_PNG;
    case ct_pdf: return TL_STORAGE_FILE_PDF;
    case ct_mp3: return TL_STORAGE_FILE_MP3;
    case ct_mov: return TL_STORAGE_FILE_MOV;
    case ct_partial: return TL_STORAGE_FILE_PARTIAL;
    case ct_mp4: return TL_STORAGE_FILE_MP4;
    case ct_webp: return TL_STORAGE_FILE_WEBP;
    case ct_last: break;
  }
  return 0;
}

int file_type_to_content_type (int file_type) {
  switch (file_type) {
    case TL_STORAGE_FILE_UNKNOWN: return ct_unknown;
    case TL_STORAGE_FILE_JPEG: return ct_jpeg;
    case TL_STORAGE_FILE_GIF: return ct_gif;
    case TL_STORAGE_FILE_PNG: return ct_png;
    case TL_STORAGE_FILE_PDF: return ct_pdf;
    case TL_STORAGE_FILE_MP3: return ct_mp3;
    case TL_STORAGE_FILE_MOV: return ct_mov;
    case TL_STORAGE_FILE_MP4: return ct_mp4;
    case TL_STORAGE_FILE_PARTIAL: return ct_partial;
    case TL_STORAGE_FILE_WEBP: return ct_webp;
  }
  return ct_last | 0x40000000;
}

