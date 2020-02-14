#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int xMin; int yMin; int xMax; int yMax; } ;
typedef  int /*<<< orphan*/  FT_Outline ;
typedef  TYPE_1__ FT_BBox ;

/* Variables and functions */
 long CLOCKS_PER_SEC ; 
 int /*<<< orphan*/  FT_Outline_Get_BBox (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  FT_Outline_Get_CBox (int /*<<< orphan*/ *,TYPE_1__*) ; 
 long REPEAT ; 
 double XVAL (int) ; 
 long clock () ; 
 int /*<<< orphan*/  dummy_outline_1 ; 
 int /*<<< orphan*/  dummy_outline_2 ; 
 int /*<<< orphan*/  dummy_outline_3 ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static long
  get_time( void )
  {
    return clock() * 10000L / CLOCKS_PER_SEC;
  }

__attribute__((used)) static void
  dump_outline( FT_Outline*  outline )
  {
    FT_BBox  bbox;

    /* compute and display cbox */
    FT_Outline_Get_CBox( outline, &bbox );
    printf( "cbox = [%.2f %.2f %.2f %.2f]\n",
             XVAL( bbox.xMin ),
             XVAL( bbox.yMin ),
             XVAL( bbox.xMax ),
             XVAL( bbox.yMax ) );

    /* compute and display bbox */
    FT_Outline_Get_BBox( outline, &bbox );
    printf( "bbox = [%.2f %.2f %.2f %.2f]\n",
             XVAL( bbox.xMin ),
             XVAL( bbox.yMin ),
             XVAL( bbox.xMax ),
             XVAL( bbox.yMax ) );
  }

__attribute__((used)) static void
  profile_outline( FT_Outline*   outline,
                   long          repeat )
  {
    FT_BBox  bbox;
    long     count;
    long     time0;

    time0 = get_time();
    for ( count = repeat; count > 0; count-- )
      FT_Outline_Get_CBox( outline, &bbox );

    time0 = get_time() - time0;
    printf( "time = %6.3f cbox = [%8.4f %8.4f %8.4f %8.4f]\n",
             ((double)time0/10000.0),
             XVAL( bbox.xMin ),
             XVAL( bbox.yMin ),
             XVAL( bbox.xMax ),
             XVAL( bbox.yMax ) );
    printf( "cbox_hex = [%08X %08X %08X %08X]\n",
             bbox.xMin, bbox.yMin, bbox.xMax, bbox.yMax );


    time0 = get_time();
    for ( count = repeat; count > 0; count-- )
      FT_Outline_Get_BBox( outline, &bbox );

    time0 = get_time() - time0;
    printf( "time = %6.3f bbox = [%8.4f %8.4f %8.4f %8.4f]\n",
             ((double)time0/10000.0),
             XVAL( bbox.xMin ),
             XVAL( bbox.yMin ),
             XVAL( bbox.xMax ),
             XVAL( bbox.yMax ) );
    printf( "bbox_hex = [%08X %08X %08X %08X]\n",
             bbox.xMin, bbox.yMin, bbox.xMax, bbox.yMax );
  }

int  main( int  argc, char**  argv )
  {
    printf( "outline #1\n" );
    profile_outline( &dummy_outline_1, REPEAT );

    printf( "outline #2\n" );
    profile_outline( &dummy_outline_2, REPEAT );

    printf( "outline #3\n" );
    profile_outline( &dummy_outline_3, REPEAT );

    return 0;
  }

