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
typedef  int s32 ;
typedef  int /*<<< orphan*/  promlib_buf ;
typedef  int phandle ;
typedef  int /*<<< orphan*/  namebuf ;

/* Variables and functions */
 int /*<<< orphan*/  p1275_cmd_direct (unsigned long*) ; 
 scalar_t__ prom_getprop_name ; 
 scalar_t__ prom_nextprop_name ; 
 char* prom_peer_name ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 

__attribute__((used)) static phandle prom_node_to_node(const char *type, phandle node)
{
	unsigned long args[5];

	args[0] = (unsigned long) type;
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (phandle) args[4];
}

inline phandle __prom_getchild(phandle node)
{
	return prom_node_to_node("child", node);
}

phandle prom_getchild(phandle node)
{
	phandle cnode;

	if ((s32)node == -1)
		return 0;
	cnode = __prom_getchild(node);
	if ((s32)cnode == -1)
		return 0;
	return cnode;
}

inline phandle prom_getparent(phandle node)
{
	phandle cnode;

	if ((s32)node == -1)
		return 0;
	cnode = prom_node_to_node("parent", node);
	if ((s32)cnode == -1)
		return 0;
	return cnode;
}

inline phandle __prom_getsibling(phandle node)
{
	return prom_node_to_node(prom_peer_name, node);
}

phandle prom_getsibling(phandle node)
{
	phandle sibnode;

	if ((s32)node == -1)
		return 0;
	sibnode = __prom_getsibling(node);
	if ((s32)sibnode == -1)
		return 0;

	return sibnode;
}

int prom_getproplen(phandle node, const char *prop)
{
	unsigned long args[6];

	if (!node || !prop)
		return -1;

	args[0] = (unsigned long) "getproplen";
	args[1] = 2;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) prop;
	args[5] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[5];
}

int prom_getproperty(phandle node, const char *prop,
		     char *buffer, int bufsize)
{
	unsigned long args[8];
	int plen;

	plen = prom_getproplen(node, prop);
	if ((plen > bufsize) || (plen == 0) || (plen == -1))
		return -1;

	args[0] = (unsigned long) prom_getprop_name;
	args[1] = 4;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) prop;
	args[5] = (unsigned long) buffer;
	args[6] = bufsize;
	args[7] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[7];
}

int prom_getint(phandle node, const char *prop)
{
	int intprop;

	if (prom_getproperty(node, prop, (char *) &intprop, sizeof(int)) != -1)
		return intprop;

	return -1;
}

int prom_getintdefault(phandle node, const char *property, int deflt)
{
	int retval;

	retval = prom_getint(node, property);
	if (retval == -1)
		return deflt;

	return retval;
}

int prom_getbool(phandle node, const char *prop)
{
	int retval;

	retval = prom_getproplen(node, prop);
	if (retval == -1)
		return 0;
	return 1;
}

void prom_getstring(phandle node, const char *prop, char *user_buf,
		int ubuf_size)
{
	int len;

	len = prom_getproperty(node, prop, user_buf, ubuf_size);
	if (len != -1)
		return;
	user_buf[0] = 0;
}

int prom_nodematch(phandle node, const char *name)
{
	char namebuf[128];
	prom_getproperty(node, "name", namebuf, sizeof(namebuf));
	if (strcmp(namebuf, name) == 0)
		return 1;
	return 0;
}

phandle prom_searchsiblings(phandle node_start, const char *nodename)
{
	phandle thisnode;
	int error;
	char promlib_buf[128];

	for(thisnode = node_start; thisnode;
	    thisnode=prom_getsibling(thisnode)) {
		error = prom_getproperty(thisnode, "name", promlib_buf,
					 sizeof(promlib_buf));
		/* Should this ever happen? */
		if(error == -1) continue;
		if(strcmp(nodename, promlib_buf)==0) return thisnode;
	}

	return 0;
}

char *prom_firstprop(phandle node, char *buffer)
{
	unsigned long args[7];

	*buffer = 0;
	if ((s32)node == -1)
		return buffer;

	args[0] = (unsigned long) prom_nextprop_name;
	args[1] = 3;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = 0;
	args[5] = (unsigned long) buffer;
	args[6] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return buffer;
}

char *prom_nextprop(phandle node, const char *oprop, char *buffer)
{
	unsigned long args[7];
	char buf[32];

	if ((s32)node == -1) {
		*buffer = 0;
		return buffer;
	}
	if (oprop == buffer) {
		strcpy (buf, oprop);
		oprop = buf;
	}

	args[0] = (unsigned long) prom_nextprop_name;
	args[1] = 3;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) oprop;
	args[5] = (unsigned long) buffer;
	args[6] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return buffer;
}

phandle prom_finddevice(const char *name)
{
	unsigned long args[5];

	if (!name)
		return 0;
	args[0] = (unsigned long) "finddevice";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) name;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[4];
}

int prom_node_has_property(phandle node, const char *prop)
{
	char buf [32];
        
	*buf = 0;
	do {
		prom_nextprop(node, buf, buf);
		if (!strcmp(buf, prop))
			return 1;
	} while (*buf);
	return 0;
}

int
prom_setprop(phandle node, const char *pname, char *value, int size)
{
	unsigned long args[8];

	if (size == 0)
		return 0;
	if ((pname == 0) || (value == 0))
		return 0;
	
#ifdef CONFIG_SUN_LDOMS
	if (ldom_domaining_enabled) {
		ldom_set_var(pname, value);
		return 0;
	}
#endif
	args[0] = (unsigned long) "setprop";
	args[1] = 4;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) pname;
	args[5] = (unsigned long) value;
	args[6] = size;
	args[7] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[7];
}

inline phandle prom_inst2pkg(int inst)
{
	unsigned long args[5];
	phandle node;
	
	args[0] = (unsigned long) "instance-to-package";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned int) inst;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	node = (int) args[4];
	if ((s32)node == -1)
		return 0;
	return node;
}

int prom_ihandle2path(int handle, char *buffer, int bufsize)
{
	unsigned long args[7];

	args[0] = (unsigned long) "instance-to-path";
	args[1] = 3;
	args[2] = 1;
	args[3] = (unsigned int) handle;
	args[4] = (unsigned long) buffer;
	args[5] = bufsize;
	args[6] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[6];
}

