package com.guyue.jnidynamicregisterdemo;

import android.content.Context;
import android.util.Log;

import java.util.Locale;

public class MyJni {

    static {
        System.loadLibrary("jni-MYJni");   //链接后面生成的MYJni.so库
    }

    static native String nativeHello();
    static native String nativeWorld();

    public static void logHelloWorld(Context context) {
        Log.d("hudouwen", String.format(Locale.ENGLISH, "%s %s", nativeHello(), nativeWorld()));
    }
}
