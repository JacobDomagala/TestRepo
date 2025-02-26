#!/usr/bin/env python3
"""
Static Analysis Checker using Pylint

Usage:
    python static_analysis.py <file1.py> [<file2.py> ...]
"""

import sys
from pylint import lint
from pylint.reporters.text import TextReporter
import io

def run_pylint(files):
    """Run pylint on the list of files and capture the output."""
    # Capture the output in a string buffer
    output = io.StringIO()
    reporter = TextReporter(output)
    
    # Run pylint on the provided files
    # You can adjust the options list below as needed
    args = files
    results = lint.Run(args, reporter=reporter, exit=False)
    
    # Get the output as a string
    output_str = output.getvalue()
    output.close()
    return results.linter.msg_status, output_str

def main():
    if len(sys.argv) < 2:
        print("Usage: {} <python_file.py> [<python_file2.py> ...]".format(sys.argv[0]))
        sys.exit(1)

    files = sys.argv[1:]
    exit_code, report = run_pylint(files)

    print("Pylint Report:")
    print(report)
    print("Exit Code:", exit_code)
    
    # Exit with the pylint status code to reflect analysis result
    sys.exit(exit_code)

if __name__ == "__main__":
    main()
