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
struct OperationConfig {int /*<<< orphan*/  global; } ;
typedef  int ParameterError ;
typedef  size_t HttpReq ;

/* Variables and functions */
 size_t HTTPREQ_UNSPEC ; 
#define  PARAM_BAD_NUMERIC 139 
#define  PARAM_BAD_USE 138 
#define  PARAM_GOT_EXTRA_PARAMETER 137 
#define  PARAM_LIBCURL_DOESNT_SUPPORT 136 
#define  PARAM_LIBCURL_UNSUPPORTED_PROTOCOL 135 
#define  PARAM_NEGATIVE_NUMERIC 134 
#define  PARAM_NO_MEM 133 
#define  PARAM_NO_PREFIX 132 
#define  PARAM_NUMBER_TOO_LARGE 131 
#define  PARAM_OPTION_AMBIGUOUS 130 
#define  PARAM_OPTION_UNKNOWN 129 
#define  PARAM_REQUIRES_PARAMETER 128 
 scalar_t__ curl_strequal (char*,char const*) ; 
 int /*<<< orphan*/  notef (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  warnf (int /*<<< orphan*/ ,char*,...) ; 

const char *param2text(int res)
{
  ParameterError error = (ParameterError)res;
  switch(error) {
  case PARAM_GOT_EXTRA_PARAMETER:
    return "had unsupported trailing garbage";
  case PARAM_OPTION_UNKNOWN:
    return "is unknown";
  case PARAM_OPTION_AMBIGUOUS:
    return "is ambiguous";
  case PARAM_REQUIRES_PARAMETER:
    return "requires parameter";
  case PARAM_BAD_USE:
    return "is badly used here";
  case PARAM_BAD_NUMERIC:
    return "expected a proper numerical parameter";
  case PARAM_NEGATIVE_NUMERIC:
    return "expected a positive numerical parameter";
  case PARAM_LIBCURL_DOESNT_SUPPORT:
    return "the installed libcurl version doesn't support this";
  case PARAM_LIBCURL_UNSUPPORTED_PROTOCOL:
    return "a specified protocol is unsupported by libcurl";
  case PARAM_NO_MEM:
    return "out of memory";
  case PARAM_NO_PREFIX:
    return "the given option can't be reversed with a --no- prefix";
  case PARAM_NUMBER_TOO_LARGE:
    return "too large number";
  default:
    return "unknown error";
  }
}

int SetHTTPrequest(struct OperationConfig *config, HttpReq req, HttpReq *store)
{
  /* this mirrors the HttpReq enum in tool_sdecls.h */
  const char *reqname[]= {
    "", /* unspec */
    "GET (-G, --get)",
    "HEAD (-I, --head)",
    "multipart formpost (-F, --form)",
    "POST (-d, --data)"
  };

  if((*store == HTTPREQ_UNSPEC) ||
     (*store == req)) {
    *store = req;
    return 0;
  }
  warnf(config->global, "You can only select one HTTP request method! "
        "You asked for both %s and %s.\n",
        reqname[req], reqname[*store]);

  return 1;
}

void customrequest_helper(struct OperationConfig *config, HttpReq req,
                          char *method)
{
  /* this mirrors the HttpReq enum in tool_sdecls.h */
  const char *dflt[]= {
    "GET",
    "GET",
    "HEAD",
    "POST",
    "POST"
  };

  if(!method)
    ;
  else if(curl_strequal(method, dflt[req])) {
    notef(config->global, "Unnecessary use of -X or --request, %s is already "
          "inferred.\n", dflt[req]);
  }
  else if(curl_strequal(method, "head")) {
    warnf(config->global,
          "Setting custom HTTP method to HEAD with -X/--request may not work "
          "the way you want. Consider using -I/--head instead.\n");
  }
}

