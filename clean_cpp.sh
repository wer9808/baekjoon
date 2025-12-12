#!/bin/bash

# 매개변수: <폴더명> [문제번호]
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "사용법: $0 <폴더명> [문제번호]"
    echo "예시: $0 dp 11047  (특정 문제)"
    echo "예시: $0 dp        (폴더 내 모든 문제)"
    exit 1
fi

dirname=$1
problem_no=$2

if [ ! -d "$dirname" ]; then
    echo "오류: 디렉토리 '$dirname'를 찾을 수 없습니다."
    exit 1
fi

shopt -s nullglob

clean_problem_dir() {
    local dir="$1"
    local outputs=("$dir"/*.output)
    local exes=("$dir"/*.exe)
    local removed=false

    if [ ${#outputs[@]} -gt 0 ]; then
        echo "삭제 중: ${outputs[*]}"
        rm -- "${outputs[@]}"
        removed=true
    fi

    if [ ${#exes[@]} -gt 0 ]; then
        echo "삭제 중: ${exes[*]}"
        rm -- "${exes[@]}"
        removed=true
    fi

    if [ "$removed" = false ]; then
        echo "정리할 .exe / .output 파일이 없습니다: $dir"
    fi
}

if [ -n "$problem_no" ]; then
    target="$dirname/$problem_no"

    if [ ! -d "$target" ]; then
        echo "오류: 디렉토리 '$target'를 찾을 수 없습니다."
        exit 1
    fi

    clean_problem_dir "$target"
else
    found=false

    for dir in "$dirname"/*/; do
        found=true
        dir="${dir%/}"
        clean_problem_dir "$dir"
    done

    if [ "$found" = false ]; then
        echo "오류: '$dirname' 안에서 처리할 문제 폴더를 찾을 수 없습니다."
        exit 1
    fi
fi
