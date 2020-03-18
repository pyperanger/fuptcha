# fuptcha
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](http://forthebadge.com)

[![code-inspector](https://www.code-inspector.com/project/4758/score/svg)](https://www.code-inspector.com/)
[![code-inspector](https://www.code-inspector.com/project/4758/status/svg)](https://www.code-inspector.com/)
[![https://travis-ci.org/pyperanger/fuptcha](https://travis-ci.org/pyperanger/fuptcha.svg?branch=master)](https://travis-ci.org/pyperanger/fuptcha)



Fuptcha is a fuzzer CAPTCHA image recongnizer tool made in [Tesseract](https://github.com/tesseract-ocr/) C API. It try to find out the best language(trained models) in your tessdata repository to crack the CAPTCHA image given. You can utilize standalone Fuptcha binary for Proof of Concept prorpose or the fuptcha Python module for simulate real world attacks.

Is recomended install trained models from: https://github.com/tesseract-ocr/tessdata for best accuracy. (166 samples)

## Usage
You provide an image of the captcha you want to break and the correct text of this image, so the fuptcha will try to find out which trained models are able to correctly identify the text, which can be used as PoC for a security report, and / or automated attacks on web forms.

### Standalone binary
```
Usage: fuptcha -f image.png -s "FPGA2"

-f FILE         - File path
-s TEXT         - Text string to find in image
-m N             - Minimum Hit Percentage (Default N = 100)
-t N             - Set the number of threads (default N = 1).
-v               - Enable verbose mode
-h               - Display this information.
```

<img src="example/demo1.gif" alt="drawing" width="550"/>![foto1](example/foto1.jpg)

By default only 100% match trained models(languages) will display in console. You can set this value with '-m' argument.
### Python Module
Coming soon

## Examples
### Wordpress
Coming soon

## Install

```
$ ./configure
$ make
// Optional
$ sudo git clone https://github.com/tesseract-ocr/tessdata.git /usr/share/tessdata/
```

Python module install - Coming soon

---
Have found a Bug or a good Idea? Nice! Report here: https://github.com/pyperanger/fuptcha/issues

Written by pype & growlnx
