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
struct sd {TYPE_1__* opts; } ;
struct buffer {char* string; scalar_t__ pos; int length; } ;
struct TYPE_2__ {int sub_filter_SDH_harder; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_VERBOSE (struct sd*,char*) ; 
 scalar_t__ mp_isalpha (char) ; 
 scalar_t__ mp_isdigit (char) ; 
 scalar_t__ mp_isupper (char) ; 
 int strlen (char*) ; 
 scalar_t__ strncasecmp (char*,char*,int) ; 
 int /*<<< orphan*/  talloc_free (char*) ; 
 char* talloc_size (int /*<<< orphan*/ *,int) ; 
 char* talloc_strdup (int /*<<< orphan*/ *,char*) ; 
 char* talloc_strndup (int /*<<< orphan*/ *,char*,int) ; 

__attribute__((used)) static void init_buf(struct buffer *buf, int length)
{
    buf->string = talloc_size(NULL, length);
    buf->pos = 0;
    buf->length = length;
}

__attribute__((used)) static inline int append(struct sd *sd, struct buffer *buf, char c)
{
    if (buf->pos >= 0 && buf->pos < buf->length) {
        buf->string[buf->pos++] = c;
    } else {
        // ensure that terminating \0 is always written
        if (c == '\0')
            buf->string[buf->length - 1] = c;
    }
    return c;
}

__attribute__((used)) static void copy_ass(struct sd *sd, char **rpp, struct buffer *buf)
{
    char *rp = *rpp;

    while (rp[0] == '{') {
        while (*rp) {
            char tmp = append(sd, buf, rp[0]);
            rp++;
            if (tmp == '}')
                break;
        }
    }
    *rpp = rp;

    return;
}

__attribute__((used)) static void skip_speaker_label(struct sd *sd, char **rpp, struct buffer *buf)
{
    int filter_harder = sd->opts->sub_filter_SDH_harder;
    char *rp = *rpp;
    int old_pos = buf->pos;

    copy_ass(sd, &rp, buf);
    // copy any leading "- "
    if (rp[0] == '-') {
        append(sd, buf, rp[0]);
        rp++;
    }
    copy_ass(sd, &rp, buf);
    while (rp[0] == ' ') {
        append(sd, buf, rp[0]);
        rp++;
        copy_ass(sd, &rp, buf);
    }
    // skip past valid data searching for :
    while (*rp && rp[0] != ':') {
        if (rp[0] == '{') {
            copy_ass(sd, &rp, buf);
        } else if ((mp_isalpha(rp[0]) &&
                    (filter_harder || mp_isupper(rp[0]) || rp[0] == 'l')) ||
                   mp_isdigit(rp[0]) ||
                   rp[0] == ' ' || rp[0] == '\'' ||
                   (filter_harder && (rp[0] == '(' || rp[0] == ')')) ||
                   rp[0] == '#' || rp[0] == '.' || rp[0] == ',') {
            rp++;
        } else {
            buf->pos = old_pos;
            return;
         }
    }
    if (!*rp) {
        // : was not found
        buf->pos = old_pos;
        return;
    }
    rp++; // skip :
    copy_ass(sd, &rp, buf);
    if (!*rp) {
        // end of data
    } else if (rp[0] == '\\' && rp[1] == 'N') {
        // line end follows - skip it as line is empty
        rp += 2;
    } else if (rp[0] == ' ') {
        while (rp[0] == ' ') {
            rp++;
        }
        if (rp[0] == '\\' && rp[1] == 'N') {
            // line end follows - skip it as line is empty
            rp += 2;
        }
    } else {
        // non space follows - no speaker label
        buf->pos = old_pos;
        return;
    }
    *rpp = rp;

    return;
}

__attribute__((used)) static bool skip_bracketed(struct sd *sd, char **rpp, struct buffer *buf)
{
    char *rp = *rpp;
    int old_pos = buf->pos;

    rp++; // skip past '['
    // skip past valid data searching for ]
    while (*rp && rp[0] != ']') {
        if (rp[0] == '{') {
            copy_ass(sd, &rp, buf);
        } else {
            rp++;
        }
    }
    if (!*rp) {
        // ] was not found
        buf->pos = old_pos;
        return false;
    }
    rp++; // skip ]
    // skip trailing spaces
    while (rp[0] == ' ') {
        rp++;
    }
    *rpp = rp;

    return true;
}

__attribute__((used)) static bool skip_parenthesed(struct sd *sd, char **rpp, struct buffer *buf)
{
    int filter_harder = sd->opts->sub_filter_SDH_harder;
    char *rp = *rpp;
    int old_pos = buf->pos;

    rp++; // skip past '('
    // skip past valid data searching for )
    bool only_digits = true;
    while (*rp && rp[0] != ')') {
        if (rp[0] == '{') {
            copy_ass(sd, &rp, buf);
        } else if ((mp_isalpha(rp[0]) &&
                    (filter_harder || mp_isupper(rp[0]) || rp[0] == 'l')) ||
                   mp_isdigit(rp[0]) ||
                   rp[0] == ' ' || rp[0] == '\'' || rp[0] == '#' ||
                   rp[0] == '.' || rp[0] == ',' ||
                   rp[0] == '-' || rp[0] == '"' || rp[0] == '\\') {
            if (!mp_isdigit(rp[0]))
                only_digits = false;
            rp++;
        } else {
            buf->pos = old_pos;
            return false;
        }
    }
    if (!*rp) {
        // ) was not found
        buf->pos = old_pos;
        return false;
    }
    if (only_digits) {
        // number within parentheses is probably not SDH
        buf->pos = old_pos;
        return false;
    }
    rp++; // skip )
    // skip trailing spaces
    while (rp[0] == ' ') {
        rp++;
    }
    *rpp = rp;

    return true;
}

__attribute__((used)) static void remove_leading_hyphen_space(struct sd *sd, int start_pos, struct buffer *buf)
{
    int old_pos = buf->pos;
    if (start_pos < 0 || start_pos >= old_pos)
        return; 
    append(sd, buf, '\0');  // \0 terminate for reading

    // move past leading ass tags
    while (buf->string[start_pos] == '{') {
        while (buf->string[start_pos] && buf->string[start_pos] != '}') {
            start_pos++;
        }
        if (buf->string[start_pos])
            start_pos++; // skip past '}'
    }

    // if there is not a leading '-' no removing will be done
    if (buf->string[start_pos] != '-') {
        buf->pos = old_pos;
        return;
    }

    char *rp = &buf->string[start_pos];  // read from here
    buf->pos = start_pos; // start writing here
    rp++; // skip '-'
    copy_ass(sd, &rp, buf);
    while (rp[0] == ' ') {
        rp++; // skip ' '
        copy_ass(sd, &rp, buf);
    }
    while (*rp) {
        // copy the rest
        append(sd, buf, rp[0]);
        rp++;
    }
}

char *filter_SDH(struct sd *sd, char *format, int n_ignored, char *data, int length)
{
    if (!format) {
        MP_VERBOSE(sd, "SDH filtering not possible - format missing\n");
        return length ? talloc_strndup(NULL, data, length) : talloc_strdup(NULL, data);
    }

    // need null terminated string
    char *ass = length ? talloc_strndup(NULL, data, length) : data;

    int comma = 0;
    // scan format line to find the number of the field where the text is
    for (char *c = format; *c; c++) {
        if (*c == ',') {
            comma++;
            if (strncasecmp(c + 1, "Text", 4) == 0)
                break;
        }
    }
    // if preprocessed line some fields are skipped
    comma -= n_ignored;

    struct buffer writebuf;
    struct buffer *buf = &writebuf;

    init_buf(buf, strlen(ass) + 1); // with room for terminating '\0'

    char *rp = ass;

    // locate text field in ASS line
    for (int k = 0; k < comma; k++) {
        while (*rp) {
            char tmp = append(sd, buf, rp[0]);
            rp++;
            if (tmp == ',')
                break;
        }
    }
    if (!*rp) {
        talloc_free(buf->string);
        MP_VERBOSE(sd, "SDH filtering not possible - cannot find text field\n");
        return length ? ass : talloc_strdup(NULL, ass);
    }

    bool contains_text = false;  // true if non SDH text was found
    bool line_with_text = false; // if last line contained text
    int wp_line_start = buf->pos; // write pos to start of last line
    int wp_line_end   = buf->pos; // write pos to end of previous line with text (\N)

    // go through the lines in the text
    // they are separated by \N
    while (*rp) {
        line_with_text = false;
        wp_line_start = buf->pos;

        // skip any speaker label
        skip_speaker_label(sd, &rp, buf);

        // go through the rest of the line looking for SDH in () or []
        while (*rp && !(rp[0] == '\\' && rp[1] == 'N')) {
            copy_ass(sd, &rp, buf);
            if (rp[0] == '[') {
                if (!skip_bracketed(sd, &rp, buf)) {
                    append(sd, buf, rp[0]);
                    rp++;
                    line_with_text =  true;
                }
            } else if (rp[0] == '(') {
                if (!skip_parenthesed(sd, &rp, buf)) {
                    append(sd, buf, rp[0]);
                    rp++;
                    line_with_text =  true;
                }
            } else if (*rp && rp[0] != '\\') {
                if ((rp[0] > 32 && rp[0] < 127 && rp[0] != '-') ||
                    (unsigned char)rp[0] >= 0xC0)
                {
                    line_with_text =  true;
                }
                append(sd, buf, rp[0]);
                rp++;
            } else if (rp[0] == '\\' && rp[1] != 'N') {
                append(sd, buf, rp[0]);
                rp++;
            }
        }
        // either end of data or ASS line end defined by separating \N
        if (*rp) {
            // ASS line end
            if (line_with_text) {
                contains_text = true;
                wp_line_end = buf->pos;
                append(sd, buf, rp[0]); // copy backslash
                append(sd, buf, rp[1]); // copy N
                rp += 2; // move read pointer past \N
            } else {
                // no text in line, remove leading hyphen and spaces
                remove_leading_hyphen_space(sd, wp_line_start, buf);
                // and join with next line
                rp += 2; // move read pointer past \N
            }
        }
    }
    // if no normal text i last line - remove last line
    // by moving write pointer to start of last line
    if (!line_with_text) {
        buf->pos = wp_line_end;
    } else {
        contains_text = true;
    }
    if (length)
        talloc_free(ass);
    if (contains_text) {
        // the ASS data contained normal text after filtering
        append(sd, buf, '\0'); // '\0' terminate
        return buf->string;
    } else {
        // all data removed by filtering
        talloc_free(buf->string);
        return NULL;
    }
}

