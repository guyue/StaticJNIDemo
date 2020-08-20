#include<jni.h>

JNIEXPORT jstring JNICALL
Java_com_guyue_jnidemo_JNITest_getStrFromJNI(JNIEnv *env, jclass clazz) {
    // TODO: implement getStrFromJNI()
    return (*env)->NewStringUTF(env,"I am Str from jni libs!");
}