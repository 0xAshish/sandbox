#include <gtk/gtk.h>



int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *title;
  GtkWidget *activate;
  GtkWidget *halign;
  GtkWidget *halign2;

  GtkWidget *valign;
  GtkWidget *close;
  GtkWidget *wins;

  GtkWidget *help;
  GtkWidget *ok;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_widget_set_size_request (window, 300, 250);
//  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  gtk_window_set_title(GTK_WINDOW(window), "Windows");

  gtk_container_set_border_width(GTK_CONTAINER(window), 15);

  table = gtk_table_new(8, 4, FALSE);
  gtk_table_set_col_spacings(GTK_TABLE(table), 3);

  title = gtk_label_new("Windows");
  halign = gtk_alignment_new(0, 0, 0, 0);
  gtk_container_add(GTK_CONTAINER(halign), title);
  gtk_table_attach(GTK_TABLE(table), halign, 0, 1, 0, 1, 
      GTK_FILL, GTK_FILL, 0, 0);

  wins = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(wins), FALSE);
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(wins), FALSE);
  gtk_table_attach(GTK_TABLE(table), wins, 0, 2, 1, 3,
      GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 1, 1);

  activate = gtk_button_new_with_label("Activate");
  gtk_widget_set_size_request(activate, 50, 30);
  gtk_table_attach(GTK_TABLE(table), activate, 3, 4, 1, 2, 
      GTK_FILL, GTK_SHRINK, 1, 1);

  valign = gtk_alignment_new(0, 0, 0, 0);
  close = gtk_button_new_with_label("Close");
 
  gtk_widget_set_size_request(close, 70, 30);
  gtk_container_add(GTK_CONTAINER(valign), close);
  gtk_table_set_row_spacing(GTK_TABLE(table), 1, 3);
  gtk_table_attach(GTK_TABLE(table), valign, 3, 4, 2, 3, 
      GTK_FILL, GTK_FILL | GTK_EXPAND, 1, 1);

  halign2 = gtk_alignment_new(0, 1, 0, 0);
  help = gtk_button_new_with_label("Help");
  gtk_container_add(GTK_CONTAINER(halign2), help);
  gtk_widget_set_size_request(help, 70, 30);
  gtk_table_set_row_spacing(GTK_TABLE(table), 3, 6);
  gtk_table_attach(GTK_TABLE(table), halign2, 0, 1, 4, 5, 
      GTK_FILL, GTK_FILL, 0, 0);

  ok = gtk_button_new_with_label("OK");
  gtk_widget_set_size_request(ok, 70, 30);
  gtk_table_attach(GTK_TABLE(table), ok, 3, 4, 4, 5, 
      GTK_FILL, GTK_FILL, 0, 0);

  gtk_container_add(GTK_CONTAINER(window), table);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

