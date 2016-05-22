#!/bin/sh
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
LIPO="xcrun -sdk iphoneos lipo"
STRIP="xcrun -sdk iphoneos strip"

SRCDIR=$DIR/LuaJit-2.0.4
DESTDIR=$DIR/ios
IXCODE=`xcode-select -print-path`
ISDK=$IXCODE/Platforms/iPhoneOS.platform/Developer

echo "ISDKP: $ISDKP"
ISDKVER=iPhoneOS.sdk
rm "$DESTDIR"/*.a
cd $SRCDIR

make clean
ISDKF="-arch armv7 -isysroot $ISDK/SDKs/$ISDKVER"
make HOST_CC="clang -m32" CROSS=$ISDKP TARGET_FLAGS="$ISDKF" TARGET_SYS=iOS
mv "$SRCDIR"/src/libluajit.a "$DESTDIR"/libluajit-armv7.a

make clean
ISDKF="-arch armv7s -isysroot $ISDK/SDKs/$ISDKVER"
make HOST_CC="clang -m32" CROSS=$ISDKP TARGET_FLAGS="$ISDKF" TARGET_SYS=iOS
mv "$SRCDIR"/src/libluajit.a "$DESTDIR"/libluajit-armv7s.a

make clean
ISDK=$IXCODE/Platforms/iPhoneSimulator.platform/Developer
ISDKVER=iPhoneSimulator.sdk
# ISDKP=$ISDK/usr/bin/
ISDKF="-arch i386 -isysroot $ISDK/SDKs/$ISDKVER -mios-simulator-version-min=7.0"
# make HOST_CC="clang -m32" CROSS=$ISDKP TARGET_FLAGS="$ISDKF"
make HOST_CC="clang -m32 " CROSS=$ISDKP TARGET_FLAGS="$ISDKF" TARGET_SYS=iOS TARGET=x86
mv "$SRCDIR"/src/libluajit.a "$DESTDIR"/libluajit-i386.a

$LIPO -create "$DESTDIR"/libluajit-*.a -output "$DESTDIR"/libluajit.a
$STRIP -S "$DESTDIR"/libluajit.a
$LIPO -info "$DESTDIR"/libluajit.a

rm "$DESTDIR"/libluajit-*.a

make clean
