#ifndef __ANDROID_LOGCAT_H__
#define __ANDROID_LOGCAT_H__

#define _CMCC_OMP_SEC_DEBUG 1

#ifdef _CMCC_OMP_SEC_DEBUG

#include <android/log.h>
	#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
	#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
	#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
	#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
	#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__)
	//#define _CMCC_OMP_SEC_MOTHERSO 1
	#define _CMCC_OMP_SEC_TIME 1

#else // _CMCC_OMP_SEC_DEBUG

	#define LOGI(...) 	{}
	#define LOGD(...)  	{}
	#define LOGW(...)  	{}
	#define LOGE(...)  	{}
	#define LOGF(...)  	{}

#endif // _CMCC_OMP_SEC_DEBUG

#endif // __ANDROID_LOGCAT_H__


