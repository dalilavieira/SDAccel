#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint64_t ;
struct TYPE_17__ {double max; double min; } ;
struct TYPE_16__ {double max; double min; } ;
struct TYPE_21__ {TYPE_2__ longitude; TYPE_1__ latitude; } ;
struct TYPE_20__ {int bits; int step; } ;
struct TYPE_19__ {TYPE_5__ north_east; TYPE_5__ south_east; TYPE_5__ east; TYPE_5__ north_west; TYPE_5__ south_west; TYPE_5__ west; TYPE_5__ north; TYPE_5__ south; } ;
struct TYPE_18__ {TYPE_6__ area; TYPE_4__ neighbors; TYPE_5__ hash; } ;
typedef  int /*<<< orphan*/  GeoHashRange ;
typedef  TYPE_3__ GeoHashRadius ;
typedef  TYPE_4__ GeoHashNeighbors ;
typedef  int GeoHashFix52Bits ;
typedef  TYPE_5__ GeoHashBits ;
typedef  TYPE_6__ GeoHashArea ;

/* Variables and functions */
 double D_R ; 
 double EARTH_RADIUS_IN_METERS ; 
 int /*<<< orphan*/  GZERO (TYPE_5__) ; 
 double MERCATOR_MAX ; 
 double asin (int /*<<< orphan*/ ) ; 
 double cos (double) ; 
 int /*<<< orphan*/  geohashDecode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_5__,TYPE_6__*) ; 
 int /*<<< orphan*/  geohashEncode (int /*<<< orphan*/ *,int /*<<< orphan*/ *,double,double,int,TYPE_5__*) ; 
 int /*<<< orphan*/  geohashGetCoordRange (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 double geohashGetDistance (double,double,double,double) ; 
 int /*<<< orphan*/  geohashNeighbors (TYPE_5__*,TYPE_4__*) ; 
 double sin (double) ; 
 int /*<<< orphan*/  sqrt (double) ; 

__attribute__((used)) static inline double deg_rad(double ang) { return ang * D_R; }

__attribute__((used)) static inline double rad_deg(double ang) { return ang / D_R; }

uint8_t geohashEstimateStepsByRadius(double range_meters, double lat) {
    if (range_meters == 0) return 26;
    int step = 1;
    while (range_meters < MERCATOR_MAX) {
        range_meters *= 2;
        step++;
    }
    step -= 2; /* Make sure range is included in most of the base cases. */

    /* Wider range torwards the poles... Note: it is possible to do better
     * than this approximation by computing the distance between meridians
     * at this latitude, but this does the trick for now. */
    if (lat > 66 || lat < -66) {
        step--;
        if (lat > 80 || lat < -80) step--;
    }

    /* Frame to valid range. */
    if (step < 1) step = 1;
    if (step > 26) step = 26;
    return step;
}

int geohashBoundingBox(double longitude, double latitude, double radius_meters,
                       double *bounds) {
    if (!bounds) return 0;

    bounds[0] = longitude - rad_deg(radius_meters/EARTH_RADIUS_IN_METERS/cos(deg_rad(latitude)));
    bounds[2] = longitude + rad_deg(radius_meters/EARTH_RADIUS_IN_METERS/cos(deg_rad(latitude)));
    bounds[1] = latitude - rad_deg(radius_meters/EARTH_RADIUS_IN_METERS);
    bounds[3] = latitude + rad_deg(radius_meters/EARTH_RADIUS_IN_METERS);
    return 1;
}

GeoHashRadius geohashGetAreasByRadius(double longitude, double latitude, double radius_meters) {
    GeoHashRange long_range, lat_range;
    GeoHashRadius radius;
    GeoHashBits hash;
    GeoHashNeighbors neighbors;
    GeoHashArea area;
    double min_lon, max_lon, min_lat, max_lat;
    double bounds[4];
    int steps;

    geohashBoundingBox(longitude, latitude, radius_meters, bounds);
    min_lon = bounds[0];
    min_lat = bounds[1];
    max_lon = bounds[2];
    max_lat = bounds[3];

    steps = geohashEstimateStepsByRadius(radius_meters,latitude);

    geohashGetCoordRange(&long_range,&lat_range);
    geohashEncode(&long_range,&lat_range,longitude,latitude,steps,&hash);
    geohashNeighbors(&hash,&neighbors);
    geohashDecode(long_range,lat_range,hash,&area);

    /* Check if the step is enough at the limits of the covered area.
     * Sometimes when the search area is near an edge of the
     * area, the estimated step is not small enough, since one of the
     * north / south / west / east square is too near to the search area
     * to cover everything. */
    int decrease_step = 0;
    {
        GeoHashArea north, south, east, west;

        geohashDecode(long_range, lat_range, neighbors.north, &north);
        geohashDecode(long_range, lat_range, neighbors.south, &south);
        geohashDecode(long_range, lat_range, neighbors.east, &east);
        geohashDecode(long_range, lat_range, neighbors.west, &west);

        if (geohashGetDistance(longitude,latitude,longitude,north.latitude.max)
            < radius_meters) decrease_step = 1;
        if (geohashGetDistance(longitude,latitude,longitude,south.latitude.min)
            < radius_meters) decrease_step = 1;
        if (geohashGetDistance(longitude,latitude,east.longitude.max,latitude)
            < radius_meters) decrease_step = 1;
        if (geohashGetDistance(longitude,latitude,west.longitude.min,latitude)
            < radius_meters) decrease_step = 1;
    }

    if (steps > 1 && decrease_step) {
        steps--;
        geohashEncode(&long_range,&lat_range,longitude,latitude,steps,&hash);
        geohashNeighbors(&hash,&neighbors);
        geohashDecode(long_range,lat_range,hash,&area);
    }

    /* Exclude the search areas that are useless. */
    if (steps >= 2) {
        if (area.latitude.min < min_lat) {
            GZERO(neighbors.south);
            GZERO(neighbors.south_west);
            GZERO(neighbors.south_east);
        }
        if (area.latitude.max > max_lat) {
            GZERO(neighbors.north);
            GZERO(neighbors.north_east);
            GZERO(neighbors.north_west);
        }
        if (area.longitude.min < min_lon) {
            GZERO(neighbors.west);
            GZERO(neighbors.south_west);
            GZERO(neighbors.north_west);
        }
        if (area.longitude.max > max_lon) {
            GZERO(neighbors.east);
            GZERO(neighbors.south_east);
            GZERO(neighbors.north_east);
        }
    }
    radius.hash = hash;
    radius.neighbors = neighbors;
    radius.area = area;
    return radius;
}

GeoHashRadius geohashGetAreasByRadiusWGS84(double longitude, double latitude,
                                           double radius_meters) {
    return geohashGetAreasByRadius(longitude, latitude, radius_meters);
}

GeoHashFix52Bits geohashAlign52Bits(const GeoHashBits hash) {
    uint64_t bits = hash.bits;
    bits <<= (52 - hash.step * 2);
    return bits;
}

double geohashGetDistance(double lon1d, double lat1d, double lon2d, double lat2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg_rad(lat1d);
    lon1r = deg_rad(lon1d);
    lat2r = deg_rad(lat2d);
    lon2r = deg_rad(lon2d);
    u = sin((lat2r - lat1r) / 2);
    v = sin((lon2r - lon1r) / 2);
    return 2.0 * EARTH_RADIUS_IN_METERS *
           asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

int geohashGetDistanceIfInRadius(double x1, double y1,
                                 double x2, double y2, double radius,
                                 double *distance) {
    *distance = geohashGetDistance(x1, y1, x2, y2);
    if (*distance > radius) return 0;
    return 1;
}

int geohashGetDistanceIfInRadiusWGS84(double x1, double y1, double x2,
                                      double y2, double radius,
                                      double *distance) {
    return geohashGetDistanceIfInRadius(x1, y1, x2, y2, radius, distance);
}

