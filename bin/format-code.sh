#!/bin/sh
if [[ $# < 1 ]]
then
  echo "Please specify the source directory."
  exit
else
  SRC_DIR=${1}
fi

SRC_REGEX=".*\(\(\.cpp\)\|\(\.c\)\)"
HEAD_REGEX=".*\(\(\.h\)\|\(\.hpp\)\)"
SRC_FILES=`find ${SRC_DIR} -regex ${SRC_REGEX}`
HEAD_FILES=`find ${SRC_DIR} -regex ${HEAD_REGEX}`
ALL_FILES="${SRC_FILES} ${HEAD_FILES}"
TMP_DIR=/tmp/clang-format
if [[ ! -d ${TMP_DIR} ]]
then
  mkdir -p ${TMP_DIR}
fi

for file in ${ALL_FILES}
do
  tmp_file=${TMP_DIR}/clang-format-files.$$
  clang-format -style=file ${file} > ${tmp_file}
  if [[ ! `cmp ${file} ${tmp_file}` == ""  ]]
  then 
    echo "formatting ${file}."
    cat ${tmp_file} > ${file}
  fi
done

rm -rf ${TMP_DIR}

