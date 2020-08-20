package com.guyue.jnidemo;

public class JNITest {
    static {
        System.loadLibrary("jni-demo");   //链接后面生成的MYJni.so库
    }
    public native static String getStrFromJNI();
}
