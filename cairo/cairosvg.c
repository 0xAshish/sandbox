#include <cairo.h>
#include <cairo-svg.h> 
 
int main() {

  cairo_surface_t *surface;
  cairo_t *cr;

  surface = cairo_svg_surface_create("svgfile.svg", 390, 60);
  cr = cairo_create(surface);

  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_select_font_face (cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
      CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 40.0);

  cairo_move_to(cr, 10.0, 50.0);
  cairo_show_text(cr, "Bharathwaaj");

  cairo_surface_destroy(surface);
  cairo_destroy(cr);

  return 0;
}

