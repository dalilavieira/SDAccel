#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  char uint8_t ;
struct TYPE_13__ {int pts; int dts; char* data; int duration; int pos; int /*<<< orphan*/  flags; void* size; } ;
typedef  TYPE_1__ AVPacket ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PKT_DATA_NEW_EXTRADATA ; 
 int /*<<< orphan*/  AV_PKT_FLAG_DISCARD ; 
 int /*<<< orphan*/  ENOMEM ; 
 int INT_MAX ; 
 char* av_err2str (int) ; 
 scalar_t__ av_grow_packet (TYPE_1__*,int) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_1__*) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 char* av_malloc (int) ; 
 scalar_t__ av_new_packet (TYPE_1__*,int) ; 
 int av_packet_add_side_data (TYPE_1__*,int /*<<< orphan*/ ,char*,int) ; 
 TYPE_1__* av_packet_clone (TYPE_1__*) ; 
 int /*<<< orphan*/  av_packet_free (TYPE_1__**) ; 
 scalar_t__ av_packet_from_data (TYPE_1__*,char*,int) ; 
 char* av_packet_side_data_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_1__*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  stderr ; 
 void* strlen (char const*) ; 

__attribute__((used)) static int setup_side_data_entry(AVPacket* avpkt)
{
    const uint8_t *data_name = NULL;
    int ret = 0, bytes;
    uint8_t *extra_data = NULL;


    /* get side_data_name string */
    data_name = av_packet_side_data_name(AV_PKT_DATA_NEW_EXTRADATA);

    /* Allocate a memory bloc */
    bytes = strlen(data_name);

    if(!(extra_data = av_malloc(bytes))){
        ret = AVERROR(ENOMEM);
        fprintf(stderr, "Error occurred: %s\n", av_err2str(ret));
        exit(1);
    }
    /* copy side_data_name to extra_data array */
    memcpy(extra_data, data_name, bytes);

    /* create side data for AVPacket */
    ret = av_packet_add_side_data(avpkt, AV_PKT_DATA_NEW_EXTRADATA,
                                        extra_data, bytes);
    if(ret < 0){
        fprintf(stderr,
                "Error occurred in av_packet_add_side_data: %s\n",
                av_err2str(ret));
    }

    return ret;
}

__attribute__((used)) static int initializations(AVPacket* avpkt)
{
    const static uint8_t* data = "selftest for av_packet_clone(...)";
    int ret = 0;

    /* initialize avpkt */
    av_init_packet(avpkt);

    /* set values for avpkt */
    avpkt->pts = 17;
    avpkt->dts = 2;
    avpkt->data = (uint8_t*)data;
    avpkt->size = strlen(data);
    avpkt->flags = AV_PKT_FLAG_DISCARD;
    avpkt->duration = 100;
    avpkt->pos = 3;

    ret = setup_side_data_entry(avpkt);

    return ret;
}

int main(void)
{
    AVPacket avpkt;
    AVPacket *avpkt_clone = NULL;
    int ret = 0;

    if(initializations(&avpkt) < 0){
        printf("failed to initialize variables\n");
        return 1;
    }
    /* test av_packet_clone*/
    avpkt_clone = av_packet_clone(&avpkt);

    if(!avpkt_clone) {
        av_log(NULL, AV_LOG_ERROR,"av_packet_clone failed to clone AVPacket\n");
        return 1;
    }
    /*test av_grow_packet*/
    if(av_grow_packet(avpkt_clone, 20) < 0){
        av_log(NULL, AV_LOG_ERROR, "av_grow_packet failed\n");
        return 1;
    }
    if(av_grow_packet(avpkt_clone, INT_MAX) == 0){
        printf( "av_grow_packet failed to return error "
                "when \"grow_by\" parameter is too large.\n" );
        ret = 1;
    }
    /* test size error check in av_new_packet*/
    if(av_new_packet(avpkt_clone, INT_MAX) == 0){
        printf( "av_new_packet failed to return error "
                "when \"size\" parameter is too large.\n" );
        ret = 1;
    }
    /*test size error check in av_packet_from_data*/
    if(av_packet_from_data(avpkt_clone, avpkt_clone->data, INT_MAX) == 0){
        printf("av_packet_from_data failed to return error "
                "when \"size\" parameter is too large.\n" );
        ret = 1;
    }
    /*clean up*/
    av_packet_free(&avpkt_clone);
    av_packet_unref(&avpkt);


    return ret;
}

