#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_38__   TYPE_8__ ;
typedef  struct TYPE_37__   TYPE_6__ ;
typedef  struct TYPE_36__   TYPE_5__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct TYPE_33__ {char const* key; char* val; } ;
typedef  TYPE_2__ xml_element_attr ;
struct TYPE_32__ {char const* str; scalar_t__ len; } ;
struct TYPE_34__ {char const* name; TYPE_1__ text; int /*<<< orphan*/  children; int /*<<< orphan*/  attrs; } ;
typedef  TYPE_3__ xml_element ;
struct TYPE_35__ {char const* name; int /*<<< orphan*/ * desc; } ;
typedef  TYPE_4__ server_method ;
typedef  scalar_t__ q_iter ;
struct TYPE_36__ {int b_called; int /*<<< orphan*/  (* method ) (TYPE_6__*,void*) ;} ;
typedef  TYPE_5__ doc_method ;
typedef  scalar_t__ XMLRPC_VALUE_TYPE ;
typedef  int /*<<< orphan*/ * XMLRPC_VALUE ;
typedef  TYPE_6__* XMLRPC_SERVER ;
typedef  int /*<<< orphan*/  XMLRPC_REQUEST ;
typedef  int /*<<< orphan*/  (* XMLRPC_IntrospectionCallback ) (TYPE_6__*,void*) ;
typedef  TYPE_8__* XMLRPC_ERROR ;
struct TYPE_38__ {int /*<<< orphan*/  xml_elem_error; } ;
struct TYPE_37__ {int /*<<< orphan*/  docslist; int /*<<< orphan*/ * xIntrospection; int /*<<< orphan*/  methodlist; } ;

/* Variables and functions */
 void* Q_Head (int /*<<< orphan*/ *) ; 
 void* Q_Iter_Get_F (scalar_t__) ; 
 scalar_t__ Q_Iter_Head_F (int /*<<< orphan*/ *) ; 
 scalar_t__ Q_Iter_Next_F (scalar_t__) ; 
 void* Q_Next (int /*<<< orphan*/ *) ; 
 scalar_t__ Q_PushTail (int /*<<< orphan*/ *,TYPE_5__*) ; 
 scalar_t__ Q_Size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_AddValueToVector (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_CleanupValue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_CopyValue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_CreateValueString (char const*,char const*,scalar_t__) ; 
 void* XMLRPC_CreateVector (char*,int /*<<< orphan*/ ) ; 
 char* XMLRPC_GetValueString (int /*<<< orphan*/ *) ; 
 scalar_t__ XMLRPC_GetValueType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_RequestGetData (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_ServerRegisterMethod (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ * (*) (TYPE_6__*,int /*<<< orphan*/ ,void*)) ; 
 int /*<<< orphan*/  XMLRPC_VectorAppendInt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  XMLRPC_VectorAppendString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 char const* XMLRPC_VectorGetStringWithID (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * XMLRPC_VectorGetValueWithID (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * XMLRPC_VectorNext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_VectorRemoveValue (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * XMLRPC_VectorRewind (int /*<<< orphan*/ *) ; 
 TYPE_5__* ecalloc (int,int) ; 
 TYPE_4__* find_method (TYPE_6__*,char const*) ; 
 int /*<<< orphan*/  my_free (TYPE_5__*) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  stub1 (TYPE_6__*,void*) ; 
 char const* type_to_str (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xi_token_default ; 
 int /*<<< orphan*/  xi_token_description ; 
 char const* xi_token_empty ; 
 int /*<<< orphan*/  xi_token_name ; 
 int /*<<< orphan*/  xi_token_optional ; 
 char* xi_token_params ; 
 int /*<<< orphan*/  xi_token_purpose ; 
 char* xi_token_returns ; 
 char* xi_token_signatures ; 
 int /*<<< orphan*/  xi_token_system_describe_methods ; 
 int /*<<< orphan*/  xi_token_system_list_methods ; 
 int /*<<< orphan*/  xi_token_system_method_help ; 
 int /*<<< orphan*/  xi_token_system_method_signature ; 
 int /*<<< orphan*/  xi_token_type ; 
 int /*<<< orphan*/  xml_elem_free (TYPE_3__*) ; 
 TYPE_3__* xml_elem_parse_buf (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlrpc_none ; 
 scalar_t__ xmlrpc_string ; 
 scalar_t__ xmlrpc_vector ; 
 int /*<<< orphan*/  xmlrpc_vector_array ; 
 int /*<<< orphan*/  xmlrpc_vector_mixed ; 
 int /*<<< orphan*/  xmlrpc_vector_struct ; 

__attribute__((used)) static inline XMLRPC_VALUE find_named_value(XMLRPC_VALUE list, const char* needle) {
   XMLRPC_VALUE xIter = XMLRPC_VectorRewind(list);
   while(xIter) {
      const char* name = XMLRPC_VectorGetStringWithID(xIter, xi_token_name);
      if(name && !strcmp(name, needle)) {
         return xIter;
      }
      xIter = XMLRPC_VectorNext(list);
   }
   return NULL;
}

__attribute__((used)) static void check_docs_loaded(XMLRPC_SERVER server, void* userData) {
   if(server) {
      q_iter qi = Q_Iter_Head_F(&server->docslist);
      while( qi ) {
         doc_method* dm = Q_Iter_Get_F(qi);
         if(dm && !dm->b_called) {
            dm->method(server, userData);
            dm->b_called = 1;
         }
         qi = Q_Iter_Next_F(qi);
      }
   }
}

__attribute__((used)) static inline void describe_method(XMLRPC_SERVER server, XMLRPC_VALUE vector, const char* method) {
   if(method) {
      server_method* sm = find_method(server, method);
      if(sm) {
         XMLRPC_AddValueToVector(vector, sm->desc);
      }
   }
}

__attribute__((used)) static XMLRPC_VALUE xi_system_describe_methods_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   XMLRPC_VALUE xParams = XMLRPC_VectorRewind(XMLRPC_RequestGetData(input));
   XMLRPC_VALUE xResponse = XMLRPC_CreateVector(NULL, xmlrpc_vector_struct);
   XMLRPC_VALUE xMethodList = XMLRPC_CreateVector("methodList", xmlrpc_vector_array);
   XMLRPC_VALUE xTypeList = NULL;
   int bAll = 1;

   /* lazy loading of introspection data */
   check_docs_loaded(server, userData);

   xTypeList = XMLRPC_VectorGetValueWithID(server->xIntrospection, "typeList");

   XMLRPC_AddValueToVector(xResponse, xTypeList);
   XMLRPC_AddValueToVector(xResponse, xMethodList);

   /* check if we have any param */
   if(xParams) {
      /* check if string or vector (1 or n) */
      XMLRPC_VALUE_TYPE type = XMLRPC_GetValueType(xParams);
      if(type == xmlrpc_string) {
         /* just one.  spit it out. */
         describe_method(server, xMethodList, XMLRPC_GetValueString(xParams));
         bAll = 0;
      }
      else if(type == xmlrpc_vector) {
         /* multiple.  spit all out */
         XMLRPC_VALUE xIter = XMLRPC_VectorRewind(xParams);
         while(xIter) {
            describe_method(server, xMethodList, XMLRPC_GetValueString(xIter));
            xIter = XMLRPC_VectorNext(xParams);
         }
         bAll = 0;
      }
   }

   /* otherwise, default to sending all methods */
   if(bAll) {
      q_iter qi = Q_Iter_Head_F(&server->methodlist);
      while( qi ) {
         server_method* sm = Q_Iter_Get_F(qi);
         if(sm) {
            XMLRPC_AddValueToVector(xMethodList, sm->desc);
         }
         qi = Q_Iter_Next_F(qi);
      }
   }

   return xResponse;
}

__attribute__((used)) static XMLRPC_VALUE xi_system_list_methods_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   XMLRPC_VALUE xResponse = XMLRPC_CreateVector(NULL, xmlrpc_vector_array);

   q_iter qi = Q_Iter_Head_F(&server->methodlist);
   while( qi ) {
      server_method* sm = Q_Iter_Get_F(qi);
      if(sm) {
         XMLRPC_VectorAppendString(xResponse, 0, sm->name, 0);
      }
      qi = Q_Iter_Next_F(qi);
   }
   return xResponse;
}

__attribute__((used)) static XMLRPC_VALUE xi_system_method_signature_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   const char* method = XMLRPC_GetValueString(XMLRPC_VectorRewind(XMLRPC_RequestGetData(input)));
   XMLRPC_VALUE xResponse = NULL;

   /* lazy loading of introspection data */
   check_docs_loaded(server, userData);

   if(method) {
      server_method* sm = find_method(server, method);
      if(sm && sm->desc) {
         XMLRPC_VALUE xTypesArray = XMLRPC_CreateVector(NULL, xmlrpc_vector_array);
         XMLRPC_VALUE xIter, xParams, xSig, xSigIter;
         const char* type;

         /* array of possible signatures.  */
         xResponse = XMLRPC_CreateVector(NULL, xmlrpc_vector_array);

         /* find first signature */
         xSig = XMLRPC_VectorGetValueWithID(sm->desc, xi_token_signatures);
         xSigIter = XMLRPC_VectorRewind( xSig );

         /* iterate through sigs */
         while(xSigIter) {
            /* first type is the return value */
            type = XMLRPC_VectorGetStringWithID(XMLRPC_VectorRewind(
                                                 XMLRPC_VectorGetValueWithID(xSigIter, xi_token_returns)),
                                                xi_token_type);
            XMLRPC_AddValueToVector(xTypesArray,
                                    XMLRPC_CreateValueString(NULL,
                                                             type ? type : type_to_str(xmlrpc_none, 0),
                                    0));

            /* the rest are parameters */
            xParams = XMLRPC_VectorGetValueWithID(xSigIter, xi_token_params);
            xIter = XMLRPC_VectorRewind(xParams);

            /* iter through params, adding to types array */
            while(xIter) {
               XMLRPC_AddValueToVector(xTypesArray,
                                       XMLRPC_CreateValueString(NULL,
                                                                XMLRPC_VectorGetStringWithID(xIter, xi_token_type),
                                                                0));
               xIter = XMLRPC_VectorNext(xParams);
            }

            /* add types for this signature */
            XMLRPC_AddValueToVector(xResponse, xTypesArray);

            xSigIter = XMLRPC_VectorNext( xSig );
         }
      }
   }

   return xResponse;
}

__attribute__((used)) static XMLRPC_VALUE xi_system_method_help_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   const char* method = XMLRPC_GetValueString(XMLRPC_VectorRewind(XMLRPC_RequestGetData(input)));
   XMLRPC_VALUE xResponse = NULL;

   /* lazy loading of introspection data */
   check_docs_loaded(server, userData);

   if(method) {
      server_method* sm = find_method(server, method);
      if(sm && sm->desc) {
         const char* help = XMLRPC_VectorGetStringWithID(sm->desc, xi_token_purpose);

         /* returns a documentation string, or empty string */
         xResponse = XMLRPC_CreateValueString(NULL, help ? help : xi_token_empty, 0);
      }
   }

   return xResponse;
}

void xi_register_system_methods(XMLRPC_SERVER server) {
   XMLRPC_ServerRegisterMethod(server, xi_token_system_list_methods, xi_system_list_methods_cb);
   XMLRPC_ServerRegisterMethod(server, xi_token_system_method_help, xi_system_method_help_cb);
   XMLRPC_ServerRegisterMethod(server, xi_token_system_method_signature, xi_system_method_signature_cb);
   XMLRPC_ServerRegisterMethod(server, xi_token_system_describe_methods, xi_system_describe_methods_cb);
}

__attribute__((used)) static XMLRPC_VALUE describeValue_worker(const char* type, const char* id, const char* desc, int optional, const char* default_val, XMLRPC_VALUE sub_params) {
   XMLRPC_VALUE xParam = NULL;
   if(id || desc) {
      xParam = XMLRPC_CreateVector(NULL, xmlrpc_vector_struct);
      XMLRPC_VectorAppendString(xParam, xi_token_name, id, 0);
      XMLRPC_VectorAppendString(xParam, xi_token_type, type, 0);
      XMLRPC_VectorAppendString(xParam, xi_token_description, desc, 0);
      if(optional != 2) {
         XMLRPC_VectorAppendInt(xParam, xi_token_optional, optional);
      }
      if(optional == 1 && default_val) {
         XMLRPC_VectorAppendString(xParam, xi_token_default, default_val, 0);
      }
      XMLRPC_AddValueToVector(xParam, sub_params);
   }
   return xParam;
}

XMLRPC_VALUE xml_element_to_method_description(xml_element* el, XMLRPC_ERROR err) {
   XMLRPC_VALUE xReturn = NULL;

   if(el->name) {
      const char* name = NULL;
      const char* type = NULL;
      const char* basetype = NULL;
      const char* desc = NULL;
      const char* def = NULL;
      int optional = 0;
      xml_element_attr* attr_iter = Q_Head(&el->attrs);

      /* grab element attributes up front to save redundant while loops */
      while(attr_iter) {
         if(!strcmp(attr_iter->key, "name")) {
            name = attr_iter->val;
         }
         else if(!strcmp(attr_iter->key, "type")) {
            type = attr_iter->val;
         }
         else if(!strcmp(attr_iter->key, "basetype")) {
            basetype = attr_iter->val;
         }
         else if(!strcmp(attr_iter->key, "desc")) {
            desc = attr_iter->val;
         }
         else if(!strcmp(attr_iter->key, "optional")) {
            if(attr_iter->val && !strcmp(attr_iter->val, "yes")) {
               optional = 1;
            }
         }
         else if(!strcmp(attr_iter->key, "default")) {
            def = attr_iter->val;
         }
         attr_iter = Q_Next(&el->attrs);
      }

      /* value and typeDescription behave about the same */
      if(!strcmp(el->name, "value") || !strcmp(el->name, "typeDescription")) {
         XMLRPC_VALUE xSubList = NULL;
         const char* ptype = !strcmp(el->name, "value") ? type : basetype;
         if(ptype) {
            if(Q_Size(&el->children) &&
               (!strcmp(ptype, "array") || !strcmp(ptype, "struct") || !strcmp(ptype, "mixed"))) {
               xSubList = XMLRPC_CreateVector("member", xmlrpc_vector_array);

               if(xSubList) {
                  xml_element* elem_iter = Q_Head(&el->children);
                  while(elem_iter) {
                     XMLRPC_AddValueToVector(xSubList,
                                             xml_element_to_method_description(elem_iter, err));
                     elem_iter = Q_Next(&el->children);
                  }
               }
            }
            xReturn = describeValue_worker(ptype, name, (desc ? desc : (xSubList ? NULL : el->text.str)), optional, def, xSubList);
         }
      }

      /* these three kids are about equivalent */
      else if(!strcmp(el->name, "params") ||
              !strcmp(el->name, "returns") ||
              !strcmp(el->name, "signature")) {
         if(Q_Size(&el->children)) {
            xml_element* elem_iter = Q_Head(&el->children);
            xReturn = XMLRPC_CreateVector(!strcmp(el->name, "signature") ? NULL : el->name, xmlrpc_vector_struct);


            while(elem_iter) {
               XMLRPC_AddValueToVector(xReturn,
                                       xml_element_to_method_description(elem_iter, err));
               elem_iter = Q_Next(&el->children);
            }
         }
      }


      else if(!strcmp(el->name, "methodDescription")) {
         xml_element* elem_iter = Q_Head(&el->children);
         xReturn = XMLRPC_CreateVector(NULL, xmlrpc_vector_struct);

         XMLRPC_VectorAppendString(xReturn, xi_token_name, name, 0);

         while(elem_iter) {
            XMLRPC_AddValueToVector(xReturn,
                                    xml_element_to_method_description(elem_iter, err));
            elem_iter = Q_Next(&el->children);
         }
      }

      /* items are slightly special */
      else if(!strcmp(el->name, "item")) {
         xReturn = XMLRPC_CreateValueString(name, el->text.str, el->text.len);
      }

      /* sure.  we'll let any ol element with children through */
      else if(Q_Size(&el->children)) {
         xml_element* elem_iter = Q_Head(&el->children);
         xReturn = XMLRPC_CreateVector(el->name, xmlrpc_vector_mixed);

         while(elem_iter) {
            XMLRPC_AddValueToVector(xReturn,
                                    xml_element_to_method_description(elem_iter, err));
            elem_iter = Q_Next(&el->children);
         }
      }

      /* or anything at all really, so long as its got some text.
       * no reason being all snotty about a spec, right?
       */
      else if(el->name && el->text.len) {
         xReturn = XMLRPC_CreateValueString(el->name, el->text.str, el->text.len);
      }
   }

   return xReturn;
}

XMLRPC_VALUE XMLRPC_IntrospectionCreateDescription(const char* xml, XMLRPC_ERROR err) {
   XMLRPC_VALUE xReturn = NULL;
   xml_element* root = xml_elem_parse_buf(xml, 0, 0, err ? &err->xml_elem_error : NULL);

   if(root) {
      xReturn = xml_element_to_method_description(root, err);

      xml_elem_free(root);
   }

   return xReturn;

}

int XMLRPC_ServerAddIntrospectionData(XMLRPC_SERVER server, XMLRPC_VALUE desc) {
   int bSuccess = 0;
   if(server && desc) {
      XMLRPC_VALUE xNewTypes = XMLRPC_VectorGetValueWithID(desc, "typeList");
      XMLRPC_VALUE xNewMethods = XMLRPC_VectorGetValueWithID(desc, "methodList");
      XMLRPC_VALUE xServerTypes = XMLRPC_VectorGetValueWithID(server->xIntrospection, "typeList");

      if(xNewMethods) {
         XMLRPC_VALUE xMethod = XMLRPC_VectorRewind(xNewMethods);

         while(xMethod) {
            const char* name = XMLRPC_VectorGetStringWithID(xMethod, xi_token_name);
            server_method* sm = find_method(server, name);

            if(sm) {
               if(sm->desc) {
                  XMLRPC_CleanupValue(sm->desc);
               }
               sm->desc = XMLRPC_CopyValue(xMethod);
               bSuccess = 1;
            }

            xMethod = XMLRPC_VectorNext(xNewMethods);
         }
      }
      if(xNewTypes) {
         if(!xServerTypes) {
            if(!server->xIntrospection) {
               server->xIntrospection = XMLRPC_CreateVector(NULL, xmlrpc_vector_struct);
            }

            XMLRPC_AddValueToVector(server->xIntrospection, xNewTypes);
            bSuccess = 1;
         }
         else {
            XMLRPC_VALUE xIter = XMLRPC_VectorRewind(xNewTypes);
            while(xIter) {
               /* get rid of old values */
               XMLRPC_VALUE xPrev = find_named_value(xServerTypes, XMLRPC_VectorGetStringWithID(xIter, xi_token_name));
               if(xPrev) {
                  XMLRPC_VectorRemoveValue(xServerTypes, xPrev);
               }
               XMLRPC_AddValueToVector(xServerTypes, xIter);
               bSuccess = 1;
               xIter = XMLRPC_VectorNext(xNewTypes);
            }
         }
      }
   }
   return bSuccess;
}

int XMLRPC_ServerRegisterIntrospectionCallback(XMLRPC_SERVER server, XMLRPC_IntrospectionCallback cb) {
   int bSuccess = 0;
   if(server && cb) {

      doc_method* dm = ecalloc(1, sizeof(doc_method));

      if(dm) {
         dm->method = cb;
         dm->b_called = 0;

         if(Q_PushTail(&server->docslist, dm)) {
            bSuccess = 1;
         }
         else {
            my_free(dm);
         }
      }
   }
   return bSuccess;
}

