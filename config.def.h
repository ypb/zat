/* settings */
int   default_width      = 800;
int   default_height     = 600;
float zoom_step          = 10;
float zoom_min           = 10;
float zoom_max           = 400;
float scroll_step        = 40;
float transparency       = 0.4;
float smooth_scrolling   = 0.0;
int   n_completion_items = 15;

/* completion */
static const char FORMAT_COMMAND[]     = "<b>%s</b>";
static const char FORMAT_DESCRIPTION[] = "<i>%s</i>";

/* Use XDG directory specification if no config and data directory are given on
 * the command line. Uncomment the next line if you just want to use CONFIG_DIR
 * and DATA_DIR instead (these will be the default locations if the XDG_*
 * environment variables are not set anyway) */
/* #define ZATHURA_NO_XDG */

/* directories and files */
static const char BOOKMARK_FILE[] = "bookmarks";
static const char ZATHURA_RC[]    = "zathurarc";
static const char GLOBAL_RC[]     = "/etc/zathurarc";
static const char CONFIG_DIR[]    = "~/.config/zathura";
static const char DATA_DIR[]      = "~/.local/share/zathura";

/* bookmarks */
static const char BM_PAGE_ENTRY[]  = "page";
static const char BM_PAGE_OFFSET[] = "offset";
int save_position = 1;

/* look */
char* font                   = "monospace normal 9";
char* default_bgcolor        = "#000000";
char* default_fgcolor        = "#DDDDDD";
char* inputbar_bgcolor       = "#141414";
char* inputbar_fgcolor       = "#9FBC00";
char* statusbar_bgcolor      = "#000000";
char* statusbar_fgcolor      = "#FFFFFF";
char* completion_fgcolor     = "#DDDDDD";
char* completion_bgcolor     = "#232323";
char* completion_g_fgcolor   = "#DEDEDE";
char* completion_g_bgcolor   = "#FF00FF";
char* completion_hl_fgcolor  = "#232323";
char* completion_hl_bgcolor  = "#9FBC00";
char* notification_e_bgcolor = "#FF1212";
char* notification_e_fgcolor = "#FFFFFF";
char* notification_w_bgcolor = "#FFF712";
char* notification_w_fgcolor = "#000000";
char* recolor_darkcolor      = "#353535";
char* recolor_lightcolor     = "#DBDBDB";

char* search_highlight       = "#9FBC00";
char* select_text            = "#000000";

/* statusbar */
char* default_text = "[No Name]";

/* printing */
char* list_printer_command = "lpstat -v | sed -n '/^.*device for \\(.*\\): .*$/s//\\1/p'";
char* print_command = "lp -d '%s' -P %s %s %s"; /* printer / pages / file */

/* open uri */
char* uri_command = "firefox %s"; /* uri */

/* additional settings */
gboolean show_scrollbars = FALSE;
gboolean scroll_wrap     = TRUE;
int adjust_open          = ADJUST_BESTFIT;
#define SELECTION_STYLE POPPLER_SELECTION_GLYPH
#define GOTO_MODE GOTO_LABELS /* GOTO_DEFAULT, GOTO_LABELS, GOTO_OFFSET */

/* define additional modes */
#define INSERT     (1 << 4)
#define VISUAL     (1 << 5)
#define EMACS_CX   (1 << 6)

/* mode names */
ModeName mode_names[] = {
  /* default mode names */
  {"all",        ALL,         ""},
  {"fullscreen", FULLSCREEN,  ""},
  {"index",      INDEX,       ""},
  {"normal",     NORMAL,      ""},
  /* additional mode names */
  {"insert",     INSERT,      "-- INSERT --"},
  {"visual",     VISUAL,      "-- VISUAL --"}
};

/* shortcuts */
Shortcut shortcuts[] = {
  /* mask,             key,               function,             mode,                argument */
  {GDK_CONTROL_MASK,   GDK_c,             sc_abort,             ALL,                 {0} },
  {0,                  GDK_a,             sc_adjust_window,     NORMAL,              { ADJUST_BESTFIT } },
  {0,                  GDK_s,             sc_adjust_window,     NORMAL,              { ADJUST_WIDTH } },
  {0,                  GDK_Escape,        sc_abort,             ALL,                 {0} },
  {0,                  GDK_BackSpace,     sc_change_buffer,     ALL,                 { DELETE_LAST } },
  {0,                  GDK_i,             sc_change_mode,       NORMAL,              { INSERT } },
  {0,                  GDK_v,             sc_change_mode,       NORMAL,              { VISUAL } },
  {0,                  GDK_m,             sc_change_mode,       NORMAL,              { ADD_MARKER } },
  {0,                  GDK_apostrophe,    sc_change_mode,       NORMAL,              { EVAL_MARKER } },
  {0,                  GDK_slash,         sc_focus_inputbar,    NORMAL,              { .data = "/" } },
  {GDK_SHIFT_MASK,     GDK_slash,         sc_focus_inputbar,    NORMAL,              { .data = "/" } },
  {GDK_SHIFT_MASK,     GDK_question,      sc_focus_inputbar,    NORMAL,              { .data = "?" } },
  {0,                  GDK_colon,         sc_focus_inputbar,    NORMAL,              { .data = ":" } },
  {0,                  GDK_o,             sc_focus_inputbar,    NORMAL,              { .data = ":open " } },
  {0,                  GDK_O,             sc_focus_inputbar,    NORMAL,              { APPEND_FILEPATH, .data = ":open " } },
  {0,                  GDK_f,             sc_follow,            NORMAL,              {0} },
  {0,                  GDK_J,             sc_navigate,          NORMAL,              { NEXT } },
  {0,                  GDK_K,             sc_navigate,          NORMAL,              { PREVIOUS } },
  {GDK_MOD1_MASK,      GDK_Right,         sc_navigate,          NORMAL,              { NEXT } },
  {GDK_MOD1_MASK,      GDK_Left,          sc_navigate,          NORMAL,              { PREVIOUS } },
  {0,                  GDK_Left,          sc_navigate,          FULLSCREEN,          { PREVIOUS } },
  {0,                  GDK_Up,            sc_navigate,          FULLSCREEN,          { PREVIOUS } },
  {0,                  GDK_Down,          sc_navigate,          FULLSCREEN,          { NEXT } },
  {0,                  GDK_Right,         sc_navigate,          FULLSCREEN,          { NEXT } },
  {0,                  GDK_space,         sc_navigate,          FULLSCREEN,          { NEXT } },
  {0,                  GDK_k,             sc_navigate_index,    INDEX,               { UP } },
  {0,                  GDK_j,             sc_navigate_index,    INDEX,               { DOWN } },
  {0,                  GDK_h,             sc_navigate_index,    INDEX,               { COLLAPSE } },
  {0,                  GDK_l,             sc_navigate_index,    INDEX,               { EXPAND } },
  {0,                  GDK_space,         sc_navigate_index,    INDEX,               { SELECT } },
  {0,                  GDK_Return,        sc_navigate_index,    INDEX,               { SELECT } },
  {GDK_CONTROL_MASK,   GDK_i,             sc_recolor,           NORMAL,              {0} },
  {0,                  GDK_R,             sc_reload,            NORMAL,              {0} },
  {0,                  GDK_r,             sc_rotate,            NORMAL,              {0} },
  {0,                  GDK_n,             sc_search,            NORMAL,              { FORWARD } },
  {0,                  GDK_N,             sc_search,            NORMAL,              { BACKWARD } },
  {0,                  GDK_h,             sc_scroll,            NORMAL,              { LEFT } },
  {0,                  GDK_j,             sc_scroll,            NORMAL,              { DOWN } },
  {0,                  GDK_k,             sc_scroll,            NORMAL,              { UP } },
  {0,                  GDK_l,             sc_scroll,            NORMAL,              { RIGHT } },
  {0,                  GDK_Left,          sc_scroll,            NORMAL,              { LEFT } },
  {0,                  GDK_Up,            sc_scroll,            NORMAL,              { UP } },
  {0,                  GDK_Down,          sc_scroll,            NORMAL,              { DOWN } },
  {0,                  GDK_Right,         sc_scroll,            NORMAL,              { RIGHT } },
  {GDK_CONTROL_MASK,   GDK_d,             sc_scroll,            NORMAL,              { HALF_DOWN } },
  {GDK_CONTROL_MASK,   GDK_u,             sc_scroll,            NORMAL,              { HALF_UP } },
  {GDK_CONTROL_MASK,   GDK_f,             sc_scroll,            NORMAL,              { FULL_DOWN } },
  {GDK_CONTROL_MASK,   GDK_b,             sc_scroll,            NORMAL,              { FULL_UP } },
  {0,                  GDK_space,         sc_scroll,            NORMAL,              { FULL_DOWN } },
  {0,                  GDK_0,             sc_switch_goto_mode,  NORMAL,              {0} },
  {0,                  GDK_F5,            sc_toggle_fullscreen, NORMAL | FULLSCREEN, {0} },
  {0,                  GDK_Tab,           sc_toggle_index,      NORMAL | INDEX,      {0} },
  {GDK_CONTROL_MASK,   GDK_m,             sc_toggle_inputbar,   NORMAL,              {0} },
  {GDK_CONTROL_MASK,   GDK_n,             sc_toggle_statusbar,  NORMAL,              {0} },
  {GDK_CONTROL_MASK,   GDK_q,             sc_quit,              ALL,                 {0} },
  {0,                  GDK_plus,          sc_zoom,              NORMAL | FULLSCREEN, { ZOOM_IN } },
  {0,                  GDK_minus,         sc_zoom,              NORMAL | FULLSCREEN, { ZOOM_OUT } },
  {0,                  GDK_equal,         sc_zoom,              NORMAL | FULLSCREEN, { ZOOM_ORIGINAL } },
};

/* inputbar shortcuts */
InputbarShortcut inputbar_shortcuts[] = {
  /* mask,             key,               function,                  argument */
  {0,                  GDK_Escape,        isc_abort,                 {0} },
  {GDK_CONTROL_MASK,   GDK_c,             isc_abort,                 {0} },
  {0,                  GDK_Up,            isc_command_history,       {0} },
  {0,                  GDK_Down,          isc_command_history,       {0} },
  {0,                  GDK_Tab,           isc_completion,            { NEXT } },
  {GDK_CONTROL_MASK,   GDK_Tab,           isc_completion,            { NEXT_GROUP } },
  {0,                  GDK_ISO_Left_Tab,  isc_completion,            { PREVIOUS } },
  {GDK_CONTROL_MASK,   GDK_ISO_Left_Tab,  isc_completion,            { PREVIOUS_GROUP } },
  {0,                  GDK_BackSpace,     isc_string_manipulation,   { DELETE_LAST_CHAR } },
  {GDK_CONTROL_MASK,   GDK_h,             isc_string_manipulation,   { DELETE_LAST_CHAR } },
  {GDK_CONTROL_MASK,   GDK_u,             isc_string_manipulation,   { DELETE_TO_LINE_START } },
  {GDK_CONTROL_MASK,   GDK_w,             isc_string_manipulation,   { DELETE_LAST_WORD } },
  {GDK_CONTROL_MASK,   GDK_f,             isc_string_manipulation,   { NEXT_CHAR } },
  {GDK_CONTROL_MASK,   GDK_b,             isc_string_manipulation,   { PREVIOUS_CHAR } },
};

/* mouse settings */
MouseScrollEvent mouse_scroll_events[] = {
  /* direction,      function,  argument */
  {GDK_SCROLL_LEFT,  sc_scroll, { LEFT } },
  {GDK_SCROLL_UP,    sc_scroll, { UP } },
  {GDK_SCROLL_DOWN,  sc_scroll, { DOWN } },
  {GDK_SCROLL_RIGHT, sc_scroll, { RIGHT } },
};

/* commands */
Command commands[] = {
  /* command,   abbreviation,   function,            completion,   description  */
  {"blist",     0,              cmd_open_bookmark,   cc_bookmark,  "List and open bookmark" },
  {"bmark",     "b",            cmd_bookmark,        0,            "Bookmark current page" },
  {"close",     "c",            cmd_close,           0,            "Close current file" },
  {"coffset",   0,              cmd_correct_offset,  0,            "Correct page offset" },
  {"delbmark",  0,              cmd_delete_bookmark, cc_bookmark,  "Bookmark current page" },
  {"export",    "e",            cmd_export,          cc_export,    "Export images or attached files" },
  {"info",      "i",            cmd_info,            0,            "Show information about the document" },
  {"map",       "m",            cmd_map,             0,            "Map keybinding to a function" },
  {"open",      "o",            cmd_open,            cc_open,      "Open a file" },
  {"print",     "p",            cmd_print,           cc_print,     "Print the document" },
  {"quit",      "q",            cmd_quit,            0,            "Quit zathura" },
  {"rotate",    "r",            cmd_rotate,          0,            "Rotate the page" },
  {"set",       "s",            cmd_set,             cc_set,       "Set an option" },
  {"write",     "w",            cmd_save,            0,            "Save the document" },
};

/* buffer commands */
BufferCommand buffer_commands[] = {
  /* regex,        function,       argument */
  {"^gg$",         bcmd_goto,       { TOP } },
  {"^G$",          bcmd_goto,       { BOTTOM } },
  {"^[0-9]+G$",    bcmd_goto,       {0} },
  {"^zI$",         bcmd_zoom,       { ZOOM_IN } },
  {"^zO$",         bcmd_zoom,       { ZOOM_OUT } },
  {"^z0$",         bcmd_zoom,       { ZOOM_ORIGINAL } },
  {"^[0-9]+Z$",    bcmd_zoom,       { ZOOM_SPECIFIC } },
  {"^[0-9]+%$",    bcmd_scroll,     {0} },
};

/* special commands */
SpecialCommand special_commands[] = {
  /* identifier,   function,      a,   argument */
  {'/',            scmd_search,   1,   { DOWN } },
  {'?',            scmd_search,   1,   { UP } },
};

/* settings */
Setting settings[] = {
  /* name,                   variable,                           type,  render,  re-init, description */
  {"adjust_open",            &(adjust_open),                     'i',   FALSE,   FALSE,   "Adjust mode"},
  {"browser",                &(uri_command),                     's',   FALSE,   FALSE,   "Command to open URIs"},
  {"completion_bgcolor",     &(completion_bgcolor),              's',   FALSE,   TRUE,    "Completion background color"},
  {"completion_fgcolor",     &(completion_fgcolor),              's',   FALSE,   TRUE,    "Completion foreground color"},
  {"completion_g_bgcolor",   &(completion_g_bgcolor),            's',   FALSE,   TRUE,    "Completion (group) background color"},
  {"completion_g_fgcolor",   &(completion_g_fgcolor),            's',   FALSE,   TRUE,    "Completion (group) foreground color"},
  {"completion_hl_bgcolor",  &(completion_hl_bgcolor),           's',   FALSE,   TRUE,    "Completion (highlight) background color"},
  {"completion_hl_fgcolor",  &(completion_hl_fgcolor),           's',   FALSE,   TRUE,    "Completion (highlight) foreground color"},
  {"default_bgcolor",        &(default_bgcolor),                 's',   FALSE,   TRUE,    "Default background color"},
  {"default_fgcolor",        &(default_fgcolor),                 's',   FALSE,   TRUE,    "Default foreground color"},
  {"default_text",           &(default_text),                    's',   FALSE,   FALSE,   "Default text"},
  {"font",                   &(font),                            's',   FALSE,   TRUE,    "The used font" },
  {"height",                 &(default_height),                  'i',   FALSE,   FALSE,   "Default window height"},
  {"inputbar_bgcolor",       &(inputbar_bgcolor),                's',   FALSE,   TRUE,    "Inputbar background color"},
  {"inputbar_fgcolor",       &(inputbar_fgcolor),                's',   FALSE,   TRUE,    "Inputbar foreground color"},
  {"labels",                 &(Zathura.Global.enable_labelmode), 'b',   FALSE,   TRUE,    "Allow label mode"},
  {"list_printer_command",   &(list_printer_command),            's',   FALSE,   FALSE,   "Command to list printers"},
  {"n_completion_items",     &(n_completion_items),              'i',   FALSE,   FALSE,   "Number of completion items"},
  {"notification_e_bgcolor", &(notification_e_bgcolor),          's',   FALSE,   TRUE,    "Notification (error) background color"},
  {"notification_e_fgcolor", &(notification_e_fgcolor),          's',   FALSE,   TRUE,    "Notification (error) foreground color"},
  {"notification_w_bgcolor", &(notification_w_bgcolor),          's',   FALSE,   TRUE,    "Notification (warning) background color"},
  {"notification_w_fgcolor", &(notification_w_fgcolor),          's',   FALSE,   TRUE,    "Notification (warning) foreground color"},
  {"offset",                 &(Zathura.PDF.page_offset),         'i',   FALSE,   FALSE,   "Optional page offset" },
  {"print_command",          &(print_command),                   's',   FALSE,   FALSE,   "Command to print"},
  {"recolor",                &(Zathura.Global.recolor),          'b',   TRUE,    FALSE,   "Invert the image" },
  {"recolor_darkcolor",      &(recolor_darkcolor),               's',   FALSE,   TRUE,    "Recoloring (dark color)"},
  {"recolor_lightcolor",     &(recolor_lightcolor),              's',   FALSE,   TRUE,    "Recoloring (light color)"},
  {"save_position",          &(save_position),                   'b',   FALSE,   FALSE,   "Save position in file on quit and restore it on open"},
  {"scroll_step",            &(scroll_step),                     'f',   FALSE,   FALSE,   "Scroll step"},
  {"scroll_wrap",            &(scroll_wrap),                     'b',   FALSE,   FALSE,   "Wrap scolling at last page"},
  {"scrollbars",             &(show_scrollbars),                 'b',   FALSE,   TRUE,    "Show scrollbars"},
  {"show_statusbar",         &(Zathura.Global.show_statusbar),   'b',   FALSE,   TRUE,    "Show statusbar"},
  {"show_inputbar",          &(Zathura.Global.show_inputbar),    'b',   FALSE,   TRUE,    "Show inputbar"},
  {"search_highlight",       &(search_highlight),                's',   FALSE,   TRUE,    "Highlighted results"},
  {"select_text",            &(select_text),                     's',   FALSE,   TRUE,    "Rectangle of the selected text"},
  {"smooth_scrolling",       &(smooth_scrolling),                'f',   FALSE,   TRUE,    "Smooth scrolling"},
  {"statusbar_bgcolor",      &(statusbar_bgcolor),               's',   FALSE,   TRUE,    "Statusbar background color"},
  {"statusbar_fgcolor",      &(statusbar_fgcolor),               's',   FALSE,   TRUE,    "Statusbar foreground color"},
  {"transparency",           &(transparency),                    'f',   FALSE,   FALSE,   "Transparency of rectangles"},
  {"uri_command",            &(uri_command),                     's',   FALSE,   FALSE,   "Command for opening URIs"},
  {"width",                  &(default_width),                   'i',   FALSE,   FALSE,   "Default window width"},
  {"zoom_max",               &(zoom_max),                        'f',   FALSE,   FALSE,   "Zoom maximum"},
  {"zoom_min",               &(zoom_min),                        'f',   FALSE,   FALSE,   "Zoom minimum"},
  {"zoom_step",              &(zoom_step),                       'f',   FALSE,   FALSE,   "Zoom step"},
};

/* shortcut names */
ShortcutName shortcut_names[] = {
  {"abort",             sc_abort},
  {"adjust_window",     sc_adjust_window},
  {"change_buffer",     sc_change_buffer},
  {"change_mode",       sc_change_mode},
  {"focus_inputbar",    sc_focus_inputbar},
  {"follow",            sc_follow},
  {"navigate",          sc_navigate},
  {"navigate_index",    sc_navigate_index},
  {"quit",              sc_quit},
  {"recolor",           sc_recolor},
  {"reload",            sc_reload},
  {"rotate",            sc_rotate},
  {"scroll",            sc_scroll},
  {"search",            sc_search},
  {"switch_goto_mode",  sc_switch_goto_mode},
  {"toggle_fullscreen", sc_toggle_fullscreen},
  {"toggle_index",      sc_toggle_index},
  {"toggle_inputbar",   sc_toggle_inputbar},
  {"toggle_statusbar",  sc_toggle_statusbar},
  {"zoom",              sc_zoom},
};

/* argument names */
ArgumentName argument_names[] = {
  {"add_marker",  ADD_MARKER},
  {"backward",    BACKWARD},
  {"bestfit",     ADJUST_BESTFIT},
  {"collapse",    COLLAPSE},
  {"delete_last", DELETE_LAST},
  {"down",        DOWN},
  {"eval_marker", EVAL_MARKER},
  {"expand",      EXPAND},
  {"forward",     FORWARD},
  {"full_down",   FULL_DOWN},
  {"full_up",     FULL_UP},
  {"half_down",   HALF_DOWN},
  {"half_up",     HALF_UP},
  {"in",          ZOOM_IN},
  {"insert",      INSERT},
  {"left",        LEFT},
  {"next",        NEXT},
  {"original",    ZOOM_ORIGINAL},
  {"out",         ZOOM_OUT},
  {"previous",    PREVIOUS},
  {"right",       RIGHT},
  {"select",      SELECT},
  {"up",          UP},
  {"visual",      VISUAL},
  {"width",       ADJUST_WIDTH},
};

/* special keys */
GDKKey gdk_keys[] = {
  {"<BackSpace>", GDK_BackSpace},
  {"<CapsLock>",  GDK_Caps_Lock},
  {"<Down>",      GDK_Down},
  {"<Esc>",       GDK_Escape},
  {"<F10>",       GDK_F10},
  {"<F11>",       GDK_F11},
  {"<F12>",       GDK_F12},
  {"<F1>",        GDK_F1},
  {"<F2>",        GDK_F2},
  {"<F3>",        GDK_F3},
  {"<F4>",        GDK_F4},
  {"<F5>",        GDK_F5},
  {"<F6>",        GDK_F6},
  {"<F7>",        GDK_F7},
  {"<F8>",        GDK_F8},
  {"<F9>",        GDK_F9},
  {"<Left>",      GDK_Left},
  {"<PageDown>",  GDK_Page_Down},
  {"<PageUp>",    GDK_Page_Up},
  {"<Return>",    GDK_Return},
  {"<Right>",     GDK_Right},
  {"<Space>",     GDK_space},
  {"<Super>",     GDK_Super_L},
  {"<Tab>",       GDK_Tab},
  {"<Up>",        GDK_Up},
};
