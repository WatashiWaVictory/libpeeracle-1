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

#include "java/jni/jni_helpers.h"
#include "peeracle/Metadata/MetadataMediaSegment.h"

namespace peeracle {

class JNIMetadataMediaSegment : public MetadataMediaSegment {
 public:
  JNIMetadataMediaSegment(JNIEnv *jni, jobject j_MetadataMediaSegment)
    : _j_global(jni, j_MetadataMediaSegment),
      _j_class(jni, GetObjectClass(jni, j_MetadataMediaSegment)) {
  }

  ~JNIMetadataMediaSegment() {
  }

 private:
  JNIEnv* jni() {
    return AttachCurrentThreadIfNeeded();
  }

  const ScopedGlobalRef<jobject> _j_global;
  const ScopedGlobalRef<jclass> _j_class;
};

}

#ifdef __cplusplus
extern "C" {
#endif

#define JOPMMS(rettype, name) \
  rettype JNIEXPORT JNICALL Java_org_peeracle_MetadataMediaSegment_##name

JOPMMS(jlong, getTimecode)(JNIEnv *, jobject) {
  return static_cast<jlong>(NULL);
}

JOPMMS(jlong, getLength)(JNIEnv *, jobject) {
  return static_cast<jlong>(NULL);
}

JOPMMS(jbyteArray, getChunks)(JNIEnv *, jobject) {
  return static_cast<jbyteArray>(NULL);
}

JOPMMS(jboolean, unserialize)(JNIEnv *, jobject, jobject, jstring, jobject) {
  return static_cast<jboolean>(NULL);
}

JOPMMS(jlong, nativeCreateMetadataMediaSegment)(JNIEnv *env, jobject j_this) {
  peeracle::MetadataMediaSegmentInterface *segment =
    new peeracle::JNIMetadataMediaSegment(env, j_this);
  return jlongFromPointer(segment);
}

#ifdef __cplusplus
}
#endif
