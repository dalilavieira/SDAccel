#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
struct TYPE_29__ {int isBinary; int isAutoSpacing; int isQuiet; scalar_t__ hasError; TYPE_1__* vtable; } ;
struct TYPE_28__ {size_t (* readString ) (TYPE_2__*,char const*,char**) ;size_t (* writeString ) (TYPE_2__*,char const*,size_t) ;size_t (* position ) (TYPE_2__*) ;int (* isOpened ) (TYPE_2__*) ;int /*<<< orphan*/  (* free ) (TYPE_2__*) ;int /*<<< orphan*/  (* close ) (TYPE_2__*) ;int /*<<< orphan*/  (* seekEnd ) (TYPE_2__*) ;int /*<<< orphan*/  (* seek ) (TYPE_2__*,size_t) ;int /*<<< orphan*/  (* synchronize ) (TYPE_2__*) ;} ;
typedef  TYPE_2__ THFile ;

/* Variables and functions */
 size_t stub1 (TYPE_2__*,char const*,char**) ; 
 size_t stub2 (TYPE_2__*,char const*,size_t) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*,size_t) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*) ; 
 size_t stub6 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_2__*) ; 
 int stub9 (TYPE_2__*) ; 

size_t THFile_readStringRaw(THFile *self, const char *format, char **str_)
{
  return self->vtable->readString(self, format, str_);
}

size_t THFile_writeStringRaw(THFile *self, const char *str, size_t size)
{
  return self->vtable->writeString(self, str, size);
}

void THFile_synchronize(THFile *self)
{
  self->vtable->synchronize(self);
}

void THFile_seek(THFile *self, size_t position)
{
  self->vtable->seek(self, position);
}

void THFile_seekEnd(THFile *self)
{
  self->vtable->seekEnd(self);
}

size_t THFile_position(THFile *self)
{
  return self->vtable->position(self);
}

void THFile_close(THFile *self)
{
  self->vtable->close(self);
}

void THFile_free(THFile *self)
{
  self->vtable->free(self);
}

int THFile_isOpened(THFile *self)
{
  return self->vtable->isOpened(self);
}

void THFile_binary(THFile *self)
{
  self->isBinary = 1;
}

void THFile_ascii(THFile *self)
{
  self->isBinary = 0;
}

void THFile_autoSpacing(THFile *self)
{
  self->isAutoSpacing = 1;
}

void THFile_noAutoSpacing(THFile *self)
{
  self->isAutoSpacing = 0;
}

void THFile_quiet(THFile *self)
{
  self->isQuiet = 1;
}

void THFile_pedantic(THFile *self)
{
  self->isQuiet = 0;
}

void THFile_clearError(THFile *self)
{
  self->hasError = 0;
}

