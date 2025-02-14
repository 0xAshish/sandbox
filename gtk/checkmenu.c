#include <gtk/gtk.h>

#if 0
void toggle_statusbar(GtkWidget *widget, gpointer statusbar) 
{
    if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget))) {
        gtk_widget_show(statusbar);
    } else {
        gtk_widget_hide(statusbar);
    }
}


int main( int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *vbox;

    GtkWidget *menubar;
    GtkWidget *viewmenu;
    GtkWidget *view;
    GtkWidget *tog_stat;
    GtkWidget *statusbar;


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    gtk_window_set_title(GTK_WINDOW(window), "view statusbar");

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    menubar = gtk_menu_bar_new();
    viewmenu = gtk_menu_new();

    view = gtk_menu_item_new_with_label("View");
    tog_stat = gtk_check_menu_item_new_with_label("View Statusbar");
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(tog_stat), TRUE);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), viewmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(viewmenu), tog_stat);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), view);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);

    g_signal_connect_swapped(G_OBJECT(window), "destroy",
            G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(G_OBJECT(tog_stat), "activate", 
            G_CALLBACK(toggle_statusbar), statusbar);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
#endif

void toggle_statusbar(GtkWidget *p_s_widget, gpointer p_s_statusbar) 
{
    if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(p_s_widget)))
    {
        gtk_widget_show(p_s_statusbar);
    }
    else
    {
        gtk_widget_hide(p_s_statusbar);
    }
}

int main( int argc, char *argv[])
{
 
    GtkWidget *p_s_window = NULL;
    GtkWidget *p_s_vbox = NULL;

    GtkWidget *p_s_menubar = NULL;
    GtkWidget *p_s_viewmenu = NULL;
    GtkWidget *p_s_view = NULL;
    GtkWidget *p_s_tog_stat = NULL;
    GtkWidget *p_s_statusbar = NULL;

    gtk_init (&argc, &argv);

    /* Prepare the window */
    p_s_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(p_s_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(p_s_window), 250, 200);
    gtk_window_set_title(GTK_WINDOW(p_s_window), "view statusbar");

    p_s_vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(p_s_window), p_s_vbox);

    p_s_menubar = gtk_menu_bar_new();
    p_s_viewmenu = gtk_menu_new();

    p_s_view = gtk_menu_item_new_with_label("View");
    p_s_tog_stat = gtk_check_menu_item_new_with_label("View Statusbar");
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(p_s_tog_stat), TRUE);

    gtk_menu_shell_append(GTK_MENU_SHELL(p_s_menubar), p_s_view);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(p_s_view), p_s_viewmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(p_s_viewmenu), p_s_tog_stat);
    gtk_box_pack_start(GTK_BOX(p_s_vbox), p_s_menubar, FALSE, FALSE, 3);

    p_s_statusbar = gtk_statusbar_new();
    gtk_box_pack_end(GTK_BOX(p_s_vbox), p_s_statusbar, FALSE, TRUE, 1);

    g_signal_connect_swapped(G_OBJECT(p_s_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(p_s_tog_stat), "activate", G_CALLBACK(toggle_statusbar), p_s_statusbar);

    gtk_widget_show_all(p_s_window);

    gtk_main();

    return 0;
}
