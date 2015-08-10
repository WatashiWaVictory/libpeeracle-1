#
# Copyright (c) 2015 peeracle contributors
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

{
  'includes': [
    '../build/common.gypi'
  ],
  'targets': [
    {
      'target_name': 'samples',
      'type': 'none',
      'dependencies': [
        'seed/seed.gyp:*',
      ],
      'conditions': [
        ['build_vlcplugin == 1', {
          'dependencies': [
            'vlc-plugin/vlc-plugin.gyp:*'
          ],
        }],
      ],
    }
  ],
  'conditions': [
    ['OS=="android"', {
      'targets': [
        {
          'target_name': 'PeeracleDemo',
          'type': 'none',
          'dependencies': [
            '<(DEPTH)/peeracle/peeracle.gyp:peeracle'
          ],
          'variables': {
            'apk_name': 'PeeracleDemo',
            'java_in_dir': 'android/app/src/main',
            'has_java_resources': 1,
            'resource_dir': 'android/app/src/main/res',
            'R_package': 'org.peeracle.peeracledemo',
            'R_package_relpath': 'org/peeracle/peeracledemo',
            'input_jars_paths': [
              'android/third_party/autobanh/autobanh.jar'
             ],
            'library_dexed_jars_paths': [
              'android/third_party/autobanh/autobanh.jar'
             ],
            'native_lib_target': 'libpeeracle',
            'add_to_dependents_classpaths':1,
          },
          'includes': [ '../third_party/webrtc/build/java_apk.gypi' ],
        },  # target PeeracleDemo

        {
          'target_name': 'PeeracleDemo_apk',
          'type': 'none',
          'dependencies': [
             'PeeracleDemo',
           ],
           'includes': [ '../third_party/webrtc/build/apk_fake_jar.gypi' ],
        },  # target PeeracleDemo_apk

        {
          'target_name': 'PeeracleDemoTest',
          'type': 'none',
          'dependencies': [
            'PeeracleDemo_apk',
           ],
          'variables': {
            'apk_name': 'PeeracleDemoTest',
            'java_in_dir': 'android/app/src/androidTest',
            'is_test_apk': 1,
          },
          'includes': [ '../third_party/webrtc/build/java_apk.gypi' ],
        },
      ],  # targets
    }],  # OS=="android"
  ],
}
