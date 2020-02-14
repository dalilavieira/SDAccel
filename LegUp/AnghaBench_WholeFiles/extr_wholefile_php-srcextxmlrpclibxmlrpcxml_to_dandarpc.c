#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct TYPE_22__ {int /*<<< orphan*/  str; int /*<<< orphan*/  len; } ;
struct TYPE_20__ {char const* name; char const* key; char* val; int /*<<< orphan*/  children; TYPE_9__ text; int /*<<< orphan*/  attrs; } ;
typedef  TYPE_2__ xml_element_attr ;
typedef  TYPE_2__ xml_element ;
struct buffer_st {int /*<<< orphan*/  offset; int /*<<< orphan*/  data; } ;
typedef  int /*<<< orphan*/  XMLRPC_VECTOR_TYPE ;
typedef  int XMLRPC_VALUE_TYPE ;
typedef  int /*<<< orphan*/ * XMLRPC_VALUE ;
typedef  scalar_t__ XMLRPC_REQUEST_TYPE ;
typedef  TYPE_4__* XMLRPC_REQUEST_OUTPUT_OPTIONS ;
typedef  int /*<<< orphan*/ * XMLRPC_REQUEST ;
struct TYPE_19__ {scalar_t__ verbosity; } ;
struct TYPE_21__ {TYPE_1__ xml_elem_opts; } ;

/* Variables and functions */
 char const* ATTR_ARRAY ; 
 char const* ATTR_BASE64 ; 
 char const* ATTR_BOOLEAN ; 
 char const* ATTR_DATETIME ; 
 char const* ATTR_DOUBLE ; 
 char const* ATTR_ID ; 
 char const* ATTR_INT ; 
 char const* ATTR_MIXED ; 
 char const* ATTR_SCALAR ; 
 char const* ATTR_STRING ; 
 char const* ATTR_STRUCT ; 
 char const* ATTR_TYPE ; 
 char const* ATTR_VECTOR ; 
 char const* ATTR_VERSION ; 
 char const* ELEM_METHODCALL ; 
 char const* ELEM_METHODNAME ; 
 char const* ELEM_METHODRESPONSE ; 
 char const* ELEM_ROOT ; 
 TYPE_2__* Q_Head (int /*<<< orphan*/ *) ; 
 TYPE_2__* Q_Next (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Q_PushTail (int /*<<< orphan*/ *,TYPE_2__*) ; 
 char const* VAL_VERSION_0_9 ; 
 int /*<<< orphan*/  XMLRPC_AddValueToVector (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_CreateValueEmpty () ; 
 int /*<<< orphan*/  XMLRPC_GetValueBase64 (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueBoolean (int /*<<< orphan*/ *) ; 
 char const* XMLRPC_GetValueDateTime_ISO8601 (int /*<<< orphan*/ *) ; 
 double XMLRPC_GetValueDouble (int /*<<< orphan*/ *) ; 
 char* XMLRPC_GetValueID (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueInt (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetValueString (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetValueStringLen (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetVectorType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_RequestGetData (int /*<<< orphan*/ *) ; 
 char* XMLRPC_RequestGetMethodName (int /*<<< orphan*/ *) ; 
 TYPE_4__* XMLRPC_RequestGetOutputOptions (int /*<<< orphan*/ *) ; 
 scalar_t__ XMLRPC_RequestGetRequestType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_RequestSetData (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetMethodName (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetRequestType (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  XMLRPC_SetIsVector (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  XMLRPC_SetValueBase64 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueBoolean (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueDateTime_ISO8601 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueDouble (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueID_Case (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueInt (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * XMLRPC_VectorNext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_VectorRewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atof (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  base64_decode_xmlrpc (struct buffer_st*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  base64_encode_xmlrpc (struct buffer_st*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  buffer_delete (struct buffer_st*) ; 
 TYPE_2__* emalloc (int) ; 
 void* estrdup (char const*) ; 
 int /*<<< orphan*/  simplestring_add (TYPE_9__*,char const*) ; 
 int /*<<< orphan*/  simplestring_addn (TYPE_9__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,double) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 TYPE_2__* xml_elem_new () ; 
 scalar_t__ xml_elem_no_white_space ; 
#define  xmlrpc_base64 137 
#define  xmlrpc_boolean 136 
 int /*<<< orphan*/  xmlrpc_case_exact ; 
#define  xmlrpc_datetime 135 
#define  xmlrpc_double 134 
#define  xmlrpc_int 133 
 scalar_t__ xmlrpc_request_call ; 
 scalar_t__ xmlrpc_request_response ; 
#define  xmlrpc_string 132 
#define  xmlrpc_vector 131 
#define  xmlrpc_vector_array 130 
#define  xmlrpc_vector_mixed 129 
#define  xmlrpc_vector_struct 128 

XMLRPC_VALUE xml_element_to_DANDARPC_REQUEST_worker(XMLRPC_REQUEST request, XMLRPC_VALUE xCurrent, xml_element* el) {
   if(!xCurrent) {
      xCurrent = XMLRPC_CreateValueEmpty();
   }

   if(el->name) {
      const char* id = NULL;
      const char* type = NULL;
      xml_element_attr* attr_iter = Q_Head(&el->attrs);

      while(attr_iter) {
         if(!strcmp(attr_iter->key, ATTR_ID)) {
            id = attr_iter->val;
         }
         if(!strcmp(attr_iter->key, ATTR_TYPE)) {
            type = attr_iter->val;
         }
         attr_iter = Q_Next(&el->attrs);
      }

      if(id) {
         XMLRPC_SetValueID_Case(xCurrent, id, 0, xmlrpc_case_exact);
      }

      if(!strcmp(el->name, ATTR_SCALAR)) {
         if(!type || !strcmp(type, ATTR_STRING)) {
            XMLRPC_SetValueString(xCurrent, el->text.str, el->text.len);
         }
         else if(!strcmp(type, ATTR_INT)) {
            XMLRPC_SetValueInt(xCurrent, atoi(el->text.str));
         }
         else if(!strcmp(type, ATTR_BOOLEAN)) {
            XMLRPC_SetValueBoolean(xCurrent, atoi(el->text.str));
         }
         else if(!strcmp(type, ATTR_DOUBLE)) {
            XMLRPC_SetValueDouble(xCurrent, atof(el->text.str));
         }
         else if(!strcmp(type, ATTR_DATETIME)) {
            XMLRPC_SetValueDateTime_ISO8601(xCurrent, el->text.str);
         }
         else if(!strcmp(type, ATTR_BASE64)) {
            struct buffer_st buf;
            base64_decode_xmlrpc(&buf, el->text.str, el->text.len);
            XMLRPC_SetValueBase64(xCurrent, buf.data, buf.offset);
            buffer_delete(&buf);
         }
      }
      else if(!strcmp(el->name, ATTR_VECTOR)) {
         xml_element* iter = (xml_element*)Q_Head(&el->children);

         if(!type || !strcmp(type, ATTR_MIXED)) {
            XMLRPC_SetIsVector(xCurrent, xmlrpc_vector_mixed);
         }
         else if(!strcmp(type, ATTR_ARRAY)) {
				XMLRPC_SetIsVector(xCurrent, xmlrpc_vector_array);
         }
         else if(!strcmp(type, ATTR_STRUCT)) {
            XMLRPC_SetIsVector(xCurrent, xmlrpc_vector_struct);
         }
         while( iter ) {
            XMLRPC_VALUE xNext = XMLRPC_CreateValueEmpty();
            xml_element_to_DANDARPC_REQUEST_worker(request, xNext, iter);
            XMLRPC_AddValueToVector(xCurrent, xNext);
            iter = (xml_element*)Q_Next(&el->children);
         }
      }
      else {
         xml_element* iter = (xml_element*)Q_Head(&el->children);
         while( iter ) {
            xml_element_to_DANDARPC_REQUEST_worker(request, xCurrent, iter);
            iter = (xml_element*)Q_Next(&el->children);
         }

         if(!strcmp(el->name, ELEM_METHODCALL)) {
            if(request) {
               XMLRPC_RequestSetRequestType(request, xmlrpc_request_call);
            }
         }
         else if(!strcmp(el->name, ELEM_METHODRESPONSE)) {
            if(request) {
               XMLRPC_RequestSetRequestType(request, xmlrpc_request_response);
            }
         }
         else if(!strcmp(el->name, ELEM_METHODNAME)) {
            if(request) {
               XMLRPC_RequestSetMethodName(request, el->text.str);
            }
         }
      }
   }
   return xCurrent;
}

XMLRPC_VALUE xml_element_to_DANDARPC_VALUE(xml_element* el)
{
   return xml_element_to_DANDARPC_REQUEST_worker(NULL, NULL, el);
}

XMLRPC_VALUE xml_element_to_DANDARPC_REQUEST(XMLRPC_REQUEST request, xml_element* el)
{
   if(request) {
      return XMLRPC_RequestSetData(request, xml_element_to_DANDARPC_REQUEST_worker(request, NULL, el));
   }
   return NULL;
}

xml_element* DANDARPC_to_xml_element_worker(XMLRPC_REQUEST request, XMLRPC_VALUE node) {
#define BUF_SIZE 512
   xml_element* root = NULL;
   if(node) {
      char buf[BUF_SIZE];
      const char* id = XMLRPC_GetValueID(node);
      XMLRPC_VALUE_TYPE type = XMLRPC_GetValueType(node);
      XMLRPC_REQUEST_OUTPUT_OPTIONS output = XMLRPC_RequestGetOutputOptions(request);
      int bNoAddType = (type == xmlrpc_string && request && output && output->xml_elem_opts.verbosity == xml_elem_no_white_space);
      xml_element* elem_val = xml_elem_new();
      const char* pAttrType = NULL;

      xml_element_attr* attr_type = bNoAddType ? NULL : emalloc(sizeof(xml_element_attr));

      if(attr_type) {
         attr_type->key = estrdup(ATTR_TYPE);
         attr_type->val = 0;
         Q_PushTail(&elem_val->attrs, attr_type);
      }

      elem_val->name = (type == xmlrpc_vector) ? estrdup(ATTR_VECTOR) : estrdup(ATTR_SCALAR);

      if(id && *id) {
         xml_element_attr* attr_id = emalloc(sizeof(xml_element_attr));
         if(attr_id) {
            attr_id->key = estrdup(ATTR_ID);
            attr_id->val = estrdup(id);
            Q_PushTail(&elem_val->attrs, attr_id);
         }
      }

      switch(type) {
         case xmlrpc_string:
            pAttrType = ATTR_STRING;
            simplestring_addn(&elem_val->text, XMLRPC_GetValueString(node), XMLRPC_GetValueStringLen(node));
            break;
         case xmlrpc_int:
            pAttrType = ATTR_INT;
            snprintf(buf, BUF_SIZE, "%i", XMLRPC_GetValueInt(node));
            simplestring_add(&elem_val->text, buf);
            break;
         case xmlrpc_boolean:
            pAttrType = ATTR_BOOLEAN;
            snprintf(buf, BUF_SIZE, "%i", XMLRPC_GetValueBoolean(node));
            simplestring_add(&elem_val->text, buf);
            break;
         case xmlrpc_double:
            pAttrType = ATTR_DOUBLE;
            snprintf(buf, BUF_SIZE, "%f", XMLRPC_GetValueDouble(node));
            simplestring_add(&elem_val->text, buf);
            break;
         case xmlrpc_datetime:
            pAttrType = ATTR_DATETIME;
            simplestring_add(&elem_val->text, XMLRPC_GetValueDateTime_ISO8601(node));
            break;
         case xmlrpc_base64:
            {
               struct buffer_st buf;
               pAttrType = ATTR_BASE64;
               base64_encode_xmlrpc(&buf, XMLRPC_GetValueBase64(node), XMLRPC_GetValueStringLen(node));
               simplestring_addn(&elem_val->text, buf.data, buf.offset );
               buffer_delete(&buf);
            }
            break;
         case xmlrpc_vector:
            {
               XMLRPC_VECTOR_TYPE my_type = XMLRPC_GetVectorType(node);
               XMLRPC_VALUE xIter = XMLRPC_VectorRewind(node);

               switch(my_type) {
                  case xmlrpc_vector_array:
                     pAttrType = ATTR_ARRAY;
                     break;
                  case xmlrpc_vector_mixed:
                     pAttrType = ATTR_MIXED;
                     break;
                  case xmlrpc_vector_struct:
                     pAttrType = ATTR_STRUCT;
                     break;
                  default:
                     break;
               }

               /* recurse through sub-elements */
               while( xIter ) {
                  xml_element* next_el = DANDARPC_to_xml_element_worker(request, xIter);
                  if(next_el) {
                     Q_PushTail(&elem_val->children, next_el);
                  }
                  xIter = XMLRPC_VectorNext(node);
               }
            }
            break;
         default:
            break;
      }
      if(pAttrType && attr_type && !bNoAddType) {
         attr_type->val = estrdup(pAttrType);
      }
      root = elem_val;
   }
   return root;
}

xml_element* DANDARPC_VALUE_to_xml_element(XMLRPC_VALUE node) {
   return DANDARPC_to_xml_element_worker(NULL, node);
}

xml_element* DANDARPC_REQUEST_to_xml_element(XMLRPC_REQUEST request) {
   xml_element* wrapper = NULL;
   xml_element* root = NULL;
   if(request) {
      XMLRPC_REQUEST_TYPE request_type = XMLRPC_RequestGetRequestType(request);
      const char* pStr = NULL;
      xml_element_attr* version = emalloc(sizeof(xml_element_attr));
      version->key = estrdup(ATTR_VERSION);
      version->val = estrdup(VAL_VERSION_0_9);

      wrapper = xml_elem_new();

      if(request_type == xmlrpc_request_response) {
         pStr = ELEM_METHODRESPONSE;
      }
      else if(request_type == xmlrpc_request_call) {
         pStr = ELEM_METHODCALL;
      }
      if(pStr) {
         wrapper->name = estrdup(pStr);
      }

      root = xml_elem_new();
      root->name = estrdup(ELEM_ROOT);
      Q_PushTail(&root->attrs, version);
      Q_PushTail(&root->children, wrapper);

      pStr = XMLRPC_RequestGetMethodName(request);

      if(pStr) {
         xml_element* method = xml_elem_new();
         method->name = estrdup(ELEM_METHODNAME);
         simplestring_add(&method->text, pStr);
         Q_PushTail(&wrapper->children, method);
      }
      Q_PushTail(&wrapper->children,
                 DANDARPC_to_xml_element_worker(request, XMLRPC_RequestGetData(request)));
   }
   return root;
}

