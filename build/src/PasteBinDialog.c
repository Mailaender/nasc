/* PasteBinDialog.c generated by valac 0.32.1, the Vala compiler
 * generated from PasteBinDialog.vala, do not modify */

/*
 * Copyright (c) 2011-2012 Giulio Collura <random.cpp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <libsoup/soup.h>
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>


#define NASC_TYPE_PASTE_BIN (nasc_paste_bin_get_type ())
#define NASC_PASTE_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NASC_TYPE_PASTE_BIN, NascPasteBin))
#define NASC_PASTE_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NASC_TYPE_PASTE_BIN, NascPasteBinClass))
#define NASC_IS_PASTE_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NASC_TYPE_PASTE_BIN))
#define NASC_IS_PASTE_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NASC_TYPE_PASTE_BIN))
#define NASC_PASTE_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NASC_TYPE_PASTE_BIN, NascPasteBinClass))

typedef struct _NascPasteBin NascPasteBin;
typedef struct _NascPasteBinClass NascPasteBinClass;
typedef struct _NascPasteBinPrivate NascPasteBinPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define NASC_TYPE_PASTE_BIN_DIALOG (nasc_paste_bin_dialog_get_type ())
#define NASC_PASTE_BIN_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NASC_TYPE_PASTE_BIN_DIALOG, NascPasteBinDialog))
#define NASC_PASTE_BIN_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NASC_TYPE_PASTE_BIN_DIALOG, NascPasteBinDialogClass))
#define NASC_IS_PASTE_BIN_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NASC_TYPE_PASTE_BIN_DIALOG))
#define NASC_IS_PASTE_BIN_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NASC_TYPE_PASTE_BIN_DIALOG))
#define NASC_PASTE_BIN_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NASC_TYPE_PASTE_BIN_DIALOG, NascPasteBinDialogClass))

typedef struct _NascPasteBinDialog NascPasteBinDialog;
typedef struct _NascPasteBinDialogClass NascPasteBinDialogClass;
typedef struct _NascPasteBinDialogPrivate NascPasteBinDialogPrivate;

#define TYPE_CONTROLLER (controller_get_type ())
#define CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONTROLLER, Controller))
#define CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONTROLLER, ControllerClass))
#define IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONTROLLER))
#define IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONTROLLER))
#define CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONTROLLER, ControllerClass))

typedef struct _Controller Controller;
typedef struct _ControllerClass ControllerClass;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

struct _NascPasteBin {
	GObject parent_instance;
	NascPasteBinPrivate * priv;
};

struct _NascPasteBinClass {
	GObjectClass parent_class;
};

struct _NascPasteBinDialog {
	GtkDialog parent_instance;
	NascPasteBinDialogPrivate * priv;
};

struct _NascPasteBinDialogClass {
	GtkDialogClass parent_class;
};

struct _NascPasteBinDialogPrivate {
	GtkBox* content;
	GtkBox* padding;
	GtkEntry* name_entry;
	GtkComboBoxText* expiry_combo;
	GtkCheckButton* private_check;
	GtkButton* send_button;
	Controller* controller;
};


static gpointer nasc_paste_bin_parent_class = NULL;
static gpointer nasc_paste_bin_dialog_parent_class = NULL;

#define NAME "Pastebin"
#define DESCRIPTION "Share files with pastebin service"
GType nasc_paste_bin_get_type (void) G_GNUC_CONST;
enum  {
	NASC_PASTE_BIN_DUMMY_PROPERTY
};
#define NASC_PASTE_BIN_PASTE_ID_LEN 8
#define NASC_PASTE_BIN_NEVER "N"
#define NASC_PASTE_BIN_TEN_MINUTES "10M"
#define NASC_PASTE_BIN_HOUR "1H"
#define NASC_PASTE_BIN_DAY "1D"
#define NASC_PASTE_BIN_MONTH "1M"
#define NASC_PASTE_BIN_PRIVATE "1"
#define NASC_PASTE_BIN_PUBLIC "0"
gint nasc_paste_bin_submit (gchar** link, const gchar* paste_code, const gchar* paste_name, const gchar* paste_private, const gchar* paste_expire_date);
NascPasteBin* nasc_paste_bin_new (void);
NascPasteBin* nasc_paste_bin_construct (GType object_type);
GType nasc_paste_bin_dialog_get_type (void) G_GNUC_CONST;
GType controller_get_type (void) G_GNUC_CONST;
#define NASC_PASTE_BIN_DIALOG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), NASC_TYPE_PASTE_BIN_DIALOG, NascPasteBinDialogPrivate))
enum  {
	NASC_PASTE_BIN_DIALOG_DUMMY_PROPERTY
};
NascPasteBinDialog* nasc_paste_bin_dialog_new (GtkWindow* parent, Controller* controller);
NascPasteBinDialog* nasc_paste_bin_dialog_construct (GType object_type, GtkWindow* parent, Controller* controller);
static void nasc_paste_bin_dialog_create_dialog (NascPasteBinDialog* self);
static void nasc_paste_bin_dialog_send_button_clicked (NascPasteBinDialog* self);
static void _nasc_paste_bin_dialog_send_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void nasc_paste_bin_dialog_populate_expiry_combo (NascPasteBinDialog* self);
static GtkAlignment* nasc_paste_bin_dialog_wrap_alignment (GtkWidget* widget, gint top, gint right, gint bottom, gint left);
static gint nasc_paste_bin_dialog_submit_paste (NascPasteBinDialog* self, gchar** link);
gchar* controller_get_export_text (Controller* self);
static void nasc_paste_bin_dialog_finalize (GObject* obj);


static guint8* string_get_data (const gchar* self, int* result_length1) {
	guint8* result;
	guint8* res = NULL;
	gint res_length1 = 0;
	gint _res_size_ = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	guint8* _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	guint8* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) self;
	res_length1 = -1;
	_res_size_ = res_length1;
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	res_length1 = (gint) _tmp1_;
	_tmp2_ = res_length1;
	_tmp3_ = res;
	_tmp3__length1 = res_length1;
	_tmp4_ = _tmp3_;
	_tmp4__length1 = _tmp3__length1;
	if (result_length1) {
		*result_length1 = _tmp4__length1;
	}
	result = _tmp4_;
	return result;
}


static gchar* string_slice (const gchar* self, glong start, glong end) {
	gchar* result = NULL;
	glong string_length = 0L;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	glong _tmp2_ = 0L;
	glong _tmp5_ = 0L;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_ = 0L;
	gboolean _tmp12_ = FALSE;
	glong _tmp13_ = 0L;
	glong _tmp16_ = 0L;
	glong _tmp17_ = 0L;
	glong _tmp18_ = 0L;
	glong _tmp19_ = 0L;
	glong _tmp20_ = 0L;
	gchar* _tmp21_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_ = 0L;
		glong _tmp4_ = 0L;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_ = 0L;
		glong _tmp7_ = 0L;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_ = 0L;
		glong _tmp11_ = 0L;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	g_return_val_if_fail (_tmp8_, NULL);
	_tmp13_ = end;
	if (_tmp13_ >= ((glong) 0)) {
		glong _tmp14_ = 0L;
		glong _tmp15_ = 0L;
		_tmp14_ = end;
		_tmp15_ = string_length;
		_tmp12_ = _tmp14_ <= _tmp15_;
	} else {
		_tmp12_ = FALSE;
	}
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp16_ = start;
	_tmp17_ = end;
	g_return_val_if_fail (_tmp16_ <= _tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	_tmp20_ = start;
	_tmp21_ = g_strndup (((gchar*) self) + _tmp18_, (gsize) (_tmp19_ - _tmp20_));
	result = _tmp21_;
	return result;
}


gint nasc_paste_bin_submit (gchar** link, const gchar* paste_code, const gchar* paste_name, const gchar* paste_private, const gchar* paste_expire_date) {
	gchar* _vala_link = NULL;
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gchar* api_url = NULL;
	gchar* _tmp4_ = NULL;
	SoupSessionSync* session = NULL;
	SoupSessionSync* _tmp5_ = NULL;
	SoupMessage* message = NULL;
	const gchar* _tmp6_ = NULL;
	SoupMessage* _tmp7_ = NULL;
	gchar* request = NULL;
	const gchar* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	SoupMessage* _tmp13_ = NULL;
	const gchar* _tmp14_ = NULL;
	guint8* _tmp15_ = NULL;
	gint _tmp15__length1 = 0;
	guint8* _tmp16_ = NULL;
	gint _tmp16__length1 = 0;
	SoupMessage* _tmp17_ = NULL;
	SoupSessionSync* _tmp18_ = NULL;
	SoupMessage* _tmp19_ = NULL;
	gchar* output = NULL;
	SoupMessage* _tmp20_ = NULL;
	SoupMessageBody* _tmp21_ = NULL;
	guint8* _tmp22_ = NULL;
	gint _tmp22__length1 = 0;
	gchar* _tmp23_ = NULL;
	const gchar* _tmp24_ = NULL;
	gchar* _tmp25_ = NULL;
	gchar* _tmp26_ = NULL;
	gboolean _tmp27_ = FALSE;
	g_return_val_if_fail (paste_code != NULL, 0);
	g_return_val_if_fail (paste_name != NULL, 0);
	g_return_val_if_fail (paste_private != NULL, 0);
	g_return_val_if_fail (paste_expire_date != NULL, 0);
	_tmp0_ = paste_code;
	_tmp1_ = strlen (_tmp0_);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == 0) {
		gchar* _tmp3_ = NULL;
		_tmp3_ = g_strdup ("");
		_g_free0 (_vala_link);
		_vala_link = _tmp3_;
		result = 2;
		if (link) {
			*link = _vala_link;
		} else {
			_g_free0 (_vala_link);
		}
		return result;
	}
	_tmp4_ = g_strdup ("http://pastebin.com/api/api_post.php");
	api_url = _tmp4_;
	_tmp5_ = (SoupSessionSync*) soup_session_sync_new ();
	session = _tmp5_;
	_tmp6_ = api_url;
	_tmp7_ = soup_message_new ("POST", _tmp6_);
	message = _tmp7_;
	_tmp8_ = paste_code;
	_tmp9_ = paste_name;
	_tmp10_ = paste_private;
	_tmp11_ = paste_expire_date;
	_tmp12_ = soup_form_encode ("api_option", "paste", "api_dev_key", "67480801fa55fc0977f7561cf650a339", "api_paste_code", _tmp8_, "api_paste_name", _tmp9_, "api_paste_private", _tmp10_, "api_paste_expire_date", _tmp11_, "api_paste_format", "matlab", NULL);
	request = _tmp12_;
	_tmp13_ = message;
	_tmp14_ = request;
	_tmp15_ = string_get_data (_tmp14_, &_tmp15__length1);
	_tmp16_ = _tmp15_;
	_tmp16__length1 = _tmp15__length1;
	soup_message_set_request (_tmp13_, "application/x-www-form-urlencoded", SOUP_MEMORY_COPY, _tmp16_, (gsize) _tmp16__length1);
	_tmp17_ = message;
	soup_message_set_flags (_tmp17_, SOUP_MESSAGE_NO_REDIRECT);
	_tmp18_ = session;
	_tmp19_ = message;
	soup_session_send_message ((SoupSession*) _tmp18_, _tmp19_);
	_tmp20_ = message;
	_tmp21_ = _tmp20_->response_body;
	_tmp22_ = _tmp21_->data;
	_tmp22__length1 = (gint) _tmp21_->length;
	_tmp23_ = g_strdup ((const gchar*) _tmp22_);
	output = _tmp23_;
	_tmp24_ = output;
	_tmp25_ = string_slice (_tmp24_, (glong) 0, (glong) 6);
	_tmp26_ = _tmp25_;
	_tmp27_ = g_strcmp0 (_tmp26_, "ERROR:") != 0;
	_g_free0 (_tmp26_);
	if (_tmp27_) {
		const gchar* _tmp28_ = NULL;
		gchar* _tmp29_ = NULL;
		const gchar* _tmp30_ = NULL;
		const gchar* _tmp31_ = NULL;
		gchar* _tmp32_ = NULL;
		_tmp28_ = output;
		_tmp29_ = string_slice (_tmp28_, (glong) 0, (glong) (20 + NASC_PASTE_BIN_PASTE_ID_LEN));
		_g_free0 (output);
		output = _tmp29_;
		_tmp30_ = output;
		g_debug ("PasteBinDialog.vala:80: %s", _tmp30_);
		_tmp31_ = output;
		_tmp32_ = g_strdup (_tmp31_);
		_g_free0 (_vala_link);
		_vala_link = _tmp32_;
	} else {
		gchar* _tmp33_ = NULL;
		const gchar* _tmp34_ = NULL;
		const gchar* _tmp35_ = NULL;
		GQuark _tmp37_ = 0U;
		static GQuark _tmp36_label0 = 0;
		static GQuark _tmp36_label1 = 0;
		_tmp33_ = g_strdup ("");
		_g_free0 (_vala_link);
		_vala_link = _tmp33_;
		_tmp34_ = output;
		_tmp35_ = _tmp34_;
		_tmp37_ = (NULL == _tmp35_) ? 0 : g_quark_from_string (_tmp35_);
		if (_tmp37_ == ((0 != _tmp36_label0) ? _tmp36_label0 : (_tmp36_label0 = g_quark_from_static_string ("ERROR: Invalid POST request, or \"paste_code\" value empty")))) {
			switch (0) {
				default:
				{
					result = 2;
					_g_free0 (output);
					_g_free0 (request);
					_g_object_unref0 (message);
					_g_object_unref0 (session);
					_g_free0 (api_url);
					if (link) {
						*link = _vala_link;
					} else {
						_g_free0 (_vala_link);
					}
					return result;
				}
			}
		} else if (_tmp37_ == ((0 != _tmp36_label1) ? _tmp36_label1 : (_tmp36_label1 = g_quark_from_static_string ("ERROR: Invalid file format")))) {
			switch (0) {
				default:
				{
					result = 3;
					_g_free0 (output);
					_g_free0 (request);
					_g_object_unref0 (message);
					_g_object_unref0 (session);
					_g_free0 (api_url);
					if (link) {
						*link = _vala_link;
					} else {
						_g_free0 (_vala_link);
					}
					return result;
				}
			}
		} else {
			switch (0) {
				default:
				{
					result = 1;
					_g_free0 (output);
					_g_free0 (request);
					_g_object_unref0 (message);
					_g_object_unref0 (session);
					_g_free0 (api_url);
					if (link) {
						*link = _vala_link;
					} else {
						_g_free0 (_vala_link);
					}
					return result;
				}
			}
		}
	}
	result = 0;
	_g_free0 (output);
	_g_free0 (request);
	_g_object_unref0 (message);
	_g_object_unref0 (session);
	_g_free0 (api_url);
	if (link) {
		*link = _vala_link;
	} else {
		_g_free0 (_vala_link);
	}
	return result;
}


NascPasteBin* nasc_paste_bin_construct (GType object_type) {
	NascPasteBin * self = NULL;
	self = (NascPasteBin*) g_object_new (object_type, NULL);
	return self;
}


NascPasteBin* nasc_paste_bin_new (void) {
	return nasc_paste_bin_construct (NASC_TYPE_PASTE_BIN);
}


static void nasc_paste_bin_class_init (NascPasteBinClass * klass) {
	nasc_paste_bin_parent_class = g_type_class_peek_parent (klass);
}


static void nasc_paste_bin_instance_init (NascPasteBin * self) {
}


GType nasc_paste_bin_get_type (void) {
	static volatile gsize nasc_paste_bin_type_id__volatile = 0;
	if (g_once_init_enter (&nasc_paste_bin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (NascPasteBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nasc_paste_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NascPasteBin), 0, (GInstanceInitFunc) nasc_paste_bin_instance_init, NULL };
		GType nasc_paste_bin_type_id;
		nasc_paste_bin_type_id = g_type_register_static (G_TYPE_OBJECT, "NascPasteBin", &g_define_type_info, 0);
		g_once_init_leave (&nasc_paste_bin_type_id__volatile, nasc_paste_bin_type_id);
	}
	return nasc_paste_bin_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _nasc_paste_bin_dialog_send_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	nasc_paste_bin_dialog_send_button_clicked ((NascPasteBinDialog*) self);
}


NascPasteBinDialog* nasc_paste_bin_dialog_construct (GType object_type, GtkWindow* parent, Controller* controller) {
	NascPasteBinDialog * self = NULL;
	Controller* _tmp0_ = NULL;
	Controller* _tmp1_ = NULL;
	GtkWindow* _tmp2_ = NULL;
	const gchar* _tmp4_ = NULL;
	GtkBox* content2 = NULL;
	GtkBox* _tmp5_ = NULL;
	GtkBox* _tmp6_ = NULL;
	GtkLabel* label = NULL;
	GtkLabel* _tmp7_ = NULL;
	gchar* lab = NULL;
	const gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	GtkButton* _tmp13_ = NULL;
	g_return_val_if_fail (controller != NULL, NULL);
	self = (NascPasteBinDialog*) g_object_new (object_type, NULL);
	_tmp0_ = controller;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->controller);
	self->priv->controller = _tmp1_;
	_tmp2_ = parent;
	if (_tmp2_ != NULL) {
		GtkWindow* _tmp3_ = NULL;
		_tmp3_ = parent;
		gtk_window_set_transient_for ((GtkWindow*) self, _tmp3_);
	}
	_tmp4_ = _ ("Share via PasteBin");
	gtk_window_set_title ((GtkWindow*) self, _tmp4_);
	_tmp5_ = (GtkBox*) gtk_dialog_get_content_area ((GtkDialog*) self);
	_tmp6_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, gtk_box_get_type ()) ? ((GtkBox*) _tmp5_) : NULL);
	content2 = _tmp6_;
	_tmp7_ = (GtkLabel*) gtk_label_new ("");
	g_object_ref_sink (_tmp7_);
	label = _tmp7_;
	_tmp8_ = _ ("Share via PasteBin");
	_tmp9_ = g_strdup (_tmp8_);
	lab = _tmp9_;
	_tmp10_ = string_to_string (lab);
	_tmp11_ = g_strconcat ("<b>", _tmp10_, "</b>", NULL);
	_tmp12_ = _tmp11_;
	gtk_label_set_markup (label, _tmp12_);
	_g_free0 (_tmp12_);
	gtk_container_add ((GtkContainer*) content2, (GtkWidget*) label);
	nasc_paste_bin_dialog_create_dialog (self);
	_tmp13_ = self->priv->send_button;
	g_signal_connect_object (_tmp13_, "clicked", (GCallback) _nasc_paste_bin_dialog_send_button_clicked_gtk_button_clicked, self, 0);
	_g_free0 (lab);
	_g_object_unref0 (label);
	_g_object_unref0 (content2);
	return self;
}


NascPasteBinDialog* nasc_paste_bin_dialog_new (GtkWindow* parent, Controller* controller) {
	return nasc_paste_bin_dialog_construct (NASC_TYPE_PASTE_BIN_DIALOG, parent, controller);
}


static void nasc_paste_bin_dialog_create_dialog (NascPasteBinDialog* self) {
	GtkBox* _tmp0_ = NULL;
	GtkBox* _tmp1_ = NULL;
	GtkEntry* _tmp2_ = NULL;
	GtkEntry* _tmp3_ = NULL;
	GtkLabel* name_entry_l = NULL;
	const gchar* _tmp4_ = NULL;
	GtkLabel* _tmp5_ = NULL;
	GtkBox* name_entry_box = NULL;
	GtkBox* _tmp6_ = NULL;
	GtkEntry* _tmp7_ = NULL;
	GtkComboBoxText* _tmp8_ = NULL;
	GtkLabel* expiry_combo_l = NULL;
	const gchar* _tmp9_ = NULL;
	GtkLabel* _tmp10_ = NULL;
	GtkBox* expiry_combo_box = NULL;
	GtkBox* _tmp11_ = NULL;
	GtkComboBoxText* _tmp12_ = NULL;
	const gchar* _tmp13_ = NULL;
	GtkCheckButton* _tmp14_ = NULL;
	const gchar* _tmp15_ = NULL;
	GtkButton* _tmp16_ = NULL;
	GtkButtonBox* bottom_buttons = NULL;
	GtkButtonBox* _tmp17_ = NULL;
	GtkButton* _tmp18_ = NULL;
	GtkBox* _tmp19_ = NULL;
	GtkAlignment* _tmp20_ = NULL;
	GtkAlignment* _tmp21_ = NULL;
	GtkBox* _tmp22_ = NULL;
	GtkBox* _tmp23_ = NULL;
	GtkCheckButton* _tmp24_ = NULL;
	GtkBox* _tmp25_ = NULL;
	GtkBox* _tmp26_ = NULL;
	GtkBox* _tmp27_ = NULL;
	GtkBox* content2 = NULL;
	GtkBox* _tmp28_ = NULL;
	GtkBox* _tmp29_ = NULL;
	GtkBox* _tmp30_ = NULL;
	GtkButton* _tmp31_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->priv->content);
	self->priv->content = _tmp0_;
	_tmp1_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
	g_object_ref_sink (_tmp1_);
	_g_object_unref0 (self->priv->padding);
	self->priv->padding = _tmp1_;
	_tmp2_ = (GtkEntry*) gtk_entry_new ();
	g_object_ref_sink (_tmp2_);
	_g_object_unref0 (self->priv->name_entry);
	self->priv->name_entry = _tmp2_;
	_tmp3_ = self->priv->name_entry;
	gtk_entry_set_text (_tmp3_, "Test");
	_tmp4_ = _ ("Name:");
	_tmp5_ = (GtkLabel*) gtk_label_new (_tmp4_);
	g_object_ref_sink (_tmp5_);
	name_entry_l = _tmp5_;
	_tmp6_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 58);
	g_object_ref_sink (_tmp6_);
	name_entry_box = _tmp6_;
	gtk_box_pack_start (name_entry_box, (GtkWidget*) name_entry_l, FALSE, TRUE, (guint) 0);
	_tmp7_ = self->priv->name_entry;
	gtk_box_pack_start (name_entry_box, (GtkWidget*) _tmp7_, TRUE, TRUE, (guint) 0);
	_tmp8_ = (GtkComboBoxText*) gtk_combo_box_text_new ();
	g_object_ref_sink (_tmp8_);
	_g_object_unref0 (self->priv->expiry_combo);
	self->priv->expiry_combo = _tmp8_;
	nasc_paste_bin_dialog_populate_expiry_combo (self);
	_tmp9_ = _ ("Expiry time:");
	_tmp10_ = (GtkLabel*) gtk_label_new (_tmp9_);
	g_object_ref_sink (_tmp10_);
	expiry_combo_l = _tmp10_;
	_tmp11_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 28);
	g_object_ref_sink (_tmp11_);
	expiry_combo_box = _tmp11_;
	gtk_box_pack_start (expiry_combo_box, (GtkWidget*) expiry_combo_l, FALSE, TRUE, (guint) 0);
	_tmp12_ = self->priv->expiry_combo;
	gtk_box_pack_start (expiry_combo_box, (GtkWidget*) _tmp12_, TRUE, TRUE, (guint) 0);
	_tmp13_ = _ ("Keep this paste private");
	_tmp14_ = (GtkCheckButton*) gtk_check_button_new_with_label (_tmp13_);
	g_object_ref_sink (_tmp14_);
	_g_object_unref0 (self->priv->private_check);
	self->priv->private_check = _tmp14_;
	_tmp15_ = _ ("Upload");
	_tmp16_ = (GtkButton*) gtk_button_new_with_label (_tmp15_);
	g_object_ref_sink (_tmp16_);
	_g_object_unref0 (self->priv->send_button);
	self->priv->send_button = _tmp16_;
	_tmp17_ = (GtkButtonBox*) gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	g_object_ref_sink (_tmp17_);
	bottom_buttons = _tmp17_;
	gtk_button_box_set_layout (bottom_buttons, GTK_BUTTONBOX_CENTER);
	gtk_box_set_spacing ((GtkBox*) bottom_buttons, 10);
	_tmp18_ = self->priv->send_button;
	gtk_box_pack_end ((GtkBox*) bottom_buttons, (GtkWidget*) _tmp18_, TRUE, TRUE, (guint) 0);
	_tmp19_ = self->priv->content;
	_tmp20_ = nasc_paste_bin_dialog_wrap_alignment ((GtkWidget*) name_entry_box, 12, 0, 0, 0);
	_tmp21_ = _tmp20_;
	gtk_box_pack_start (_tmp19_, (GtkWidget*) _tmp21_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp21_);
	_tmp22_ = self->priv->content;
	gtk_box_pack_start (_tmp22_, (GtkWidget*) expiry_combo_box, TRUE, TRUE, (guint) 0);
	_tmp23_ = self->priv->content;
	_tmp24_ = self->priv->private_check;
	gtk_box_pack_start (_tmp23_, (GtkWidget*) _tmp24_, TRUE, TRUE, (guint) 0);
	_tmp25_ = self->priv->content;
	gtk_box_pack_end (_tmp25_, (GtkWidget*) bottom_buttons, TRUE, TRUE, (guint) 12);
	_tmp26_ = self->priv->padding;
	_tmp27_ = self->priv->content;
	gtk_box_pack_start (_tmp26_, (GtkWidget*) _tmp27_, FALSE, TRUE, (guint) 12);
	_tmp28_ = (GtkBox*) gtk_dialog_get_content_area ((GtkDialog*) self);
	_tmp29_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp28_, gtk_box_get_type ()) ? ((GtkBox*) _tmp28_) : NULL);
	content2 = _tmp29_;
	_tmp30_ = self->priv->padding;
	gtk_container_add ((GtkContainer*) content2, (GtkWidget*) _tmp30_);
	gtk_widget_show_all ((GtkWidget*) self);
	_tmp31_ = self->priv->send_button;
	gtk_widget_grab_focus ((GtkWidget*) _tmp31_);
	_g_object_unref0 (content2);
	_g_object_unref0 (bottom_buttons);
	_g_object_unref0 (expiry_combo_box);
	_g_object_unref0 (expiry_combo_l);
	_g_object_unref0 (name_entry_box);
	_g_object_unref0 (name_entry_l);
}


static GtkAlignment* nasc_paste_bin_dialog_wrap_alignment (GtkWidget* widget, gint top, gint right, gint bottom, gint left) {
	GtkAlignment* result = NULL;
	GtkAlignment* alignment = NULL;
	GtkAlignment* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	GtkWidget* _tmp5_ = NULL;
	g_return_val_if_fail (widget != NULL, NULL);
	_tmp0_ = (GtkAlignment*) gtk_alignment_new (0.0f, 0.0f, 1.0f, 1.0f);
	g_object_ref_sink (_tmp0_);
	alignment = _tmp0_;
	_tmp1_ = top;
	g_object_set (alignment, "top-padding", (guint) _tmp1_, NULL);
	_tmp2_ = right;
	g_object_set (alignment, "right-padding", (guint) _tmp2_, NULL);
	_tmp3_ = bottom;
	g_object_set (alignment, "bottom-padding", (guint) _tmp3_, NULL);
	_tmp4_ = left;
	g_object_set (alignment, "left-padding", (guint) _tmp4_, NULL);
	_tmp5_ = widget;
	gtk_container_add ((GtkContainer*) alignment, _tmp5_);
	result = alignment;
	return result;
}


static void nasc_paste_bin_dialog_send_button_clicked (NascPasteBinDialog* self) {
	GtkBox* _tmp0_ = NULL;
	GtkSpinner* spinner = NULL;
	GtkSpinner* _tmp1_ = NULL;
	GtkBox* _tmp2_ = NULL;
	GtkSpinner* _tmp3_ = NULL;
	GtkSpinner* _tmp4_ = NULL;
	GtkSpinner* _tmp5_ = NULL;
	gchar* link = NULL;
	gint submit_result = 0;
	gchar* _tmp6_ = NULL;
	gint _tmp7_ = 0;
	GtkSpinner* _tmp8_ = NULL;
	GtkBox* box = NULL;
	GtkBox* _tmp9_ = NULL;
	gint _tmp10_ = 0;
	GtkBox* _tmp26_ = NULL;
	GtkBox* _tmp27_ = NULL;
	GtkBox* _tmp28_ = NULL;
	GtkBox* _tmp29_ = NULL;
	GtkBox* _tmp30_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->content;
	gtk_widget_hide ((GtkWidget*) _tmp0_);
	_tmp1_ = (GtkSpinner*) gtk_spinner_new ();
	g_object_ref_sink (_tmp1_);
	spinner = _tmp1_;
	_tmp2_ = self->priv->padding;
	_tmp3_ = spinner;
	gtk_box_pack_start (_tmp2_, (GtkWidget*) _tmp3_, TRUE, TRUE, (guint) 10);
	_tmp4_ = spinner;
	gtk_widget_show ((GtkWidget*) _tmp4_);
	_tmp5_ = spinner;
	gtk_spinner_start (_tmp5_);
	_tmp7_ = nasc_paste_bin_dialog_submit_paste (self, &_tmp6_);
	_g_free0 (link);
	link = _tmp6_;
	submit_result = _tmp7_;
	_tmp8_ = spinner;
	gtk_widget_hide ((GtkWidget*) _tmp8_);
	_tmp9_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
	g_object_ref_sink (_tmp9_);
	box = _tmp9_;
	_tmp10_ = submit_result;
	if (_tmp10_ == 0) {
		GtkLinkButton* link_button = NULL;
		const gchar* _tmp11_ = NULL;
		GtkLinkButton* _tmp12_ = NULL;
		GtkBox* _tmp13_ = NULL;
		GtkLinkButton* _tmp14_ = NULL;
		_tmp11_ = link;
		_tmp12_ = (GtkLinkButton*) gtk_link_button_new (_tmp11_);
		g_object_ref_sink (_tmp12_);
		link_button = _tmp12_;
		_tmp13_ = box;
		_tmp14_ = link_button;
		gtk_box_pack_start (_tmp13_, (GtkWidget*) _tmp14_, FALSE, TRUE, (guint) 25);
		_g_object_unref0 (link_button);
	} else {
		GString* error_desc = NULL;
		GString* _tmp15_ = NULL;
		gint _tmp16_ = 0;
		GString* _tmp20_ = NULL;
		GtkLabel* err_label = NULL;
		GString* _tmp21_ = NULL;
		const gchar* _tmp22_ = NULL;
		GtkLabel* _tmp23_ = NULL;
		GtkBox* _tmp24_ = NULL;
		GtkLabel* _tmp25_ = NULL;
		_tmp15_ = g_string_new ("");
		error_desc = _tmp15_;
		_tmp16_ = submit_result;
		switch (_tmp16_) {
			case 2:
			{
				GString* _tmp17_ = NULL;
				_tmp17_ = error_desc;
				g_string_append (_tmp17_, "The text is void!");
				break;
			}
			case 3:
			{
				GString* _tmp18_ = NULL;
				_tmp18_ = error_desc;
				g_string_append (_tmp18_, "The text format doesn't exist");
				break;
			}
			default:
			{
				GString* _tmp19_ = NULL;
				_tmp19_ = error_desc;
				g_string_append (_tmp19_, "An error occured");
				break;
			}
		}
		_tmp20_ = error_desc;
		g_string_append (_tmp20_, "\n" "The text was sent");
		_tmp21_ = error_desc;
		_tmp22_ = _tmp21_->str;
		_tmp23_ = (GtkLabel*) gtk_label_new (_tmp22_);
		g_object_ref_sink (_tmp23_);
		err_label = _tmp23_;
		_tmp24_ = box;
		_tmp25_ = err_label;
		gtk_box_pack_start (_tmp24_, (GtkWidget*) _tmp25_, FALSE, TRUE, (guint) 0);
		_g_object_unref0 (err_label);
		_g_string_free0 (error_desc);
	}
	_tmp26_ = self->priv->padding;
	_tmp27_ = box;
	gtk_box_pack_start (_tmp26_, (GtkWidget*) _tmp27_, FALSE, TRUE, (guint) 12);
	_tmp28_ = self->priv->padding;
	gtk_widget_set_halign ((GtkWidget*) _tmp28_, GTK_ALIGN_CENTER);
	_tmp29_ = box;
	gtk_widget_set_valign ((GtkWidget*) _tmp29_, GTK_ALIGN_CENTER);
	_tmp30_ = box;
	gtk_widget_show_all ((GtkWidget*) _tmp30_);
	_g_object_unref0 (box);
	_g_free0 (link);
	_g_object_unref0 (spinner);
}


static gint nasc_paste_bin_dialog_submit_paste (NascPasteBinDialog* self, gchar** link) {
	gchar* _vala_link = NULL;
	gint result = 0;
	gchar* paste_code = NULL;
	Controller* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* paste_name = NULL;
	GtkEntry* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	GtkCheckButton* _tmp7_ = NULL;
	gboolean _tmp8_ = FALSE;
	gchar* paste_private = NULL;
	gchar* _tmp9_ = NULL;
	gchar* paste_expire_date = NULL;
	GtkComboBoxText* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	gint submit_result = 0;
	const gchar* _tmp13_ = NULL;
	const gchar* _tmp14_ = NULL;
	gchar* _tmp15_ = NULL;
	gint _tmp16_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->controller;
	_tmp1_ = controller_get_export_text (_tmp0_);
	paste_code = _tmp1_;
	_tmp2_ = self->priv->name_entry;
	_tmp3_ = gtk_entry_get_text (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup (_tmp4_);
	paste_name = _tmp5_;
	_tmp7_ = self->priv->private_check;
	_tmp8_ = gtk_toggle_button_get_active ((GtkToggleButton*) _tmp7_);
	if (_tmp8_ == TRUE) {
		_tmp6_ = NASC_PASTE_BIN_PRIVATE;
	} else {
		_tmp6_ = NASC_PASTE_BIN_PUBLIC;
	}
	_tmp9_ = g_strdup (_tmp6_);
	paste_private = _tmp9_;
	_tmp10_ = self->priv->expiry_combo;
	_tmp11_ = gtk_combo_box_get_active_id ((GtkComboBox*) _tmp10_);
	_tmp12_ = g_strdup (_tmp11_);
	paste_expire_date = _tmp12_;
	_tmp13_ = paste_code;
	_tmp14_ = paste_name;
	_tmp16_ = nasc_paste_bin_submit (&_tmp15_, _tmp13_, _tmp14_, paste_private, paste_expire_date);
	_g_free0 (_vala_link);
	_vala_link = _tmp15_;
	submit_result = _tmp16_;
	result = submit_result;
	_g_free0 (paste_expire_date);
	_g_free0 (paste_private);
	_g_free0 (paste_name);
	_g_free0 (paste_code);
	if (link) {
		*link = _vala_link;
	} else {
		_g_free0 (_vala_link);
	}
	return result;
}


static void nasc_paste_bin_dialog_populate_expiry_combo (NascPasteBinDialog* self) {
	GtkComboBoxText* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GtkComboBoxText* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	GtkComboBoxText* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	GtkComboBoxText* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	GtkComboBoxText* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->expiry_combo;
	_tmp1_ = _ ("Never");
	gtk_combo_box_text_append (_tmp0_, NASC_PASTE_BIN_NEVER, _tmp1_);
	_tmp2_ = self->priv->expiry_combo;
	_tmp3_ = _ ("Ten minutes");
	gtk_combo_box_text_append (_tmp2_, NASC_PASTE_BIN_TEN_MINUTES, _tmp3_);
	_tmp4_ = self->priv->expiry_combo;
	_tmp5_ = _ ("One hour");
	gtk_combo_box_text_append (_tmp4_, NASC_PASTE_BIN_HOUR, _tmp5_);
	_tmp6_ = self->priv->expiry_combo;
	_tmp7_ = _ ("One day");
	gtk_combo_box_text_append (_tmp6_, NASC_PASTE_BIN_DAY, _tmp7_);
	_tmp8_ = self->priv->expiry_combo;
	_tmp9_ = _ ("One month");
	gtk_combo_box_text_append (_tmp8_, NASC_PASTE_BIN_MONTH, _tmp9_);
}


static void nasc_paste_bin_dialog_class_init (NascPasteBinDialogClass * klass) {
	nasc_paste_bin_dialog_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (NascPasteBinDialogPrivate));
	G_OBJECT_CLASS (klass)->finalize = nasc_paste_bin_dialog_finalize;
}


static void nasc_paste_bin_dialog_instance_init (NascPasteBinDialog * self) {
	self->priv = NASC_PASTE_BIN_DIALOG_GET_PRIVATE (self);
}


static void nasc_paste_bin_dialog_finalize (GObject* obj) {
	NascPasteBinDialog * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, NASC_TYPE_PASTE_BIN_DIALOG, NascPasteBinDialog);
	_g_object_unref0 (self->priv->content);
	_g_object_unref0 (self->priv->padding);
	_g_object_unref0 (self->priv->name_entry);
	_g_object_unref0 (self->priv->expiry_combo);
	_g_object_unref0 (self->priv->private_check);
	_g_object_unref0 (self->priv->send_button);
	_g_object_unref0 (self->priv->controller);
	G_OBJECT_CLASS (nasc_paste_bin_dialog_parent_class)->finalize (obj);
}


GType nasc_paste_bin_dialog_get_type (void) {
	static volatile gsize nasc_paste_bin_dialog_type_id__volatile = 0;
	if (g_once_init_enter (&nasc_paste_bin_dialog_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (NascPasteBinDialogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nasc_paste_bin_dialog_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NascPasteBinDialog), 0, (GInstanceInitFunc) nasc_paste_bin_dialog_instance_init, NULL };
		GType nasc_paste_bin_dialog_type_id;
		nasc_paste_bin_dialog_type_id = g_type_register_static (gtk_dialog_get_type (), "NascPasteBinDialog", &g_define_type_info, 0);
		g_once_init_leave (&nasc_paste_bin_dialog_type_id__volatile, nasc_paste_bin_dialog_type_id);
	}
	return nasc_paste_bin_dialog_type_id__volatile;
}


