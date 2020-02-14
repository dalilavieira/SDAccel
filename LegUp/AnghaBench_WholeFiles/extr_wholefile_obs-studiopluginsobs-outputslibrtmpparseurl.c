#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int av_len; char* av_val; } ;
typedef  TYPE_1__ AVal ;

/* Variables and functions */
 int FALSE ; 
 int /*<<< orphan*/  RTMP_LOGDEBUG ; 
 int /*<<< orphan*/  RTMP_LOGERROR ; 
 int /*<<< orphan*/  RTMP_LOGWARNING ; 
 int /*<<< orphan*/  RTMP_Log (int /*<<< orphan*/ ,char*,...) ; 
 int RTMP_PROTOCOL_RTMFP ; 
 int RTMP_PROTOCOL_RTMP ; 
 int RTMP_PROTOCOL_RTMPE ; 
 int RTMP_PROTOCOL_RTMPS ; 
 int RTMP_PROTOCOL_RTMPT ; 
 int RTMP_PROTOCOL_RTMPTE ; 
 int RTMP_PROTOCOL_RTMPTS ; 
 int TRUE ; 
 unsigned int atoi (char*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  sscanf (char*,char*,unsigned int*) ; 
 void* strchr (char const*,char) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char const*) ; 
 scalar_t__ strncasecmp (char const*,char*,int) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 void* strstr (char const*,char*) ; 

int RTMP_ParseURL(const char *url, int *protocol, AVal *host, unsigned int *port,
                  AVal *app)
{
    char *p, *end, *col, /* *ques, */ *slash, *v6;

    RTMP_Log(RTMP_LOGDEBUG, "Parsing...");

    *protocol = RTMP_PROTOCOL_RTMP;
    *port = 0;
    app->av_len = 0;
    app->av_val = NULL;

    /* Old School Parsing */

    /* look for usual :// pattern */
    p = strstr(url, "://");
    if(!p)
    {
        RTMP_Log(RTMP_LOGERROR, "RTMP URL: No :// in url!");
        return FALSE;
    }
    {
        int len = (int)(p-url);

        if(len == 4 && strncasecmp(url, "rtmp", 4)==0)
            *protocol = RTMP_PROTOCOL_RTMP;
        else if(len == 5 && strncasecmp(url, "rtmpt", 5)==0)
            *protocol = RTMP_PROTOCOL_RTMPT;
        else if(len == 5 && strncasecmp(url, "rtmps", 5)==0)
            *protocol = RTMP_PROTOCOL_RTMPS;
        else if(len == 5 && strncasecmp(url, "rtmpe", 5)==0)
            *protocol = RTMP_PROTOCOL_RTMPE;
        else if(len == 5 && strncasecmp(url, "rtmfp", 5)==0)
            *protocol = RTMP_PROTOCOL_RTMFP;
        else if(len == 6 && strncasecmp(url, "rtmpte", 6)==0)
            *protocol = RTMP_PROTOCOL_RTMPTE;
        else if(len == 6 && strncasecmp(url, "rtmpts", 6)==0)
            *protocol = RTMP_PROTOCOL_RTMPTS;
        else
        {
            RTMP_Log(RTMP_LOGWARNING, "Unknown protocol!\n");
            goto parsehost;
        }
    }

    RTMP_Log(RTMP_LOGDEBUG, "Parsed protocol: %d", *protocol);

parsehost:
    /* let's get the hostname */
    p+=3;

    /* check for sudden death */
    if(*p==0)
    {
        RTMP_Log(RTMP_LOGWARNING, "No hostname in URL!");
        return FALSE;
    }

    end   = p + strlen(p);
    v6    = strchr(p, ']');
    // ques  = strchr(p, '?');
    slash = strchr(p, '/');
    col   = strchr((v6 && v6 < slash) ? v6 : p, ':');

    {
        int hostlen;
        if(slash)
            hostlen = slash - p;
        else
            hostlen = end - p;
        if(col && col -p < hostlen)
            hostlen = col - p;

        if(hostlen < 256)
        {
            host->av_val = p;
            host->av_len = hostlen;
            RTMP_Log(RTMP_LOGDEBUG, "Parsed host    : %.*s", hostlen, host->av_val);
        }
        else
        {
            RTMP_Log(RTMP_LOGWARNING, "Hostname exceeds 255 characters!");
        }

        p+=hostlen;
    }

    /* get the port number if available */
    if(*p == ':')
    {
        unsigned int p2;
        p++;
        p2 = atoi(p);
        if(p2 > 65535)
        {
            RTMP_Log(RTMP_LOGWARNING, "Invalid port number!");
        }
        else
        {
            *port = p2;
        }
    }

    if(!slash)
    {
        RTMP_Log(RTMP_LOGWARNING, "No application or playpath in URL!");
        return TRUE;
    }
    p = slash+1;

    //just..  whatever.
    app->av_val = p;
    app->av_len = (int)strlen(p);

    if(app->av_len && p[app->av_len-1] == '/')
        app->av_len--;

    RTMP_Log(RTMP_LOGDEBUG, "Parsed app     : %.*s", app->av_len, p);
    p += app->av_len;

    if (*p == '/')
        p++;

    return TRUE;
}

void RTMP_ParsePlaypath(AVal *in, AVal *out)
{
    int addMP4 = 0;
    int addMP3 = 0;
    int subExt = 0;
    const char *playpath = in->av_val;
    const char *temp, *q, *ext = NULL;
    const char *ppstart = playpath;
    char *streamname, *destptr, *p;

    int pplen = in->av_len;

    out->av_val = NULL;
    out->av_len = 0;

    if (!playpath)
        return;

    if ((*ppstart == '?') &&
            (temp=strstr(ppstart, "slist=")) != 0)
    {
        ppstart = temp+6;
        pplen = (int)strlen(ppstart);

        temp = strchr(ppstart, '&');
        if (temp)
        {
            pplen = temp-ppstart;
        }
    }

    q = strchr(ppstart, '?');
    if (pplen >= 4)
    {
        if (q)
            ext = q-4;
        else
            ext = &ppstart[pplen-4];
        if ((strncmp(ext, ".f4v", 4) == 0) ||
                (strncmp(ext, ".mp4", 4) == 0))
        {
            addMP4 = 1;
            subExt = 1;
            /* Only remove .flv from rtmp URL, not slist params */
        }
        else if ((ppstart == playpath) &&
                 (strncmp(ext, ".flv", 4) == 0))
        {
            subExt = 1;
        }
        else if (strncmp(ext, ".mp3", 4) == 0)
        {
            addMP3 = 1;
            subExt = 1;
        }
    }

    streamname = (char *)malloc((pplen+4+1)*sizeof(char));
    if (!streamname)
        return;

    destptr = streamname;
    if (addMP4)
    {
        if (strncmp(ppstart, "mp4:", 4))
        {
            strcpy(destptr, "mp4:");
            destptr += 4;
        }
        else
        {
            subExt = 0;
        }
    }
    else if (addMP3)
    {
        if (strncmp(ppstart, "mp3:", 4))
        {
            strcpy(destptr, "mp3:");
            destptr += 4;
        }
        else
        {
            subExt = 0;
        }
    }

    for (p=(char *)ppstart; pplen >0;)
    {
        /* skip extension */
        if (subExt && p == ext)
        {
            p += 4;
            pplen -= 4;
            continue;
        }
        if (*p == '%')
        {
            unsigned int c;
            sscanf(p+1, "%02x", &c);
            *destptr++ = c;
            pplen -= 3;
            p += 3;
        }
        else
        {
            *destptr++ = *p++;
            pplen--;
        }
    }
    *destptr = '\0';

    out->av_val = streamname;
    out->av_len = destptr - streamname;
}

