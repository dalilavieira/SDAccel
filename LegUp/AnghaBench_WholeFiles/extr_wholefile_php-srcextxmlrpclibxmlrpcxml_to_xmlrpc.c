#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {int /*<<< orphan*/  str; int /*<<< orphan*/  len; } ;
struct TYPE_12__ {int /*<<< orphan*/  children; void* name; TYPE_6__ text; } ;
typedef  TYPE_1__ xml_element ;
struct buffer_st {int /*<<< orphan*/  offset; int /*<<< orphan*/  data; } ;
typedef  scalar_t__ XMLRPC_VECTOR_TYPE ;
typedef  int XMLRPC_VALUE_TYPE ;
typedef  int /*<<< orphan*/ * XMLRPC_VALUE ;
typedef  scalar_t__ XMLRPC_REQUEST_TYPE ;
typedef  int /*<<< orphan*/ * XMLRPC_REQUEST ;

/* Variables and functions */
 scalar_t__ EG (int /*<<< orphan*/ ) ; 
 char const* ELEM_ARRAY ; 
 char const* ELEM_BASE64 ; 
 char const* ELEM_BOOLEAN ; 
 char const* ELEM_DATA ; 
 char const* ELEM_DATETIME ; 
 char const* ELEM_DOUBLE ; 
 char const* ELEM_FAULT ; 
 int /*<<< orphan*/  ELEM_FAULTCODE ; 
 char const* ELEM_I4 ; 
 char const* ELEM_INT ; 
 char const* ELEM_MEMBER ; 
 char const* ELEM_METHODCALL ; 
 char const* ELEM_METHODNAME ; 
 char const* ELEM_METHODRESPONSE ; 
 char const* ELEM_NAME ; 
 char const* ELEM_PARAM ; 
 char const* ELEM_PARAMS ; 
 char const* ELEM_STRING ; 
 char const* ELEM_STRUCT ; 
 char const* ELEM_VALUE ; 
 scalar_t__ Q_Head (int /*<<< orphan*/ *) ; 
 scalar_t__ Q_Next (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Q_PushTail (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ Q_Size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_AddValueToVector (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_CreateValueEmpty () ; 
 int /*<<< orphan*/  XMLRPC_GetValueBase64 (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueBoolean (int /*<<< orphan*/ *) ; 
 char const* XMLRPC_GetValueDateTime_ISO8601 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetValueDouble (int /*<<< orphan*/ *) ; 
 char const* XMLRPC_GetValueID (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueInt (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetValueString (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_GetValueStringLen (int /*<<< orphan*/ *) ; 
 int XMLRPC_GetValueType (int /*<<< orphan*/ *) ; 
 scalar_t__ XMLRPC_GetVectorType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_RequestGetData (int /*<<< orphan*/ *) ; 
 char* XMLRPC_RequestGetMethodName (int /*<<< orphan*/ *) ; 
 scalar_t__ XMLRPC_RequestGetRequestType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_RequestSetData (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetMethodName (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetRequestType (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  XMLRPC_SetIsVector (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  XMLRPC_SetValueBase64 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueBoolean (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueDateTime_ISO8601 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueDouble (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueID_Case (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueInt (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_SetValueString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ XMLRPC_VectorGetValueWithID (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * XMLRPC_VectorNext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_VectorRewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ap_php_snprintf (char*,int,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atof (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  base64_decode_xmlrpc (struct buffer_st*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  base64_encode_xmlrpc (struct buffer_st*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  buffer_delete (struct buffer_st*) ; 
 void* estrdup (char const*) ; 
 int /*<<< orphan*/  precision ; 
 int /*<<< orphan*/  simplestring_add (TYPE_6__*,char const*) ; 
 int /*<<< orphan*/  simplestring_addn (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  strcmp (void*,char const*) ; 
 TYPE_1__* xml_elem_new () ; 
#define  xmlrpc_base64 138 
#define  xmlrpc_boolean 137 
 int /*<<< orphan*/  xmlrpc_case_exact ; 
#define  xmlrpc_datetime 136 
#define  xmlrpc_double 135 
#define  xmlrpc_empty 134 
#define  xmlrpc_int 133 
 scalar_t__ xmlrpc_request_call ; 
 scalar_t__ xmlrpc_request_none ; 
 scalar_t__ xmlrpc_request_response ; 
#define  xmlrpc_string 132 
#define  xmlrpc_vector 131 
#define  xmlrpc_vector_array 130 
#define  xmlrpc_vector_mixed 129 
 scalar_t__ xmlrpc_vector_none ; 
#define  xmlrpc_vector_struct 128 

XMLRPC_VALUE xml_element_to_XMLRPC_REQUEST_worker(XMLRPC_REQUEST request, XMLRPC_VALUE parent_vector, XMLRPC_VALUE current_val, xml_element* el) {
   if (!current_val) {
      /* This should only be the case for the first element */
      current_val = XMLRPC_CreateValueEmpty();
   }

	if (el->name) {

      /* first, deal with the crazy/stupid fault format */
      if (!strcmp(el->name, ELEM_FAULT)) {
			xml_element* fault_value = (xml_element*)Q_Head(&el->children);
			XMLRPC_SetIsVector(current_val, xmlrpc_vector_struct);

         if(fault_value) {
            xml_element* fault_struct = (xml_element*)Q_Head(&fault_value->children);
            if(fault_struct) {
               xml_element* iter = (xml_element*)Q_Head(&fault_struct->children);

               while (iter) {
                  XMLRPC_VALUE xNextVal = XMLRPC_CreateValueEmpty();
                  xml_element_to_XMLRPC_REQUEST_worker(request, current_val, xNextVal, iter);
                  XMLRPC_AddValueToVector(current_val, xNextVal);
                  iter = (xml_element*)Q_Next(&fault_struct->children);
               }
            }
         }
      }
		else if (!strcmp(el->name, ELEM_DATA)	/* should be ELEM_ARRAY, but there is an extra level. weird */
			 || (!strcmp(el->name, ELEM_PARAMS) &&
				  (XMLRPC_RequestGetRequestType(request) == xmlrpc_request_call)) ) {		/* this "PARAMS" concept is silly.  dave?! */
         xml_element* iter = (xml_element*)Q_Head(&el->children);
         XMLRPC_SetIsVector(current_val, xmlrpc_vector_array);

         while (iter) {
            XMLRPC_VALUE xNextVal = XMLRPC_CreateValueEmpty();
            xml_element_to_XMLRPC_REQUEST_worker(request, current_val, xNextVal, iter);
            XMLRPC_AddValueToVector(current_val, xNextVal);
            iter = (xml_element*)Q_Next(&el->children);
         }
		}
		else if (!strcmp(el->name, ELEM_STRUCT)) {
         xml_element* iter = (xml_element*)Q_Head(&el->children);
         XMLRPC_SetIsVector(current_val, xmlrpc_vector_struct);

         while ( iter ) {
            XMLRPC_VALUE xNextVal = XMLRPC_CreateValueEmpty();
            xml_element_to_XMLRPC_REQUEST_worker(request, current_val, xNextVal, iter);
            XMLRPC_AddValueToVector(current_val, xNextVal);
            iter = (xml_element*)Q_Next(&el->children);
         }
		}
		else if (!strcmp(el->name, ELEM_STRING) ||
                 (!strcmp(el->name, ELEM_VALUE) && Q_Size(&el->children) == 0)) {
         XMLRPC_SetValueString(current_val, el->text.str, el->text.len);
		}
		else if (!strcmp(el->name, ELEM_NAME)) {
         XMLRPC_SetValueID_Case(current_val, el->text.str, 0, xmlrpc_case_exact);
		}
		else if (!strcmp(el->name, ELEM_INT) || !strcmp(el->name, ELEM_I4)) {
         XMLRPC_SetValueInt(current_val, atoi(el->text.str));
		}
		else if (!strcmp(el->name, ELEM_BOOLEAN)) {
         XMLRPC_SetValueBoolean(current_val, atoi(el->text.str));
		}
		else if (!strcmp(el->name, ELEM_DOUBLE)) {
         XMLRPC_SetValueDouble(current_val, atof(el->text.str));
		}
		else if (!strcmp(el->name, ELEM_DATETIME)) {
         XMLRPC_SetValueDateTime_ISO8601(current_val, el->text.str);
		}
		else if (!strcmp(el->name, ELEM_BASE64)) {
         struct buffer_st buf;
         base64_decode_xmlrpc(&buf, el->text.str, el->text.len);
         XMLRPC_SetValueBase64(current_val, buf.data, buf.offset);
         buffer_delete(&buf);
		}
		else {
         xml_element* iter;

         if (!strcmp(el->name, ELEM_METHODCALL)) {
            if (request) {
               XMLRPC_RequestSetRequestType(request, xmlrpc_request_call);
            }
			}
			else if (!strcmp(el->name, ELEM_METHODRESPONSE)) {
            if (request) {
               XMLRPC_RequestSetRequestType(request, xmlrpc_request_response);
            }
			}
			else if (!strcmp(el->name, ELEM_METHODNAME)) {
            if (request) {
               XMLRPC_RequestSetMethodName(request, el->text.str);
            }
         }

         iter = (xml_element*)Q_Head(&el->children);
         while ( iter ) {
            xml_element_to_XMLRPC_REQUEST_worker(request, parent_vector,
                                                 current_val, iter);
            iter = (xml_element*)Q_Next(&el->children);
         }
      }
   }
   return current_val;
}

XMLRPC_VALUE xml_element_to_XMLRPC_VALUE(xml_element* el)
{
   return xml_element_to_XMLRPC_REQUEST_worker(NULL, NULL, NULL, el);
}

XMLRPC_VALUE xml_element_to_XMLRPC_REQUEST(XMLRPC_REQUEST request, xml_element* el)
{
   if (request) {
      return XMLRPC_RequestSetData(request, xml_element_to_XMLRPC_REQUEST_worker(request, NULL, NULL, el));
   }
   return NULL;
}

xml_element* XMLRPC_to_xml_element_worker(XMLRPC_VALUE current_vector, XMLRPC_VALUE node,
                                          XMLRPC_REQUEST_TYPE request_type, int depth) {
#define BUF_SIZE 512
   xml_element* root = NULL;
   if (node) {
      char buf[BUF_SIZE];
      XMLRPC_VALUE_TYPE type = XMLRPC_GetValueType(node);
      XMLRPC_VECTOR_TYPE vtype = XMLRPC_GetVectorType(node);
      xml_element* elem_val = xml_elem_new();

      /* special case for when root element is not an array */
      if (depth == 0 &&
          !(type == xmlrpc_vector &&
            vtype == xmlrpc_vector_array &&
            request_type == xmlrpc_request_call) ) {
         int bIsFault = (vtype == xmlrpc_vector_struct && XMLRPC_VectorGetValueWithID(node, ELEM_FAULTCODE));

         xml_element* next_el = XMLRPC_to_xml_element_worker(NULL, node, request_type, depth + 1);
         if (next_el) {
            Q_PushTail(&elem_val->children, next_el);
         }
         elem_val->name = estrdup(bIsFault ? ELEM_FAULT : ELEM_PARAMS);
		}
		else {
         switch (type) {
			case xmlrpc_empty: /*  treat null value as empty string in xmlrpc. */
         case xmlrpc_string:
            elem_val->name = estrdup(ELEM_STRING);
            simplestring_addn(&elem_val->text, XMLRPC_GetValueString(node), XMLRPC_GetValueStringLen(node));
            break;
         case xmlrpc_int:
            elem_val->name = estrdup(ELEM_INT);
            snprintf(buf, BUF_SIZE, "%i", XMLRPC_GetValueInt(node));
            simplestring_add(&elem_val->text, buf);
            break;
         case xmlrpc_boolean:
            elem_val->name = estrdup(ELEM_BOOLEAN);
            snprintf(buf, BUF_SIZE, "%i", XMLRPC_GetValueBoolean(node));
            simplestring_add(&elem_val->text, buf);
            break;
         case xmlrpc_double:
            {
                                elem_val->name = estrdup(ELEM_DOUBLE);
                ap_php_snprintf(buf, BUF_SIZE, "%.*G", (int) EG(precision), XMLRPC_GetValueDouble(node));
                simplestring_add(&elem_val->text, buf);
            }
            break;
         case xmlrpc_datetime:
            elem_val->name = estrdup(ELEM_DATETIME);
            simplestring_add(&elem_val->text, XMLRPC_GetValueDateTime_ISO8601(node));
            break;
         case xmlrpc_base64:
            {
               struct buffer_st buf;
               elem_val->name = estrdup(ELEM_BASE64);
               base64_encode_xmlrpc(&buf, XMLRPC_GetValueBase64(node), XMLRPC_GetValueStringLen(node));
               simplestring_addn(&elem_val->text, buf.data, buf.offset );
               buffer_delete(&buf);
            }
            break;
         case xmlrpc_vector:
            {
               XMLRPC_VECTOR_TYPE my_type = XMLRPC_GetVectorType(node);
               XMLRPC_VALUE xIter = XMLRPC_VectorRewind(node);
               xml_element* root_vector_elem = elem_val;

               switch (my_type) {
               case xmlrpc_vector_array:
                  {
                      if(depth == 0) {
                         elem_val->name = estrdup(ELEM_PARAMS);
                      }
                      else {
                         /* Hi my name is Dave and I like to make things as confusing
                          * as possible, thus I will throw in this 'data' element
                          * where it absolutely does not belong just so that people
                          * cannot code arrays and structs in a similar and straight
                          * forward manner. Have a good day.
                          *
                          * GRRRRRRRRR!
                          */
                         xml_element* data = xml_elem_new();
                         data->name = estrdup(ELEM_DATA);

                         elem_val->name = estrdup(ELEM_ARRAY);
                         Q_PushTail(&elem_val->children, data);
                         root_vector_elem = data;
                      }
                  }
                  break;
               case xmlrpc_vector_mixed:       /* not officially supported */
               case xmlrpc_vector_struct:
                  elem_val->name = estrdup(ELEM_STRUCT);
                  break;
               default:
                  break;
               }

               /* recurse through sub-elements */
               while ( xIter ) {
                  xml_element* next_el = XMLRPC_to_xml_element_worker(node, xIter, request_type, depth + 1);
                  if (next_el) {
                     Q_PushTail(&root_vector_elem->children, next_el);
                  }
                  xIter = XMLRPC_VectorNext(node);
               }
            }
            break;
         default:
            break;
         }
      }

      {
         XMLRPC_VECTOR_TYPE vtype = XMLRPC_GetVectorType(current_vector);

         if (depth == 1) {
            xml_element* value = xml_elem_new();
            value->name = estrdup(ELEM_VALUE);

            /* yet another hack for the "fault" crap */
            if (XMLRPC_VectorGetValueWithID(node, ELEM_FAULTCODE)) {
               root = value;
				}
				else {
               xml_element* param = xml_elem_new();
               param->name = estrdup(ELEM_PARAM);

               Q_PushTail(&param->children, value);

               root = param;
            }
            Q_PushTail(&value->children, elem_val);
			}
			else if (vtype == xmlrpc_vector_struct || vtype == xmlrpc_vector_mixed) {
            xml_element* member = xml_elem_new();
            xml_element* name = xml_elem_new();
            xml_element* value = xml_elem_new();

            member->name = estrdup(ELEM_MEMBER);
            name->name = estrdup(ELEM_NAME);
            value->name = estrdup(ELEM_VALUE);

            simplestring_add(&name->text, XMLRPC_GetValueID(node));

            Q_PushTail(&member->children, name);
            Q_PushTail(&member->children, value);
            Q_PushTail(&value->children, elem_val);

            root = member;
			}
			else if (vtype == xmlrpc_vector_array) {
            xml_element* value = xml_elem_new();

            value->name = estrdup(ELEM_VALUE);

            Q_PushTail(&value->children, elem_val);

            root = value;
			}
			else if (vtype == xmlrpc_vector_none) {
            /* no parent.  non-op */
            root = elem_val;
			}
			else {
            xml_element* value = xml_elem_new();

            value->name = estrdup(ELEM_VALUE);

            Q_PushTail(&value->children, elem_val);

            root = value;
         }
      }
   }
   return root;
}

xml_element* XMLRPC_VALUE_to_xml_element(XMLRPC_VALUE node) {
   return XMLRPC_to_xml_element_worker(NULL, node, xmlrpc_request_none, 0);
}

xml_element* XMLRPC_REQUEST_to_xml_element(XMLRPC_REQUEST request) {
   xml_element* wrapper = NULL;
   if (request) {
      const char* pStr = NULL;
      XMLRPC_REQUEST_TYPE request_type = XMLRPC_RequestGetRequestType(request);
      XMLRPC_VALUE xParams = XMLRPC_RequestGetData(request);

      wrapper = xml_elem_new();

      if (request_type == xmlrpc_request_call) {
         pStr = ELEM_METHODCALL;
		}
		else if (request_type == xmlrpc_request_response) {
         pStr = ELEM_METHODRESPONSE;
      }
      if (pStr) {
         wrapper->name = estrdup(pStr);
      }

		if(request_type == xmlrpc_request_call) {
      pStr = XMLRPC_RequestGetMethodName(request);

      if (pStr) {
         xml_element* method = xml_elem_new();
         method->name = estrdup(ELEM_METHODNAME);
         simplestring_add(&method->text, pStr);
         Q_PushTail(&wrapper->children, method);
      }
		}
      if (xParams) {
         Q_PushTail(&wrapper->children,
                    XMLRPC_to_xml_element_worker(NULL, XMLRPC_RequestGetData(request), XMLRPC_RequestGetRequestType(request), 0));
		}
		else {
         /* Despite the spec, the xml-rpc list folk want me to send an empty params element */
         xml_element* params = xml_elem_new();
         params->name = estrdup(ELEM_PARAMS);
         Q_PushTail(&wrapper->children, params);
      }
   }
   return wrapper;
}

