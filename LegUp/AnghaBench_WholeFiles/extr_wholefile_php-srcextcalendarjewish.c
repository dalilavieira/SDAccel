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
typedef  int zend_ulong ;
typedef  int zend_long ;

/* Variables and functions */
 int AM3_11_20 ; 
 int AM9_32_43 ; 
 int FRIDAY ; 
 int HALAKIM_PER_DAY ; 
 int HALAKIM_PER_LUNAR_CYCLE ; 
 int HALAKIM_PER_METONIC_CYCLE ; 
 int JEWISH_SDN_MAX ; 
 int JEWISH_SDN_OFFSET ; 
 int MONDAY ; 
 int NEW_MOON_OF_CREATION ; 
 int NOON ; 
 int SUNDAY ; 
 int TUESDAY ; 
 int WEDNESDAY ; 
 int* monthsPerYear ; 
 int* yearOffset ; 

__attribute__((used)) static zend_long Tishri1(
						   int metonicYear,
						   zend_long moladDay,
						   zend_long moladHalakim)
{
	zend_long tishri1;
	int dow;
	int leapYear;
	int lastWasLeapYear;

	tishri1 = moladDay;
	dow = tishri1 % 7;
	leapYear = metonicYear == 2 || metonicYear == 5 || metonicYear == 7
		|| metonicYear == 10 || metonicYear == 13 || metonicYear == 16
		|| metonicYear == 18;
	lastWasLeapYear = metonicYear == 3 || metonicYear == 6
		|| metonicYear == 8 || metonicYear == 11 || metonicYear == 14
		|| metonicYear == 17 || metonicYear == 0;

	/* Apply rules 2, 3 and 4. */
	if ((moladHalakim >= NOON) ||
		((!leapYear) && dow == TUESDAY && moladHalakim >= AM3_11_20) ||
		(lastWasLeapYear && dow == MONDAY && moladHalakim >= AM9_32_43)) {
		tishri1++;
		dow++;
		if (dow == 7) {
			dow = 0;
		}
	}
	/* Apply rule 1 after the others because it can cause an additional
	 * delay of one day. */
	if (dow == WEDNESDAY || dow == FRIDAY || dow == SUNDAY) {
		tishri1++;
	}
	return (tishri1);
}

__attribute__((used)) static void MoladOfMetonicCycle(
								   int metonicCycle,
								   zend_long *pMoladDay,
								   zend_long *pMoladHalakim)
{
	register zend_ulong r1, r2, d1, d2;

	/* Start with the time of the first molad after creation. */
	r1 = NEW_MOON_OF_CREATION;

	/* Calculate metonicCycle * HALAKIM_PER_METONIC_CYCLE.  The upper 32
	 * bits of the result will be in r2 and the lower 16 bits will be
	 * in r1. */
	r1 += metonicCycle * (HALAKIM_PER_METONIC_CYCLE & 0xFFFF);
	r2 = r1 >> 16;
	r2 += metonicCycle * ((HALAKIM_PER_METONIC_CYCLE >> 16) & 0xFFFF);

	/* Calculate r2r1 / HALAKIM_PER_DAY.  The remainder will be in r1, the
	 * upper 16 bits of the quotient will be in d2 and the lower 16 bits
	 * will be in d1. */
	d2 = r2 / HALAKIM_PER_DAY;
	r2 -= d2 * HALAKIM_PER_DAY;
	r1 = (r2 << 16) | (r1 & 0xFFFF);
	d1 = r1 / HALAKIM_PER_DAY;
	r1 -= d1 * HALAKIM_PER_DAY;

	*pMoladDay = (d2 << 16) | d1;
	*pMoladHalakim = r1;
}

__attribute__((used)) static void FindTishriMolad(
							   zend_long inputDay,
							   int *pMetonicCycle,
							   int *pMetonicYear,
							   zend_long *pMoladDay,
							   zend_long *pMoladHalakim)
{
	zend_long moladDay;
	zend_long moladHalakim;
	int metonicCycle;
	int metonicYear;

	/* Estimate the metonic cycle number.  Note that this may be an under
	 * estimate because there are 6939.6896 days in a metonic cycle not
	 * 6940, but it will never be an over estimate.  The loop below will
	 * correct for any error in this estimate. */
	metonicCycle = (inputDay + 310) / 6940;

	/* Calculate the time of the starting molad for this metonic cycle. */
	MoladOfMetonicCycle(metonicCycle, &moladDay, &moladHalakim);

	/* If the above was an under estimate, increment the cycle number until
	 * the correct one is found.  For modern dates this loop is about 98.6%
	 * likely to not execute, even once, because the above estimate is
	 * really quite close. */
	while (moladDay < inputDay - 6940 + 310) {
		metonicCycle++;
		moladHalakim += HALAKIM_PER_METONIC_CYCLE;
		moladDay += moladHalakim / HALAKIM_PER_DAY;
		moladHalakim = moladHalakim % HALAKIM_PER_DAY;
	}

	/* Find the molad of Tishri closest to this date. */
	for (metonicYear = 0; metonicYear < 18; metonicYear++) {
		if (moladDay > inputDay - 74) {
			break;
		}
		moladHalakim += HALAKIM_PER_LUNAR_CYCLE * monthsPerYear[metonicYear];
		moladDay += moladHalakim / HALAKIM_PER_DAY;
		moladHalakim = moladHalakim % HALAKIM_PER_DAY;
	}

	*pMetonicCycle = metonicCycle;
	*pMetonicYear = metonicYear;
	*pMoladDay = moladDay;
	*pMoladHalakim = moladHalakim;
}

__attribute__((used)) static void FindStartOfYear(
							   int year,
							   int *pMetonicCycle,
							   int *pMetonicYear,
							   zend_long *pMoladDay,
							   zend_long *pMoladHalakim,
							   int *pTishri1)
{
	*pMetonicCycle = (year - 1) / 19;
	*pMetonicYear = (year - 1) % 19;
	MoladOfMetonicCycle(*pMetonicCycle, pMoladDay, pMoladHalakim);

	*pMoladHalakim += HALAKIM_PER_LUNAR_CYCLE * yearOffset[*pMetonicYear];
	*pMoladDay += *pMoladHalakim / HALAKIM_PER_DAY;
	*pMoladHalakim = *pMoladHalakim % HALAKIM_PER_DAY;

	*pTishri1 = Tishri1(*pMetonicYear, *pMoladDay, *pMoladHalakim);
}

void SdnToJewish(
					zend_long sdn,
					int *pYear,
					int *pMonth,
					int *pDay)
{
	zend_long inputDay;
	zend_long day;
	zend_long halakim;
	int metonicCycle;
	int metonicYear;
	int tishri1;
	int tishri1After;
	int yearLength;

	if (sdn <= JEWISH_SDN_OFFSET || sdn > JEWISH_SDN_MAX) {
		*pYear = 0;
		*pMonth = 0;
		*pDay = 0;
		return;
	}
	inputDay = sdn - JEWISH_SDN_OFFSET;

	FindTishriMolad(inputDay, &metonicCycle, &metonicYear, &day, &halakim);
	tishri1 = Tishri1(metonicYear, day, halakim);

	if (inputDay >= tishri1) {
		/* It found Tishri 1 at the start of the year. */
		*pYear = metonicCycle * 19 + metonicYear + 1;
		if (inputDay < tishri1 + 59) {
			if (inputDay < tishri1 + 30) {
				*pMonth = 1;
				*pDay = inputDay - tishri1 + 1;
			} else {
				*pMonth = 2;
				*pDay = inputDay - tishri1 - 29;
			}
			return;
		}
		/* We need the length of the year to figure this out, so find
		 * Tishri 1 of the next year. */
		halakim += HALAKIM_PER_LUNAR_CYCLE * monthsPerYear[metonicYear];
		day += halakim / HALAKIM_PER_DAY;
		halakim = halakim % HALAKIM_PER_DAY;
		tishri1After = Tishri1((metonicYear + 1) % 19, day, halakim);
	} else {
		/* It found Tishri 1 at the end of the year. */
		*pYear = metonicCycle * 19 + metonicYear;
		if (inputDay >= tishri1 - 177) {
			/* It is one of the last 6 months of the year. */
			if (inputDay > tishri1 - 30) {
				*pMonth = 13;
				*pDay = inputDay - tishri1 + 30;
			} else if (inputDay > tishri1 - 60) {
				*pMonth = 12;
				*pDay = inputDay - tishri1 + 60;
			} else if (inputDay > tishri1 - 89) {
				*pMonth = 11;
				*pDay = inputDay - tishri1 + 89;
			} else if (inputDay > tishri1 - 119) {
				*pMonth = 10;
				*pDay = inputDay - tishri1 + 119;
			} else if (inputDay > tishri1 - 148) {
				*pMonth = 9;
				*pDay = inputDay - tishri1 + 148;
			} else {
				*pMonth = 8;
				*pDay = inputDay - tishri1 + 178;
			}
			return;
		} else {
			if (monthsPerYear[(*pYear - 1) % 19] == 13) {
				*pMonth = 7;
				*pDay = inputDay - tishri1 + 207;
				if (*pDay > 0)
					return;
				(*pMonth)--;
				(*pDay) += 30;
				if (*pDay > 0)
					return;
				(*pMonth)--;
				(*pDay) += 30;
			} else {
				*pMonth = 7;
				*pDay = inputDay - tishri1 + 207;
				if (*pDay > 0)
					return;
				(*pMonth) -= 2;
				(*pDay) += 30;
			}
			if (*pDay > 0)
				return;
			(*pMonth)--;
			(*pDay) += 29;
			if (*pDay > 0)
				return;

			/* We need the length of the year to figure this out, so find
			 * Tishri 1 of this year. */
			tishri1After = tishri1;
			FindTishriMolad(day - 365,
							&metonicCycle, &metonicYear, &day, &halakim);
			tishri1 = Tishri1(metonicYear, day, halakim);
		}
	}

	yearLength = tishri1After - tishri1;
	day = inputDay - tishri1 - 29;
	if (yearLength == 355 || yearLength == 385) {
		/* Heshvan has 30 days */
		if (day <= 30) {
			*pMonth = 2;
			*pDay = day;
			return;
		}
		day -= 30;
	} else {
		/* Heshvan has 29 days */
		if (day <= 29) {
			*pMonth = 2;
			*pDay = day;
			return;
		}
		day -= 29;
	}

	/* It has to be Kislev. */
	*pMonth = 3;
	*pDay = day;
}

zend_long JewishToSdn(
						int year,
						int month,
						int day)
{
	zend_long sdn;
	int metonicCycle;
	int metonicYear;
	int tishri1;
	int tishri1After;
	zend_long moladDay;
	zend_long moladHalakim;
	int yearLength;
	int lengthOfAdarIAndII;

	if (year <= 0 || day <= 0 || day > 30) {
		return (0);
	}
	switch (month) {
		case 1:
		case 2:
			/* It is Tishri or Heshvan - don't need the year length. */
			FindStartOfYear(year, &metonicCycle, &metonicYear,
							&moladDay, &moladHalakim, &tishri1);
			if (month == 1) {
				sdn = tishri1 + day - 1;
			} else {
				sdn = tishri1 + day + 29;
			}
			break;

		case 3:
			/* It is Kislev - must find the year length. */

			/* Find the start of the year. */
			FindStartOfYear(year, &metonicCycle, &metonicYear,
							&moladDay, &moladHalakim, &tishri1);

			/* Find the end of the year. */
			moladHalakim += HALAKIM_PER_LUNAR_CYCLE * monthsPerYear[metonicYear];
			moladDay += moladHalakim / HALAKIM_PER_DAY;
			moladHalakim = moladHalakim % HALAKIM_PER_DAY;
			tishri1After = Tishri1((metonicYear + 1) % 19, moladDay, moladHalakim);

			yearLength = tishri1After - tishri1;

			if (yearLength == 355 || yearLength == 385) {
				sdn = tishri1 + day + 59;
			} else {
				sdn = tishri1 + day + 58;
			}
			break;

		case 4:
		case 5:
		case 6:
			/* It is Tevet, Shevat or Adar I - don't need the year length. */

			FindStartOfYear(year + 1, &metonicCycle, &metonicYear,
							&moladDay, &moladHalakim, &tishri1After);

			if (monthsPerYear[(year - 1) % 19] == 12) {
				lengthOfAdarIAndII = 29;
			} else {
				lengthOfAdarIAndII = 59;
			}

			if (month == 4) {
				sdn = tishri1After + day - lengthOfAdarIAndII - 237;
			} else if (month == 5) {
				sdn = tishri1After + day - lengthOfAdarIAndII - 208;
			} else {
				sdn = tishri1After + day - lengthOfAdarIAndII - 178;
			}
			break;

		default:
			/* It is Adar II or later - don't need the year length. */
			FindStartOfYear(year + 1, &metonicCycle, &metonicYear,
							&moladDay, &moladHalakim, &tishri1After);

			switch (month) {
				case 7:
					sdn = tishri1After + day - 207;
					break;
				case 8:
					sdn = tishri1After + day - 178;
					break;
				case 9:
					sdn = tishri1After + day - 148;
					break;
				case 10:
					sdn = tishri1After + day - 119;
					break;
				case 11:
					sdn = tishri1After + day - 89;
					break;
				case 12:
					sdn = tishri1After + day - 60;
					break;
				case 13:
					sdn = tishri1After + day - 30;
					break;
				default:
					return (0);
			}
	}
	return (sdn + JEWISH_SDN_OFFSET);
}

