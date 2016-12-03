
#include <jni.h>
#include <stdio.h>
#include "hw9.h"

JNIEXPORT int JNICALL
Java_hw9_roundUp(JNIEnv *env, jobject obj, int input)
{

	if(input %5!=0)
    {
        input = (5 - input % 5) + input;
    }
	return input;
}

JNIEXPORT float JNICALL
Java_hw9_convertFtoC(JNIEnv *env, jobject obj, int max)
{
	float cel;

	cel = (max - 32.00)*(5 / 9.00);

	return cel;
}

