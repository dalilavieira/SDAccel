#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct in_addr {int s_addr; } ;
struct sockaddr_in {struct in_addr sin_addr; int /*<<< orphan*/  sin_zero; void* sin_port; void* sin_family; } ;
struct sockaddr {int dummy; } ;
struct hostent {scalar_t__ h_addr; } ;
typedef  int /*<<< orphan*/  enable ;
struct TYPE_16__ {int ip; int siaddr; int router; int mask; int lease; } ;
struct TYPE_15__ {int* options; int yiaddr; int siaddr; char* sname; int ciaddr; int /*<<< orphan*/  xid; void* op; int /*<<< orphan*/  chaddr; } ;
struct TYPE_14__ {int type; int r_ip; int r_mask; int r_router; int r_lease; char* hostname; } ;
typedef  TYPE_1__ DHCPOPTIONS ;
typedef  TYPE_2__ DHCPMESSAGE ;
typedef  TYPE_3__ DHCPLEASE ;

/* Variables and functions */
 void* AF_INET ; 
#define  ALLSUBLOCAL 205 
#define  ARPCACHE 204 
#define  BOOTFILE 203 
#define  BOOTFILESIZE 202 
 void* BOOTREPLY ; 
#define  BROADCAST 201 
#define  CLIENT 200 
#define  COOKIESERVER 199 
#define  DEFAULTTTL 198 
 void* DHCPACK ; 
#define  DHCPDISCOVER 197 
 int DHCPNAK ; 
 void* DHCPOFFER ; 
#define  DHCPREQUEST 196 
#define  DNS 195 
#define  DOMAINNAME 194 
#define  END 193 
#define  ETHENCAPSUL 192 
#define  EXTENSIONPATH 191 
#define  FINGERSERVER 190 
#define  HOSTNAME 189 
#define  HTTPSERVER 188 
#define  IMPSERVER 187 
#define  IMTU 186 
#define  IP 185 
#define  IPFORWARD 184 
#define  IRCSERVER 183 
#define  LEASE 182 
#define  LOGSERVER 181 
#define  LPRSERVER 180 
#define  MASK 179 
#define  MASKSUPPLIER 178 
#define  MAXIMUMDATAG 177 
#define  MAXIMUMDHCP 176 
#define  MERITDUMPFILE 175 
#define  MESSAGE 174 
#define  MESSAGETYPE 173 
#define  MOBILEIP 172 
#define  NBTCPIPDDS 171 
#define  NBTCPIPNS 170 
#define  NBTCPIPNT 169 
#define  NBTCPIPSC 168 
#define  NISDOMAIN 167 
#define  NISPLUSDOMAIN 166 
#define  NISPLUSSERVER 165 
#define  NISSERVER 164 
#define  NNTPSERVER 163 
#define  NONLOCAL 162 
#define  NS 161 
#define  NTPSERVER 160 
#define  OVERLOAD 159 
#define  PAD 158 
#define  PATHMTUATO 157 
#define  PATHMTUPTO 156 
#define  PMASKDISCOVERY 155 
#define  POLICYFILTER 154 
#define  POP3SERVER 153 
#define  PREQUEST 152 
#define  PROUTERDISCOVE 151 
#define  REBINDING 150 
#define  RENEWALTIME 149 
#define  RESLOCSERVER 148 
#define  ROOTPATH 147 
#define  ROUTER 146 
#define  RSOLICIADDRESS 145 
#define  SERVER 144 
#define  SMTPSERVER 143 
 int /*<<< orphan*/  SOCK_DGRAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_BROADCAST ; 
#define  STATICROUTE 142 
#define  STREETTALKDA 141 
#define  STREETTALKSE 140 
#define  SWAPSERVER 139 
#define  TCPDEFTTL 138 
#define  TCPKAG 137 
#define  TCPKAI 136 
#define  TENCAPSULATION 135 
#define  TFTPSERVER 134 
#define  TIMESERVER 133 
#define  TOFFSET 132 
#define  VENDORCLASS 131 
#define  VENDORSP 130 
 char* VERSION ; 
#define  XWINDISPLAY 129 
#define  XWINFONTSERVER 128 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  confirm_lease (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  display_dhcp_packet (TYPE_2__*,TYPE_1__*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  find_lease (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 struct hostent* gethostbyname (char*) ; 
 void* htons (int) ; 
 char* inet_ntoa (struct in_addr) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,char,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,int,char*) ; 
 int sendto (int,TYPE_2__*,int,int /*<<< orphan*/ ,struct sockaddr*,int) ; 
 int setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int socket (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,int,int) ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  strncpy (char*,int*,int) ; 
 int write_packet (TYPE_2__*,char*) ; 

int parse_dhcp_options( DHCPMESSAGE *dhcpm, DHCPOPTIONS *dhcpo )
{
  int pointer, opointer;
  int olength;

  pointer = 0;

  fprintf( stdout, "parse_dhcp_options [begin]!\n");

  /* Options Initialization */
  /* No message type */
  dhcpo->type = 0;
  /* No ip address, 0.0.0.0 */
  dhcpo->r_ip = 0;
  /* No mask address, 0.0.0.0 */
  dhcpo->r_mask = 0;
  /* No router, 0.0.0.0 */
  dhcpo->r_router = 0;
  /* No lease 0 */
  dhcpo->r_lease = 0;
  /* No name '\n' */
  dhcpo->hostname = NULL;

  while( pointer< 312 )
    {
      if(( dhcpm->options[0] != 99 ) && (dhcpm->options[1]!=130) && (dhcpm->options[2]!=83) && (dhcpm->options[3]!= 99))
	{
	  fprintf( stdout, "No magic cookie! Aborting! \n" );
	  return -1;
	}
      switch( dhcpm->options[pointer] ){
      case PAD:
	pointer++;
	break;
      case MESSAGETYPE:
	/* Try to figure out the kind of message and start the configuring process */
	pointer += 2;
	dhcpo->type = dhcpm->options[pointer++];
	break;
      case PREQUEST:
	/* Take note of the requested parameters */
	opointer = pointer + 2;
	olength = pointer + dhcpm->options[pointer + 1];
	while( opointer < olength )
	  {
	    switch( dhcpm->options[opointer] ){
	    case IP:
	      /* Take note of the requested ip */
	      opointer += 2;
	      dhcpo->r_ip += dhcpm->options[opointer++];
	      dhcpo->r_ip = dhcpo->r_ip << 8;
	      dhcpo->r_ip += dhcpm->options[opointer++];
	      dhcpo->r_ip = dhcpo->r_ip << 8;
	      dhcpo->r_ip += dhcpm->options[opointer++];
	      dhcpo->r_ip = dhcpo->r_ip << 8;
	      dhcpo->r_ip += dhcpm->options[opointer++];
	      break;
	    case MASK:
	      /* Take note of the requested mask */
	      opointer += 2;
	      dhcpo->r_mask += dhcpm->options[opointer++];
	      dhcpo->r_mask = dhcpo->r_ip << 8;
	      dhcpo->r_mask += dhcpm->options[opointer++];
	      dhcpo->r_mask = dhcpo->r_ip << 8;
	      dhcpo->r_mask += dhcpm->options[opointer++];
	      dhcpo->r_mask = dhcpo->r_ip << 8;
	      dhcpo->r_mask += dhcpm->options[opointer++];
	      break;
	    case ROUTER:
	      /* Take note of the requested router */
	      opointer += 2;
	      dhcpo->r_router += dhcpm->options[opointer++];
	      dhcpo->r_router = dhcpo->r_ip << 8;
	      dhcpo->r_router += dhcpm->options[opointer++];
	      dhcpo->r_router = dhcpo->r_ip << 8;
	      dhcpo->r_router += dhcpm->options[opointer++];
	      dhcpo->r_router = dhcpo->r_ip << 8;
	      dhcpo->r_router += dhcpm->options[opointer++];
	      break;
	    case LEASE:
	      opointer += 2;
	      dhcpo->r_lease += dhcpm->options[opointer++];
	      dhcpo->r_lease = dhcpo->r_ip << 8;
	      dhcpo->r_lease += dhcpm->options[opointer++];
	      dhcpo->r_lease = dhcpo->r_ip << 8;
	      dhcpo->r_lease += dhcpm->options[opointer++];
	      dhcpo->r_lease = dhcpo->r_ip << 8;
	      dhcpo->r_lease += dhcpm->options[opointer++];
	      break;
	    case HOSTNAME:
	      opointer += 1;
	      dhcpo->hostname = (char *)malloc( dhcpm->options[opointer] + 1);
	      strncpy( dhcpo->hostname, &dhcpm->options[opointer+1], dhcpm->options[opointer] );
	      opointer += dhcpm->options[opointer] + 1;
	    default:
	      /* Ignore option */
	      opointer++;
	      break;
	    }
	  }
	pointer = opointer;
	break;
      case  TOFFSET:
      case  TIMESERVER:
      case  NS:
      case  DNS:
      case  LOGSERVER:
      case  COOKIESERVER:
      case  LPRSERVER:
      case  IMPSERVER:
      case  RESLOCSERVER:
      case  BOOTFILESIZE:
      case  MERITDUMPFILE:
      case  DOMAINNAME:
      case  SWAPSERVER:
      case  ROOTPATH:
      case  EXTENSIONPATH:
      case  IPFORWARD:
      case  NONLOCAL:
      case  POLICYFILTER:
      case  MAXIMUMDATAG:
      case  DEFAULTTTL:
      case  PATHMTUATO:
      case  PATHMTUPTO:
      case  IMTU:
      case  ALLSUBLOCAL:
      case  BROADCAST:
      case  PMASKDISCOVERY:
      case  MASKSUPPLIER:
      case  PROUTERDISCOVE:
      case  RSOLICIADDRESS:
      case  STATICROUTE:
      case  TENCAPSULATION:
      case  ARPCACHE:
      case  ETHENCAPSUL:
      case  TCPDEFTTL:
      case  TCPKAI:
      case  TCPKAG:
      case  NISDOMAIN:
      case  NISSERVER:
      case  NTPSERVER:
      case  VENDORSP:
      case  NBTCPIPNS:
      case  NBTCPIPDDS:
      case  NBTCPIPNT:
      case  NBTCPIPSC:
      case  XWINFONTSERVER:
      case  XWINDISPLAY:
      case  OVERLOAD:
      case  SERVER:
      case  MESSAGE:
      case  MAXIMUMDHCP:
      case  RENEWALTIME:
      case  REBINDING:
      case  VENDORCLASS:
      case  NISPLUSDOMAIN:
      case  NISPLUSSERVER:
      case  TFTPSERVER:
      case  BOOTFILE:
      case  MOBILEIP:
      case  SMTPSERVER:
      case  POP3SERVER:
      case  NNTPSERVER:
      case  HTTPSERVER:
      case  FINGERSERVER:
      case  IRCSERVER:
      case  STREETTALKSE:
      case  STREETTALKDA:
      case CLIENT:
	pointer++;
	pointer += dhcpm->options[pointer];
      case END:
	/* return to the calling functions because this is over */
	fprintf( stdout, "parse_dhcp_options: END option found! [end]!\n");
	return 0;
      default:
	/* ignored */
	pointer++;
	break;
      }
    }
  fprintf( stdout, "parse_dhcp_options [end]!\n");
  return 0;
}

int process_dhcp_packet( DHCPMESSAGE *dhcpm, DHCPOPTIONS *dhcpo )
{
  int pointer = 4;
  DHCPLEASE dhcpl;
  char *name;

  fprintf( stdout, "process_dhcp_packet [begin]!\n");

  if( (!dhcpm) || (!dhcpo) )
    return -1;

  name = (char *)malloc( 16 );
  switch( dhcpo->type ){

  case DHCPDISCOVER:
    /* We need to send a DHCPOFFER */
    if( find_lease( &dhcpl, dhcpm->xid, dhcpm->chaddr ) < 0 )
      {
	fprintf( stdout, "No free leases! \n" );
	free( name );
	return -1;
      }
    dhcpm->op = BOOTREPLY;
    dhcpm->yiaddr = dhcpl.ip;
    dhcpm->siaddr = dhcpl.siaddr;
    strcpy(dhcpm->sname, VERSION);
    dhcpm->options[pointer++] = MESSAGETYPE;
    dhcpm->options[pointer++] = 1;
    dhcpm->options[pointer++] = DHCPOFFER;
    dhcpm->options[pointer++] = ROUTER;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.router & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.router >> 8) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.router >> 16) &0xFF);
    dhcpm->options[pointer++] = (dhcpl.router >> 24);
    dhcpm->options[pointer++] = MASK;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.mask & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.mask >> 8) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.mask >> 16) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.mask >> 24);
    dhcpm->options[pointer++] = SERVER;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.siaddr & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.siaddr >> 8) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.siaddr >> 16) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.siaddr >> 24);
    dhcpm->options[pointer++] = LEASE;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF);
    dhcpm->options[pointer++] = REBINDING;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF) - 5;
    dhcpm->options[pointer++] = RENEWALTIME;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF) - 5;
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = END;
    for( ; pointer < 312; pointer++ )
      dhcpm->options[pointer] = PAD;
    dhcpo->type = DHCPOFFER;
    strcpy( name, "255.255.255.255" );
    break;

  case DHCPREQUEST:
    /* We need to send an DHCPACK */
    dhcpm->op = BOOTREPLY;
    dhcpm->yiaddr = dhcpm->ciaddr;
    strcpy(dhcpm->sname, VERSION);
    if( confirm_lease( &dhcpl, dhcpm->xid ) < 0)
      {
	dhcpm->options[pointer++] = MESSAGETYPE;
	dhcpm->options[pointer++] = 1;
	dhcpm->options[pointer++] = DHCPNAK;
	dhcpm->options[pointer++] = PAD;
	dhcpm->options[pointer++] = END;
	for( ; pointer < 312; pointer++ )
	  dhcpm->options[pointer] = PAD;
	sprintf( name, "%u.%u.%u.%u", (dhcpm->ciaddr &0xFF), ((dhcpm->ciaddr>>8)&0xFF), ((dhcpm->ciaddr>>16)&0xFF), ((dhcpm->ciaddr>>24)&0xFF));
	display_dhcp_packet( dhcpm, dhcpo );
	write_packet( dhcpm, name );
	free( name );
	return -1;
      }
    dhcpm->siaddr = dhcpl.siaddr;
    dhcpm->options[pointer++] = MESSAGETYPE;
    dhcpm->options[pointer++] = 1;
    dhcpm->options[pointer++] = DHCPACK;
    dhcpm->options[pointer++] = ROUTER;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.router >> 24);
    dhcpm->options[pointer++] = ((dhcpl.router >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.router >> 8) &0xFF);
    dhcpm->options[pointer++] = (dhcpl.router & 0xFF);
    dhcpm->options[pointer++] = MASK;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.mask >> 24);
    dhcpm->options[pointer++] = ((dhcpl.mask >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.mask >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.mask & 0xFF);
    dhcpm->options[pointer++] = SERVER;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = dhcpl.siaddr >> 24;
    dhcpm->options[pointer++] = ((dhcpl.siaddr >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.siaddr >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.siaddr & 0xFF);
    dhcpm->options[pointer++] = LEASE;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF);
    dhcpm->options[pointer++] = REBINDING;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF);
    dhcpm->options[pointer++] = RENEWALTIME;
    dhcpm->options[pointer++] = 4;
    dhcpm->options[pointer++] = (dhcpl.lease >> 24);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 16) & 0xFF);
    dhcpm->options[pointer++] = ((dhcpl.lease >> 8) & 0xFF);
    dhcpm->options[pointer++] = (dhcpl.lease & 0xFF);
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = PAD;
    dhcpm->options[pointer++] = END;
    for( ; pointer < 312; pointer++ )
      dhcpm->options[pointer] = PAD;
    dhcpo->type = DHCPACK;
    sprintf( name, "%u.%u.%u.%u", (dhcpl.ip & 0xFF), ((dhcpl.ip>>8) & 0xFF), ((dhcpl.ip>>16)&0xFF), (dhcpl.ip>>24));
    break;

  default:
    break;
  }
  display_dhcp_packet( dhcpm, dhcpo );
  write_packet( dhcpm, name );
  fprintf( stdout, "process_dhcp_packet [end]!\n");
  free( name );
  return 0;
}

int write_packet( DHCPMESSAGE *dhcpm, char *name )
{
  int sockfd;
  struct sockaddr_in their_addr; // connector's address information
  struct hostent *he;
  int numbytes;
  int enable = 1;

  fprintf( stdout, "write_packet [begin]\n" );

  if( !dhcpm )
    return -1;

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  if( setsockopt( sockfd, SOL_SOCKET, SO_BROADCAST, &enable, sizeof( enable )) == -1 )
    {
      perror("setsockopt");
      exit(1);
    }

  if( strcmp( "255.255.255.255", name ) )
    {
      if ((he=gethostbyname(name)) == NULL) {  // get the host info
	perror("gethostbyname");
	fprintf( stdout, "Unknown host %s \n", name );
	return -1;
      }
      their_addr.sin_family = AF_INET;     // host byte order
      their_addr.sin_port = htons(68); // short, network byte order
      their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    } else {
      their_addr.sin_family = AF_INET;     // host byte order
      their_addr.sin_port = htons(68); // short, network byte order
      their_addr.sin_addr.s_addr = 0xFFFFFFFF;
    }

  fprintf( stdout, "IP a buscar: %s \n", name );
  memset(&(their_addr.sin_zero), '\0', 8); // zero the rest of the struct

  if ((numbytes=sendto(sockfd, dhcpm, sizeof(DHCPMESSAGE), 0,
		       (struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
    perror("sendto");
    exit(1);
  }

  printf("sent %d bytes to %s\n", numbytes,
	 inet_ntoa(their_addr.sin_addr));

  close(sockfd);

  fprintf( stdout, "write_packet [end]\n" );

  return 0;
}

