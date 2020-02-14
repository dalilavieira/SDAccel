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
struct ktermios {unsigned int c_cflag; int c_ispeed; int c_ospeed; } ;
struct tty_struct {struct ktermios termios; } ;
typedef  int speed_t ;

/* Variables and functions */
 unsigned int CBAUD ; 
 unsigned int CBAUDEX ; 
 unsigned int* baud_bits ; 
 int* baud_table ; 
 unsigned int n_baud_table ; 
 int /*<<< orphan*/  pr_warn_once (char*) ; 

speed_t tty_termios_baud_rate(struct ktermios *termios)
{
	unsigned int cbaud;

	cbaud = termios->c_cflag & CBAUD;

#ifdef BOTHER
	/* Magic token for arbitrary speed via c_ispeed/c_ospeed */
	if (cbaud == BOTHER)
		return termios->c_ospeed;
#endif
	if (cbaud & CBAUDEX) {
		cbaud &= ~CBAUDEX;

		if (cbaud < 1 || cbaud + 15 > n_baud_table)
			termios->c_cflag &= ~CBAUDEX;
		else
			cbaud += 15;
	}
	return cbaud >= n_baud_table ? 0 : baud_table[cbaud];
}

speed_t tty_termios_input_baud_rate(struct ktermios *termios)
{
#ifdef IBSHIFT
	unsigned int cbaud = (termios->c_cflag >> IBSHIFT) & CBAUD;

	if (cbaud == B0)
		return tty_termios_baud_rate(termios);
#ifdef BOTHER
	/* Magic token for arbitrary speed via c_ispeed*/
	if (cbaud == BOTHER)
		return termios->c_ispeed;
#endif
	if (cbaud & CBAUDEX) {
		cbaud &= ~CBAUDEX;

		if (cbaud < 1 || cbaud + 15 > n_baud_table)
			termios->c_cflag &= ~(CBAUDEX << IBSHIFT);
		else
			cbaud += 15;
	}
	return cbaud >= n_baud_table ? 0 : baud_table[cbaud];
#else	/* IBSHIFT */
	return tty_termios_baud_rate(termios);
#endif	/* IBSHIFT */
}

void tty_termios_encode_baud_rate(struct ktermios *termios,
				  speed_t ibaud, speed_t obaud)
{
	int i = 0;
	int ifound = -1, ofound = -1;
	int iclose = ibaud/50, oclose = obaud/50;
	int ibinput = 0;

	if (obaud == 0)			/* CD dropped 		  */
		ibaud = 0;		/* Clear ibaud to be sure */

	termios->c_ispeed = ibaud;
	termios->c_ospeed = obaud;

#ifdef IBSHIFT
	if ((termios->c_cflag >> IBSHIFT) & CBAUD)
		ibinput = 1;	/* An input speed was specified */
#endif
#ifdef BOTHER
	/* If the user asked for a precise weird speed give a precise weird
	   answer. If they asked for a Bfoo speed they may have problems
	   digesting non-exact replies so fuzz a bit */

	if ((termios->c_cflag & CBAUD) == BOTHER) {
		oclose = 0;
		if (!ibinput)
			iclose = 0;
	}
	if (((termios->c_cflag >> IBSHIFT) & CBAUD) == BOTHER)
		iclose = 0;
#endif
	termios->c_cflag &= ~CBAUD;
#ifdef IBSHIFT
	termios->c_cflag &= ~(CBAUD << IBSHIFT);
#endif

	/*
	 *	Our goal is to find a close match to the standard baud rate
	 *	returned. Walk the baud rate table and if we get a very close
	 *	match then report back the speed as a POSIX Bxxxx value by
	 *	preference
	 */

	do {
		if (obaud - oclose <= baud_table[i] &&
		    obaud + oclose >= baud_table[i]) {
			termios->c_cflag |= baud_bits[i];
			ofound = i;
		}
		if (ibaud - iclose <= baud_table[i] &&
		    ibaud + iclose >= baud_table[i]) {
			/* For the case input == output don't set IBAUD bits
			   if the user didn't do so */
			if (ofound == i && !ibinput)
				ifound  = i;
#ifdef IBSHIFT
			else {
				ifound = i;
				termios->c_cflag |= (baud_bits[i] << IBSHIFT);
			}
#endif
		}
	} while (++i < n_baud_table);

	/*
	 *	If we found no match then use BOTHER if provided or warn
	 *	the user their platform maintainer needs to wake up if not.
	 */
#ifdef BOTHER
	if (ofound == -1)
		termios->c_cflag |= BOTHER;
	/* Set exact input bits only if the input and output differ or the
	   user already did */
	if (ifound == -1 && (ibaud != obaud || ibinput))
		termios->c_cflag |= (BOTHER << IBSHIFT);
#else
	if (ifound == -1 || ofound == -1)
		pr_warn_once("tty: Unable to return correct speed data as your architecture needs updating.\n");
#endif
}

void tty_encode_baud_rate(struct tty_struct *tty, speed_t ibaud, speed_t obaud)
{
	tty_termios_encode_baud_rate(&tty->termios, ibaud, obaud);
}

