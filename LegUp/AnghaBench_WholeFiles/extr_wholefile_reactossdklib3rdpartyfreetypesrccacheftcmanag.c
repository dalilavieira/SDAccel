#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  y_res; int /*<<< orphan*/  x_res; scalar_t__ height; scalar_t__ width; scalar_t__ pixel; int /*<<< orphan*/  face_id; } ;
struct TYPE_5__ {scalar_t__ face_id; } ;
struct TYPE_6__ {TYPE_1__ scaler; } ;
typedef  int /*<<< orphan*/ * FT_Size ;
typedef  int /*<<< orphan*/  FT_Pointer ;
typedef  int /*<<< orphan*/  FT_Face ;
typedef  int /*<<< orphan*/  FT_F26Dot6 ;
typedef  scalar_t__ FT_Error ;
typedef  int /*<<< orphan*/  FT_Bool ;
typedef  TYPE_2__* FTC_SizeNode ;
typedef  TYPE_3__* FTC_Scaler ;
typedef  int /*<<< orphan*/  FTC_MruNode ;
typedef  int /*<<< orphan*/  FTC_Manager ;
typedef  scalar_t__ FTC_FaceID ;

/* Variables and functions */
 scalar_t__ FTC_Manager_LookupFace (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_Activate_Size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_BOOL (int) ; 
 int /*<<< orphan*/  FT_Done_Size (int /*<<< orphan*/ *) ; 
 scalar_t__ FT_New_Size (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 scalar_t__ FT_Set_Char_Size (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ FT_Set_Pixel_Sizes (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 

__attribute__((used)) static FT_Error
  ftc_scaler_lookup_size( FTC_Manager  manager,
                          FTC_Scaler   scaler,
                          FT_Size     *asize )
  {
    FT_Face   face;
    FT_Size   size = NULL;
    FT_Error  error;


    error = FTC_Manager_LookupFace( manager, scaler->face_id, &face );
    if ( error )
      goto Exit;

    error = FT_New_Size( face, &size );
    if ( error )
      goto Exit;

    FT_Activate_Size( size );

    if ( scaler->pixel )
      error = FT_Set_Pixel_Sizes( face, scaler->width, scaler->height );
    else
      error = FT_Set_Char_Size( face,
                                (FT_F26Dot6)scaler->width,
                                (FT_F26Dot6)scaler->height,
                                scaler->x_res,
                                scaler->y_res );
    if ( error )
    {
      FT_Done_Size( size );
      size = NULL;
    }

  Exit:
    *asize = size;
    return error;
  }

__attribute__((used)) static FT_Bool
  ftc_size_node_compare_faceid( FTC_MruNode  ftcnode,
                                FT_Pointer   ftcface_id )
  {
    FTC_SizeNode  node    = (FTC_SizeNode)ftcnode;
    FTC_FaceID    face_id = (FTC_FaceID)ftcface_id;


    return FT_BOOL( node->scaler.face_id == face_id );
  }

