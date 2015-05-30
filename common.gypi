{
  'includes': [
    'build/common.gypi'
  ],
  'target_defaults': {
    'rules': [
      {
        'rule_name': 'lint_cc',
        'extension': 'cc',
        'inputs': [
          '<(DEPTH)/third_party/cpplint/cpplint.py',
        ],
        'outputs': [
          '>(INTERMEDIATE_DIR)/<(RULE_INPUT_NAME).lintstamp',
        ],
        'action': [
          'python', '>(_inputs)', '$$(pwd)/<(RULE_INPUT_PATH)'
        ],
      },
      {
        'rule_name': 'lint_h',
        'extension': 'h',
        'inputs': [
          '<(DEPTH)/third_party/cpplint/cpplint.py',
        ],
        'outputs': [
          '>(INTERMEDIATE_DIR)/<(RULE_INPUT_NAME).lintstamp',
        ],
        'action': [
          'python', '>(_inputs)', '$$(pwd)/<(RULE_INPUT_PATH)'
        ],
      },
    ],
  },
}