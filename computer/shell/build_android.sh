scriptDir=$(cd "$(dirname "$0")"; pwd)
releaseDir=$(cd ${scriptDir}/../channel_project; pwd)
androidSDK=$SDK_ROOT
androidANT="/Users/luxiaodong/Program/Android/apache-ant-1.9.3"
versionStr="v1.5.11.0"

function copy_res()
{
    #copy assets.
    if [ -d ${projectDir}/assets ]; then
        rm -rf ${projectDir}/assets
    fi

    mkdir ${projectDir}/assets
    for file in ${scriptDir}/assets/*
    do
        if [ -d "$file" ]; then
            cp -rf "$file" ${projectDir}/assets
        fi

        if [ -f "$file" ]; then
            cp "$file" ${projectDir}/assets
        fi
    done

    #copy lib_assets.
    for file in ${projectDir}/lib_assets/*
    do
        if [ -d "$file" ]; then
            cp -rf "$file" ${projectDir}/assets
        fi

        if [ -f "$file" ]; then
            cp "$file" ${projectDir}/assets
        fi
    done

    #copy libcocos2dlua.so
    if [ ! -d ${projectDir}/libs ]; then
        mkdir ${projectDir}/libs
    fi

    if [ ! -d ${projectDir}/libs/armeabi ]; then
        mkdir ${projectDir}/libs/armeabi
    fi

    if [ -f ${projectDir}/libs/armeabi/libcocos2dlua.so ]; then
        rm ${projectDir}/libs/armeabi/libcocos2dlua.so
    fi

    cp ${scriptDir}/libs/armeabi/libcocos2dlua.so ${projectDir}/libs/armeabi/libcocos2dlua.so
}

function build_config()
{
    if [ -f ${projectDir}/ant.properties ]; then
        rm ${projectDir}/ant.properties
    fi

    cp ${scriptDir}/ant.properties ${projectDir}/ant.properties
    timeStr=$(date "+%Y%m%d%H%M")
    channelName=${projectDir##*.}
    outPut="out.final.file=../android_build_key/gcld_${timeStr}_${versionStr}_${channelName}.apk"
    echo $outPut>>${projectDir}/ant.properties
}

function build_android()
{
    if [ ! -f ${projectDir}/AndroidManifest.xml ]; then
        echo "can't find android project."
        exit 1
    fi

    copy_res
    build_config
    cd $projectDir
    ${androidSDK}/tools/android update project -t android-19 -p $projectDir -s
    ${androidANT}/bin/ant clean release
    echo "love is over."
}

if [ $# == 0 ]; then
    echo "miss project dir"
    exit 1
fi

until [ $# -eq 0 ]
do
projectDir=$(cd $1; pwd)
build_android
shift
done

exit 0
