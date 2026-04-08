#!/bin/bash
# Xiang Wang(ramwin@qq.com)

sphinx-autobuild \
    --verbose \
    --host 0.0.0.0 \
    -j auto \
    --port 18006 \
    . _build/html/ \
    --re-ignore "\.mypy_cache" \
    --re-ignore "\.git"    \
    --re-ignore "\.*\.swp" \
    --re-ignore "\.*\.log" \
