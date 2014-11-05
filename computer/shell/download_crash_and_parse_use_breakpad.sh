#!/bin/sh

scriptDir=$(cd "$(dirname "$0")"; pwd)
libName="libcocos2dlua.so"
outputDir='/home/luxiaodong/Desktop/crashStack'
downloadDir="/home/luxiaodong/Desktop/dumpFile"
yesterday=$(date "+%Y%m%d" -d '-1 day')
workDir=${downloadDir}/${yesterday}

download_crash_dump()
{
	cd $downloadDir
	wget -d "http://flash.aoshitang.com/download/$yesterday/mobile_gcld_androidcrash.zip"
	unzip 'mobile_gcld_androidcrash.zip'
	mv 'crashlog' $yesterday
	rm 'mobile_gcld_androidcrash.zip'
}

create_symbols()
{
	cd $scriptDir

	if [ -d symblos ]; then
		rm -R symblos
	fi

	symFile=${libName}.sym
	${scriptDir}/bin/dump_syms ${soDir}/${libName} > $symFile
	str=$(head -n1 ${scriptDir}/${symFile} | awk -F ' ' '{print $4}')
	mkdir symblos
	mkdir symblos/${libName}
	mkdir symblos/${libName}/${str}
	mv ${scriptDir}/${symFile} ${scriptDir}/symblos/${libName}/${str}
}

parse_dump_floder()
{
	local parentFloderName=${workDir##*/}
	outputDir=${outputDir}/${parentFloderName}

	if [ ! -d $outputDir ]; then
		mkdir $outputDir;
	fi

	for file in ${workDir}/*
	do
		if [ -f "$file" ]; then
			local fileName=${file##"${workDir}/"}
			if [ -n "$(echo $fileName | grep 'crash')" ]; then
				${scriptDir}/bin/minidump_stackwalk $file ${scriptDir}/symblos > ${outputDir}/${fileName}.txt
				if [ -n "$(grep 'cocos2d::' "${outputDir}/${fileName}.txt")" ]; then
					rm $file
				else
					rm ${outputDir}/${fileName}.txt 
				fi
			fi
		fi
	done
}

crash_log_script()
{
	echo ${downloadDir}/${yesterday}
	echo ${outputDir}/${yesterday}
	echo ${scriptDir}
	
	python ${scriptDir}/crash_log_scritp.py -i ${downloadDir}/${yesterday} -c ${outputDir}/${yesterday} -d ${yesterday}
}

#crash_log_script

if [ $# = 0 ]; then
    echo "miss .so file"
    exit 1
fi

soDir=$(cd "$(dirname "$1")"; pwd)
download_crash_dump && create_symbols && parse_dump_floder && crash_log_script

exit 0


