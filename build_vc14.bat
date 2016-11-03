rm -r build
mkdir build
cd build
set BOOST_ROOT=C:\local\boost_1_60_0\
set BOOST_LIBRARYDIR=C:\local\boost_1_60_0\lib64-msvc-14.0\
cmake -G "Visual Studio 14 Win64" -Dgtest_force_shared_crt=1 -DBoost_DEBUG=ON ..
msbuild plugin.vcxproj /p:Configuration=Release /flp:logfile=plugin_build.log;verbosity=normal
cd ..
cp "C:\Users\lee\Documents\projects\datareftool\bin\datareftool\Release\win.xpl" "C:\Program Files (x86)\Steam\steamapps\common\X-Plane 10\Resources\plugins\DataRefTool\win.xpl"
