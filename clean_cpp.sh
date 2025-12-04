#!/bin/bash

# 매개변수 개수 확인
if [ $# -ne 1 ]; then
    echo "사용법: $0 <문제번호>"
    echo "예시: $0 11047"
    exit 1
fi

dirname=$1

# 지정된 디렉토리로 이동
if [ ! -d "$dirname" ]; then
    echo "오류: 디렉토리 '$dirname'를 찾을 수 없습니다."
    exit 1
fi

cd "$dirname" || {
    echo "오류: 디렉토리 '$dirname'로 이동할 수 없습니다."
    exit 1
}

shopt -s nullglob
output_files=(*.output)
exe_files=(*.exe)
removed=false

if [ ${#output_files[@]} -gt 0 ]; then
    echo "삭제 중: ${output_files[*]}"
    rm -- "${output_files[@]}"
    removed=true
else
    echo "삭제할 .output 파일이 없습니다."
fi

if [ ${#exe_files[@]} -gt 0 ]; then
    echo "삭제 중: ${exe_files[*]}"
    rm -- "${exe_files[@]}"
    removed=true
else
    echo "삭제할 .exe 파일이 없습니다."
fi

if [ "$removed" = false ]; then
    echo "정리할 파일이 없습니다."
fi
