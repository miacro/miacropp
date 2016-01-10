#!/bin/sh
directory=${1}
find ${directory} -regex ".*~" -delete
find ${directory} -regex ".*#[^#]+" -delete
find ${directory} -regex ".*\.#.*" -delete
