#ifndef __CLOCK_LOCATION_TILE_H__
#define __CLOCK_LOCATION_TILE_H__

#include <gtk/gtkalignment.h>

#include "clock.h"
#include "clock-face.h"
#include "clock-location.h"

G_BEGIN_DECLS

#define CLOCK_LOCATION_TILE_TYPE         (clock_location_tile_get_type ())
#define CLOCK_LOCATION_TILE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), CLOCK_LOCATION_TILE_TYPE, ClockLocationTile))
#define CLOCK_LOCATION_TILE_CLASS(c)     (G_TYPE_CHECK_CLASS_CAST ((c), CLOCK_LOCATION_TILE_TYPE, ClockLocationTileClass))
#define IS_CLOCK_LOCATION_TILE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), CLOCK_LOCATION_TILE_TYPE))
#define IS_CLOCK_LOCATION_TILE_CLASS(c)  (G_TYPE_CHECK_CLASS_TYPE ((c), CLOCK_LOCATION_TILE_TYPE))
#define CLOCK_LOCATION_TILE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), CLOCK_LOCATION_TILE_TYPE, ClockLocationTileClass))

typedef struct
{
        GtkAlignment parent;
} ClockLocationTile;

typedef struct
{
        GtkAlignmentClass parent_class;

	void (* tile_pressed) (ClockLocationTile *tile);
	void (* timezone_set) (ClockLocationTile *tile);
	void (* weather_updated) (ClockLocationTile *tile, GdkPixbuf *weather_icon, const char *temperature);
	char *(* need_formatted_time) (ClockLocationTile *tile);
} ClockLocationTileClass;

GType clock_location_tile_get_type (void);

ClockLocationTile *clock_location_tile_new (ClockLocation *loc,
					    ClockFaceSize size);

ClockLocation *clock_location_tile_get_location (ClockLocationTile *this);

void weather_info_setup_tooltip (WeatherInfo *info, GtkTooltip *tip);

void clock_location_tile_refresh (ClockLocationTile *this);

G_END_DECLS
#endif /* __CLOCK_H__ */