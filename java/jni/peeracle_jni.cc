/*
 * Copyright (c) 2015 peeracle contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jni.h>
#include "java/jni/jni_helpers.h"

static JavaVM *g_jvm = NULL;

#ifdef __cplusplus
extern "C" {
#endif

jint JNIEXPORT JNI_OnLoad(JavaVM *vm, void *reserved) {
  CHECK(!g_jvm, "OnLoad called more than once");
  return JNI_VERSION_1_4;
}

void JNIEXPORT JNI_OnUnload(JavaVM *vm, void *reserved) {
}

#ifdef __cplusplus
}
#endif

JNIEXPORT void JNICALL Java_org_peeracle_Peeracle_Update(JNIEnv *, jclass) {
  printf("appel update\n");
  peeracle::update();
}

JNIEXPORT void JNICALL Java_org_peeracle_Peeracle_Cleanup(JNIEnv *, jclass) {
  printf("appel cleanup\n");
  peeracle::cleanup();
}

#ifdef __cplusplus
}
#endif
