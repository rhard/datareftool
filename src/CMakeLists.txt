SET(SRC 
	"${CMAKE_CURRENT_SOURCE_DIR}/about_window.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/plugin.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/viewer_window.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/datarefs.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/find_datarefs_in_files.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/prefs.cpp" PARENT_SCOPE)
SET(HDR 
	"${CMAKE_CURRENT_SOURCE_DIR}/about_window.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/viewer_window.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/datarefs.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/clipboard.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/find_datarefs_in_files.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/prefs.h" PARENT_SCOPE)

SET(SRC_PLUGIN_EXAMPLE "${CMAKE_CURRENT_SOURCE_DIR}/plugin_custom_dataref.cpp" PARENT_SCOPE)
