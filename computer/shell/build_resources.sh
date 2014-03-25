cmdToolsDir=$(cd "$(dirname "$0")"; pwd)
resourceDir=$1
buildDir="$resourceDir/../Resources_build"
#export PATH=$PATH:"$cmdToolsDir/ImageMagick/lib/"
export DYLD_LIBRARY_PATH="$cmdToolsDir/ImageMagick/lib/"

function scandir() {
    local cur_dir
    local workdir=$1
    cd ${workdir}
    if [ ${workdir} = "/" ]
    then
        cur_dir=""
    else
        cur_dir=$(pwd)
    fi

    for dirlist in $(ls ${cur_dir})
    do
        if test -d ${dirlist};then
            cd ${dirlist}
            scandir ${cur_dir}/${dirlist}
            cd ..
        else
            processingFile ${cur_dir}/${dirlist}
        fi
    done
}

function processingFile()
{
    local sourcePath=$1
    local relativePath=${sourcePath##"$resourceDir/"}
    local filePathMD5=$(md5 -s $relativePath | awk -F ' ' '{print $4}')
    local targetPath=${buildDir}/${filePathMD5}

    if [ "${sourcePath##*.}" = "lua" ]; then
        ${cmdToolsDir}/luajit -b $sourcePath $targetPath
    elif [ "${sourcePath##*.}" = "mp3" ]; then
        cp $sourcePath ${targetPath}.mp3
    elif [ "${sourcePath##*.}" = "jpg" ]; then
        ${cmdToolsDir}/ImageMagick/bin/convert -quality 25 -strip $sourcePath $targetPath
    elif [ "${sourcePath##*.}" = "png" ]; then
        local temp=${buildDir}/temp.png
        cp $sourcePath $temp
        ${cmdToolsDir}/pngquant --force --ordered --ext .png --quality=40-90 $temp
        mv $temp $targetPath
    elif [ "${sourcePath##*.}" = "plist" ]; then
        cp $sourcePath $targetPath
    elif [ "${sourcePath##*.}" = "ccz" ]; then
        cp $sourcePath $targetPath
    else #if [ "${sourcePath##*.}" = "so" ]; then
        echo $sourcePath
    fi

    if [ -f $targetPath ]; then
        local fileDataMD5=$(md5 $targetPath | awk -F ' ' '{print $4}');
        local fileSize=$(ls -l $targetPath | awk '{print $5}')
        echo "[\"$filePathMD5\"] = {md5=\"$fileDataMD5\", size=$fileSize},--$relativePath" >> ${buildDir}/res.lua
    fi

    return 0
}

if test -d $1
then
    if test -d $buildDir
    then
        rm -rf $buildDir
    fi
    mkdir $buildDir
    echo 'data_res_info = {' > ${buildDir}/res.lua
    scandir $1
    echo '}' >> ${buildDir}/res.lua
    #echo $buildDir
elif test -f $1
then
    echo "you input a file but not a directory,pls reinput and try again"
    exit 1
else
    echo "the Directory isn't exist which you input,pls input a new one!!"
    exit 1
fi
