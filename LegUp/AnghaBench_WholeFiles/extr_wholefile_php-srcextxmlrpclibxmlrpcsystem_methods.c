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
typedef  scalar_t__ XMLRPC_VALUE ;
typedef  int /*<<< orphan*/  XMLRPC_SERVER ;
typedef  scalar_t__ XMLRPC_REQUEST ;

/* Variables and functions */
 int /*<<< orphan*/  XMLRPC_AddValueToVector (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XMLRPC_AddValuesToVector (scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_CleanupValue (scalar_t__) ; 
 scalar_t__ XMLRPC_CreateVector (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ XMLRPC_IntrospectionCreateDescription (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XMLRPC_RequestFree (scalar_t__,int) ; 
 scalar_t__ XMLRPC_RequestGetData (scalar_t__) ; 
 scalar_t__ XMLRPC_RequestNew () ; 
 int /*<<< orphan*/  XMLRPC_RequestSetData (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetMethodName (scalar_t__,char const*) ; 
 int /*<<< orphan*/  XMLRPC_RequestSetRequestType (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XMLRPC_ServerAddIntrospectionData (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ XMLRPC_ServerCallMethod (int /*<<< orphan*/ ,scalar_t__,void*) ; 
 int /*<<< orphan*/  XMLRPC_ServerRegisterIntrospectionCallback (int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,void*)) ; 
 int /*<<< orphan*/  XMLRPC_ServerRegisterMethod (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__ (*) (int /*<<< orphan*/ ,scalar_t__,void*)) ; 
 int /*<<< orphan*/  XMLRPC_VectorAppendInt (scalar_t__,char*,int) ; 
 int /*<<< orphan*/  XMLRPC_VectorAppendString (scalar_t__,char*,char*,int /*<<< orphan*/ ) ; 
 char* XMLRPC_VectorGetStringWithID (scalar_t__,char*) ; 
 scalar_t__ XMLRPC_VectorGetValueWithID (scalar_t__,char*) ; 
 scalar_t__ XMLRPC_VectorNext (scalar_t__) ; 
 scalar_t__ XMLRPC_VectorRewind (scalar_t__) ; 
 int /*<<< orphan*/  xi_register_system_methods (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmlrpc_request_call ; 
 int /*<<< orphan*/  xmlrpc_vector_array ; 
 int /*<<< orphan*/  xmlrpc_vector_struct ; 
 int /*<<< orphan*/  xsm_introspection_xml ; 
 scalar_t__ xsm_system_get_capabilities_cb (int /*<<< orphan*/ ,scalar_t__,void*) ; 
 scalar_t__ xsm_system_multicall_cb (int /*<<< orphan*/ ,scalar_t__,void*) ; 
 int /*<<< orphan*/  xsm_token_system_get_capabilities ; 
 int /*<<< orphan*/  xsm_token_system_multicall ; 

__attribute__((used)) static void xsm_lazy_doc_methods_cb(XMLRPC_SERVER server, void* userData) {
   XMLRPC_VALUE xDesc = XMLRPC_IntrospectionCreateDescription(xsm_introspection_xml, NULL);
   XMLRPC_ServerAddIntrospectionData(server, xDesc);
   XMLRPC_CleanupValue(xDesc);
}

void xsm_register(XMLRPC_SERVER server) {
   xi_register_system_methods(server);

   XMLRPC_ServerRegisterMethod(server, xsm_token_system_multicall, xsm_system_multicall_cb);
   XMLRPC_ServerRegisterMethod(server, xsm_token_system_get_capabilities, xsm_system_get_capabilities_cb);

   /* callback for documentation generation should it be requested */
   XMLRPC_ServerRegisterIntrospectionCallback(server, xsm_lazy_doc_methods_cb);
}

XMLRPC_VALUE xsm_system_multicall_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   XMLRPC_VALUE xArray = XMLRPC_VectorRewind(XMLRPC_RequestGetData(input));
   XMLRPC_VALUE xReturn = XMLRPC_CreateVector(0, xmlrpc_vector_array);

   if (xArray) {
      XMLRPC_VALUE xMethodIter = XMLRPC_VectorRewind(xArray);

      while (xMethodIter) {
         XMLRPC_REQUEST request = XMLRPC_RequestNew();
         if(request) {
            const char* methodName = XMLRPC_VectorGetStringWithID(xMethodIter, "methodName");
            XMLRPC_VALUE params = XMLRPC_VectorGetValueWithID(xMethodIter, "params");

            if(methodName && params) {
               XMLRPC_VALUE xRandomArray = XMLRPC_CreateVector(0, xmlrpc_vector_array);
               XMLRPC_RequestSetMethodName(request, methodName);
               XMLRPC_RequestSetData(request, params);
               XMLRPC_RequestSetRequestType(request, xmlrpc_request_call);

               XMLRPC_AddValueToVector(xRandomArray,
                                       XMLRPC_ServerCallMethod(server, request, userData));

               XMLRPC_AddValueToVector(xReturn, xRandomArray);
            }
            XMLRPC_RequestFree(request, 1);
         }
         xMethodIter = XMLRPC_VectorNext(xArray);
      }
   }
   return xReturn;
}

XMLRPC_VALUE xsm_system_get_capabilities_cb(XMLRPC_SERVER server, XMLRPC_REQUEST input, void* userData) {
   XMLRPC_VALUE xReturn = XMLRPC_CreateVector(0, xmlrpc_vector_struct);
   XMLRPC_VALUE xFaults = XMLRPC_CreateVector("faults_interop", xmlrpc_vector_struct);
   XMLRPC_VALUE xIntro = XMLRPC_CreateVector("introspection", xmlrpc_vector_struct);

   /* support for fault spec */
   XMLRPC_VectorAppendString(xFaults, "specURL", "http://xmlrpc-epi.sourceforge.net/specs/rfc.fault_codes.php", 0);
   XMLRPC_VectorAppendInt(xFaults, "specVersion", 20010516);

   /* support for introspection spec */
   XMLRPC_VectorAppendString(xIntro, "specURL", "http://xmlrpc-epi.sourceforge.net/specs/rfc.introspection.php", 0);
   XMLRPC_VectorAppendInt(xIntro, "specVersion", 20010516);

   XMLRPC_AddValuesToVector(xReturn,
                            xFaults,
                            xIntro,
                            NULL);

   return xReturn;

}

