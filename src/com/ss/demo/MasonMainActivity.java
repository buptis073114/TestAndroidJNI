package com.ss.demo;

import com.ss.jni.JNIUtil;

import android.app.Activity;
import android.os.Bundle;

public class MasonMainActivity extends Activity {
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		JNIUtil.nativec(this,savedInstanceState);
	}
}

//protected void onCreate1(Bundle savedInstanceState){
//
//}
//@Override
//public void onCreate(Bundle savedInstanceState) {
//super.onCreate(savedInstanceState);
////setContentView(R.layout.main);
//JNIUtil.nativec(this);
////EditText str1 = (EditText) this.findViewById(R.id.str1);
////str1.setText(JNIUtil.getPWD(this));
//
//// try {
//// PackageInfo info =
//// getPackageManager().getPackageInfo(getPackageName(), 64);
//// //签名就是用私钥加密后的字符串
//// Signature sign = info.signatures[0];
////
//// Log.e("test", "hashCode : " + sign.hashCode());
//// Log.e("test", "hashCodestring : " + sign.toCharsString());
//// Toast.makeText(this,sign.toCharsString(), Toast.LENGTH_LONG).show();
//// } catch (NameNotFoundException e) {
//// e.printStackTrace();
//// }
//
//}