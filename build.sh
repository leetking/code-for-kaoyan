#!/usr/bin/env bash

RELEASE_DIR="./release"
OUTPUT_FILE="code-of-datastruct-and-algorithm.pdf"

clean() {
    latexmk -c
    rm -rf _minted-code-of-data-struct-and-algorithm/
}

build() {
    latexmk
    mv "$OUTPUT_FILE" "$RELEASE_DIR"
}

print_usage() {
cat << EOF
Usage: ./build.sh [clean|build]
       if no parameter given, the default action is 'build'
EOF
}

if [[ $# -eq 0 ]]; then
    build
    exit 0
fi


case "$1" in
    "clean")
        clean
        ;;
    "build")
        build
        ;;
    "help")
        print_usage
        ;;
    *)
        echo "No such action '$1'"
        print_usage
        ;;
esac
