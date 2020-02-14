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

/* Variables and functions */
#define  CEPH_CAP_OP_DROP 203 
#define  CEPH_CAP_OP_EXPORT 202 
#define  CEPH_CAP_OP_FLUSH 201 
#define  CEPH_CAP_OP_FLUSHSNAP 200 
#define  CEPH_CAP_OP_FLUSHSNAP_ACK 199 
#define  CEPH_CAP_OP_FLUSH_ACK 198 
#define  CEPH_CAP_OP_GRANT 197 
#define  CEPH_CAP_OP_IMPORT 196 
#define  CEPH_CAP_OP_RELEASE 195 
#define  CEPH_CAP_OP_RENEW 194 
#define  CEPH_CAP_OP_REVOKE 193 
#define  CEPH_CAP_OP_TRUNC 192 
#define  CEPH_CAP_OP_UPDATE 191 
#define  CEPH_MDS_LEASE_RELEASE 190 
#define  CEPH_MDS_LEASE_RENEW 189 
#define  CEPH_MDS_LEASE_REVOKE 188 
#define  CEPH_MDS_LEASE_REVOKE_ACK 187 
#define  CEPH_MDS_OP_CREATE 186 
#define  CEPH_MDS_OP_GETATTR 185 
#define  CEPH_MDS_OP_GETFILELOCK 184 
#define  CEPH_MDS_OP_LINK 183 
#define  CEPH_MDS_OP_LOOKUP 182 
#define  CEPH_MDS_OP_LOOKUPHASH 181 
#define  CEPH_MDS_OP_LOOKUPINO 180 
#define  CEPH_MDS_OP_LOOKUPNAME 179 
#define  CEPH_MDS_OP_LOOKUPPARENT 178 
#define  CEPH_MDS_OP_LOOKUPSNAP 177 
#define  CEPH_MDS_OP_LSSNAP 176 
#define  CEPH_MDS_OP_MKDIR 175 
#define  CEPH_MDS_OP_MKNOD 174 
#define  CEPH_MDS_OP_MKSNAP 173 
#define  CEPH_MDS_OP_OPEN 172 
#define  CEPH_MDS_OP_READDIR 171 
#define  CEPH_MDS_OP_RENAME 170 
#define  CEPH_MDS_OP_RENAMESNAP 169 
#define  CEPH_MDS_OP_RMDIR 168 
#define  CEPH_MDS_OP_RMSNAP 167 
#define  CEPH_MDS_OP_RMXATTR 166 
#define  CEPH_MDS_OP_SETATTR 165 
#define  CEPH_MDS_OP_SETDIRLAYOUT 164 
#define  CEPH_MDS_OP_SETFILELOCK 163 
#define  CEPH_MDS_OP_SETLAYOUT 162 
#define  CEPH_MDS_OP_SETXATTR 161 
#define  CEPH_MDS_OP_SYMLINK 160 
#define  CEPH_MDS_OP_UNLINK 159 
#define  CEPH_MDS_STATE_ACTIVE 158 
#define  CEPH_MDS_STATE_BOOT 157 
#define  CEPH_MDS_STATE_CLIENTREPLAY 156 
#define  CEPH_MDS_STATE_CREATING 155 
#define  CEPH_MDS_STATE_DNE 154 
#define  CEPH_MDS_STATE_RECONNECT 153 
#define  CEPH_MDS_STATE_REJOIN 152 
#define  CEPH_MDS_STATE_REPLAY 151 
#define  CEPH_MDS_STATE_REPLAYONCE 150 
#define  CEPH_MDS_STATE_RESOLVE 149 
#define  CEPH_MDS_STATE_STANDBY 148 
#define  CEPH_MDS_STATE_STANDBY_REPLAY 147 
#define  CEPH_MDS_STATE_STARTING 146 
#define  CEPH_MDS_STATE_STOPPED 145 
#define  CEPH_MDS_STATE_STOPPING 144 
#define  CEPH_SESSION_CLOSE 143 
#define  CEPH_SESSION_FLUSHMSG 142 
#define  CEPH_SESSION_FLUSHMSG_ACK 141 
#define  CEPH_SESSION_FORCE_RO 140 
#define  CEPH_SESSION_OPEN 139 
#define  CEPH_SESSION_RECALL_STATE 138 
#define  CEPH_SESSION_REJECT 137 
#define  CEPH_SESSION_RENEWCAPS 136 
#define  CEPH_SESSION_REQUEST_CLOSE 135 
#define  CEPH_SESSION_REQUEST_OPEN 134 
#define  CEPH_SESSION_REQUEST_RENEWCAPS 133 
#define  CEPH_SESSION_STALE 132 
#define  CEPH_SNAP_OP_CREATE 131 
#define  CEPH_SNAP_OP_DESTROY 130 
#define  CEPH_SNAP_OP_SPLIT 129 
#define  CEPH_SNAP_OP_UPDATE 128 

const char *ceph_mds_state_name(int s)
{
	switch (s) {
		/* down and out */
	case CEPH_MDS_STATE_DNE:        return "down:dne";
	case CEPH_MDS_STATE_STOPPED:    return "down:stopped";
		/* up and out */
	case CEPH_MDS_STATE_BOOT:       return "up:boot";
	case CEPH_MDS_STATE_STANDBY:    return "up:standby";
	case CEPH_MDS_STATE_STANDBY_REPLAY:    return "up:standby-replay";
	case CEPH_MDS_STATE_REPLAYONCE: return "up:oneshot-replay";
	case CEPH_MDS_STATE_CREATING:   return "up:creating";
	case CEPH_MDS_STATE_STARTING:   return "up:starting";
		/* up and in */
	case CEPH_MDS_STATE_REPLAY:     return "up:replay";
	case CEPH_MDS_STATE_RESOLVE:    return "up:resolve";
	case CEPH_MDS_STATE_RECONNECT:  return "up:reconnect";
	case CEPH_MDS_STATE_REJOIN:     return "up:rejoin";
	case CEPH_MDS_STATE_CLIENTREPLAY: return "up:clientreplay";
	case CEPH_MDS_STATE_ACTIVE:     return "up:active";
	case CEPH_MDS_STATE_STOPPING:   return "up:stopping";
	}
	return "???";
}

const char *ceph_session_op_name(int op)
{
	switch (op) {
	case CEPH_SESSION_REQUEST_OPEN: return "request_open";
	case CEPH_SESSION_OPEN: return "open";
	case CEPH_SESSION_REQUEST_CLOSE: return "request_close";
	case CEPH_SESSION_CLOSE: return "close";
	case CEPH_SESSION_REQUEST_RENEWCAPS: return "request_renewcaps";
	case CEPH_SESSION_RENEWCAPS: return "renewcaps";
	case CEPH_SESSION_STALE: return "stale";
	case CEPH_SESSION_RECALL_STATE: return "recall_state";
	case CEPH_SESSION_FLUSHMSG: return "flushmsg";
	case CEPH_SESSION_FLUSHMSG_ACK: return "flushmsg_ack";
	case CEPH_SESSION_FORCE_RO: return "force_ro";
	case CEPH_SESSION_REJECT: return "reject";
	}
	return "???";
}

const char *ceph_mds_op_name(int op)
{
	switch (op) {
	case CEPH_MDS_OP_LOOKUP:  return "lookup";
	case CEPH_MDS_OP_LOOKUPHASH:  return "lookuphash";
	case CEPH_MDS_OP_LOOKUPPARENT:  return "lookupparent";
	case CEPH_MDS_OP_LOOKUPINO:  return "lookupino";
	case CEPH_MDS_OP_LOOKUPNAME:  return "lookupname";
	case CEPH_MDS_OP_GETATTR:  return "getattr";
	case CEPH_MDS_OP_SETXATTR: return "setxattr";
	case CEPH_MDS_OP_SETATTR: return "setattr";
	case CEPH_MDS_OP_RMXATTR: return "rmxattr";
	case CEPH_MDS_OP_SETLAYOUT: return "setlayou";
	case CEPH_MDS_OP_SETDIRLAYOUT: return "setdirlayout";
	case CEPH_MDS_OP_READDIR: return "readdir";
	case CEPH_MDS_OP_MKNOD: return "mknod";
	case CEPH_MDS_OP_LINK: return "link";
	case CEPH_MDS_OP_UNLINK: return "unlink";
	case CEPH_MDS_OP_RENAME: return "rename";
	case CEPH_MDS_OP_MKDIR: return "mkdir";
	case CEPH_MDS_OP_RMDIR: return "rmdir";
	case CEPH_MDS_OP_SYMLINK: return "symlink";
	case CEPH_MDS_OP_CREATE: return "create";
	case CEPH_MDS_OP_OPEN: return "open";
	case CEPH_MDS_OP_LOOKUPSNAP: return "lookupsnap";
	case CEPH_MDS_OP_LSSNAP: return "lssnap";
	case CEPH_MDS_OP_MKSNAP: return "mksnap";
	case CEPH_MDS_OP_RMSNAP: return "rmsnap";
	case CEPH_MDS_OP_RENAMESNAP: return "renamesnap";
	case CEPH_MDS_OP_SETFILELOCK: return "setfilelock";
	case CEPH_MDS_OP_GETFILELOCK: return "getfilelock";
	}
	return "???";
}

const char *ceph_cap_op_name(int op)
{
	switch (op) {
	case CEPH_CAP_OP_GRANT: return "grant";
	case CEPH_CAP_OP_REVOKE: return "revoke";
	case CEPH_CAP_OP_TRUNC: return "trunc";
	case CEPH_CAP_OP_EXPORT: return "export";
	case CEPH_CAP_OP_IMPORT: return "import";
	case CEPH_CAP_OP_UPDATE: return "update";
	case CEPH_CAP_OP_DROP: return "drop";
	case CEPH_CAP_OP_FLUSH: return "flush";
	case CEPH_CAP_OP_FLUSH_ACK: return "flush_ack";
	case CEPH_CAP_OP_FLUSHSNAP: return "flushsnap";
	case CEPH_CAP_OP_FLUSHSNAP_ACK: return "flushsnap_ack";
	case CEPH_CAP_OP_RELEASE: return "release";
	case CEPH_CAP_OP_RENEW: return "renew";
	}
	return "???";
}

const char *ceph_lease_op_name(int o)
{
	switch (o) {
	case CEPH_MDS_LEASE_REVOKE: return "revoke";
	case CEPH_MDS_LEASE_RELEASE: return "release";
	case CEPH_MDS_LEASE_RENEW: return "renew";
	case CEPH_MDS_LEASE_REVOKE_ACK: return "revoke_ack";
	}
	return "???";
}

const char *ceph_snap_op_name(int o)
{
	switch (o) {
	case CEPH_SNAP_OP_UPDATE: return "update";
	case CEPH_SNAP_OP_CREATE: return "create";
	case CEPH_SNAP_OP_DESTROY: return "destroy";
	case CEPH_SNAP_OP_SPLIT: return "split";
	}
	return "???";
}

