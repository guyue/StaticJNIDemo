//
// Created by issuser on 2020/8/20.
//
#include <jni.h>
#define JAVA_CLASS_COM_GUYUE_JNIDYNAMICREGISTERDEMO_MYJNI "com/guyue/jnidynamicregisterdemo/MyJni"

jstring get_hello(JNIEnv *env, jclass obj) {
    return env->NewStringUTF("hello");
}

jstring get_world(JNIEnv *jniEnv, jclass clazz) {
    return jniEnv->NewStringUTF("world");
}

jstring get_hello_world(JNIEnv *jniEnv, jclass clazz, jstring helloworld) {
    return helloworld;
}


// 结构体JNINativeMethod的数组
// 结构体JNINativeMethod包含java的函数名, 参数列表, 本地函数指针
JNINativeMethod JNI_NATIVE_METHOD[] = {
        {"nativeHello", "()Ljava/lang/String;", (void *) get_hello},
        {"nativeWorld", "()Ljava/lang/String;", (void *) get_world}
};

// 注册函数
int register_native_method(JNIEnv *jniEnv) {
    jclass jclazz;
    // 先找到对应的jclass对象
    if (!(jclazz = jniEnv->FindClass(JAVA_CLASS_COM_GUYUE_JNIDYNAMICREGISTERDEMO_MYJNI))) {
        return -1;
    }
    // 使用JNIEnv进行注册, 参数为jclass对象, JNINativeMethod的数组, 以及数组的长度
    if (jniEnv->RegisterNatives(jclazz, JNI_NATIVE_METHOD,
                                sizeof(JNI_NATIVE_METHOD) / sizeof(JNINativeMethod)) < 0) {
        return -1;
    }
    return JNI_OK;
}

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *unused) {
    // 先从JavaVM获取JNIEnv对象
    JNIEnv *jniEnv;
    if (vm->GetEnv(reinterpret_cast<void **>(&jniEnv), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    // 执行函数注册
    register_native_method(jniEnv);
    return JNI_VERSION_1_6;
}