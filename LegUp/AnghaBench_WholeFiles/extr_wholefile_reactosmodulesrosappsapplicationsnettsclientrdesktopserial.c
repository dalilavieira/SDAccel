#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint32 ;
struct termios {int c_cflag; int c_iflag; long* c_cc; int c_lflag; int /*<<< orphan*/  c_oflag; } ;
typedef  int speed_t ;
struct TYPE_20__ {TYPE_1__* rdpdr_device; } ;
struct TYPE_19__ {int baud_rate; int dtr; int stop_bits; int parity; int word_length; int control; int xonoff; long* chars; int rts; int event_txempty; int event_cts; int event_dsr; int event_pending; int read_total_timeout_constant; int read_total_timeout_multiplier; int read_interval_timeout; int queue_in_size; int queue_out_size; int onlimit; int offlimit; int write_total_timeout_multiplier; int write_total_timeout_constant; int wait_mask; struct termios* ptermios; scalar_t__ event_rlsd; struct termios* pold_termios; } ;
struct TYPE_18__ {scalar_t__ handle; char* name; char* local_path; scalar_t__ device_type; void* pdevice_data; } ;
typedef  int /*<<< orphan*/  STREAM ;
typedef  TYPE_2__ SERIAL_DEVICE ;
typedef  TYPE_3__ RDPCLIENT ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  scalar_t__ NTHANDLE ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int B0 ; 
 int B9600 ; 
 int BRKINT ; 
 int CRTSCTS ; 
#define  CS5 162 
#define  CS6 161 
#define  CS7 160 
 int const CS8 ; 
 int CSIZE ; 
 int CSTOPB ; 
 int /*<<< orphan*/  DEBUG_SERIAL (char*) ; 
 scalar_t__ DEVICE_TYPE_SERIAL ; 
 int ECHO ; 
 int ECHONL ; 
#define  EVEN_PARITY 159 
 int FILE_DEVICE_SERIAL_PORT ; 
 int /*<<< orphan*/  F_SETFL ; 
 scalar_t__ False ; 
 int ICANON ; 
 int ICRNL ; 
 int IEXTEN ; 
 int IGNBRK ; 
 int IGNCR ; 
 int IMAXBEL ; 
 int INLCR ; 
 int ISIG ; 
 int ISTRIP ; 
 int IXOFF ; 
 int IXON ; 
#define  NO_PARITY 158 
#define  ODD_PARITY 157 
 int /*<<< orphan*/  OPOST ; 
 int O_NOCTTY ; 
 int O_NONBLOCK ; 
 int O_RDWR ; 
 int PARENB ; 
 int PARMRK ; 
 int PARODD ; 
 int RDPDR_MAX_DEVICES ; 
 size_t SERIAL_CHAR_BREAK ; 
 size_t SERIAL_CHAR_EOF ; 
 size_t SERIAL_CHAR_ERROR ; 
 size_t SERIAL_CHAR_XOFF ; 
 size_t SERIAL_CHAR_XON ; 
#define  SERIAL_CLR_DTR 156 
#define  SERIAL_CLR_RTS 155 
#define  SERIAL_CONFIG_SIZE 154 
 int SERIAL_CTS_HANDSHAKE ; 
 int SERIAL_DSR_SENSITIVITY ; 
 int SERIAL_DTR_CONTROL ; 
 int SERIAL_ERROR_ABORT ; 
 int SERIAL_EV_CTS ; 
 int SERIAL_EV_DSR ; 
#define  SERIAL_GET_BAUD_RATE 153 
#define  SERIAL_GET_CHARS 152 
#define  SERIAL_GET_COMMSTATUS 151 
#define  SERIAL_GET_HANDFLOW 150 
#define  SERIAL_GET_LINE_CONTROL 149 
#define  SERIAL_GET_MODEMSTATUS 148 
#define  SERIAL_GET_TIMEOUTS 147 
#define  SERIAL_GET_WAIT_MASK 146 
#define  SERIAL_IMMEDIATE_CHAR 145 
#define  SERIAL_PURGE 144 
 int SERIAL_PURGE_RXABORT ; 
 int SERIAL_PURGE_RXCLEAR ; 
 int SERIAL_PURGE_TXABORT ; 
 int SERIAL_PURGE_TXCLEAR ; 
#define  SERIAL_RESET_DEVICE 143 
#define  SERIAL_SET_BAUD_RATE 142 
#define  SERIAL_SET_BREAK_OFF 141 
#define  SERIAL_SET_BREAK_ON 140 
#define  SERIAL_SET_CHARS 139 
#define  SERIAL_SET_DTR 138 
#define  SERIAL_SET_HANDFLOW 137 
#define  SERIAL_SET_LINE_CONTROL 136 
#define  SERIAL_SET_QUEUE_SIZE 135 
#define  SERIAL_SET_RTS 134 
#define  SERIAL_SET_TIMEOUTS 133 
#define  SERIAL_SET_WAIT_MASK 132 
#define  SERIAL_SET_XOFF 131 
#define  SERIAL_SET_XON 130 
#define  SERIAL_WAIT_ON_MASK 129 
 int SERIAL_XOFF_HANDSHAKE ; 
 int SERIAL_XON_HANDSHAKE ; 
 int /*<<< orphan*/  STATUS_ACCESS_DENIED ; 
 int /*<<< orphan*/  STATUS_CANCELLED ; 
 int /*<<< orphan*/  STATUS_INVALID_PARAMETER ; 
 int /*<<< orphan*/  STATUS_PENDING ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  STATUS_TIMEOUT ; 
 int STOP_BITS_1 ; 
#define  STOP_BITS_2 128 
 int TCIFLUSH ; 
 int /*<<< orphan*/  TCION ; 
 int TCOFLUSH ; 
 int /*<<< orphan*/  TCSANOW ; 
 int /*<<< orphan*/  TIOCMGET ; 
 int /*<<< orphan*/  TIOCMSET ; 
 int TIOCM_CTS ; 
 int TIOCM_DSR ; 
 int TIOCM_DTR ; 
 int TIOCM_RTS ; 
 scalar_t__ True ; 
 size_t VEOF ; 
 size_t VINTR ; 
 size_t VKILL ; 
 size_t VMIN ; 
 size_t VSTART ; 
 size_t VSTOP ; 
 size_t VTIME ; 
 int cfgetispeed (struct termios*) ; 
 int cfgetospeed (struct termios*) ; 
 int /*<<< orphan*/  cfsetispeed (struct termios*,int) ; 
 int /*<<< orphan*/  cfsetospeed (struct termios*,int) ; 
 int /*<<< orphan*/  close (scalar_t__) ; 
 int fcntl (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int get_device_index (TYPE_3__*,scalar_t__) ; 
 int /*<<< orphan*/  in_uint32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint32_le (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8a (int /*<<< orphan*/ ,long*,int) ; 
 int /*<<< orphan*/  ioctl (scalar_t__,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  memset (struct termios*,int /*<<< orphan*/ ,int) ; 
 char* next_arg (char*,char) ; 
 scalar_t__ open (char*,int) ; 
 int /*<<< orphan*/  out_uint32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint32_le (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint8a (int /*<<< orphan*/ ,long*,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,char*,...) ; 
 int /*<<< orphan*/  rdpdr_abort_io (TYPE_3__*,scalar_t__,int,int /*<<< orphan*/ ) ; 
 int read (scalar_t__,int*,int) ; 
 scalar_t__ serial_get_event (TYPE_3__*,scalar_t__,int*) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  tcflow (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tcflush (scalar_t__,int) ; 
 int tcgetattr (scalar_t__,struct termios*) ; 
 int /*<<< orphan*/  tcsendbreak (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tcsetattr (scalar_t__,int /*<<< orphan*/ ,struct termios*) ; 
 int /*<<< orphan*/  toupper_str (char*) ; 
 int /*<<< orphan*/  unimpl (char*,int) ; 
 int write (scalar_t__,int*,int) ; 
 char* xmalloc (int) ; 

__attribute__((used)) static SERIAL_DEVICE *
get_serial_info(RDPCLIENT * This, NTHANDLE handle)
{
	int index;

	for (index = 0; index < RDPDR_MAX_DEVICES; index++)
	{
		if (handle == This->rdpdr_device[index].handle)
			return (SERIAL_DEVICE *) This->rdpdr_device[index].pdevice_data;
	}
	return NULL;
}

__attribute__((used)) static BOOL
get_termios(SERIAL_DEVICE * pser_inf, NTHANDLE serial_fd)
{
	speed_t speed;
	struct termios *ptermios;

	ptermios = pser_inf->ptermios;

	if (tcgetattr(serial_fd, ptermios) == -1)
		return False;

	speed = cfgetispeed(ptermios);
	switch (speed)
	{
#ifdef B75
		case B75:
			pser_inf->baud_rate = 75;
			break;
#endif
#ifdef B110
		case B110:
			pser_inf->baud_rate = 110;
			break;
#endif
#ifdef B134
		case B134:
			pser_inf->baud_rate = 134;
			break;
#endif
#ifdef B150
		case B150:
			pser_inf->baud_rate = 150;
			break;
#endif
#ifdef B300
		case B300:
			pser_inf->baud_rate = 300;
			break;
#endif
#ifdef B600
		case B600:
			pser_inf->baud_rate = 600;
			break;
#endif
#ifdef B1200
		case B1200:
			pser_inf->baud_rate = 1200;
			break;
#endif
#ifdef B1800
		case B1800:
			pser_inf->baud_rate = 1800;
			break;
#endif
#ifdef B2400
		case B2400:
			pser_inf->baud_rate = 2400;
			break;
#endif
#ifdef B4800
		case B4800:
			pser_inf->baud_rate = 4800;
			break;
#endif
#ifdef B9600
		case B9600:
			pser_inf->baud_rate = 9600;
			break;
#endif
#ifdef B19200
		case B19200:
			pser_inf->baud_rate = 19200;
			break;
#endif
#ifdef B38400
		case B38400:
			pser_inf->baud_rate = 38400;
			break;
#endif
#ifdef B57600
		case B57600:
			pser_inf->baud_rate = 57600;
			break;
#endif
#ifdef B115200
		case B115200:
			pser_inf->baud_rate = 115200;
			break;
#endif
#ifdef B230400
		case B230400:
			pser_inf->baud_rate = 230400;
			break;
#endif
#ifdef B460800
		case B460800:
			pser_inf->baud_rate = 460800;
			break;
#endif
		default:
			pser_inf->baud_rate = 9600;
			break;
	}

	speed = cfgetospeed(ptermios);
	pser_inf->dtr = (speed == B0) ? 0 : 1;

	pser_inf->stop_bits = (ptermios->c_cflag & CSTOPB) ? STOP_BITS_2 : STOP_BITS_1;
	pser_inf->parity =
		(ptermios->
		 c_cflag & PARENB) ? ((ptermios->
				       c_cflag & PARODD) ? ODD_PARITY : EVEN_PARITY) : NO_PARITY;
	switch (ptermios->c_cflag & CSIZE)
	{
		case CS5:
			pser_inf->word_length = 5;
			break;
		case CS6:
			pser_inf->word_length = 6;
			break;
		case CS7:
			pser_inf->word_length = 7;
			break;
		default:
			pser_inf->word_length = 8;
			break;
	}

	if (ptermios->c_cflag & CRTSCTS)
	{
		pser_inf->control = SERIAL_DTR_CONTROL | SERIAL_CTS_HANDSHAKE | SERIAL_ERROR_ABORT;
	}
	else
	{
		pser_inf->control = SERIAL_DTR_CONTROL | SERIAL_ERROR_ABORT;
	}

	pser_inf->xonoff = SERIAL_DSR_SENSITIVITY;
	if (ptermios->c_iflag & IXON)
		pser_inf->xonoff |= SERIAL_XON_HANDSHAKE;

	if (ptermios->c_iflag & IXOFF)
		pser_inf->xonoff |= SERIAL_XOFF_HANDSHAKE;

	pser_inf->chars[SERIAL_CHAR_XON] = ptermios->c_cc[VSTART];
	pser_inf->chars[SERIAL_CHAR_XOFF] = ptermios->c_cc[VSTOP];
	pser_inf->chars[SERIAL_CHAR_EOF] = ptermios->c_cc[VEOF];
	pser_inf->chars[SERIAL_CHAR_BREAK] = ptermios->c_cc[VINTR];
	pser_inf->chars[SERIAL_CHAR_ERROR] = ptermios->c_cc[VKILL];

	return True;
}

__attribute__((used)) static void
set_termios(SERIAL_DEVICE * pser_inf, NTHANDLE serial_fd)
{
	speed_t speed;

	struct termios *ptermios;

	ptermios = pser_inf->ptermios;


	switch (pser_inf->baud_rate)
	{
#ifdef B75
		case 75:
			speed = B75;
			break;
#endif
#ifdef B110
		case 110:
			speed = B110;
			break;
#endif
#ifdef B134
		case 134:
			speed = B134;
			break;
#endif
#ifdef B150
		case 150:
			speed = B150;
			break;
#endif
#ifdef B300
		case 300:
			speed = B300;
			break;
#endif
#ifdef B600
		case 600:
			speed = B600;
			break;
#endif
#ifdef B1200
		case 1200:
			speed = B1200;
			break;
#endif
#ifdef B1800
		case 1800:
			speed = B1800;
			break;
#endif
#ifdef B2400
		case 2400:
			speed = B2400;
			break;
#endif
#ifdef B4800
		case 4800:
			speed = B4800;
			break;
#endif
#ifdef B9600
		case 9600:
			speed = B9600;
			break;
#endif
#ifdef B19200
		case 19200:
			speed = B19200;
			break;
#endif
#ifdef B38400
		case 38400:
			speed = B38400;
			break;
#endif
#ifdef B57600
		case 57600:
			speed = B57600;
			break;
#endif
#ifdef B115200
		case 115200:
			speed = B115200;
			break;
#endif
#ifdef B230400
		case 230400:
			speed = B115200;
			break;
#endif
#ifdef B460800
		case 460800:
			speed = B115200;
			break;
#endif
		default:
			speed = B9600;
			break;
	}

#ifdef CBAUD
	ptermios->c_cflag &= ~CBAUD;
	ptermios->c_cflag |= speed;
#else
	/* on systems with separate ispeed and ospeed, we can remember the speed
	   in ispeed while changing DTR with ospeed */
	cfsetispeed(pser_inf->ptermios, speed);
	cfsetospeed(pser_inf->ptermios, pser_inf->dtr ? speed : 0);
#endif

	ptermios->c_cflag &= ~(CSTOPB | PARENB | PARODD | CSIZE | CRTSCTS);
	switch (pser_inf->stop_bits)
	{
		case STOP_BITS_2:
			ptermios->c_cflag |= CSTOPB;
			break;
		default:
			ptermios->c_cflag &= ~CSTOPB;
			break;
	}

	switch (pser_inf->parity)
	{
		case EVEN_PARITY:
			ptermios->c_cflag |= PARENB;
			break;
		case ODD_PARITY:
			ptermios->c_cflag |= PARENB | PARODD;
			break;
		case NO_PARITY:
			ptermios->c_cflag &= ~(PARENB | PARODD);
			break;
	}

	switch (pser_inf->word_length)
	{
		case 5:
			ptermios->c_cflag |= CS5;
			break;
		case 6:
			ptermios->c_cflag |= CS6;
			break;
		case 7:
			ptermios->c_cflag |= CS7;
			break;
		default:
			ptermios->c_cflag |= CS8;
			break;
	}

#if 0
	if (pser_inf->rts)
		ptermios->c_cflag |= CRTSCTS;
	else
		ptermios->c_cflag &= ~CRTSCTS;
#endif

	if (pser_inf->control & SERIAL_CTS_HANDSHAKE)
	{
		ptermios->c_cflag |= CRTSCTS;
	}
	else
	{
		ptermios->c_cflag &= ~CRTSCTS;
	}


	if (pser_inf->xonoff & SERIAL_XON_HANDSHAKE)
	{
		ptermios->c_iflag |= IXON | IMAXBEL;
	}
	if (pser_inf->xonoff & SERIAL_XOFF_HANDSHAKE)
	{
		ptermios->c_iflag |= IXOFF | IMAXBEL;
	}

	if ((pser_inf->xonoff & (SERIAL_XOFF_HANDSHAKE | SERIAL_XON_HANDSHAKE)) == 0)
	{
		ptermios->c_iflag &= ~IXON;
		ptermios->c_iflag &= ~IXOFF;
	}

	ptermios->c_cc[VSTART] = pser_inf->chars[SERIAL_CHAR_XON];
	ptermios->c_cc[VSTOP] = pser_inf->chars[SERIAL_CHAR_XOFF];
	ptermios->c_cc[VEOF] = pser_inf->chars[SERIAL_CHAR_EOF];
	ptermios->c_cc[VINTR] = pser_inf->chars[SERIAL_CHAR_BREAK];
	ptermios->c_cc[VKILL] = pser_inf->chars[SERIAL_CHAR_ERROR];

	tcsetattr(serial_fd, TCSANOW, ptermios);
}

int
serial_enum_devices(RDPCLIENT * This, uint32 * id, char *optarg)
{
	SERIAL_DEVICE *pser_inf;

	char *pos = optarg;
	char *pos2;
	int count = 0;

	/* skip the first colon */
	optarg++;
	while ((pos = next_arg(optarg, ',')) && *id < RDPDR_MAX_DEVICES)
	{
		/* Init data structures for device */
		pser_inf = (SERIAL_DEVICE *) xmalloc(sizeof(SERIAL_DEVICE));
		pser_inf->ptermios = (struct termios *) xmalloc(sizeof(struct termios));
		memset(pser_inf->ptermios, 0, sizeof(struct termios));
		pser_inf->pold_termios = (struct termios *) xmalloc(sizeof(struct termios));
		memset(pser_inf->pold_termios, 0, sizeof(struct termios));

		pos2 = next_arg(optarg, '=');
		strcpy(This->rdpdr_device[*id].name, optarg);

		toupper_str(This->rdpdr_device[*id].name);

		This->rdpdr_device[*id].local_path = xmalloc(strlen(pos2) + 1);
		strcpy(This->rdpdr_device[*id].local_path, pos2);
		printf("SERIAL %s to %s\n", This->rdpdr_device[*id].name,
		       This->rdpdr_device[*id].local_path);
		/* set device type */
		This->rdpdr_device[*id].device_type = DEVICE_TYPE_SERIAL;
		This->rdpdr_device[*id].pdevice_data = (void *) pser_inf;
		count++;
		(*id)++;

		optarg = pos;
	}
	return count;
}

__attribute__((used)) static NTSTATUS
serial_create(RDPCLIENT * This, uint32 device_id, uint32 access, uint32 share_mode, uint32 disposition,
	      uint32 flags_and_attributes, char *filename, NTHANDLE * handle)
{
	NTHANDLE serial_fd;
	SERIAL_DEVICE *pser_inf;
	struct termios *ptermios;

	pser_inf = (SERIAL_DEVICE *) This->rdpdr_device[device_id].pdevice_data;
	ptermios = pser_inf->ptermios;
	serial_fd = open(This->rdpdr_device[device_id].local_path, O_RDWR | O_NOCTTY | O_NONBLOCK);

	if (serial_fd == -1)
	{
		perror("open");
		return STATUS_ACCESS_DENIED;
	}

	if (!get_termios(pser_inf, serial_fd))
	{
		printf("INFO: SERIAL %s access denied\n", This->rdpdr_device[device_id].name);
		fflush(stdout);
		return STATUS_ACCESS_DENIED;
	}

	/* Store handle for later use */
	This->rdpdr_device[device_id].handle = serial_fd;

	/* some sane information */
	DEBUG_SERIAL(("INFO: SERIAL %s to %s\nINFO: speed %u baud, stop bits %u, parity %u, word length %u bits, dtr %u, rts %u\n", This->rdpdr_device[device_id].name, This->rdpdr_device[device_id].local_path, pser_inf->baud_rate, pser_inf->stop_bits, pser_inf->parity, pser_inf->word_length, pser_inf->dtr, pser_inf->rts));

	pser_inf->ptermios->c_iflag &=
		~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	pser_inf->ptermios->c_oflag &= ~OPOST;
	pser_inf->ptermios->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	pser_inf->ptermios->c_cflag &= ~(CSIZE | PARENB);
	pser_inf->ptermios->c_cflag |= CS8;

	tcsetattr(serial_fd, TCSANOW, pser_inf->ptermios);

	pser_inf->event_txempty = 0;
	pser_inf->event_cts = 0;
	pser_inf->event_dsr = 0;
	pser_inf->event_rlsd = 0;
	pser_inf->event_pending = 0;

	*handle = serial_fd;

	/* all read and writes should be non blocking */
	if (fcntl(*handle, F_SETFL, O_NONBLOCK) == -1)
		perror("fcntl");

	pser_inf->read_total_timeout_constant = 5;

	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
serial_close(RDPCLIENT * This, NTHANDLE handle)
{
	int i = get_device_index(This, handle);
	if (i >= 0)
		This->rdpdr_device[i].handle = 0;

	rdpdr_abort_io(This, handle, 0, STATUS_TIMEOUT);
	close(handle);
	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
serial_read(RDPCLIENT * This, NTHANDLE handle, uint8 * data, uint32 length, uint32 offset, uint32 * result)
{
	long timeout;
	SERIAL_DEVICE *pser_inf;
	struct termios *ptermios;
#ifdef WITH_DEBUG_SERIAL
	int bytes_inqueue;
#endif


	timeout = 90;
	pser_inf = get_serial_info(This, handle);
	ptermios = pser_inf->ptermios;

	/* Set timeouts kind of like the windows serial timeout parameters. Multiply timeout
	   with requested read size */
	if (pser_inf->read_total_timeout_multiplier | pser_inf->read_total_timeout_constant)
	{
		timeout =
			(pser_inf->read_total_timeout_multiplier * length +
			 pser_inf->read_total_timeout_constant + 99) / 100;
	}
	else if (pser_inf->read_interval_timeout)
	{
		timeout = (pser_inf->read_interval_timeout * length + 99) / 100;
	}

	/* If a timeout is set, do a blocking read, which times out after some time.
	   It will make rdesktop less responsive, but it will improve serial performance, by not
	   reading one character at a time. */
	if (timeout == 0)
	{
		ptermios->c_cc[VTIME] = 0;
		ptermios->c_cc[VMIN] = 0;
	}
	else
	{
		ptermios->c_cc[VTIME] = timeout;
		ptermios->c_cc[VMIN] = 1;
	}
	tcsetattr(handle, TCSANOW, ptermios);

#if defined(WITH_DEBUG_SERIAL) && defined(TIOCINQ)
	ioctl(handle, TIOCINQ, &bytes_inqueue);
	DEBUG_SERIAL(("serial_read inqueue: %d expected %d\n", bytes_inqueue, length));
#endif

	*result = read(handle, data, length);

#ifdef WITH_DEBUG_SERIAL
	DEBUG_SERIAL(("serial_read Bytes %d\n", *result));
	if (*result > 0)
		hexdump(data, *result);
#endif

	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
serial_write(RDPCLIENT * This, NTHANDLE handle, uint8 * data, uint32 length, uint32 offset, uint32 * result)
{
	SERIAL_DEVICE *pser_inf;

	pser_inf = get_serial_info(This, handle);

	*result = write(handle, data, length);

	if (*result > 0)
		pser_inf->event_txempty = *result;

	DEBUG_SERIAL(("serial_write length %d, offset %d result %d\n", length, offset, *result));

	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
serial_device_control(RDPCLIENT * This, NTHANDLE handle, uint32 request, STREAM in, STREAM out)
{
	int flush_mask, purge_mask;
	uint32 result, modemstate;
	uint8 immediate;
	SERIAL_DEVICE *pser_inf;
	struct termios *ptermios;

	if ((request >> 16) != FILE_DEVICE_SERIAL_PORT)
		return STATUS_INVALID_PARAMETER;

	pser_inf = get_serial_info(This, handle);
	ptermios = pser_inf->ptermios;

	/* extract operation */
	request >>= 2;
	request &= 0xfff;

	switch (request)
	{
		case SERIAL_SET_BAUD_RATE:
			in_uint32_le(in, pser_inf->baud_rate);
			set_termios(pser_inf, handle);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_BAUD_RATE %d\n",
				      pser_inf->baud_rate));
			break;
		case SERIAL_GET_BAUD_RATE:
			out_uint32_le(out, pser_inf->baud_rate);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_BAUD_RATE %d\n",
				      pser_inf->baud_rate));
			break;
		case SERIAL_SET_QUEUE_SIZE:
			in_uint32_le(in, pser_inf->queue_in_size);
			in_uint32_le(in, pser_inf->queue_out_size);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_QUEUE_SIZE in %d out %d\n",
				      pser_inf->queue_in_size, pser_inf->queue_out_size));
			break;
		case SERIAL_SET_LINE_CONTROL:
			in_uint8(in, pser_inf->stop_bits);
			in_uint8(in, pser_inf->parity);
			in_uint8(in, pser_inf->word_length);
			set_termios(pser_inf, handle);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_LINE_CONTROL stop %d parity %d word %d\n", pser_inf->stop_bits, pser_inf->parity, pser_inf->word_length));
			break;
		case SERIAL_GET_LINE_CONTROL:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_LINE_CONTROL\n"));
			out_uint8(out, pser_inf->stop_bits);
			out_uint8(out, pser_inf->parity);
			out_uint8(out, pser_inf->word_length);
			break;
		case SERIAL_IMMEDIATE_CHAR:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_IMMEDIATE_CHAR\n"));
			in_uint8(in, immediate);
			serial_write(This, handle, &immediate, 1, 0, &result);
			break;
		case SERIAL_CONFIG_SIZE:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_CONFIG_SIZE\n"));
			out_uint32_le(out, 0);
			break;
		case SERIAL_GET_CHARS:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_CHARS\n"));
			out_uint8a(out, pser_inf->chars, 6);
			break;
		case SERIAL_SET_CHARS:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_CHARS\n"));
			in_uint8a(in, pser_inf->chars, 6);
#ifdef WITH_DEBUG_SERIAL
			hexdump(pser_inf->chars, 6);
#endif
			set_termios(pser_inf, handle);
			break;
		case SERIAL_GET_HANDFLOW:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_HANDFLOW\n"));
			get_termios(pser_inf, handle);
			out_uint32_le(out, pser_inf->control);
			out_uint32_le(out, pser_inf->xonoff);	/* Xon/Xoff */
			out_uint32_le(out, pser_inf->onlimit);
			out_uint32_le(out, pser_inf->offlimit);
			break;
		case SERIAL_SET_HANDFLOW:
			in_uint32_le(in, pser_inf->control);
			in_uint32_le(in, pser_inf->xonoff);
			in_uint32_le(in, pser_inf->onlimit);
			in_uint32_le(in, pser_inf->offlimit);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_HANDFLOW %x %x %x %x\n",
				      pser_inf->control, pser_inf->xonoff, pser_inf->onlimit,
				      pser_inf->onlimit));
			set_termios(pser_inf, handle);
			break;
		case SERIAL_SET_TIMEOUTS:
			in_uint32(in, pser_inf->read_interval_timeout);
			in_uint32(in, pser_inf->read_total_timeout_multiplier);
			in_uint32(in, pser_inf->read_total_timeout_constant);
			in_uint32(in, pser_inf->write_total_timeout_multiplier);
			in_uint32(in, pser_inf->write_total_timeout_constant);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_TIMEOUTS read timeout %d %d %d\n",
				      pser_inf->read_interval_timeout,
				      pser_inf->read_total_timeout_multiplier,
				      pser_inf->read_total_timeout_constant));
			break;
		case SERIAL_GET_TIMEOUTS:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_TIMEOUTS read timeout %d %d %d\n",
				      pser_inf->read_interval_timeout,
				      pser_inf->read_total_timeout_multiplier,
				      pser_inf->read_total_timeout_constant));

			out_uint32(out, pser_inf->read_interval_timeout);
			out_uint32(out, pser_inf->read_total_timeout_multiplier);
			out_uint32(out, pser_inf->read_total_timeout_constant);
			out_uint32(out, pser_inf->write_total_timeout_multiplier);
			out_uint32(out, pser_inf->write_total_timeout_constant);
			break;
		case SERIAL_GET_WAIT_MASK:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_WAIT_MASK %X\n",
				      pser_inf->wait_mask));
			out_uint32(out, pser_inf->wait_mask);
			break;
		case SERIAL_SET_WAIT_MASK:
			in_uint32(in, pser_inf->wait_mask);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_WAIT_MASK %X\n",
				      pser_inf->wait_mask));
			break;
		case SERIAL_SET_DTR:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_DTR\n"));
			ioctl(handle, TIOCMGET, &result);
			result |= TIOCM_DTR;
			ioctl(handle, TIOCMSET, &result);
			pser_inf->dtr = 1;
			break;
		case SERIAL_CLR_DTR:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_CLR_DTR\n"));
			ioctl(handle, TIOCMGET, &result);
			result &= ~TIOCM_DTR;
			ioctl(handle, TIOCMSET, &result);
			pser_inf->dtr = 0;
			break;
		case SERIAL_SET_RTS:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_RTS\n"));
			ioctl(handle, TIOCMGET, &result);
			result |= TIOCM_RTS;
			ioctl(handle, TIOCMSET, &result);
			pser_inf->rts = 1;
			break;
		case SERIAL_CLR_RTS:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_CLR_RTS\n"));
			ioctl(handle, TIOCMGET, &result);
			result &= ~TIOCM_RTS;
			ioctl(handle, TIOCMSET, &result);
			pser_inf->rts = 0;
			break;
		case SERIAL_GET_MODEMSTATUS:
			modemstate = 0;
#ifdef TIOCMGET
			ioctl(handle, TIOCMGET, &result);
			if (result & TIOCM_CTS)
				modemstate |= SERIAL_MS_CTS;
			if (result & TIOCM_DSR)
				modemstate |= SERIAL_MS_DSR;
			if (result & TIOCM_RNG)
				modemstate |= SERIAL_MS_RNG;
			if (result & TIOCM_CAR)
				modemstate |= SERIAL_MS_CAR;
			if (result & TIOCM_DTR)
				modemstate |= SERIAL_MS_DTR;
			if (result & TIOCM_RTS)
				modemstate |= SERIAL_MS_RTS;
#endif
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_MODEMSTATUS %X\n", modemstate));
			out_uint32_le(out, modemstate);
			break;
		case SERIAL_GET_COMMSTATUS:
			out_uint32_le(out, 0);	/* Errors */
			out_uint32_le(out, 0);	/* Hold reasons */

			result = 0;
#ifdef TIOCINQ
			ioctl(handle, TIOCINQ, &result);
#endif
			out_uint32_le(out, result);	/* Amount in in queue */
			if (result)
				DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_COMMSTATUS in queue %d\n",
					      result));

			result = 0;
#ifdef TIOCOUTQ
			ioctl(handle, TIOCOUTQ, &result);
#endif
			out_uint32_le(out, result);	/* Amount in out queue */
			if (result)
				DEBUG_SERIAL(("serial_ioctl -> SERIAL_GET_COMMSTATUS out queue %d\n", result));

			out_uint8(out, 0);	/* EofReceived */
			out_uint8(out, 0);	/* WaitForImmediate */
			break;
		case SERIAL_PURGE:
			in_uint32(in, purge_mask);
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_PURGE purge_mask %X\n", purge_mask));
			flush_mask = 0;
			if (purge_mask & SERIAL_PURGE_TXCLEAR)
				flush_mask |= TCOFLUSH;
			if (purge_mask & SERIAL_PURGE_RXCLEAR)
				flush_mask |= TCIFLUSH;
			if (flush_mask != 0)
				tcflush(handle, flush_mask);
			if (purge_mask & SERIAL_PURGE_TXABORT)
				rdpdr_abort_io(This, handle, 4, STATUS_CANCELLED);
			if (purge_mask & SERIAL_PURGE_RXABORT)
				rdpdr_abort_io(This, handle, 3, STATUS_CANCELLED);
			break;
		case SERIAL_WAIT_ON_MASK:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_WAIT_ON_MASK %X\n",
				      pser_inf->wait_mask));
			pser_inf->event_pending = 1;
			if (serial_get_event(This, handle, &result))
			{
				DEBUG_SERIAL(("WAIT end  event = %x\n", result));
				out_uint32_le(out, result);
				break;
			}
			return STATUS_PENDING;
			break;
		case SERIAL_SET_BREAK_ON:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_BREAK_ON\n"));
			tcsendbreak(handle, 0);
			break;
		case SERIAL_RESET_DEVICE:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_RESET_DEVICE\n"));
			break;
		case SERIAL_SET_BREAK_OFF:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_BREAK_OFF\n"));
			break;
		case SERIAL_SET_XOFF:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_XOFF\n"));
			break;
		case SERIAL_SET_XON:
			DEBUG_SERIAL(("serial_ioctl -> SERIAL_SET_XON\n"));
			tcflow(handle, TCION);
			break;
		default:
			unimpl("SERIAL IOCTL %d\n", request);
			return STATUS_INVALID_PARAMETER;
	}

	return STATUS_SUCCESS;
}

BOOL
serial_get_event(RDPCLIENT * This, NTHANDLE handle, uint32 * result)
{
	int index;
	SERIAL_DEVICE *pser_inf;
	int bytes;
	BOOL ret = False;

	*result = 0;
	index = get_device_index(This, handle);
	if (index < 0)
		return False;

#ifdef TIOCINQ
	pser_inf = (SERIAL_DEVICE *) This->rdpdr_device[index].pdevice_data;

	ioctl(handle, TIOCINQ, &bytes);

	if (bytes > 0)
	{
		DEBUG_SERIAL(("serial_get_event Bytes %d\n", bytes));
		if (bytes > pser_inf->event_rlsd)
		{
			pser_inf->event_rlsd = bytes;
			if (pser_inf->wait_mask & SERIAL_EV_RLSD)
			{
				DEBUG_SERIAL(("Event -> SERIAL_EV_RLSD \n"));
				*result |= SERIAL_EV_RLSD;
				ret = True;
			}

		}

		if ((bytes > 1) && (pser_inf->wait_mask & SERIAL_EV_RXFLAG))
		{
			DEBUG_SERIAL(("Event -> SERIAL_EV_RXFLAG Bytes %d\n", bytes));
			*result |= SERIAL_EV_RXFLAG;
			ret = True;
		}
		if ((pser_inf->wait_mask & SERIAL_EV_RXCHAR))
		{
			DEBUG_SERIAL(("Event -> SERIAL_EV_RXCHAR Bytes %d\n", bytes));
			*result |= SERIAL_EV_RXCHAR;
			ret = True;
		}

	}
	else
	{
		pser_inf->event_rlsd = 0;
	}
#endif

#ifdef TIOCOUTQ
	ioctl(handle, TIOCOUTQ, &bytes);
	if ((bytes == 0)
	    && (pser_inf->event_txempty > 0) && (pser_inf->wait_mask & SERIAL_EV_TXEMPTY))
	{

		DEBUG_SERIAL(("Event -> SERIAL_EV_TXEMPTY\n"));
		*result |= SERIAL_EV_TXEMPTY;
		ret = True;
	}
	pser_inf->event_txempty = bytes;
#endif

	ioctl(handle, TIOCMGET, &bytes);
	if ((bytes & TIOCM_DSR) != pser_inf->event_dsr)
	{
		pser_inf->event_dsr = bytes & TIOCM_DSR;
		if (pser_inf->wait_mask & SERIAL_EV_DSR)
		{
			DEBUG_SERIAL(("event -> SERIAL_EV_DSR %s\n",
				      (bytes & TIOCM_DSR) ? "ON" : "OFF"));
			*result |= SERIAL_EV_DSR;
			ret = True;
		}
	}

	if ((bytes & TIOCM_CTS) != pser_inf->event_cts)
	{
		pser_inf->event_cts = bytes & TIOCM_CTS;
		if (pser_inf->wait_mask & SERIAL_EV_CTS)
		{
			DEBUG_SERIAL((" EVENT-> SERIAL_EV_CTS %s\n",
				      (bytes & TIOCM_CTS) ? "ON" : "OFF"));
			*result |= SERIAL_EV_CTS;
			ret = True;
		}
	}

	if (ret)
		pser_inf->event_pending = 0;

	return ret;
}

BOOL
serial_get_timeout(RDPCLIENT * This, NTHANDLE handle, uint32 length, uint32 * timeout, uint32 * itv_timeout)
{
	int index;
	SERIAL_DEVICE *pser_inf;

	index = get_device_index(This, handle);
	if (index < 0)
		return True;

	if (This->rdpdr_device[index].device_type != DEVICE_TYPE_SERIAL)
	{
		return False;
	}

	pser_inf = (SERIAL_DEVICE *) This->rdpdr_device[index].pdevice_data;

	*timeout =
		pser_inf->read_total_timeout_multiplier * length +
		pser_inf->read_total_timeout_constant;
	*itv_timeout = pser_inf->read_interval_timeout;
	return True;
}

