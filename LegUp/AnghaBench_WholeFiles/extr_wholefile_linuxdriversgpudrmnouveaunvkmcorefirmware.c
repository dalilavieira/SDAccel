#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct nvkm_device {int /*<<< orphan*/  dev; TYPE_1__* chip; } ;
struct firmware {int dummy; } ;
typedef  int /*<<< orphan*/  f ;
typedef  int /*<<< orphan*/  cname ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char const*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,int) ; 
 char tolower (char) ; 

int
nvkm_firmware_get(struct nvkm_device *device, const char *fwname,
		  const struct firmware **fw)
{
	char f[64];
	char cname[16];
	int i;

	/* Convert device name to lowercase */
	strncpy(cname, device->chip->name, sizeof(cname));
	cname[sizeof(cname) - 1] = '\0';
	i = strlen(cname);
	while (i) {
		--i;
		cname[i] = tolower(cname[i]);
	}

	snprintf(f, sizeof(f), "nvidia/%s/%s.bin", cname, fwname);
	return request_firmware(fw, f, device->dev);
}

void
nvkm_firmware_put(const struct firmware *fw)
{
	release_firmware(fw);
}

