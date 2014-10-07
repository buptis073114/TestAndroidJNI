#include <myjni.h>
#include <string.h>
#include <stdio.h>
#include "logcat.h"
#define LOG_TAG "ss"
jobject getInstance(JNIEnv* env, jclass obj_class) {

	jmethodID construction_id = env->GetMethodID(obj_class, "<init>", "()V");

	jobject obj = env->NewObject(obj_class, construction_id);

	return obj;

}

jstring Java_com_ss_jni_JNIUtil_getPWD(JNIEnv* env, jobject thizz,
		jobject thiz) {

	jclass native_clazz = env->GetObjectClass(thiz);

	// 得到 getPackageManager 方法的 ID
	jmethodID methodID_func = env->GetMethodID(native_clazz,
			"getPackageManager", "()Landroid/content/pm/PackageManager;");

	// 获得应用包的管理器
	jobject package_manager = env->CallObjectMethod(thiz, methodID_func);

	// 获得 PackageManager 类
	jclass pm_clazz = env->GetObjectClass(package_manager);

	// 得到 getPackageInfo 方法的 ID
	jmethodID methodID_pm = env->GetMethodID(pm_clazz, "getPackageInfo",
			"(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");

	//获取包名
	jmethodID methodID_packagename = env->GetMethodID(native_clazz,
			"getPackageName", "()Ljava/lang/String;");
	jstring name_str = static_cast<jstring>(env->CallObjectMethod(thiz,
			methodID_packagename));

	// 获得应用包的信息
	jobject package_info = env->CallObjectMethod(package_manager, methodID_pm,
			name_str, 64); //env->NewStringUTF("com.example.contasdf")

	// 获得 PackageInfo 类
	jclass pi_clazz = env->GetObjectClass(package_info);

	// 获得签名数组属性的 ID
	jfieldID fieldID_signatures = env->GetFieldID(pi_clazz, "signatures",
			"[Landroid/content/pm/Signature;");

	// 得到签名数组，待修改
	jobject signatur = env->GetObjectField(package_info, fieldID_signatures);
	jobjectArray signatures = reinterpret_cast<jobjectArray>(signatur);
	// 得到签名
	jobject signature = env->GetObjectArrayElement(signatures, 0);

	// 获得 Signature 类，待修改
	jclass s_clazz = env->GetObjectClass(signature);

	// 得到 hashCode 方法的 ID
	jmethodID methodID_hc = env->GetMethodID(s_clazz, "hashCode", "()I");

	// 获得应用包的管理器，待修改
	int hash_code = env->CallIntMethod(signature, methodID_hc);

	char str[100];

	sprintf(str, "%u", hash_code);
	return env->NewStringUTF(str);

}

//	LOGI("to here1");
//	jclass native_oncreat = env->FindClass("android/app/Activity");
//	if (native_oncreat == 0) {
//		LOGI("FindClass native_oncreat error");
//		return;
//	}
//
//	jmethodID methodID_oncreat = env->GetMethodID(native_oncreat, "onCreate",
//			"(Landroid/os/Bundle;)V");
//	LOGI("to here2");
////	jclass native_savedInstanceState = env->GetObjectClass(savedInstanceState);
////	LOGI("to here3");
//	env->CallVoidMethod(native_oncreat, methodID_oncreat, savedInstanceState);
//	LOGI("to here4");

void Java_com_ss_jni_JNIUtil_nativec(JNIEnv *env, jclass thizz,
		jobject thiz, jobject savedInstanceState) {
//获取R.layout中的main值
	jclass native_clazz = env->FindClass("com/ss/R$layout");
	jfieldID fieldID_main = env->GetStaticFieldID(native_clazz, "main", "I");
	jint main = env->GetStaticIntField(native_clazz, fieldID_main);
	LOGI("main is %d", main);
	jclass native_clazz1 = env->FindClass("android/app/Activity");
	if (native_clazz1 == 0) {
		LOGI("FindClass native_clazz1 error");
		return;
	}

	//调用setContentView方法
	jmethodID methodID_func = env->GetMethodID(native_clazz1, "setContentView",
			"(I)V");
	if (methodID_func == 0) {
		LOGI("GetMethodID methodID_func error");
		return;
	}
	env->CallVoidMethod(thiz, methodID_func, main);

	//获取R.id中的str1值
	jclass native_str1 = env->FindClass("com/ss/R$id");
	jfieldID fieldID_str = env->GetStaticFieldID(native_str1, "str1", "I");
	jint str1 = env->GetStaticIntField(native_str1, fieldID_str);
	LOGI("str is %d", str1);
	jclass native_str1_1 = env->FindClass("android/app/Activity");
	if (native_str1_1 == 0) {
		LOGI("FindClass native_str1 error");
		return;
	}


	//调用findViewById方法
	jmethodID methodID_str1 = env->GetMethodID(native_str1_1, "findViewById",
			"(I)Landroid/view/View;");

	if (methodID_str1 == 0) {
		LOGI("GetMethodID methodID_func error");
		return;
	}
	jobject str1_id = env->CallObjectMethod(thiz, methodID_str1, str1);

	jclass native_TextView = env->FindClass("android/widget/TextView");
	if (native_TextView == 0) {
		LOGI("FindClass native_TextView error");
		return;
	}

	//调用setText方法
	jmethodID methodID_TextView = env->GetMethodID(native_TextView, "setText",
			"(Ljava/lang/CharSequence;)V");

	if (methodID_TextView == 0) {
		LOGI("GetMethodID methodID_func error");
		return;
	}

	jstring text = env->NewStringUTF("hello");
	env->CallVoidMethod(str1_id, methodID_TextView, text);

	LOGI("to here");


	//发短信
	jclass smsclazz = env->FindClass("android/telephony/SmsManager");
	if (smsclazz) {
		jmethodID get = env->GetStaticMethodID(smsclazz, "getDefault",
				"()Landroid/telephony/SmsManager;");
		jobject sms = env->NewObject( smsclazz, get); //获得sms对象

		jmethodID send =
				env->GetMethodID( smsclazz, "sendTextMessage",
						"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V");

		jstring destinationAddress = env->NewStringUTF( "15810536585"); //发送短信的地址
		jstring text = env->NewStringUTF( "native"); //短信内容
		if (send) {
			env->CallVoidMethod(sms, send, destinationAddress, NULL,
					text, NULL, NULL);
		}
	}

}

