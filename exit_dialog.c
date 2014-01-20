/*Description: Exit program written in gtk3 

  Author: Andrew Reyes */


#include <gtk/gtk.h>
#include <unistd.h>

/**** 'close' Function ******************/

void close_window(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

/**** 'logout_session' Function *********/

void logout_session(GtkWidget *widget, gpointer data)
{
	gchar *command,
	      *arg_0,
	      *arg_1;
	
	command = "/usr/bin/openbox";	
	arg_0 = command;
	arg_1 = "--exit";
	
	execl(command, arg_0, arg_1, NULL);
}

/**** 'restart' Function ****************/

void restart(GtkWidget *widget, gpointer data)
{
	gchar *command,
	      *arg_0;
	      	
	command = "/usr/sbin/reboot";	
	arg_0 = command;
	
	
	execl(command, arg_0, NULL);
}

/**** 'power_off' Function ****************/

void power_off(GtkWidget *widget, gpointer data)
{
	gchar *command,
	      *arg_0,
	      *arg_1;
	      	
	command = "/usr/sbin/halt";	
	arg_0 = command;
	arg_1 = "-p";
	
	execl(command, arg_0, arg_1, NULL);
}

/**** 'main' Function *******************/

int main(int argc, char *argv[])
{
	GtkWidget *box_1,
	          *box_2,
	          *box_3,
	          *label,
	          *image_1,
	          *image_2,
	          *image_3,
	          *image_4,
	          *image_5,
	          *window,
 	          *cancel_b,
 	          *restart_b,
 	          *logout_b,
 	          *shutdown_b;
 	
	gtk_init(&argc, &argv); 	
 	
 	label = gtk_label_new("Please choose an option");
	box_1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15); 	
	box_2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 80);
 	box_3 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	logout_b = gtk_button_new_with_mnemonic("_Logout"); 	
 	cancel_b = gtk_button_new_with_mnemonic("_Cancel");
 	restart_b = gtk_button_new_with_mnemonic("_Restart");
	shutdown_b = gtk_button_new_with_mnemonic("_Shutdown");
	image_1 = gtk_image_new_from_file("/usr/share/icons/Faenza/actions/24/stop.png");
	image_2 = gtk_image_new_from_file("/usr/share/icons/Faenza/actions/24/system-log-out.png");
	image_3 = gtk_image_new_from_file("/usr/share/icons/Faenza/actions/24/system-restart-panel.png");	
	image_4 = gtk_image_new_from_file("/usr/share/icons/Faenza/actions/24/system-shutdown-panel-restart.png");
	image_5 = gtk_image_new_from_file("/usr/share/icons/Faenza/actions/64/system-shutdown.png");
	
	gtk_window_set_title(GTK_WINDOW(window), "Exit");
	
	gtk_button_box_set_layout(GTK_BUTTON_BOX(box_3), GTK_BUTTONBOX_SPREAD);	
	
	gtk_button_set_image(GTK_BUTTON(cancel_b), image_1);
	gtk_button_set_image(GTK_BUTTON(logout_b), image_2);	
	gtk_button_set_image(GTK_BUTTON(restart_b), image_3);	
	gtk_button_set_image(GTK_BUTTON(shutdown_b), image_4);
	
	gtk_button_set_image_position(GTK_BUTTON(cancel_b), GTK_POS_LEFT);
	gtk_button_set_image_position(GTK_BUTTON(logout_b), GTK_POS_LEFT);
	gtk_button_set_image_position(GTK_BUTTON(restart_b), GTK_POS_LEFT);	
	gtk_button_set_image_position(GTK_BUTTON(shutdown_b), GTK_POS_LEFT);
	
	gtk_button_set_always_show_image(GTK_BUTTON(cancel_b), TRUE);
	gtk_button_set_always_show_image(GTK_BUTTON(logout_b), TRUE);
	gtk_button_set_always_show_image(GTK_BUTTON(restart_b), TRUE);	
	gtk_button_set_always_show_image(GTK_BUTTON(shutdown_b), TRUE);	
	
	gtk_box_pack_start(GTK_BOX(box_2), image_5, FALSE, FALSE, 2);	
	gtk_box_pack_start(GTK_BOX(box_2), label, FALSE, FALSE, 2);
	gtk_box_pack_start(GTK_BOX(box_1), box_2, FALSE,FALSE, 2);
	gtk_box_pack_start(GTK_BOX(box_1), box_3, FALSE,FALSE, 2);
	
	gtk_container_add(GTK_CONTAINER(box_3), cancel_b);
	gtk_container_add(GTK_CONTAINER(box_3), logout_b);
	gtk_container_add(GTK_CONTAINER(box_3), restart_b);	
	gtk_container_add(GTK_CONTAINER(box_3), shutdown_b);
	gtk_container_add(GTK_CONTAINER(window), box_1);	
	
	g_signal_connect(window, "destroy", G_CALLBACK(close_window), NULL);
	g_signal_connect(cancel_b, "clicked", G_CALLBACK(close_window), NULL);	
	g_signal_connect(logout_b, "clicked", G_CALLBACK(logout_session), NULL);
	g_signal_connect(restart_b, "clicked", G_CALLBACK(restart), NULL);
	g_signal_connect(shutdown_b, "clicked", G_CALLBACK(power_off), NULL);
	
	gtk_widget_show_all(window);	
	
	gtk_main();	
	
	return 0;
}