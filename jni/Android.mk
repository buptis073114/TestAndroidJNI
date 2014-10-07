LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=rusteze

LOCAL_SRC_FILES:=myjni.cpp myjni.h

LOCAL_LDLIBS :=  -lz -llog -L$(SYSROOT)/usr/lib  
include $(BUILD_SHARED_LIBRARY)
