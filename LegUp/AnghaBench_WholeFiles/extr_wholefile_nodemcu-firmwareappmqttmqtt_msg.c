#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_50__   TYPE_3__ ;
typedef  struct TYPE_49__   TYPE_2__ ;
typedef  struct TYPE_48__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint16_t ;
struct mqtt_connect_variable_header {int lengthLsb; int* magic; int version; int flags; int keepaliveMsb; int keepaliveLsb; scalar_t__ lengthMsb; } ;
struct TYPE_48__ {scalar_t__ length; int* data; } ;
typedef  TYPE_1__ mqtt_message_t ;
struct TYPE_49__ {scalar_t__ buffer_length; int* buffer; int message_id; TYPE_1__ message; } ;
typedef  TYPE_2__ mqtt_connection_t ;
struct TYPE_50__ {int keepalive; char* client_id; char* will_topic; char* will_message; int will_qos; char* username; char* password; scalar_t__ will_retain; scalar_t__ clean_session; } ;
typedef  TYPE_3__ mqtt_connect_info_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  connection ;

/* Variables and functions */
 int MQTT_CONNECT_FLAG_CLEAN_SESSION ; 
 int MQTT_CONNECT_FLAG_PASSWORD ; 
 int MQTT_CONNECT_FLAG_USERNAME ; 
 int MQTT_CONNECT_FLAG_WILL ; 
 int MQTT_CONNECT_FLAG_WILL_RETAIN ; 
 int MQTT_MAX_FIXED_HEADER_SIZE ; 
 int MQTT_MSG_TYPE_CONNECT ; 
 int MQTT_MSG_TYPE_DISCONNECT ; 
 int MQTT_MSG_TYPE_PINGREQ ; 
 int MQTT_MSG_TYPE_PINGRESP ; 
#define  MQTT_MSG_TYPE_PUBACK 135 
#define  MQTT_MSG_TYPE_PUBCOMP 134 
#define  MQTT_MSG_TYPE_PUBLISH 133 
#define  MQTT_MSG_TYPE_PUBREC 132 
#define  MQTT_MSG_TYPE_PUBREL 131 
#define  MQTT_MSG_TYPE_SUBACK 130 
#define  MQTT_MSG_TYPE_SUBSCRIBE 129 
#define  MQTT_MSG_TYPE_UNSUBACK 128 
 int MQTT_MSG_TYPE_UNSUBSCRIBE ; 
 int /*<<< orphan*/  c_memcpy (int*,char const*,int) ; 
 int /*<<< orphan*/  c_memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int c_strlen (char const*) ; 

__attribute__((used)) static inline uint8_t mqtt_get_type(uint8_t* buffer) { return (buffer[0] & 0xf0) >> 4; }

__attribute__((used)) static inline uint8_t mqtt_get_dup(uint8_t* buffer) { return (buffer[0] & 0x08) >> 3; }

__attribute__((used)) static inline uint8_t mqtt_get_qos(uint8_t* buffer) { return (buffer[0] & 0x06) >> 1; }

__attribute__((used)) static inline uint8_t mqtt_get_retain(uint8_t* buffer) { return (buffer[0] & 0x01); }

__attribute__((used)) static inline uint8_t mqtt_get_connect_ret_code(uint8_t* buffer) { return (buffer[3]); }

__attribute__((used)) static int append_string(mqtt_connection_t* connection, const char* string, int len)
{
  if(connection->message.length + len + 2 > connection->buffer_length)
    return -1;

  connection->buffer[connection->message.length++] = len >> 8;
  connection->buffer[connection->message.length++] = len & 0xff;
  c_memcpy(connection->buffer + connection->message.length, string, len);
  connection->message.length += len;

  return len + 2;
}

__attribute__((used)) static uint16_t append_message_id(mqtt_connection_t* connection, uint16_t message_id)
{
  // If message_id is zero then we should assign one, otherwise
  // we'll use the one supplied by the caller
  while(message_id == 0)
    message_id = ++connection->message_id;

  if(connection->message.length + 2 > connection->buffer_length)
    return 0;

  connection->buffer[connection->message.length++] = message_id >> 8;
  connection->buffer[connection->message.length++] = message_id & 0xff;

  return message_id;
}

__attribute__((used)) static int init_message(mqtt_connection_t* connection)
{
  connection->message.length = MQTT_MAX_FIXED_HEADER_SIZE;
  return MQTT_MAX_FIXED_HEADER_SIZE;
}

__attribute__((used)) static mqtt_message_t* fail_message(mqtt_connection_t* connection)
{
  connection->message.data = connection->buffer;
  connection->message.length = 0;
  return &connection->message;
}

__attribute__((used)) static mqtt_message_t* fini_message(mqtt_connection_t* connection, int type, int dup, int qos, int retain)
{
  int remaining_length = connection->message.length - MQTT_MAX_FIXED_HEADER_SIZE;

  if(remaining_length > 127)
  {
    connection->buffer[0] = ((type & 0x0f) << 4) | ((dup & 1) << 3) | ((qos & 3) << 1) | (retain & 1);
    connection->buffer[1] = 0x80 | (remaining_length % 128);
    connection->buffer[2] = remaining_length / 128;
    connection->message.length = remaining_length + 3;
    connection->message.data = connection->buffer;
  }
  else
  {
    connection->buffer[1] = ((type & 0x0f) << 4) | ((dup & 1) << 3) | ((qos & 3) << 1) | (retain & 1);
    connection->buffer[2] = remaining_length;
    connection->message.length = remaining_length + 2;
    connection->message.data = connection->buffer + 1;
  }

  return &connection->message;
}

void mqtt_msg_init(mqtt_connection_t* connection, uint8_t* buffer, uint16_t buffer_length)
{
  c_memset(connection, 0, sizeof(connection));
  connection->buffer = buffer;
  connection->buffer_length = buffer_length;
}

int32_t mqtt_get_total_length(uint8_t* buffer, uint16_t buffer_length)
{
  int i;
  int totlen = 0;

  if(buffer_length == 1)
    return -1;

  for(i = 1; i < buffer_length; ++i)
  {
    totlen += (buffer[i] & 0x7f) << (7 * (i - 1));
    if((buffer[i] & 0x80) == 0)
    {
      ++i;
      break;
    }

    if(i == buffer_length)
      return -1;
  }

  totlen += i;

  return totlen;
}

const char* mqtt_get_publish_topic(uint8_t* buffer, uint16_t* buffer_length)
{
  int i;
  int totlen = 0;
  int topiclen;

  for(i = 1; i < *buffer_length; ++i)
  {
    totlen += (buffer[i] & 0x7f) << (7 * (i -1));
    if((buffer[i] & 0x80) == 0)
    {
      ++i;
      break;
    }
  }
  totlen += i;

  if(i + 2 > *buffer_length)
    return NULL;
  topiclen = buffer[i++] << 8;
  topiclen |= buffer[i++];

  if(i + topiclen > *buffer_length)
    return NULL;

  *buffer_length = topiclen;
  return (const char*)(buffer + i);
}

const char* mqtt_get_publish_data(uint8_t* buffer, uint16_t* buffer_length)
{
  int i;
  int totlen = 0;
  int topiclen;

  for(i = 1; i < *buffer_length; ++i)
  {
    totlen += (buffer[i] & 0x7f) << (7 * (i - 1));
    if((buffer[i] & 0x80) == 0)
    {
      ++i;
      break;
    }
  }
  totlen += i;

  if(i + 2 > *buffer_length)
    return NULL;
  topiclen = buffer[i++] << 8;
  topiclen |= buffer[i++];

  if(i + topiclen > *buffer_length){
	*buffer_length = 0;
    return NULL;
  }
  i += topiclen;

  if(mqtt_get_qos(buffer) > 0)
  {
    if(i + 2 > *buffer_length)
      return NULL;
    i += 2;
  }

  if(totlen < i)
    return NULL;

  if(totlen <= *buffer_length)
    *buffer_length = totlen - i;
  else
    *buffer_length = *buffer_length - i;
  return (const char*)(buffer + i);
}

uint16_t mqtt_get_id(uint8_t* buffer, uint16_t buffer_length)
{
  if(buffer_length < 1)
    return 0;

  switch(mqtt_get_type(buffer))
  {
    case MQTT_MSG_TYPE_PUBLISH:
    {
      int i;
      int topiclen;

      if(mqtt_get_qos(buffer) <= 0)
        return 0;

      for(i = 1; i < buffer_length; ++i)
      {
        if((buffer[i] & 0x80) == 0)
        {
          ++i;
          break;
        }
      }

      if(i + 2 > buffer_length)
        return 0;
      topiclen = buffer[i++] << 8;
      topiclen |= buffer[i++];

      if(i + topiclen > buffer_length)
        return 0;
      i += topiclen;

      if(i + 2 > buffer_length)
        return 0;

      return (buffer[i] << 8) | buffer[i + 1];
    }
    case MQTT_MSG_TYPE_PUBACK:
    case MQTT_MSG_TYPE_PUBREC:
    case MQTT_MSG_TYPE_PUBREL:
    case MQTT_MSG_TYPE_PUBCOMP:
    case MQTT_MSG_TYPE_SUBACK:
    case MQTT_MSG_TYPE_UNSUBACK:
    case MQTT_MSG_TYPE_SUBSCRIBE:
    {
      // This requires the remaining length to be encoded in 1 byte,
      // which it should be.
      if(buffer_length >= 4 && (buffer[1] & 0x80) == 0)
        return (buffer[2] << 8) | buffer[3];
      else
        return 0;
    }

    default:
      return 0;
  }
}

mqtt_message_t* mqtt_msg_connect(mqtt_connection_t* connection, mqtt_connect_info_t* info)
{
  struct mqtt_connect_variable_header* variable_header;

  init_message(connection);

  if(connection->message.length + sizeof(*variable_header) > connection->buffer_length)
    return fail_message(connection);
  variable_header = (void*)(connection->buffer + connection->message.length);
  connection->message.length += sizeof(*variable_header);

  variable_header->lengthMsb = 0;
  variable_header->lengthLsb = 4;
  c_memcpy(variable_header->magic, "MQTT", 4);
  variable_header->version = 4;
  variable_header->flags = 0;
  variable_header->keepaliveMsb = info->keepalive >> 8;
  variable_header->keepaliveLsb = info->keepalive & 0xff;

  if(info->clean_session)
    variable_header->flags |= MQTT_CONNECT_FLAG_CLEAN_SESSION;

  if(info->client_id != NULL && info->client_id[0] != '\0')
  {
    if(append_string(connection, info->client_id, c_strlen(info->client_id)) < 0)
      return fail_message(connection);
  }
  else
    return fail_message(connection);

  if(info->will_topic != NULL && info->will_topic[0] != '\0')
  {
    if(append_string(connection, info->will_topic, c_strlen(info->will_topic)) < 0)
      return fail_message(connection);

    if(append_string(connection, info->will_message, c_strlen(info->will_message)) < 0)
      return fail_message(connection);

    variable_header->flags |= MQTT_CONNECT_FLAG_WILL;
    if(info->will_retain)
      variable_header->flags |= MQTT_CONNECT_FLAG_WILL_RETAIN;
    variable_header->flags |= (info->will_qos & 3) << 3;
  }

  if(info->username != NULL && info->username[0] != '\0')
  {
    if(append_string(connection, info->username, c_strlen(info->username)) < 0)
      return fail_message(connection);

    variable_header->flags |= MQTT_CONNECT_FLAG_USERNAME;
  }

  if(info->password != NULL && info->password[0] != '\0')
  {
    if(append_string(connection, info->password, c_strlen(info->password)) < 0)
      return fail_message(connection);

    variable_header->flags |= MQTT_CONNECT_FLAG_PASSWORD;
  }

  return fini_message(connection, MQTT_MSG_TYPE_CONNECT, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_publish(mqtt_connection_t* connection, const char* topic, const char* data, int data_length, int qos, int retain, uint16_t* message_id)
{
  init_message(connection);

  if(topic == NULL || topic[0] == '\0')
    return fail_message(connection);

  if(append_string(connection, topic, c_strlen(topic)) < 0)
    return fail_message(connection);

  if(qos > 0)
  {
    if((*message_id = append_message_id(connection, 0)) == 0)
      return fail_message(connection);
  }
  else
    *message_id = 0;

  if(connection->message.length + data_length > connection->buffer_length)
    return fail_message(connection);
  c_memcpy(connection->buffer + connection->message.length, data, data_length);
  connection->message.length += data_length;

  return fini_message(connection, MQTT_MSG_TYPE_PUBLISH, 0, qos, retain);
}

mqtt_message_t* mqtt_msg_puback(mqtt_connection_t* connection, uint16_t message_id)
{
  init_message(connection);
  if(append_message_id(connection, message_id) == 0)
    return fail_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PUBACK, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_pubrec(mqtt_connection_t* connection, uint16_t message_id)
{
  init_message(connection);
  if(append_message_id(connection, message_id) == 0)
    return fail_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PUBREC, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_pubrel(mqtt_connection_t* connection, uint16_t message_id)
{
  init_message(connection);
  if(append_message_id(connection, message_id) == 0)
    return fail_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PUBREL, 0, 1, 0);
}

mqtt_message_t* mqtt_msg_pubcomp(mqtt_connection_t* connection, uint16_t message_id)
{
  init_message(connection);
  if(append_message_id(connection, message_id) == 0)
    return fail_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PUBCOMP, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_subscribe_init(mqtt_connection_t* connection, uint16_t *message_id)
{
  init_message(connection);

  if((*message_id = append_message_id(connection, 0)) == 0)
    return fail_message(connection);

  return &connection->message;
}

mqtt_message_t* mqtt_msg_subscribe_topic(mqtt_connection_t* connection, const char* topic, int qos)
{
  if(topic == NULL || topic[0] == '\0')
    return fail_message(connection);

  if(append_string(connection, topic, c_strlen(topic)) < 0)
    return fail_message(connection);

  if(connection->message.length + 1 > connection->buffer_length)
    return fail_message(connection);
  connection->buffer[connection->message.length++] = qos;

  return &connection->message;
}

mqtt_message_t* mqtt_msg_subscribe_fini(mqtt_connection_t* connection)
{
  return fini_message(connection, MQTT_MSG_TYPE_SUBSCRIBE, 0, 1, 0);
}

mqtt_message_t* mqtt_msg_subscribe(mqtt_connection_t* connection, const char* topic, int qos, uint16_t* message_id)
{
  mqtt_message_t* result;

  result = mqtt_msg_subscribe_init(connection, message_id);
  if (result->length != 0) {
    result = mqtt_msg_subscribe_topic(connection, topic, qos);
  }
  if (result->length != 0) {
    result = mqtt_msg_subscribe_fini(connection);
  }

  return result;
}

mqtt_message_t* mqtt_msg_unsubscribe_init(mqtt_connection_t* connection, uint16_t *message_id)
{
  return mqtt_msg_subscribe_init(connection, message_id);
}

mqtt_message_t* mqtt_msg_unsubscribe_topic(mqtt_connection_t* connection, const char* topic)
{
  if(topic == NULL || topic[0] == '\0')
    return fail_message(connection);

  if(append_string(connection, topic, c_strlen(topic)) < 0)
    return fail_message(connection);

  return &connection->message;
}

mqtt_message_t* mqtt_msg_unsubscribe_fini(mqtt_connection_t* connection)
{
  return fini_message(connection, MQTT_MSG_TYPE_UNSUBSCRIBE, 0, 1, 0);
}

mqtt_message_t* mqtt_msg_unsubscribe(mqtt_connection_t* connection, const char* topic, uint16_t* message_id)
{
  mqtt_message_t* result;

  result = mqtt_msg_unsubscribe_init(connection, message_id);
  if (result->length != 0) {
    result = mqtt_msg_unsubscribe_topic(connection, topic);
  }
  if (result->length != 0) {
    result = mqtt_msg_unsubscribe_fini(connection);
  }

  return result;
}

mqtt_message_t* mqtt_msg_pingreq(mqtt_connection_t* connection)
{
  init_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PINGREQ, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_pingresp(mqtt_connection_t* connection)
{
  init_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_PINGRESP, 0, 0, 0);
}

mqtt_message_t* mqtt_msg_disconnect(mqtt_connection_t* connection)
{
  init_message(connection);
  return fini_message(connection, MQTT_MSG_TYPE_DISCONNECT, 0, 0, 0);
}

