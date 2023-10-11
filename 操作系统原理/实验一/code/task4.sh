#!/bin/bash

# 获取当前日期和时间
date=$(date +%Y-%m-%d-%H-%M)

# 获取脚本第一个参数，即目标目录
target_dir=$1

# 遍历目标目录中的所有文件
for file in "$target_dir"/*
do
  # 如果文件是一个普通文件而不是目录
  if [ -f "$file" ]; then
    # 获取文件名和扩展名
    filename=$(basename -- "$file")
    extension="${filename##*.}"
    filename="${filename%.*}"
    
    # 如果文件名中已经有日期和时间后缀，则不再添加
    if [[ $filename == *-$date ]]; then
      continue
    fi
    
    # 为文件名添加日期和时间后缀
    new_filename="$filename-$date.$extension"
    
    # 重命名文件
    mv "$file" "$target_dir/$new_filename"
  fi
done


