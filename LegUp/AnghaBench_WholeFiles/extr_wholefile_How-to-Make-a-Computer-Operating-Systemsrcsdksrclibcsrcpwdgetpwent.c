#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct passwd {int /*<<< orphan*/  pw_shell; int /*<<< orphan*/  pw_dir; int /*<<< orphan*/  pw_gecos; int /*<<< orphan*/  pw_gid; int /*<<< orphan*/  pw_uid; int /*<<< orphan*/  pw_passwd; int /*<<< orphan*/  pw_name; } ;
struct TYPE_5__ {int /*<<< orphan*/  shell; int /*<<< orphan*/  dir; int /*<<< orphan*/  gecos; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; int /*<<< orphan*/  password; int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ passwd_myos ;

/* Variables and functions */
 struct passwd __tmp_passwd ; 
 int _passwd_db_position ; 
 TYPE_1__ myos_pass ; 
 int syscall2 (int,int,int) ; 

passwd_myos* myos_user_getN(const char* name){
	int ret=syscall2(68,(uint32_t)name,(uint32_t)&myos_pass);
	if (ret!=0)
		return &myos_pass;
	else
		return NULL;
}

passwd_myos* myos_user_getID(int id){
	int ret=syscall2(69,id,(uint32_t)&myos_pass);
	if (ret!=0)
		return &myos_pass;
	else
		return NULL;
}

void build_tmp_passwd(){
	__tmp_passwd.pw_name=myos_pass.name;
	__tmp_passwd.pw_passwd=myos_pass.password;
	__tmp_passwd.pw_uid=myos_pass.uid;
	__tmp_passwd.pw_gid=myos_pass.gid;
	__tmp_passwd.pw_gecos=myos_pass.gecos;
	__tmp_passwd.pw_dir=myos_pass.dir;
	__tmp_passwd.pw_shell=myos_pass.shell;
}

struct passwd* getpwent( void ) {

	passwd_myos* pass=myos_user_getID(_passwd_db_position);
	if (pass==NULL)
		return NULL;
	
	build_tmp_passwd();
	_passwd_db_position++;
	return &__tmp_passwd;
}

