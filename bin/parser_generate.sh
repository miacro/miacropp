#!/bin/sh
function usage()
{
  echo "Usage: PROGRAM [working_dir] [flex_file] [bison_file]"
}

if [[ $# < 3 ]]
then
  usage
else
  working_dir=${1}
  flex_file=${2}
  bison_file=${3}
fi
postfix=.cpp
flex_base=`echo ${flex_file} | awk -F '.'  '{print $1}'`
bison_base=`echo ${bison_file} | awk -F '.' '{print $1}'`

flex --header-file=${working_dir}/${flex_base}.hpp -o ${working_dir}/${flex_base}${postfix}  ${working_dir}/${flex_file}
bison -L c -d -o ${working_dir}/${bison_base}${postfix} ${working_dir}/${bison_file}

