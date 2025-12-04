#!/bin/bash

# 매개변수 개수 확인
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "사용법: $0 <문제번호> [입력예제번호]"
    echo "예시: $0 solution 1"
    exit 1
fi

filename=$1
number=$2

# 지정된 디렉토리로 이동
if [ ! -d "$filename" ]; then
    echo "오류: 디렉토리 '$filename'를 찾을 수 없습니다."
    exit 1
fi

echo "작업 디렉토리: $filename"
cd "$filename" || {
    echo "오류: 디렉토리 '$filename'로 이동할 수 없습니다."
    exit 1
}

# C++ 소스 파일 존재 확인
if [ ! -f "${filename}.cpp" ]; then
    echo "오류: ${filename}.cpp 파일을 찾을 수 없습니다."
    exit 1
fi

echo "컴파일 중: ${filename}.cpp -> ${filename}.exe"

# g++로 컴파일
g++ -o "${filename}.exe" "${filename}.cpp"

# 컴파일 성공 여부 확인
if [ $? -ne 0 ]; then
    echo "오류: 컴파일에 실패했습니다."
    exit 1
fi

echo "컴파일 완료!"

if [ -n "$number" ]; then
    # 단일 입력 파일 존재 확인
    if [ ! -f "${number}.input" ]; then
        echo "오류: ${number}.input 파일을 찾을 수 없습니다."
        exit 1
    fi

    echo "실행 중: ${number}.input | ${filename}.exe > ${number}.output"

    "./${filename}.exe" < "${number}.input" > "${number}.output"

    if [ $? -eq 0 ]; then
        echo "실행 완료! 결과가 ${number}.output에 저장되었습니다."
    else
        echo "오류: 프로그램 실행 중 오류가 발생했습니다."
        exit 1
    fi
else
    shopt -s nullglob
    input_files=(*.input)

    if [ ${#input_files[@]} -eq 0 ]; then
        echo "오류: *.input 파일을 찾을 수 없습니다."
        exit 1
    fi

    for input_file in "${input_files[@]}"; do
        base="${input_file%.input}"
        echo "실행 중: ${input_file} | ${filename}.exe > ${base}.output"
        "./${filename}.exe" < "${input_file}" > "${base}.output"

        if [ $? -eq 0 ]; then
            echo "${input_file} 처리 완료 -> ${base}.output"
        else
            echo "오류: ${input_file} 처리 중 오류가 발생했습니다."
            exit 1
        fi
    done
fi
