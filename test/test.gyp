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
  'conditions': [
    ['build_tests == 1', {
      'targets': [
        {
          'target_name': 'peeracle_tests_utils',
          'type': 'static_library',
          'include_dirs': [
            '<(DEPTH)',
          ],
          'sources': [
            'unittest_main.cc',
          ],
          'defines': [
            'GTEST_RELATIVE_PATH',
          ],
          'dependencies': [
            '<(webrtc_depth)/testing/gtest.gyp:gtest',
          ],
          'direct_dependent_settings': {
            'defines': [
              'GTEST_RELATIVE_PATH',
            ],
            'include_dirs': [
              '<(webrtc_depth)/testing/gtest/include',
            ],
          },
          'export_dependent_settings': [
            '<(webrtc_depth)/testing/gtest.gyp:gtest',
          ],
        },
      ],
    }, {
      'targets': [
        {
          'target_name': 'peeracle_tests_utils',
          'type': 'none'
        },
      ],
    }],
  ],
}
