/*Bu özellik deltafab tarafından eklenmiştir. Yazan İbrahim ŞENER */
#include "../../../inc/MarlinConfig.h"
#include "../../gcode.h"
#include "../../../lcd/ultralcd.h"
void GcodeSuite::M1005(){
  #if ENABLED(SDSUPPORT)
    wait_for_heatup = wait_for_user = false;
    card.flag.abort_sd_printing = true;
  #endif
  #ifdef ACTION_ON_CANCEL
    host_action_cancel();
  #endif
  ui.set_status_P(PSTR(MSG_PRINT_ABORTED), -1);
  ui.return_to_status();
}