#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int m_nOldX; int m_nOldY; scalar_t__ m_nXPos; int m_nZPos; scalar_t__ m_nYPos; } ;
typedef  TYPE_1__ STAR ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int MAX_STARS ; 
 int MB_ICONWARNING ; 
 int MB_OK ; 
 int /*<<< orphan*/  MessageBox (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* RANDOM (int,int) ; 
 int /*<<< orphan*/  RGB (int,int,int) ; 
 int /*<<< orphan*/  SetPixel (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 long m_nCenterX ; 
 long m_nCenterY ; 
 int m_nTotStars ; 
 scalar_t__ malloc (int) ; 
 TYPE_1__* stars ; 

void DrawStarField (HDC pDC)
{
    int nX, nY;
    int i;
    for (i = 0; i < m_nTotStars; i++)
    {
        // Clear last position of this star
        SetPixel (
            pDC,
            stars[i].m_nOldX,
            stars[i].m_nOldY,
            RGB (0, 0, 0));

        nX = (int)((((long)stars[i].m_nXPos << 7) / (long)stars[i].m_nZPos) + m_nCenterX);
        nY = (int)((((long)stars[i].m_nYPos << 7) / (long)stars[i].m_nZPos) + m_nCenterY);

        // Draw star
        SetPixel (
            pDC,
            nX,
            nY,
            RGB (255, 255, 255));

        // Remember current position for clearing later
        stars[i].m_nOldX = nX;
        stars[i].m_nOldY = nY;
    }
}

BOOL SetUpStars (int nNumStars)
{
    int i;
    if (nNumStars > MAX_STARS)
    {
        MessageBox (0,
            _T("Too many stars! Aborting!"),
            _T("Error"),
            MB_OK | MB_ICONWARNING);
        return FALSE;
    }

    if (stars)
        free (stars);

    m_nTotStars = nNumStars;

    stars = (STAR*)malloc(nNumStars * sizeof(STAR));

    if (!stars)
    {
        MessageBox (0,
            _T("Unable to allocate memory! Aborting!"),
            _T("Error"),
            MB_OK | MB_ICONWARNING);
        return FALSE;
    }

    for (i = 0; i < m_nTotStars; i++)
    {
        do
        {
            stars[i].m_nXPos = RANDOM (-320, 320);
            stars[i].m_nYPos = RANDOM (-200, 200);
            stars[i].m_nZPos = i+1;
            stars[i].m_nOldX = -1;
            stars[i].m_nOldY = -1;
        } while ((stars[i].m_nXPos == 0) || (stars[i].m_nYPos == 0));
    }
    return TRUE;
}

void MoveStarField (int nXofs, int nYofs, int nZofs)
{
    int i;
    for (i = 0; i < m_nTotStars; i++)
    {
        stars[i].m_nXPos += nXofs;
        stars[i].m_nYPos += nYofs;
        stars[i].m_nZPos += nZofs;

        if (stars[i].m_nZPos > m_nTotStars)
            stars[i].m_nZPos -= m_nTotStars;
        if (stars[i].m_nZPos < 1)
            stars[i].m_nZPos += m_nTotStars;
    }
}

void SetDimensions (int nWidth, int nHeight)
{
    m_nCenterX = nWidth / 2;
    m_nCenterY = nHeight / 2;
}

