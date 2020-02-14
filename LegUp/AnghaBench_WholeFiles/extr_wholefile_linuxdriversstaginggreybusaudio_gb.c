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
typedef  void* u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct gb_operation {int flags; void* private; } ;
struct gb_connection {int dummy; } ;
struct gb_audio_topology {int dummy; } ;
struct gb_audio_set_tx_data_size_request {void* size; void* data_cport; } ;
struct gb_audio_set_rx_data_size_request {void* size; void* data_cport; } ;
struct gb_audio_set_pcm_request {void* sig_bits; void* channels; void* rate; void* format; void* data_cport; } ;
struct gb_audio_ctl_elem_value {int dummy; } ;
struct gb_audio_set_control_request {struct gb_audio_ctl_elem_value value; void* index; void* control_id; } ;
struct gb_audio_get_topology_size_response {int /*<<< orphan*/  size; } ;
struct gb_audio_get_pcm_response {void* sig_bits; void* channels; int /*<<< orphan*/  rate; int /*<<< orphan*/  format; } ;
struct gb_audio_get_pcm_request {void* data_cport; } ;
struct gb_audio_get_control_response {struct gb_audio_ctl_elem_value value; } ;
struct gb_audio_get_control_request {void* index; void* control_id; } ;
struct gb_audio_enable_widget_request {void* widget_id; } ;
struct gb_audio_disable_widget_request {void* widget_id; } ;
struct gb_audio_deactivate_tx_request {void* data_cport; } ;
struct gb_audio_deactivate_rx_request {void* data_cport; } ;
struct gb_audio_activate_tx_request {void* data_cport; } ;
struct gb_audio_activate_rx_request {void* data_cport; } ;
typedef  int /*<<< orphan*/  size_resp ;
typedef  int /*<<< orphan*/  resp ;
typedef  int /*<<< orphan*/  req ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int ENODATA ; 
 int ENOMEM ; 
 int GB_AUDIO_TYPE_ACTIVATE_RX ; 
 int GB_AUDIO_TYPE_ACTIVATE_TX ; 
 int GB_AUDIO_TYPE_DEACTIVATE_RX ; 
 int GB_AUDIO_TYPE_DEACTIVATE_TX ; 
 int GB_AUDIO_TYPE_DISABLE_WIDGET ; 
 int GB_AUDIO_TYPE_ENABLE_WIDGET ; 
 int GB_AUDIO_TYPE_GET_CONTROL ; 
 int GB_AUDIO_TYPE_GET_PCM ; 
 int GB_AUDIO_TYPE_GET_TOPOLOGY ; 
 int GB_AUDIO_TYPE_GET_TOPOLOGY_SIZE ; 
 int GB_AUDIO_TYPE_SET_CONTROL ; 
 int GB_AUDIO_TYPE_SET_PCM ; 
 int GB_AUDIO_TYPE_SET_RX_DATA_SIZE ; 
 int GB_AUDIO_TYPE_SET_TX_DATA_SIZE ; 
 int GB_OPERATION_FLAG_CORE ; 
 int GB_OPERATION_FLAG_INCOMING ; 
 int GB_OPERATION_FLAG_SHORT_RESPONSE ; 
 int GB_OPERATION_FLAG_UNIDIRECTIONAL ; 
 int /*<<< orphan*/  GB_OPERATION_TIMEOUT_DEFAULT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* cpu_to_le16 (int) ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 struct gb_operation* gb_operation_create_flags (struct gb_connection*,void*,size_t,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gb_operation_request_send_sync_timeout (struct gb_operation*,int /*<<< orphan*/ ) ; 
 int gb_operation_sync_timeout (struct gb_connection*,int,void*,int,void*,int,int /*<<< orphan*/ ) ; 
 int gb_operation_unidirectional_timeout (struct gb_connection*,int,void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct gb_audio_topology*) ; 
 struct gb_audio_topology* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct gb_audio_ctl_elem_value*,struct gb_audio_ctl_elem_value*,int) ; 

__attribute__((used)) static inline bool
gb_operation_is_incoming(struct gb_operation *operation)
{
	return operation->flags & GB_OPERATION_FLAG_INCOMING;
}

__attribute__((used)) static inline bool
gb_operation_is_unidirectional(struct gb_operation *operation)
{
	return operation->flags & GB_OPERATION_FLAG_UNIDIRECTIONAL;
}

__attribute__((used)) static inline bool
gb_operation_short_response_allowed(struct gb_operation *operation)
{
	return operation->flags & GB_OPERATION_FLAG_SHORT_RESPONSE;
}

__attribute__((used)) static inline bool gb_operation_is_core(struct gb_operation *operation)
{
	return operation->flags & GB_OPERATION_FLAG_CORE;
}

__attribute__((used)) static inline struct gb_operation *
gb_operation_create(struct gb_connection *connection,
				u8 type, size_t request_size,
				size_t response_size, gfp_t gfp)
{
	return gb_operation_create_flags(connection, type, request_size,
						response_size, 0, gfp);
}

__attribute__((used)) static inline int
gb_operation_request_send_sync(struct gb_operation *operation)
{
	return gb_operation_request_send_sync_timeout(operation,
			GB_OPERATION_TIMEOUT_DEFAULT);
}

__attribute__((used)) static inline int gb_operation_sync(struct gb_connection *connection, int type,
		      void *request, int request_size,
		      void *response, int response_size)
{
	return gb_operation_sync_timeout(connection, type,
			request, request_size, response, response_size,
			GB_OPERATION_TIMEOUT_DEFAULT);
}

__attribute__((used)) static inline int gb_operation_unidirectional(struct gb_connection *connection,
				int type, void *request, int request_size)
{
	return gb_operation_unidirectional_timeout(connection, type,
			request, request_size, GB_OPERATION_TIMEOUT_DEFAULT);
}

__attribute__((used)) static inline void *gb_operation_get_data(struct gb_operation *operation)
{
	return operation->private;
}

__attribute__((used)) static inline void gb_operation_set_data(struct gb_operation *operation,
					 void *data)
{
	operation->private = data;
}

int gb_audio_gb_get_topology(struct gb_connection *connection,
			     struct gb_audio_topology **topology)
{
	struct gb_audio_get_topology_size_response size_resp;
	struct gb_audio_topology *topo;
	u16 size;
	int ret;

	ret = gb_operation_sync(connection, GB_AUDIO_TYPE_GET_TOPOLOGY_SIZE,
				NULL, 0, &size_resp, sizeof(size_resp));
	if (ret)
		return ret;

	size = le16_to_cpu(size_resp.size);
	if (size < sizeof(*topo))
		return -ENODATA;

	topo = kzalloc(size, GFP_KERNEL);
	if (!topo)
		return -ENOMEM;

	ret = gb_operation_sync(connection, GB_AUDIO_TYPE_GET_TOPOLOGY, NULL, 0,
				topo, size);
	if (ret) {
		kfree(topo);
		return ret;
	}

	*topology = topo;

	return 0;
}

int gb_audio_gb_get_control(struct gb_connection *connection,
			    u8 control_id, u8 index,
			    struct gb_audio_ctl_elem_value *value)
{
	struct gb_audio_get_control_request req;
	struct gb_audio_get_control_response resp;
	int ret;

	req.control_id = control_id;
	req.index = index;

	ret = gb_operation_sync(connection, GB_AUDIO_TYPE_GET_CONTROL,
				&req, sizeof(req), &resp, sizeof(resp));
	if (ret)
		return ret;

	memcpy(value, &resp.value, sizeof(*value));

	return 0;
}

int gb_audio_gb_set_control(struct gb_connection *connection,
			    u8 control_id, u8 index,
			    struct gb_audio_ctl_elem_value *value)
{
	struct gb_audio_set_control_request req;

	req.control_id = control_id;
	req.index = index;
	memcpy(&req.value, value, sizeof(req.value));

	return gb_operation_sync(connection, GB_AUDIO_TYPE_SET_CONTROL,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_enable_widget(struct gb_connection *connection,
			      u8 widget_id)
{
	struct gb_audio_enable_widget_request req;

	req.widget_id = widget_id;

	return gb_operation_sync(connection, GB_AUDIO_TYPE_ENABLE_WIDGET,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_disable_widget(struct gb_connection *connection,
			       u8 widget_id)
{
	struct gb_audio_disable_widget_request req;

	req.widget_id = widget_id;

	return gb_operation_sync(connection, GB_AUDIO_TYPE_DISABLE_WIDGET,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_get_pcm(struct gb_connection *connection, u16 data_cport,
			u32 *format, u32 *rate, u8 *channels,
			u8 *sig_bits)
{
	struct gb_audio_get_pcm_request req;
	struct gb_audio_get_pcm_response resp;
	int ret;

	req.data_cport = cpu_to_le16(data_cport);

	ret = gb_operation_sync(connection, GB_AUDIO_TYPE_GET_PCM,
				&req, sizeof(req), &resp, sizeof(resp));
	if (ret)
		return ret;

	*format = le32_to_cpu(resp.format);
	*rate = le32_to_cpu(resp.rate);
	*channels = resp.channels;
	*sig_bits = resp.sig_bits;

	return 0;
}

int gb_audio_gb_set_pcm(struct gb_connection *connection, u16 data_cport,
			u32 format, u32 rate, u8 channels,
			u8 sig_bits)
{
	struct gb_audio_set_pcm_request req;

	req.data_cport = cpu_to_le16(data_cport);
	req.format = cpu_to_le32(format);
	req.rate = cpu_to_le32(rate);
	req.channels = channels;
	req.sig_bits = sig_bits;

	return gb_operation_sync(connection, GB_AUDIO_TYPE_SET_PCM,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_set_tx_data_size(struct gb_connection *connection,
				 u16 data_cport, u16 size)
{
	struct gb_audio_set_tx_data_size_request req;

	req.data_cport = cpu_to_le16(data_cport);
	req.size = cpu_to_le16(size);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_SET_TX_DATA_SIZE,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_activate_tx(struct gb_connection *connection,
			    u16 data_cport)
{
	struct gb_audio_activate_tx_request req;

	req.data_cport = cpu_to_le16(data_cport);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_ACTIVATE_TX,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_deactivate_tx(struct gb_connection *connection,
			      u16 data_cport)
{
	struct gb_audio_deactivate_tx_request req;

	req.data_cport = cpu_to_le16(data_cport);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_DEACTIVATE_TX,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_set_rx_data_size(struct gb_connection *connection,
				 u16 data_cport, u16 size)
{
	struct gb_audio_set_rx_data_size_request req;

	req.data_cport = cpu_to_le16(data_cport);
	req.size = cpu_to_le16(size);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_SET_RX_DATA_SIZE,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_activate_rx(struct gb_connection *connection,
			    u16 data_cport)
{
	struct gb_audio_activate_rx_request req;

	req.data_cport = cpu_to_le16(data_cport);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_ACTIVATE_RX,
				 &req, sizeof(req), NULL, 0);
}

int gb_audio_gb_deactivate_rx(struct gb_connection *connection,
			      u16 data_cport)
{
	struct gb_audio_deactivate_rx_request req;

	req.data_cport = cpu_to_le16(data_cport);

	return gb_operation_sync(connection, GB_AUDIO_TYPE_DEACTIVATE_RX,
				 &req, sizeof(req), NULL, 0);
}

