#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {char* geoip_database; int /*<<< orphan*/  geo_db; } ;
struct TYPE_7__ {char* country_name; char* country_code; char* continent_code; char* city; char* region; } ;
typedef  TYPE_1__ GeoIPRecord ;
typedef  int /*<<< orphan*/  GeoIP ;
typedef  scalar_t__ GTypeIP ;

/* Variables and functions */
 int /*<<< orphan*/  CITY_LEN ; 
 int /*<<< orphan*/  CONTINENT_LEN ; 
 int /*<<< orphan*/  COUNTRY_LEN ; 
 int /*<<< orphan*/  FATAL (char*,char const*) ; 
 int /*<<< orphan*/  GEOIP_CHARSET_UTF8 ; 
#define  GEOIP_CITY_EDITION_REV0 133 
#define  GEOIP_CITY_EDITION_REV0_V6 132 
#define  GEOIP_CITY_EDITION_REV1 131 
#define  GEOIP_CITY_EDITION_REV1_V6 130 
#define  GEOIP_COUNTRY_EDITION 129 
#define  GEOIP_COUNTRY_EDITION_V6 128 
 int /*<<< orphan*/  GEOIP_MEMORY_CACHE ; 
 int /*<<< orphan*/  GeoIPRecord_delete (TYPE_1__*) ; 
 int /*<<< orphan*/  GeoIP_cleanup () ; 
 char* GeoIP_code_by_id (int) ; 
 char* GeoIP_continent_by_id (int) ; 
 char* GeoIP_country_name_by_name (int /*<<< orphan*/ *,char const*) ; 
 char* GeoIP_country_name_by_name_v6 (int /*<<< orphan*/ *,char const*) ; 
 unsigned char GeoIP_database_edition (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GeoIP_delete (int /*<<< orphan*/ *) ; 
 int GeoIP_id_by_name (int /*<<< orphan*/ *,char const*) ; 
 int GeoIP_id_by_name_v6 (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/ * GeoIP_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * GeoIP_open (char const*,int /*<<< orphan*/ ) ; 
 TYPE_1__* GeoIP_record_by_name (int /*<<< orphan*/ *,char const*) ; 
 TYPE_1__* GeoIP_record_by_name_v6 (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  GeoIP_set_charset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOG_DEBUG (char*) ; 
 scalar_t__ TYPE_IPV4 ; 
 scalar_t__ TYPE_IPV6 ; 
 TYPE_3__ conf ; 
 int /*<<< orphan*/ * geo_location_data ; 
 scalar_t__ invalid_ipaddr (char*,int*) ; 
 scalar_t__ memcmp (char const*,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,char const*,...) ; 

int
is_geoip_resource (void)
{
  return geo_location_data != NULL ? 1 : 0;
}

void
geoip_free (void)
{
  if (!is_geoip_resource ())
    return;

  GeoIP_delete (geo_location_data);
  GeoIP_cleanup ();
}

__attribute__((used)) static GeoIP *
geoip_open_db (const char *db)
{
  GeoIP *geoip;
  geoip = GeoIP_open (db, GEOIP_MEMORY_CACHE);

  if (geoip == NULL)
    FATAL ("Unable to open GeoIP database: %s\n", db);

  GeoIP_set_charset (geoip, GEOIP_CHARSET_UTF8);
  LOG_DEBUG (("Opened GeoIP City database: %s\n", db));

  return geoip;
}

void
init_geoip (void)
{
  /* open custom city GeoIP database */
  if (conf.geoip_database != NULL)
    geo_location_data = geoip_open_db (conf.geoip_database);
  /* fall back to legacy GeoIP database */
  else
    geo_location_data = GeoIP_new (conf.geo_db);
}

__attribute__((used)) static const char *
get_continent_name_and_code (const char *continentid)
{
  if (memcmp (continentid, "NA", 2) == 0)
    return "NA North America";
  else if (memcmp (continentid, "OC", 2) == 0)
    return "OC Oceania";
  else if (memcmp (continentid, "EU", 2) == 0)
    return "EU Europe";
  else if (memcmp (continentid, "SA", 2) == 0)
    return "SA South America";
  else if (memcmp (continentid, "AF", 2) == 0)
    return "AF Africa";
  else if (memcmp (continentid, "AN", 2) == 0)
    return "AN Antarctica";
  else if (memcmp (continentid, "AS", 2) == 0)
    return "AS Asia";
  else
    return "-- Unknown";
}

__attribute__((used)) static void
geoip_set_country (const char *country, const char *code, char *loc)
{
  if (country && code)
    snprintf (loc, COUNTRY_LEN, "%s %s", code, country);
  else
    snprintf (loc, COUNTRY_LEN, "%s", "Unknown");
}

__attribute__((used)) static void
geoip_set_city (const char *city, const char *region, char *loc)
{
  snprintf (loc, CITY_LEN, "%s, %s", city ? city : "N/A City",
            region ? region : "N/A Region");
}

__attribute__((used)) static void
geoip_set_continent (const char *continent, char *loc)
{
  if (continent)
    snprintf (loc, CONTINENT_LEN, "%s",
              get_continent_name_and_code (continent));
  else
    snprintf (loc, CONTINENT_LEN, "%s", "Unknown");
}

__attribute__((used)) static GeoIPRecord *
get_geoip_record (const char *addr, GTypeIP type_ip)
{
  GeoIPRecord *rec = NULL;

  if (TYPE_IPV4 == type_ip)
    rec = GeoIP_record_by_name (geo_location_data, addr);
  else if (TYPE_IPV6 == type_ip)
    rec = GeoIP_record_by_name_v6 (geo_location_data, addr);

  return rec;
}

__attribute__((used)) static void
geoip_set_country_by_record (const char *ip, char *location, GTypeIP type_ip)
{
  GeoIPRecord *rec = NULL;
  const char *country = NULL, *code = NULL, *addr = ip;

  if (conf.geoip_database == NULL || geo_location_data == NULL)
    return;

  /* Custom GeoIP database */
  if ((rec = get_geoip_record (addr, type_ip))) {
    country = rec->country_name;
    code = rec->country_code;
  }

  geoip_set_country (country, code, location);
  if (rec != NULL) {
    GeoIPRecord_delete (rec);
  }
}

__attribute__((used)) static int
geoip_get_geoid (const char *addr, GTypeIP type_ip)
{
  int geoid = 0;

  if (TYPE_IPV4 == type_ip)
    geoid = GeoIP_id_by_name (geo_location_data, addr);
  else if (TYPE_IPV6 == type_ip)
    geoid = GeoIP_id_by_name_v6 (geo_location_data, addr);

  return geoid;
}

__attribute__((used)) static const char *
geoip_get_country_by_geoid (const char *addr, GTypeIP type_ip)
{
  const char *country = NULL;

  if (TYPE_IPV4 == type_ip)
    country = GeoIP_country_name_by_name (geo_location_data, addr);
  else if (TYPE_IPV6 == type_ip)
    country = GeoIP_country_name_by_name_v6 (geo_location_data, addr);

  return country;
}

__attribute__((used)) static void
geoip_set_country_by_geoid (const char *ip, char *location, GTypeIP type_ip)
{
  const char *country = NULL, *code = NULL, *addr = ip;
  int geoid = 0;

  if (!is_geoip_resource ())
    return;

  if (!(country = geoip_get_country_by_geoid (addr, type_ip)))
    goto out;

  /* return two letter country code */
  if (!(geoid = geoip_get_geoid (addr, type_ip)))
    goto out;
  code = GeoIP_code_by_id (geoid);

out:
  geoip_set_country (country, code, location);
}

void
geoip_get_country (const char *ip, char *location, GTypeIP type_ip)
{
  unsigned char rec = GeoIP_database_edition (geo_location_data);

  switch (rec) {
  case GEOIP_COUNTRY_EDITION:
    if (TYPE_IPV4 == type_ip)
      geoip_set_country_by_geoid (ip, location, TYPE_IPV4);
    else
      geoip_set_country (NULL, NULL, location);
    break;
  case GEOIP_COUNTRY_EDITION_V6:
    if (TYPE_IPV6 == type_ip)
      geoip_set_country_by_geoid (ip, location, TYPE_IPV6);
    else
      geoip_set_country (NULL, NULL, location);
    break;
  case GEOIP_CITY_EDITION_REV0:
  case GEOIP_CITY_EDITION_REV1:
    if (TYPE_IPV4 == type_ip)
      geoip_set_country_by_record (ip, location, TYPE_IPV4);
    else
      geoip_set_country (NULL, NULL, location);
    break;
  case GEOIP_CITY_EDITION_REV0_V6:
  case GEOIP_CITY_EDITION_REV1_V6:
    if (TYPE_IPV6 == type_ip)
      geoip_set_country_by_record (ip, location, TYPE_IPV6);
    else
      geoip_set_country (NULL, NULL, location);
    break;
  }
}

__attribute__((used)) static void
geoip_set_continent_by_record (const char *ip, char *location, GTypeIP type_ip)
{
  GeoIPRecord *rec = NULL;
  const char *continent = NULL, *addr = ip;

  if (conf.geoip_database == NULL || geo_location_data == NULL)
    return;

  /* Custom GeoIP database */
  if ((rec = get_geoip_record (addr, type_ip)))
    continent = rec->continent_code;

  geoip_set_continent (continent, location);
  if (rec != NULL) {
    GeoIPRecord_delete (rec);
  }
}

__attribute__((used)) static void
geoip_set_continent_by_geoid (const char *ip, char *location, GTypeIP type_ip)
{
  const char *continent = NULL, *addr = ip;
  int geoid = 0;

  if (!is_geoip_resource ())
    return;

  if (!(geoid = geoip_get_geoid (addr, type_ip)))
    goto out;
  continent = GeoIP_continent_by_id (geoid);

out:
  geoip_set_continent (continent, location);
}

void
geoip_get_continent (const char *ip, char *location, GTypeIP type_ip)
{
  unsigned char rec = GeoIP_database_edition (geo_location_data);

  switch (rec) {
  case GEOIP_COUNTRY_EDITION:
    if (TYPE_IPV4 == type_ip)
      geoip_set_continent_by_geoid (ip, location, TYPE_IPV4);
    else
      geoip_set_continent (NULL, location);
    break;
  case GEOIP_COUNTRY_EDITION_V6:
    if (TYPE_IPV6 == type_ip)
      geoip_set_continent_by_geoid (ip, location, TYPE_IPV6);
    else
      geoip_set_continent (NULL, location);
    break;
  case GEOIP_CITY_EDITION_REV0:
  case GEOIP_CITY_EDITION_REV1:
    if (TYPE_IPV4 == type_ip)
      geoip_set_continent_by_record (ip, location, TYPE_IPV4);
    else
      geoip_set_continent (NULL, location);
    break;
  case GEOIP_CITY_EDITION_REV0_V6:
  case GEOIP_CITY_EDITION_REV1_V6:
    if (TYPE_IPV6 == type_ip)
      geoip_set_continent_by_record (ip, location, TYPE_IPV6);
    else
      geoip_set_continent (NULL, location);
    break;
  }
}

__attribute__((used)) static void
geoip_set_city_by_record (const char *ip, char *location, GTypeIP type_ip)
{
  GeoIPRecord *rec = NULL;
  const char *city = NULL, *region = NULL, *addr = ip;

  /* Custom GeoIP database */
  if ((rec = get_geoip_record (addr, type_ip))) {
    city = rec->city;
    region = rec->region;
  }

  geoip_set_city (city, region, location);
  if (rec != NULL) {
    GeoIPRecord_delete (rec);
  }
}

void
geoip_get_city (const char *ip, char *location, GTypeIP type_ip)
{
  unsigned char rec = GeoIP_database_edition (geo_location_data);

  if (conf.geoip_database == NULL || geo_location_data == NULL)
    return;

  switch (rec) {
  case GEOIP_CITY_EDITION_REV0:
  case GEOIP_CITY_EDITION_REV1:
    if (TYPE_IPV4 == type_ip)
      geoip_set_city_by_record (ip, location, TYPE_IPV4);
    else
      geoip_set_city (NULL, NULL, location);
    break;
  case GEOIP_CITY_EDITION_REV0_V6:
  case GEOIP_CITY_EDITION_REV1_V6:
    if (TYPE_IPV6 == type_ip)
      geoip_set_city_by_record (ip, location, TYPE_IPV6);
    else
      geoip_set_city (NULL, NULL, location);
    break;
  }
}

int
set_geolocation (char *host, char *continent, char *country, char *city)
{
  int type_ip = 0;

  if (!is_geoip_resource ())
    return 1;

  if (invalid_ipaddr (host, &type_ip))
    return 1;

  geoip_get_country (host, country, type_ip);
  geoip_get_continent (host, continent, type_ip);
  if (conf.geoip_database)
    geoip_get_city (host, city, type_ip);

  return 0;
}

