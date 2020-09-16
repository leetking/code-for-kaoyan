#!/usr/bin/env bash

BASE_NAME="code-of-datastruct-and-algorithm"
OUTPUT_FILE="$BASE_NAME.pdf"
RELEASE_DIR="./release"

clean() {
    latexmk -c
    rm -rf "_minted-$BASE_NAME"
}

build() {
    # need double compiling
    latexmk     # generate contents
    latexmk     # generate table of contents
    cp "$OUTPUT_FILE" "$RELEASE_DIR"
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
