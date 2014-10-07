package com.ss.jni;

import android.content.Context;
import android.os.Bundle;

public class JNIUtil {
	static {
		System.loadLibrary("rusteze");
	}
	public static native void nativec(Context con,Bundle savedInstanceState);
	public native String stringFromJNI2(String str);
	public static native String getPWD(Context con);
}
