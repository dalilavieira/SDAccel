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
typedef  scalar_t__ WORD ;
typedef  int TCHAR ;
typedef  int* LPTSTR ;
typedef  scalar_t__ INT ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 unsigned int CCHMAXPATHCOMP ; 
 int CHAR_BACKSLASH ; 
 int CHAR_COLON ; 
#define  CHAR_DOT 130 
 int CHAR_DQUOTE ; 
 int CHAR_GREATER ; 
 int CHAR_LESS ; 
 int CHAR_NULL ; 
 int CHAR_PIPE ; 
#define  CHAR_QUESTION 129 
 int CHAR_SLASH ; 
 int CHAR_SPACE ; 
#define  CHAR_STAR 128 
 int DOT ; 
 scalar_t__ ERROR_INVALID_PARAMETER ; 
 scalar_t__ LFNCANON_MASK ; 
 scalar_t__ NO_ERROR ; 
 scalar_t__ isalpha (int) ; 

DWORD
I_LFNCanon(WORD CanonType, LPTSTR InFile, LPTSTR OutFile)
{
   LPTSTR       ins = InFile;
   LPTSTR       outs = OutFile;
   unsigned    size;
   unsigned    trails;
   TCHAR        c;

   if (!InFile || !OutFile)
      return ERROR_INVALID_PARAMETER;

   if (*InFile == CHAR_NULL)
      return ERROR_INVALID_PARAMETER;


   /* First, check if we have a fully qualified name, or a relative name */
   if (*InFile != CHAR_BACKSLASH && *InFile != CHAR_SLASH) {
      if (isalpha(*InFile)) {
         if (InFile[1] == CHAR_COLON) {
            *outs++ = *ins++;
            *outs++ = *ins++;     // Copy over the drive and colon
         }
      }
   } else {
      ins++;
      *outs++ = CHAR_BACKSLASH;
   }

   /*  Note:  When calculating size, we ignore the d:\ that may appear.  This
    *  is because that is not considered part of the path by OS/2.  IT IS THE
    *  RESPONSIBILITY OF THE CALLING FUNCTION TO RESERVE ENOUGH SPACE FOR THE
    *  CANON NAME, WHICH CAN BE EITHER 256 or 260.
    */

   size = 0;
   do {
      c = *ins++;
      if ((c < 0x001f && c != CHAR_NULL) || (c == CHAR_DQUOTE) || (c == CHAR_COLON) || (c == CHAR_PIPE) ||
          (c == CHAR_GREATER) || (c == CHAR_LESS)) {
             *OutFile = CHAR_NULL;
             return ERROR_INVALID_PARAMETER;
      }
      if (CanonType != LFNCANON_MASK && ((c == CHAR_STAR) || (c == CHAR_QUESTION))) {
         *OutFile = CHAR_NULL;
         return ERROR_INVALID_PARAMETER;
      }
      if (c == CHAR_SLASH)
         c = CHAR_BACKSLASH;       // Convert / to \ for canon

      if (c == CHAR_BACKSLASH || c == CHAR_NULL) {   // Component separator:  Trim file name

         /*  We have to special case . and ..   . we resolve, but .. we pass
          *  through.
          */
         if (outs > OutFile) {
            if (*(outs - 1) == CHAR_DOT) {
               if  ((outs - 1) == OutFile || *(outs - 2) == CHAR_BACKSLASH) {   // Single dot
                  *(outs--) = c;
                  if (size)
                     size--;
                  continue;
               }
               if (*(outs - 2) == CHAR_DOT) {     // Possible ..
                  if ((outs - 2) == OutFile || *(outs - 3) == CHAR_BACKSLASH ||
                        *(outs - 3) == CHAR_COLON) {
                     *outs++ = c;
                     size++;
                     continue;
                  }
               }
            }
         }

         /*  Okay, the component is neither a . nor a .. so we go into trim
          *  trailing dots and spaces mode.
          */
         trails = 0;
         while (outs > OutFile && ((*(outs-1) == CHAR_DOT || *(outs-1) == CHAR_SPACE)
                 && (*(outs-1) != CHAR_BACKSLASH && *(outs - 1) != CHAR_COLON)) ) {
            outs--;
            trails++;
            if (size)
               size--;
         }
         if (outs == OutFile) {
            *OutFile = CHAR_NULL;
            return ERROR_INVALID_PARAMETER;
         }
         if (outs > OutFile && *(outs-1) == CHAR_BACKSLASH) {
            *OutFile = CHAR_NULL;
            return ERROR_INVALID_PARAMETER;
         }
      }
      *outs++ = c;
      size++;
      if (size > CCHMAXPATHCOMP) {
         *OutFile = CHAR_NULL;
         return ERROR_INVALID_PARAMETER;
      }
   } while (c);

   /*  Last check:  We don't allow paths to end in \ or /.  Since / has been
    *  mapped to \, we just check for \
    */
   if (outs != OutFile)
      if (*(outs-1) == CHAR_BACKSLASH) {
         *OutFile = CHAR_NULL;
         return ERROR_INVALID_PARAMETER;
      }

   return 0;

}

WORD I_LFNEditName( LPTSTR lpSrc, LPTSTR lpEd, LPTSTR lpRes, INT iResBufSize )
{
   INT ResLen = 0;     // Length of result

// This is turned off until we agree
// that cmd operates in the same way

#ifdef USELASTDOT
   LPTSTR lpChar;

   //
   // We have a special case hack for the dot, since when we do a
   // rename from foo.bar.baz to *.txt, we want to use the last dot, not
   // the first one (desired result = foo.bar.txt, not foo.txt)
   //
   // We find the dot (GetExtension rets first char after last dot if there
   // is a dot), then if the delimiter for the '*' is a CHAR_DOT, we continue
   // copying until we get to the last dot instead of finding the first one.
   //

   lpChar = GetExtension(lpSrc);
   if (*lpChar) {
      lpChar--;
   } else {
      lpChar = NULL;
   }
#endif

   while (*lpEd) {

      if (ResLen < iResBufSize) {

         switch (*lpEd) {

         case CHAR_STAR:
            {
               TCHAR delimit = *(lpEd+1);

#ifdef USELASTDOT

               //
               // For all other delimiters, we use the first
               // occurrence (e.g., *f.txt).
               //
               if (CHAR_DOT != delimit)
                  lpChar = NULL;

               while ((ResLen < iResBufSize) && ( *lpSrc != CHAR_NULL ) &&
                  ( *lpSrc != delimit || (lpChar && lpChar != lpSrc ))) {
#else
               while ((ResLen < iResBufSize) &&
                  ( *lpSrc != CHAR_NULL ) && ( *lpSrc != delimit )) {
#endif

                  *(lpRes++) = *(lpSrc++);
                  ResLen++;

               }
            }
            break;


         case CHAR_QUESTION:
            if ((*lpSrc != DOT ) && (*lpSrc != CHAR_NULL)) {

               if (ResLen < iResBufSize) {

                  *(lpRes++) = *(lpSrc++);
                  ResLen++;
               }
               else
                  return ERROR_INVALID_PARAMETER ;
            }
            break;

         case CHAR_DOT:
            while ((*lpSrc != DOT ) && (*lpSrc != CHAR_NULL))
               lpSrc++;

            *(lpRes++) = DOT ;       // from EditMask, even if src doesn't
                                     // have one, so always put one.
            ResLen++;
            if (*lpSrc)              // point one past CHAR_DOT
               lpSrc++;
               break;

         default:
            if ((*lpSrc != DOT ) && (*lpSrc != CHAR_NULL)) {

               lpSrc++;
            }

            if (ResLen < iResBufSize) {

               *(lpRes++) = *lpEd;
               ResLen++;
            }
            else
               return ERROR_INVALID_PARAMETER ;
            break;
         }
         lpEd++;

      }
      else {

         return ERROR_INVALID_PARAMETER ;
      }
   }

   if ((ResLen) < iResBufSize) {
      *lpRes = CHAR_NULL;
      return NO_ERROR ;
   }
   else
      return ERROR_INVALID_PARAMETER ;
}

