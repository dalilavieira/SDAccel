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
typedef  int /*<<< orphan*/  zval ;
typedef  int /*<<< orphan*/  zend_object_iterator ;
typedef  int /*<<< orphan*/  zend_class_entry ;
typedef  int /*<<< orphan*/  UErrorCode ;
struct TYPE_10__ {int /*<<< orphan*/ * funcs; int /*<<< orphan*/  data; } ;
struct TYPE_9__ {scalar_t__ i; int is_table; scalar_t__ length; int /*<<< orphan*/ * currentkey; int /*<<< orphan*/  current; TYPE_1__* subject; TYPE_3__ intern; } ;
struct TYPE_8__ {int /*<<< orphan*/  me; int /*<<< orphan*/  child; } ;
typedef  TYPE_1__ ResourceBundle_object ;
typedef  TYPE_2__ ResourceBundle_iterator ;

/* Variables and functions */
 int /*<<< orphan*/  E_ERROR ; 
 int FAILURE ; 
 int SUCCESS ; 
 scalar_t__ URES_TABLE ; 
 scalar_t__ U_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  U_ZERO_ERROR ; 
 int /*<<< orphan*/  ZVAL_COPY (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZVAL_LONG (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  ZVAL_STRING (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZVAL_UNDEF (int /*<<< orphan*/ *) ; 
 TYPE_1__* Z_INTL_RESOURCEBUNDLE_P (int /*<<< orphan*/ *) ; 
 scalar_t__ Z_ISUNDEF (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  efree (int /*<<< orphan*/ *) ; 
 TYPE_2__* emalloc (int) ; 
 int /*<<< orphan*/ * estrdup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  php_error (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  resourcebundle_extract_value (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  resourcebundle_iterator_funcs ; 
 int /*<<< orphan*/  ures_getByIndex (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ures_getKey (int /*<<< orphan*/ ) ; 
 scalar_t__ ures_getSize (int /*<<< orphan*/ ) ; 
 scalar_t__ ures_getType (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zend_iterator_init (TYPE_3__*) ; 
 int /*<<< orphan*/  zval_ptr_dtor (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void resourcebundle_iterator_read( ResourceBundle_iterator *iterator )
{
	UErrorCode icuerror = U_ZERO_ERROR;
	ResourceBundle_object *rb = iterator->subject;

	rb->child = ures_getByIndex( rb->me, iterator->i, rb->child, &icuerror );

	if (U_SUCCESS(icuerror)) {
		/* ATTN: key extraction must be the first thing to do... rb->child might be reset in read! */
		if (iterator->is_table) {
			iterator->currentkey = estrdup( ures_getKey( rb->child ) );
		}
		resourcebundle_extract_value( &iterator->current, rb );
	}
	else {
		// zend_throw_exception( spl_ce_OutOfRangeException, "Running past end of ResourceBundle", 0);
		ZVAL_UNDEF(&iterator->current);
	}
}

__attribute__((used)) static void resourcebundle_iterator_invalidate( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;

	if (!Z_ISUNDEF(iterator->current)) {
		zval_ptr_dtor( &iterator->current );
		ZVAL_UNDEF(&iterator->current);
	}
	if (iterator->currentkey) {
		efree( iterator->currentkey );
		iterator->currentkey = NULL;
	}
}

__attribute__((used)) static void resourcebundle_iterator_dtor( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;
	zval                    *object = &iterator->intern.data;

	resourcebundle_iterator_invalidate( iter );

	zval_ptr_dtor(object);
}

__attribute__((used)) static int resourcebundle_iterator_has_more( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;
	return (iterator->i < iterator->length) ? SUCCESS : FAILURE;
}

__attribute__((used)) static zval *resourcebundle_iterator_current( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;
	if (Z_ISUNDEF(iterator->current)) {
		resourcebundle_iterator_read( iterator);
	}
	return &iterator->current;
}

__attribute__((used)) static void resourcebundle_iterator_key( zend_object_iterator *iter, zval *key )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;

	if (Z_ISUNDEF(iterator->current)) {
		resourcebundle_iterator_read( iterator);
	}

	if (iterator->is_table) {
		ZVAL_STRING(key, iterator->currentkey);
	} else {
		ZVAL_LONG(key, iterator->i);
	}
}

__attribute__((used)) static void resourcebundle_iterator_step( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;

	iterator->i++;
	resourcebundle_iterator_invalidate( iter );
}

__attribute__((used)) static void resourcebundle_iterator_reset( zend_object_iterator *iter )
{
	ResourceBundle_iterator *iterator = (ResourceBundle_iterator *) iter;

	iterator->i = 0;
	resourcebundle_iterator_invalidate( iter );
}

zend_object_iterator *resourcebundle_get_iterator( zend_class_entry *ce, zval *object, int byref )
{
	ResourceBundle_object   *rb = Z_INTL_RESOURCEBUNDLE_P(object );
	ResourceBundle_iterator *iterator = emalloc( sizeof( ResourceBundle_iterator ) );

	if (byref) {
	     php_error( E_ERROR, "ResourceBundle does not support writable iterators" );
	}

	zend_iterator_init(&iterator->intern);
	ZVAL_COPY(&iterator->intern.data, object);
	iterator->intern.funcs = &resourcebundle_iterator_funcs;

	iterator->subject = rb;

	/* The iterated rb can only be either URES_TABLE or URES_ARRAY
	 * All other types are returned as php primitives!
	 */
	iterator->is_table = (ures_getType( rb->me ) == URES_TABLE);
	iterator->length = ures_getSize( rb->me );

	ZVAL_UNDEF(&iterator->current);
	iterator->currentkey = NULL;
	iterator->i = 0;

	return (zend_object_iterator *) iterator;
}

