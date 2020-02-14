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
struct iio_event_data {char const* timestamp; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  event ;
typedef  enum iio_modifier { ____Placeholder_iio_modifier } iio_modifier ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
typedef  enum iio_chan_type { ____Placeholder_iio_chan_type } iio_chan_type ;

/* Variables and functions */
 int EAGAIN ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_ACCEL 206 
#define  IIO_ACTIVITY 205 
#define  IIO_ALTVOLTAGE 204 
#define  IIO_ANGL 203 
#define  IIO_ANGL_VEL 202 
#define  IIO_CAPACITANCE 201 
#define  IIO_CCT 200 
#define  IIO_CONCENTRATION 199 
#define  IIO_CURRENT 198 
#define  IIO_DISTANCE 197 
#define  IIO_ENERGY 196 
 int IIO_EVENT_CODE_EXTRACT_CHAN (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_CHAN2 (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_CHAN_TYPE (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_DIFF (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_DIR (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_MODIFIER (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_TYPE (int /*<<< orphan*/ ) ; 
#define  IIO_EV_DIR_EITHER 195 
#define  IIO_EV_DIR_FALLING 194 
#define  IIO_EV_DIR_NONE 193 
#define  IIO_EV_DIR_RISING 192 
#define  IIO_EV_TYPE_CHANGE 191 
#define  IIO_EV_TYPE_MAG 190 
#define  IIO_EV_TYPE_MAG_ADAPTIVE 189 
#define  IIO_EV_TYPE_ROC 188 
#define  IIO_EV_TYPE_THRESH 187 
#define  IIO_EV_TYPE_THRESH_ADAPTIVE 186 
 int /*<<< orphan*/  IIO_GET_EVENT_FD_IOCTL ; 
#define  IIO_GRAVITY 185 
#define  IIO_HUMIDITYRELATIVE 184 
#define  IIO_INCLI 183 
#define  IIO_INTENSITY 182 
#define  IIO_LIGHT 181 
#define  IIO_MAGN 180 
#define  IIO_MOD_CO2 179 
#define  IIO_MOD_I 178 
#define  IIO_MOD_JOGGING 177 
#define  IIO_MOD_LIGHT_BLUE 176 
#define  IIO_MOD_LIGHT_BOTH 175 
#define  IIO_MOD_LIGHT_CLEAR 174 
#define  IIO_MOD_LIGHT_DUV 173 
#define  IIO_MOD_LIGHT_GREEN 172 
#define  IIO_MOD_LIGHT_IR 171 
#define  IIO_MOD_LIGHT_RED 170 
#define  IIO_MOD_LIGHT_UV 169 
#define  IIO_MOD_NORTH_MAGN 168 
#define  IIO_MOD_NORTH_MAGN_TILT_COMP 167 
#define  IIO_MOD_NORTH_TRUE 166 
#define  IIO_MOD_NORTH_TRUE_TILT_COMP 165 
#define  IIO_MOD_Q 164 
#define  IIO_MOD_QUATERNION 163 
#define  IIO_MOD_ROOT_SUM_SQUARED_X_Y 162 
#define  IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z 161 
#define  IIO_MOD_RUNNING 160 
#define  IIO_MOD_STILL 159 
#define  IIO_MOD_SUM_SQUARED_X_Y_Z 158 
#define  IIO_MOD_TEMP_AMBIENT 157 
#define  IIO_MOD_TEMP_OBJECT 156 
#define  IIO_MOD_VOC 155 
#define  IIO_MOD_WALKING 154 
#define  IIO_MOD_X 153 
#define  IIO_MOD_X_AND_Y 152 
#define  IIO_MOD_X_AND_Y_AND_Z 151 
#define  IIO_MOD_X_AND_Z 150 
#define  IIO_MOD_X_OR_Y 149 
#define  IIO_MOD_X_OR_Y_OR_Z 148 
#define  IIO_MOD_X_OR_Z 147 
#define  IIO_MOD_Y 146 
#define  IIO_MOD_Y_AND_Z 145 
#define  IIO_MOD_Y_OR_Z 144 
#define  IIO_MOD_Z 143 
#define  IIO_NO_MOD 142 
#define  IIO_PH 141 
#define  IIO_PHASE 140 
#define  IIO_POSITIONRELATIVE 139 
#define  IIO_POWER 138 
#define  IIO_PRESSURE 137 
#define  IIO_PROXIMITY 136 
#define  IIO_RESISTANCE 135 
#define  IIO_ROT 134 
#define  IIO_STEPS 133 
#define  IIO_TEMP 132 
#define  IIO_TIMESTAMP 131 
#define  IIO_UVINDEX 130 
#define  IIO_VELOCITY 129 
#define  IIO_VOLTAGE 128 
 int asprintf (char**,char*,int) ; 
 int close (int) ; 
 int errno ; 
 int find_type_by_name (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int* iio_chan_type_name_spec ; 
 char** iio_ev_dir_text ; 
 char** iio_ev_type_text ; 
 char** iio_modifier_names ; 
 int ioctl (int,int /*<<< orphan*/ ,int*) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int read (int,struct iio_event_data*,int) ; 
 int /*<<< orphan*/  stderr ; 
 char* strdup (char const*) ; 
 int strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char const*,int) ; 

__attribute__((used)) static inline int iioutils_check_suffix(const char *str, const char *suffix)
{
	return strlen(str) >= strlen(suffix) &&
		strncmp(str+strlen(str)-strlen(suffix),
			suffix, strlen(suffix)) == 0;
}

__attribute__((used)) static bool event_is_known(struct iio_event_data *event)
{
	enum iio_chan_type type = IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event->id);
	enum iio_modifier mod = IIO_EVENT_CODE_EXTRACT_MODIFIER(event->id);
	enum iio_event_type ev_type = IIO_EVENT_CODE_EXTRACT_TYPE(event->id);
	enum iio_event_direction dir = IIO_EVENT_CODE_EXTRACT_DIR(event->id);

	switch (type) {
	case IIO_VOLTAGE:
	case IIO_CURRENT:
	case IIO_POWER:
	case IIO_ACCEL:
	case IIO_ANGL_VEL:
	case IIO_MAGN:
	case IIO_LIGHT:
	case IIO_INTENSITY:
	case IIO_PROXIMITY:
	case IIO_TEMP:
	case IIO_INCLI:
	case IIO_ROT:
	case IIO_ANGL:
	case IIO_TIMESTAMP:
	case IIO_CAPACITANCE:
	case IIO_ALTVOLTAGE:
	case IIO_CCT:
	case IIO_PRESSURE:
	case IIO_HUMIDITYRELATIVE:
	case IIO_ACTIVITY:
	case IIO_STEPS:
	case IIO_ENERGY:
	case IIO_DISTANCE:
	case IIO_VELOCITY:
	case IIO_CONCENTRATION:
	case IIO_RESISTANCE:
	case IIO_PH:
	case IIO_UVINDEX:
	case IIO_GRAVITY:
	case IIO_POSITIONRELATIVE:
	case IIO_PHASE:
		break;
	default:
		return false;
	}

	switch (mod) {
	case IIO_NO_MOD:
	case IIO_MOD_X:
	case IIO_MOD_Y:
	case IIO_MOD_Z:
	case IIO_MOD_X_AND_Y:
	case IIO_MOD_X_AND_Z:
	case IIO_MOD_Y_AND_Z:
	case IIO_MOD_X_AND_Y_AND_Z:
	case IIO_MOD_X_OR_Y:
	case IIO_MOD_X_OR_Z:
	case IIO_MOD_Y_OR_Z:
	case IIO_MOD_X_OR_Y_OR_Z:
	case IIO_MOD_LIGHT_BOTH:
	case IIO_MOD_LIGHT_IR:
	case IIO_MOD_ROOT_SUM_SQUARED_X_Y:
	case IIO_MOD_SUM_SQUARED_X_Y_Z:
	case IIO_MOD_LIGHT_CLEAR:
	case IIO_MOD_LIGHT_RED:
	case IIO_MOD_LIGHT_GREEN:
	case IIO_MOD_LIGHT_BLUE:
	case IIO_MOD_LIGHT_UV:
	case IIO_MOD_LIGHT_DUV:
	case IIO_MOD_QUATERNION:
	case IIO_MOD_TEMP_AMBIENT:
	case IIO_MOD_TEMP_OBJECT:
	case IIO_MOD_NORTH_MAGN:
	case IIO_MOD_NORTH_TRUE:
	case IIO_MOD_NORTH_MAGN_TILT_COMP:
	case IIO_MOD_NORTH_TRUE_TILT_COMP:
	case IIO_MOD_RUNNING:
	case IIO_MOD_JOGGING:
	case IIO_MOD_WALKING:
	case IIO_MOD_STILL:
	case IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z:
	case IIO_MOD_I:
	case IIO_MOD_Q:
	case IIO_MOD_CO2:
	case IIO_MOD_VOC:
		break;
	default:
		return false;
	}

	switch (ev_type) {
	case IIO_EV_TYPE_THRESH:
	case IIO_EV_TYPE_MAG:
	case IIO_EV_TYPE_ROC:
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
	case IIO_EV_TYPE_MAG_ADAPTIVE:
	case IIO_EV_TYPE_CHANGE:
		break;
	default:
		return false;
	}

	switch (dir) {
	case IIO_EV_DIR_EITHER:
	case IIO_EV_DIR_RISING:
	case IIO_EV_DIR_FALLING:
	case IIO_EV_DIR_NONE:
		break;
	default:
		return false;
	}

	return true;
}

__attribute__((used)) static void print_event(struct iio_event_data *event)
{
	enum iio_chan_type type = IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event->id);
	enum iio_modifier mod = IIO_EVENT_CODE_EXTRACT_MODIFIER(event->id);
	enum iio_event_type ev_type = IIO_EVENT_CODE_EXTRACT_TYPE(event->id);
	enum iio_event_direction dir = IIO_EVENT_CODE_EXTRACT_DIR(event->id);
	int chan = IIO_EVENT_CODE_EXTRACT_CHAN(event->id);
	int chan2 = IIO_EVENT_CODE_EXTRACT_CHAN2(event->id);
	bool diff = IIO_EVENT_CODE_EXTRACT_DIFF(event->id);

	if (!event_is_known(event)) {
		fprintf(stderr, "Unknown event: time: %lld, id: %llx\n",
			event->timestamp, event->id);

		return;
	}

	printf("Event: time: %lld, type: %s", event->timestamp,
	       iio_chan_type_name_spec[type]);

	if (mod != IIO_NO_MOD)
		printf("(%s)", iio_modifier_names[mod]);

	if (chan >= 0) {
		printf(", channel: %d", chan);
		if (diff && chan2 >= 0)
			printf("-%d", chan2);
	}

	printf(", evtype: %s", iio_ev_type_text[ev_type]);

	if (dir != IIO_EV_DIR_NONE)
		printf(", direction: %s", iio_ev_dir_text[dir]);

	printf("\n");
}

int main(int argc, char **argv)
{
	struct iio_event_data event;
	const char *device_name;
	char *chrdev_name;
	int ret;
	int dev_num;
	int fd, event_fd;

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <device_name>\n", argv[0]);
		return -1;
	}

	device_name = argv[1];

	dev_num = find_type_by_name(device_name, "iio:device");
	if (dev_num >= 0) {
		printf("Found IIO device with name %s with device number %d\n",
		       device_name, dev_num);
		ret = asprintf(&chrdev_name, "/dev/iio:device%d", dev_num);
		if (ret < 0)
			return -ENOMEM;
	} else {
		/*
		 * If we can't find an IIO device by name assume device_name is
		 * an IIO chrdev
		 */
		chrdev_name = strdup(device_name);
		if (!chrdev_name)
			return -ENOMEM;
	}

	fd = open(chrdev_name, 0);
	if (fd == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to open %s\n", chrdev_name);
		goto error_free_chrdev_name;
	}

	ret = ioctl(fd, IIO_GET_EVENT_FD_IOCTL, &event_fd);
	if (ret == -1 || event_fd == -1) {
		ret = -errno;
		if (ret == -ENODEV)
			fprintf(stderr,
				"This device does not support events\n");
		else
			fprintf(stderr, "Failed to retrieve event fd\n");
		if (close(fd) == -1)
			perror("Failed to close character device file");

		goto error_free_chrdev_name;
	}

	if (close(fd) == -1)  {
		ret = -errno;
		goto error_free_chrdev_name;
	}

	while (true) {
		ret = read(event_fd, &event, sizeof(event));
		if (ret == -1) {
			if (errno == EAGAIN) {
				fprintf(stderr, "nothing available\n");
				continue;
			} else {
				ret = -errno;
				perror("Failed to read event from device");
				break;
			}
		}

		if (ret != sizeof(event)) {
			fprintf(stderr, "Reading event failed!\n");
			ret = -EIO;
			break;
		}

		print_event(&event);
	}

	if (close(event_fd) == -1)
		perror("Failed to close event file");

error_free_chrdev_name:
	free(chrdev_name);

	return ret;
}

