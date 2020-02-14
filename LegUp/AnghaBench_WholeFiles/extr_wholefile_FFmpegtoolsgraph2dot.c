#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct line {int /*<<< orphan*/  data; struct line* next; } ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  filter_ctx_label ;
typedef  int /*<<< orphan*/  dst_filter_ctx_label ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_17__ {char* name; int nb_outputs; TYPE_1__* filter; TYPE_4__** outputs; } ;
struct TYPE_16__ {int nb_filters; TYPE_6__** filters; } ;
struct TYPE_13__ {int num; int den; } ;
struct TYPE_15__ {scalar_t__ type; int w; int h; int sample_rate; TYPE_2__ time_base; int /*<<< orphan*/  format; int /*<<< orphan*/  channel_layout; int /*<<< orphan*/  dstpad; int /*<<< orphan*/  srcpad; TYPE_6__* dst; } ;
struct TYPE_14__ {char* name; } ;
struct TYPE_12__ {char* name; } ;
typedef  int /*<<< orphan*/  FILE ;
typedef  TYPE_3__ AVPixFmtDescriptor ;
typedef  TYPE_4__ AVFilterLink ;
typedef  TYPE_5__ AVFilterGraph ;
typedef  TYPE_6__ AVFilterContext ;

/* Variables and functions */
 scalar_t__ AVMEDIA_TYPE_AUDIO ; 
 scalar_t__ AVMEDIA_TYPE_VIDEO ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  av_get_channel_layout_string (char*,int,int,int /*<<< orphan*/ ) ; 
 char* av_get_sample_fmt_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_log_set_level (int /*<<< orphan*/ ) ; 
 void* av_malloc (int) ; 
 TYPE_5__* av_mallocz (int) ; 
 TYPE_3__* av_pix_fmt_desc_get (int /*<<< orphan*/ ) ; 
 scalar_t__ avfilter_graph_config (TYPE_5__*,int /*<<< orphan*/ *) ; 
 scalar_t__ avfilter_graph_parse (TYPE_5__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* avfilter_pad_get_name (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ *) ; 
 scalar_t__ fgets (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 char getopt (int,char**,char*) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,size_t) ; 
 char* optarg ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char*) ; 
 int /*<<< orphan*/ * stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char* strerror (int /*<<< orphan*/ ) ; 
 int strlen (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void usage(void)
{
    printf("Convert a libavfilter graph to a dot file.\n");
    printf("Usage: graph2dot [OPTIONS]\n");
    printf("\n"
           "Options:\n"
           "-i INFILE         set INFILE as input file, stdin if omitted\n"
           "-o OUTFILE        set OUTFILE as output file, stdout if omitted\n"
           "-h                print this help\n");
}

__attribute__((used)) static void print_digraph(FILE *outfile, AVFilterGraph *graph)
{
    int i, j;

    fprintf(outfile, "digraph G {\n");
    fprintf(outfile, "node [shape=box]\n");
    fprintf(outfile, "rankdir=LR\n");

    for (i = 0; i < graph->nb_filters; i++) {
        char filter_ctx_label[128];
        const AVFilterContext *filter_ctx = graph->filters[i];

        snprintf(filter_ctx_label, sizeof(filter_ctx_label), "%s\\n(%s)",
                 filter_ctx->name,
                 filter_ctx->filter->name);

        for (j = 0; j < filter_ctx->nb_outputs; j++) {
            AVFilterLink *link = filter_ctx->outputs[j];
            if (link) {
                char dst_filter_ctx_label[128];
                const AVFilterContext *dst_filter_ctx = link->dst;

                snprintf(dst_filter_ctx_label, sizeof(dst_filter_ctx_label),
                         "%s\\n(%s)",
                         dst_filter_ctx->name,
                         dst_filter_ctx->filter->name);

                fprintf(outfile, "\"%s\" -> \"%s\" [ label= \"inpad:%s -> outpad:%s\\n",
                        filter_ctx_label, dst_filter_ctx_label,
                        avfilter_pad_get_name(link->srcpad, 0),
                        avfilter_pad_get_name(link->dstpad, 0));

                if (link->type == AVMEDIA_TYPE_VIDEO) {
                    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(link->format);
                    fprintf(outfile,
                            "fmt:%s w:%d h:%d tb:%d/%d",
                            desc->name,
                            link->w, link->h,
                            link->time_base.num, link->time_base.den);
                } else if (link->type == AVMEDIA_TYPE_AUDIO) {
                    char buf[255];
                    av_get_channel_layout_string(buf, sizeof(buf), -1,
                                                 link->channel_layout);
                    fprintf(outfile,
                            "fmt:%s sr:%d cl:%s tb:%d/%d",
                            av_get_sample_fmt_name(link->format),
                            link->sample_rate, buf,
                            link->time_base.num, link->time_base.den);
                }
                fprintf(outfile, "\" ];\n");
            }
        }
    }
    fprintf(outfile, "}\n");
}

int main(int argc, char **argv)
{
    const char *outfilename = NULL;
    const char *infilename  = NULL;
    FILE *outfile           = NULL;
    FILE *infile            = NULL;
    char *graph_string      = NULL;
    AVFilterGraph *graph = av_mallocz(sizeof(AVFilterGraph));
    char c;

    av_log_set_level(AV_LOG_DEBUG);

    while ((c = getopt(argc, argv, "hi:o:")) != -1) {
        switch (c) {
        case 'h':
            usage();
            return 0;
        case 'i':
            infilename = optarg;
            break;
        case 'o':
            outfilename = optarg;
            break;
        case '?':
            return 1;
        }
    }

    if (!infilename || !strcmp(infilename, "-"))
        infilename = "/dev/stdin";
    infile = fopen(infilename, "r");
    if (!infile) {
        fprintf(stderr, "Failed to open input file '%s': %s\n",
                infilename, strerror(errno));
        return 1;
    }

    if (!outfilename || !strcmp(outfilename, "-"))
        outfilename = "/dev/stdout";
    outfile = fopen(outfilename, "w");
    if (!outfile) {
        fprintf(stderr, "Failed to open output file '%s': %s\n",
                outfilename, strerror(errno));
        return 1;
    }

    /* read from infile and put it in a buffer */
    {
        int64_t count = 0;
        struct line *line, *last_line, *first_line;
        char *p;
        last_line = first_line = av_malloc(sizeof(struct line));
        if (!last_line) {
            fprintf(stderr, "Memory allocation failure\n");
            return 1;
        }

        while (fgets(last_line->data, sizeof(last_line->data), infile)) {
            struct line *new_line = av_malloc(sizeof(struct line));
            if (!new_line) {
                fprintf(stderr, "Memory allocation failure\n");
                return 1;
            }
            count += strlen(last_line->data);
            last_line->next = new_line;
            last_line       = new_line;
        }
        last_line->next = NULL;

        graph_string = av_malloc(count + 1);
        if (!graph_string) {
            fprintf(stderr, "Memory allocation failure\n");
            return 1;
        }
        p = graph_string;
        for (line = first_line; line->next; line = line->next) {
            size_t l = strlen(line->data);
            memcpy(p, line->data, l);
            p += l;
        }
        *p = '\0';
    }

    if (avfilter_graph_parse(graph, graph_string, NULL, NULL, NULL) < 0) {
        fprintf(stderr, "Failed to parse the graph description\n");
        return 1;
    }

    if (avfilter_graph_config(graph, NULL) < 0)
        return 1;

    print_digraph(outfile, graph);
    fflush(outfile);

    return 0;
}

